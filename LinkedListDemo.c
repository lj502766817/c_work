//
// Created by lijia07 on 2021/6/2.
//
#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

void printLinkedList(LinkedList L);

int main(){
    printf("hello LinkedList");
    LinkedList a = malloc(sizeof(LNode));
    a->data=1;
    a->next=NULL;
    LinkedList b = malloc(sizeof(LNode));
    b->data=2;b->next=a;
    LinkedList c = malloc(sizeof(LNode));
    c->data=3;c->next=b;
    LinkedList d = malloc(sizeof(LNode));
    d->data=4;d->next=c;
    LinkedList e = malloc(sizeof(LNode));
    e->data=3;e->next=d;
    LinkedList f = malloc(sizeof(LNode));
    f->data=5;
    f->next=e;
    LinkedList L=f;
    deleteValueX(L,3);
    printLinkedList(L);
    return 1;
}

void printLinkedList(LinkedList L){
    printf("LinkedList:");
    while (L!=NULL){
        printf("%d\t",L->data);
        L= L->next;
    }
}

/*
 * 相当于从最后开始检查,每次返回的链表都是已经删除了X的链表,时间复杂度为O(n)
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