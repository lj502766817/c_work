/*
 * @description: 
 * @Date: 2021-07-19 19:50:16
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-21 13:52:31
 * @FilePath: \c_work\demo1\tree\forestDemo.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct CsTNode{
    char data;
    struct CsTNode *firstChild,*nextSibline;
}CsTNode, *CsTree;

typedef struct Forest{
    struct CsTNode *trees;
    int cnt;
}Forest;

/**
 * 根据先序序列和中序序列构建森林对应的二叉树,使用孩子兄弟表示法
 */
CsTree buildBiForest(char *, int, int, char *, int, int);

CsTree buildBiForest(char *pre, int pb, int pe, char *mid, int mb, int me)
{
    if (pb>pe)
    {
        return NULL;
    }
    
    CsTree root = malloc(sizeof(CsTNode));
    root->data = pre[pb];
    root->firstChild = NULL;
    root->nextSibline = NULL;
    if (pb==pe)
    {
        return root;
    }
    
    int index;
    for (int i = mb; i <= me; i++)
    {
        if (mid[i]==pre[pb])
        {
            index = i;
            break;
        }
        
    }
    root->firstChild = buildBiForest(pre,pb+1,index-mb+pb,mid,mb,index-1);
    root->nextSibline = buildBiForest(pre,pe-me+index+1,pe,mid,index+1,me);
}

/**
 * 根据孩子兄弟表示法的树生成森林
 */
Forest buildForest(CsTree);

/**
 * 暂不考虑扩容问题
*/
Forest buildForest(CsTree tree)
{   
    int cnt = 0;
    CsTNode *trees= malloc(10 * sizeof(CsTNode));
    Forest forest = {trees,0};
    CsTree temp=tree;
    while (temp->nextSibline)
    {   
        CsTree p = temp;
        temp = temp->nextSibline;
        p->nextSibline=NULL;
        trees[cnt++]=*p;
    }
    trees[cnt++]=*temp;
    forest.cnt = cnt;
    return forest;
}

/**
 * 求树(孩子兄弟表示法)中的叶子结点,先序遍历
*/
int countLeafNodeInTree(CsTree);

int countLeafNodeInTree(CsTree tree)
{
    int cnt=0;
    //处理子结点
    if (tree->firstChild==NULL)
    {
        cnt++;
    }
    else 
    {
        cnt += countLeafNodeInTree(tree->firstChild);
    }
    //处理兄弟结点
    if (tree->nextSibline)
    {
        cnt += countLeafNodeInTree(tree->nextSibline);
    }

    return cnt;
}

/**
 * 编程求以孩子兄弟表示法存储的森林的叶子结点数。
 */
int countLeafNodeInForest(Forest);

int countLeafNodeInForest(Forest forest)
{
    int cnt=0;
    for (int i = 0; i < forest.cnt; i++)
    {
        cnt+=countLeafNodeInTree(&(forest.trees[i]));
    }
    
    return cnt;
}

/**
 * 以孩子兄弟链表为存储结构，请设计递归算法求树的深度。
 */
int getDepth(CsTree);

int getDepth(CsTree tree)
{   
    int depth=0,nextSiblineDepth=0;
    if (tree==NULL)
    {
        return 0;
    }

    //自己的深度
    if (tree->firstChild!=NULL)
    {
        depth=getDepth(tree->firstChild)+1;
    }
    else
    {
        depth = 1;
    }
    //兄弟结点的深度
    if (tree->nextSibline)
    {
        nextSiblineDepth = getDepth(tree->nextSibline);
    }
    //返回当前层最大深度
    return depth>nextSiblineDepth?depth:nextSiblineDepth;
    

    
}

/**
 * 已知一棵树的层次序列及每个结点的度，编写算法构造此树的孩子-兄弟链表。
 */
CsTree buildTree(char *,int *, int);

CsTree buildTree(char *seq,int *degrees, int len)
{
    CsTree nodes[len];
    for (int i = 0; i < len; i++)
    {
        CsTree node = malloc(sizeof(CsTNode));
        node->data = seq[i];
        node->firstChild = node->nextSibline= NULL;
        nodes[i]=node;
    }
    
    int index=0;
    for (int i = 0; i < len; i++)
    {   
        CsTree node = nodes[i];
        int degree = degrees[i];
        if (degree>=1)
        {   
            //链接孩子结点
            node->firstChild = nodes[++index];
            //孩子结点链接兄弟结点
            for (int i = 1; i < degree; i++)
            {
                CsTree cur = nodes[index];
                CsTree next = nodes[++index];
                cur->nextSibline = next;
            }
        }
    } 
    return nodes[0];  
}

int main(){
    printf("hello forest.\n");
    char pre1[13] = {'A','B','D','E','H','C','F','I','M','G','J','K','L'};
    char mid1[13] = {'D','B','H','E','A','I','M','F','C','G','K','L','J'};
    CsTree tree = buildBiForest(pre1,0,12,mid1,0,12);
    Forest forest = buildForest(tree);
    // countLeafNodeInForest(forest);
    int depth = getDepth(&(forest.trees[0]));
    printf("depth:%d\n",depth);
    char seq[13] = {'a','b','c','d','e','f','g','h','i','k','l','j','m'};
    int degrees[13] = {3,4,1,2,0,0,0,0,1,1,0,0,0};
    CsTree tree1 = buildTree(seq,degrees,13);
}
