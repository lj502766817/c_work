/*
 * @description: 
 * @Date: 2021-07-05 14:30:22
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-14 17:18:17
 * @FilePath: \c_work\demo1\tree\MyTree.h
 */

#ifndef DEMO1_MYTREE_H
#define DEMO1_MYTREE_H

#include <stdbool.h>
#include <math.h>

typedef struct BiTreeNode{
    char value;
    struct BiTreeNode *lChild,*rChild;
}BiTreeNode,*BiTree;

double log2(double x);

/**
 * 先序遍历构建树,value在a-z
*/
BiTree creatTree();

/**
 * 精度丢失风险
*/
double log2(double x){
    if(x==0){
        return 0;
    }
    double base = 2;
    double a = log(x);
    double b = log(base);
    return a/b;
}

BiTree creatTree(){
    char value[10];
    printf("enter value:");
    scanf("%s",value);
    if (value[0]>122||value[0]<97)
    {
        return NULL;
    }
    else
    {
        BiTree t = malloc(sizeof(BiTreeNode));
        t->value=value[0];
        t->lChild = creatTree();
        t->rChild = creatTree();
    }
}

/**
 * 已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点的最近的公共祖先结点的值。
 * @param {int} i
 * @param {int} j
 * @return {*}
 */
int getCommonParent(int i,int j);

/**
 * 编写后序遍历二叉树的非递归算法。
 * @param {BiTree} t
 * @param {int} cnt
 * @return {*}
 */
void subTraversal(BiTree t, int cnt);

/**
 * 试给出二叉树的自下而上、从右到左的层次遍历算法。
 * @param {BiTree} t
 * @param {int} cnt
 * @return {*}
 */
void seqTraversal(BiTree t, int cnt);

/**
 * 假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度。
 * @param {*}
 * @return {*}
 */
int height(BiTree t);

/**
 * 设一棵二叉树中各结点的值互不相同,其先序遍历序列和中序遍历序列分别存于两个一维数组A[1...n]和B[1...n]中,试编写算法建立该二叉树的二叉链表.
 * @param {char} pre
 * @param {int} preLen
 * @param {char} mid
 * @param {int} midLen
 * @return {*}
 */
BiTree buildTree(char pre[], int preLen, char mid[], int midLen);

/**
 * 二叉树按二叉链表形式存储，写一个判别给定二叉树是否是完全二叉树的算法.
 * @param {BiTree} t
 * @return {*}
 */
void checkComplete(BiTree t);

#endif //DEMO1_MYTREE_H
