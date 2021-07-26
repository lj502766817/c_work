/*
 * @Author: your name
 * @Date: 2021-07-26 15:12:10
 * @LastEditTime: 2021-07-26 18:15:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c_work\tree\TreeApplication.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *lChild, *rChild;
} BSTNode, *BSTree;

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

    printf("there is no node %d.\n",value);
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
            bst->lChild = NULL;
            bst->rChild = NULL;
            tree->rChild = bst;
        }
    }

    return tree;
}

int main()
{
    int arr[10] = {40, 72, 38, 35, 67, 51, 90, 8, 55, 21};
    BSTree tree = NULL;
    for (int i = 0; i < 10; i++)
    {
        tree = insertBst(tree, arr[i]);
    }
    // checkBst(tree);
    checkTier(tree,40);
    printf("use tree.\n");
}