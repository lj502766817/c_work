/*
 * @description: 
 * @Date: 2021-07-19 19:50:16
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-20 16:08:07
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
 * 根据先序序列和中序序列构建树对应的二叉树,使用孩子兄弟表示法
 */
CsTree buildTree(char *, int, int, char *, int, int);

CsTree buildTree(char *pre, int pb, int pe, char *mid, int mb, int me)
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
    root->firstChild = buildTree(pre,pb+1,index-mb+pb,mid,mb,index-1);
    root->nextSibline = buildTree(pre,pe-me+index+1,pe,mid,index+1,me);
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

    return forest;
}

int main(){
    printf("hello forest.\n");
    char pre1[13] = {'A','B','D','E','H','C','F','I','M','G','J','K','L'};
    char mid1[13] = {'D','B','H','E','A','I','M','F','C','G','K','L','J'};
    CsTree tree = buildTree(pre1,0,12,mid1,0,12);
    buildForest(tree);
}
