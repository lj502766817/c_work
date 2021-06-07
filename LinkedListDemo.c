//
// Created by lijia07 on 2021/6/2.
//
#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

/*
 * 打印不带头结点的单链表
 */
void printLinkedList(LinkedList L);

/*
 * 打印带头结点的单链表
 */
void printLinkedListWithHead(LinkedList L);

/*
 * 初始化不带头结点的单链表,采用尾插法
 */
LinkedList initLinkedList(const int arr[], int len);

/*
 * 初始化带头结点的单链表,采用尾插法
 */
LinkedList initLinkedListWithHead(const int arr[], int len);

int main(){
    printf("hello LinkedList\n");
    int a[] = {11,2,8,4,3,5};
    LinkedList L= initLinkedList(a,6);
    LinkedList LWithHead = initLinkedListWithHead(a,6);
//    deleteValueX(L,3);
//    printLinkedList(L);
//    removeValueX(LWithHead,3);
//    printLinkedListWithHead(LWithHead);
//    printListReverse(LWithHead);
    deleteMin(LWithHead);
    return 1;
}

LinkedList initLinkedList(const int arr[], int len){
    LinkedList head;
    LinkedList pre;
    for (int i = 0; i < len; ++i) {
        if(i==0){
            head = malloc(sizeof(LNode));
            head->data = arr[i];
            head->next = NULL;
            pre = head;
        } else{
            LinkedList node = malloc(sizeof(LNode));
            node->data = arr[i];
            node->next = NULL;
            pre->next = node;
            pre = node;
        }
    }
    return head;
}

LinkedList initLinkedListWithHead(const int arr[], int len){
    LinkedList head = malloc(sizeof(LNode));
    head->data=len;
    head->next=NULL;
    LinkedList pre = head;
    for (int i = 0; i < len; ++i) {
        LinkedList node = malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = NULL;
        pre->next = node;
        pre = node;
    }
    return head;
}

void printLinkedList(LinkedList L){
    printf("LinkedList:");
    while (L!=NULL){
        printf("%d\t",L->data);
        L= L->next;
    }
}

void printLinkedListWithHead(LinkedList L){
    printf("LinkedListWithHead:");
    while (L->next!=NULL){
        printf("%d\t",L->next->data);
        L = L->next;
    }
}

/*
 * 相当于从最后开始检查,每次返回的链表都是已经删除了X的链表,时间复杂度为O(n),采用了递归,每轮递归的额外空间为常量,空间复杂度为O(n)
 */
LinkedList deleteValueX(LinkedList L, int X){
    //终态返回
    if(L==NULL){
        return L;
    }
    //检查后一个结点
    LinkedList last = deleteValueX(L->next,X);
    if(L->data==X){
        //如果当前结点需要被删除就返回后面的结点
        free(L);
        return last;
    } else {
        //将后面的结点拼接在当前结点上,然后返回当前结点
        L->next = last;
        return L;
    }
}

/*
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
void removeValueX(LinkedList L, int x){
    if(L->next==NULL){
        return;
    }
    while (L->next!=NULL){
        if(L->next->data==x){
            LNode *p = L->next;
            L->next = p->next;
            free(p);
        } else{
            L=L->next;
        }
    }
}

/*
 * 法1:采用头插法,逆序一个链表.时间复杂度为O(n),空间复杂度为O(n)
 * 法2:先进后出,采用可以使用栈,考虑到栈的思想,可以使用递归进行操作.时间复杂度为O(n),空间复杂度为O(n)
 */
void printListReverse(LinkedList L){
    void printListReverse2(LinkedList L);
    printListReverse2(L);
    void printListReverse1(LinkedList L);
    printListReverse1(L);
}

void printListReverse1(LinkedList L){
    LinkedList head = malloc(sizeof(LNode));
    head->next=NULL;
    head->data=0;
    while (L->next!=NULL){
        //取出一个node
        LNode *temp = L->next;
        L->next = temp->next;
        //将这个node用头插法放到新链表下
        temp->next = head->next;
        head->next = temp;
    }
    printLinkedListWithHead(head);
}

void printListReverse2(LinkedList L){
    if(L==NULL){
        return;
    }
    printListReverse2(L->next);
    printf("%d\t",L->data);
}

void deleteMin(LinkedList L){
    LinkedList head = L;
    LNode *preNode=L;
    int temp = L->next->data;
    //遍历找出最小节点的前一个节点
    while (L->next!=NULL){
        if(L->next->data<temp){
            preNode=L;
            temp = L->next->data;
        }
        L = L->next;
    }
    //删除最小节点
    LNode *p = preNode->next;
    preNode->next = preNode->next->next;
    free(p);
    printLinkedListWithHead(head);
}
