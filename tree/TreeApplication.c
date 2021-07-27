/*
 * @Author: your name
 * @Date: 2021-07-26 15:12:10
 * @LastEditTime: 2021-07-27 16:54:19
 * @LastEditors: lijia
 * @Description: In User Settings Edit
 * @FilePath: \c_work\demo1\tree\TreeApplication.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode
{
    int data,count;
    struct BSTNode *lChild, *rChild;
} BSTNode, *BSTree;

/**
 * 根据先序和中序构造树
*/
BSTree buildTree(int pre[], int preLen, int mid[], int midLen);

/**
 * 二叉排序树插入
*/
BSTree insertBst(BSTree, int);

/**
 * 判断是否是二叉排序树
*/
bool checkBst(BSTree);

/**
 * 查看结点在数的第几层
*/
int checkTier(BSTree, int);

/**
 * 判断一个树是否是平衡二叉树
*/
bool checkBalance(BSTree, int *);

/**
 * 找到二叉排序树的最大最小关键字
*/
void findMaxAndMin(BSTree);

/**
 * 找到二叉排序树中所有不大于k的关键字,从大到小输出
 * ------------------------------------
 * 也可以正常的中序遍历然后用辅助栈进行逆向输出
*/
void findByK(BSTree, int);

BSTree findIndexK(BSTree, int);

BSTree findIndexK(BSTree tree, int k)
{   
    if (tree==NULL)
    {
        return NULL;
    }
    
    int lCnt=0,rCnt=0;
    if (tree->lChild!=NULL)
    {
        lCnt=tree->lChild->count+1;
    }
    if (tree->rChild!=NULL)
    {
        rCnt = tree->rChild->count+1;
    }
    if (k==lCnt+1)
    {
        printf("the node is %d.\n",tree->data);
        return tree;
    }
    //k在左子树上
    if (k<lCnt+1)
    {
        return findIndexK(tree->lChild,k);
    }
    //k在右子树上
    else
    {
        return findIndexK(tree->rChild,k-lCnt-1);
    }
    
    return NULL;
}

void findByK(BSTree tree, int k)
{
    //进行先右子树,再根节点,再左子树的中序遍历,进行从大到小的输出
    if (tree==NULL)
    {
        return;
    }
    if (tree->rChild!=NULL)
    {
        findByK(tree->rChild,k);
    }
    if (tree->data>=k)
    {
        printf("%d\t",tree->data);
    }
    if (tree->lChild!=NULL)
    {
        findByK(tree->lChild,k);
    }    
}

void findMaxAndMin(BSTree tree)
{
    BSTree p = tree;
    int max,min;
    while (p)
    {
        min= p->data;
        p = p->lChild;
    }
    p = tree;
    while (p)
    {
        max = p->data;
        p = p->rChild;
    }
    
    printf("max is:%d,min is:%d.\n",max,min);
}

bool checkBalance(BSTree tree, int *height)
{
    //平衡二叉树的左右子树都是平衡二叉树,并且左右子树高度差不大于1;
    if (tree == NULL)
    {
        *height = 0;
        return true;
    }

    int hL, hR;
    if (!checkBalance(tree->lChild, &hL) || !checkBalance(tree->rChild, &hR))
    {
        return false;
    }
    if ((hL > hR ? hL-hR : hR-hL)<=1)
    {
        *height = hL > hR ? hL + 1 : hR + 1;
    }
    else
    {
        return false;
    }
    
    return true;
}

int checkTier(BSTree tree, int value)
{
    //二叉排序树每寻找一次都会向下降一层
    int tier = 0;
    BSTree p = tree;

    while (p)
    {
        tier++;
        if (p->data == value)
        {
            printf("%d is at %d tier.\n", value, tier);
            return tier;
        }
        p = p->data < value ? p->rChild : p->lChild;
    }

    printf("there is no node %d.\n", value);
    return 0;
}

