//
// Created by lijia07 on 2021/6/2.
//

#include <stdbool.h>

#ifndef DEMO1_MYLINKEDLIST_H
#define DEMO1_MYLINKEDLIST_H

typedef struct LNode{
    int data; //数据域
    struct LNode *next;//指针域
}LNode,*LinkedList;

typedef struct DNode{
    int data; //数据域
    struct DNode *prior,*next;
}DNode,*DLinkedList;

/**
 * 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。
 * @param list
 * @param X
 * @return
 */
LinkedList deleteValueX(LinkedList L, int X);

/**
 * 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作
 * @param L
 * @param x
 */
void removeValueX(LinkedList L, int x);

/**
 * 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
 * @param L
 */
void printListReverse(LinkedList L);

/**
 * 试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的)
 * @param L
 */
void deleteMin(LinkedList L);

/**
 * 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)
 * @param L
 */
void reverseLinkedListWithHead(LinkedList L);

/**
 * 有一个带头结点的单链表L，设计一个算法使其元素递增有序
 * @param L
 */
void ascendLinkedListWithHead(LinkedList L);

/**
 * 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）。
 * @param L
 * @param begin
 * @param end
 */
void removeBetween(LinkedList L, int begin, int end);

/**
 * 给定两个单链表，编写算法找出两个链表的公共结点。
 * @param l1
 * @param l2
 */
void findSameNode(LinkedList l1, LinkedList l2);

#endif //DEMO1_MYLINKEDLIST_H
