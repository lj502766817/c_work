//
// Created by lijia07 on 2021/5/24.
//

#include <stdbool.h>

#ifndef DEMO1_MYDEMO_H
#define DEMO1_MYDEMO_H

#define InitSize 100

typedef struct {
    int value;
} ElemType;

typedef struct {
    int MaxSize, Length;
    ElemType *data;
} SeqList;

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
bool exchangeArray(int arr[], int len, int m, int n);

/**
 * 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。
 * 要求设计一算法，完成用最少时间在表中查找数值为x的元素，
 * 若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序。
 * @param list
 * @param x
 * @return
 */
bool handleValueX(SeqList *, int x);

/**
 * 设将n (n> 1)个整数存放到一维数组R中。 设计一个在时间和空间两方面都尽可能高效的算法。
 * 将R中保存的序列循环左移p(p在0和n之间)个位置， 即将R中的数据由(X0,X1,...,Xn-1)变换为(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)
 * @param arr
 * @param n
 * @return
 */
bool cycleMove(int *arr, int len, int n);

/**
 * 一个长度为L(L大于)的升序序列S处在第[L/2]个位置的数称为S的中位数。
 * 例如，若序列S1= (11， 13, 15, 17, 19)，则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。
 * 例如， 若S2=(2, 4, 6, 8, 20)， 则S1和S2的中位数是11。 现在有两个等长升序序列A和B试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列d和召的中位数。
 * @param A
 * @param B
 * @param len
 * @return
 */
bool findMid(int A[], int B[], int len);

/**
 * 已知一个整数序列A = (a0,a1,...,an-1)， 其中0小于等于ai小于n ( 0小于等于i小于n )。若存在 ap1 = ap2=...=apm = x且m大于n/2 (0小于等于pk小于n, 1大于等于k小于等于m),则称 x 为 A的主元素。
 * 例如A=(0,5,5,3,5,7,5,5),则5为主元素;又如A=(0,5,5,3,5,1,5,7),则A中没有主元素. 假设A中的n个元素保存在一个一维数组中， 请设计一个尽可能高效的算法， 找出A的主元素。
 * @param list
 * @param len
 * @return
 */
int findMainEle(const int *list, int len);

/**
 * 给定一个含n(n大于等于1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
 * 例如，数组{-5,3,2,3}中未出现的最小正整数是1;数组{1，2,3}中未出现的最小正整数是4。
 * @param arr
 * @param len
 * @return
 */
bool findNotAppearNum(const int *arr, int len);

#endif //DEMO1_MYDEMO_H
