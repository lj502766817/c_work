/*
 * @description: 
 * @Date: 2021-07-05 14:30:22
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-05 16:20:43
 * @FilePath: \c_work\demo1\tree\MyTree.h
 */

#ifndef DEMO1_MYTREE_H
#define DEMO1_MYTREE_H

#include <stdbool.h>
#include <math.h>

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

#endif //DEMO1_MYTREE_H
