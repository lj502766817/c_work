/*
 * @Author: lijia
 * @Date: 2021-06-20 22:25:29
 * @LastEditTime: 2021-06-23 14:56:53
 * @LastEditors: lijia
 * @Description: 栈算法题
 * @FilePath: \c_work\demo1\stack\MyStack.h
 */

#include <stdbool.h>
#include "../linkedList/MyLinkedList.h"

#ifndef DEMO1_MYSTACK_H
#define DEMO1_MYSTACK_H


struct SharingSeqStack {
    int data[10];
    int top[50];
} sharingSeqStack={{0},{-1,50}};

struct TagSeqQueue {
    int data[10];
    int tag;
    int front;
    int rear;
} tagSeqQueue={{0},0,0,0};


/**************************************************** Implementation *************************************************************/



/*****************************************************************************************************************/

/**
 * 查看出入栈操作是否合法,arr = {I,O,I,I},I表示进栈,O表示出栈
 * @param {char} arr
 * @param {int} len
 * @return {*}
 */
int checkStackOpt(char arr[],int len);

/**
 * 设单链表的表头指针为L,结点结构由data和next两个域构成,其中data域为字符型.试设计算法判断该链表的全部n个字符是否中心对称。
 * 例如xyx、xyyx都是中心对称。
 * @param {CharLinkedList} L
 * @param {int} n
 * @return {*}
 */
int checkCharListSymmetry(CharLinkedList L, int n);

/**
 * 共享栈入栈
 * @param {int} i
 * @param {int} value
 * @return {*}
 */
int pushSharingSeqStack(int i, int value);

/**
 * 共享栈出栈
 * @param {int} i
 * @param {int *} value
 * @return {*}
 */
int popSharingSeqStack(int i, int * value);

/**
 * 若希望循环队列中的元素都能得到利用，则需设置一个标志域tag，
 * 并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的队列状态是“空”还是“满”。
 * 试编写与此结构相应的入队和出队算法。
*/
int enQueueWithTag(int value);
int deQueueWithTap(int * value);

#endif //DEMO1_MYSTACK_H
