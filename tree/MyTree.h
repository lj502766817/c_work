/*
 * @description: 
 * @Date: 2021-07-05 14:30:22
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-09 15:53:47
 * @FilePath: \c_work\demo1\tree\MyTree.h
 */

#ifndef DEMO1_MYTREE_H
#define DEMO1_MYTREE_H

#include <stdbool.h>
#include <math.h>

typedef struct BiTreeNode{
    int value;
    struct BiTreeNode *lChild,*rChild;
}BiTreeNode,*BiTree;

double log2(double x);
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

#endif //DEMO1_MYTREE_H