bool checkBst(BSTree tree)
{
    //使用栈进行非递归的中序遍历
    BSTree stack[50];
    int top = -1, pre;
    bool flag = false;
    BSTree p = tree;

    while (p || top >= 0)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->lChild;
        }
        else
        {
            //没有左结点,读取栈顶结点
            BSTree node = stack[top--];
            printf("check node:%d\n", node->data);
            if (flag)
            {
                if (pre < node->data)
                {
                    pre = node->data;
                }
                else
                {
                    printf("tree is not BST.\n");
                    return false;
                }
            }
            else
            {
                pre = node->data;
            }
            p = node->rChild;
        }
    }
    return true;
}

BSTree insertBst(BSTree tree, int value)
{
    if (tree == NULL)
    {
        BSTree bst = malloc(sizeof(BSTNode));
        bst->data = value;
        bst->count = 0;
        bst->lChild = NULL;
        bst->rChild = NULL;
        return bst;
    }
    if (value < tree->data)
    {
        if (tree->lChild != NULL)
        {
            insertBst(tree->lChild, value);
        }
        else
        {
            BSTree bst = malloc(sizeof(BSTNode));
            bst->data = value;
            bst->count = 0;
            bst->lChild = NULL;
            bst->rChild = NULL;
            tree->lChild = bst;
        }
    }

    if (value > tree->data)
    {
        if (tree->rChild != NULL)
        {
            insertBst(tree->rChild, value);
        }
        else
        {
            BSTree bst = malloc(sizeof(BSTNode));
            bst->data = value;
            bst->count = 0;
            bst->lChild = NULL;
            bst->rChild = NULL;
            tree->rChild = bst;
        }
    }
    tree->count+=1;
    return tree;
}

BSTree buildTree(int pre[], int preLen, int mid[], int midLen)
{
    BSTree t = malloc(sizeof(BSTNode));
    int head = pre[0];
    t->data = head;
    t->lChild = NULL;
    t->rChild = NULL;
    //如果先序和中序都是一个结点,直接返回
    if (preLen == 1 || midLen == 1)
    {
        return t;
    }

    //找到父节点在中序遍历中的位置
    int index;
    for (int i = 0; i < midLen; i++)
    {
        if (t->data == mid[i])
        {
            index = i;
            break;
        }
    }
    //生成左子树
    int leftNum = index;
    if (leftNum > 0)
    {
        int midLeft[leftNum], preLeft[leftNum];
        //处理中序遍历
        for (int i = 0; i < index; i++)
        {
            midLeft[i] = mid[i];
        }
        //处理先序遍历
        for (int i = 1, j = 0; j < leftNum; i++, j++)
        {
            preLeft[j] = pre[i];
        }
        t->lChild = buildTree(preLeft, leftNum, midLeft, leftNum);
    }
    //生成右子树
    int rightNum = midLen - 1 - index;
    if (rightNum > 0)
    {
        int midRight[rightNum], preRight[rightNum];
        //处理中序遍历
        for (int i = index + 1, j = 0; j < rightNum; i++, j++)
        {
            midRight[j] = mid[i];
        }
        //处理先序遍历
        for (int i = leftNum + 1, j = 0; j < rightNum; i++, j++)
        {
            preRight[j] = pre[i];
        }
        t->rChild = buildTree(preRight, rightNum, midRight, rightNum);
    }

    return t;
}

int main()
{
    int pre1[6] = {34,23,15,103,98,115};
    int mid1[6] = {15,23,34,98,103,115};
    BSTree t1 = buildTree(pre1, 6, mid1, 6);
    int arr[10] = {40, 72, 38, 35, 67, 51, 90, 8, 55, 21};
    BSTree tree = NULL;
    for (int i = 0; i < 10; i++)
    {
        tree = insertBst(tree, arr[i]);
    }
    // checkBst(tree);
    // checkTier(tree,40);
    // int height;
    // bool result = checkBalance(tree,&height);
    // printf("checkBalance:%d.\n",result);
    // findMaxAndMin(t1);
    // findByK(t1,-1);
    findIndexK(tree,8);
    printf("tree applicantion.\n");
}
