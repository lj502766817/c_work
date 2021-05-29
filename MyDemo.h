//
// Created by lijia07 on 2021/5/24.
//

#include <stdbool.h>

#ifndef DEMO1_MYDEMO_H
#define DEMO1_MYDEMO_H

#define InitSize 100

typedef struct {
    int value;
}ElemType;

typedef struct {
    int MaxSize,Length;
    ElemType *data;
}SeqList;

//斐波那契数列递归和非递归
int fibonacciRecursion(int n);
int fibonacciNonrecursion(int n);

/**
 * 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
 * @param list
 * @param e
 * @return
 */
bool delMin(SeqList *list, ElemType *e);

/**
 * 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
 * @param list
 * @return
 */
bool reverseList(SeqList *list);

/**
 * 对长度为 n 的顺序表I，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素。
 * @param x
 * @param list
 * @return
 */
bool delValueX(SeqList *list, int x);

/**
 * 从有序顺序表中删除其值在给定值s与t之间（要求s小于t)的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
 * @param list
 * @param s
 * @param t
 * @return
 */
bool delBetween(SeqList *list, int s, int t);

/**
 * 从顺序表中删除其值在给定值s与t之间（包含s和t，要求 s < t)的所有元素，如果S或t不合理或顺序表为空，则显示出错信息并退出运行。
 * @param list
 * @param s
 * @param t
 * @return
 */
bool delBetweenAndEqual(SeqList *list, int s, int t);

/**
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 * @param list
 * @return
 */
bool removeDuplicative(SeqList *list);

/**
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 * @param l1
 * @param l2
 * @return
 */
SeqList mergeSeqList(SeqList *l1, SeqList *l2);

/**
 * 已知在一维数组[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。
 * 试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面
 * @param arr
 * @param len
 * @param m
 * @param n
 * @return
 */
bool exchangeArray(int arr[],int len, int m, int n);

/**
 * 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。
 * 要求设计一算法，完成用最少时间在表中查找数值为x的元素，
 * 若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。
 * @param list
 * @return
 */
bool handleValueX(SeqList *list);

#endif //DEMO1_MYDEMO_H
