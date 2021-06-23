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
    int freq; //频度域
    struct DNode *prior,*next; //指针域
}DNode,*DLinkedList;

typedef struct LCharNode{
    char data;
    struct LCharNode *next;
}LCharNode,*CharLinkedList;

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

void initLinkedListY(LinkedList l1, LinkedList l2);

/*
 * 初始化带头结点的双链表,采用尾插法
 */
DLinkedList initDLinkedList(const int arr[], int len);

/*
 * 初始化带头结点的双链表,采用尾插法
 */
DLinkedList initCycleDLinkedList(const int arr[], int len);

void printDLinkedList(DLinkedList L);


LinkedList initCycleLinkedList(const int arr[], int len);

LinkedList initCycleLinkedListWithHead(const int arr[], int len);

LinkedList initLinkedListContainCycle(const int arr[], int len);

CharLinkedList initCharLinkedList(const char arr[], int len);

/**************************************************** Implementation *************************************************************/

LinkedList initCycleLinkedListWithHead(const int arr[], int len){
    LNode *head = malloc(sizeof(LNode));
    head->data = len;
    head->next = head;
    LNode *pre = head;
    for (int i = 0; i < len; ++i) {
        LNode *node = malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = pre->next;
        pre->next = node;
        pre = node;
    }
    return head;
}

LinkedList initCycleLinkedList(const int arr[], int len){
    LinkedList L;
    LNode *pre;
    for (int i = 0; i < len; ++i) {
        LNode *node = malloc(sizeof(LNode));
        node->data = arr[i];
        if(i==0){
            L = node;
            node->next = L;
        } else{
            node->next = pre->next;
            pre->next = node;
        }
        pre = node;
    }
    return L;
}

DLinkedList initCycleDLinkedList(const int arr[], int len){
    DNode *head = malloc(sizeof(DNode));
    head->data = len;
    head->next = head;
    head->prior = head;
    DNode *p = head;
    for (int i = 0; i < len; ++i) {
        DNode *node = malloc(sizeof(DNode));
        node->data = arr[i];
        node->next = head;
        node->prior = head->prior;
        head->prior->next = node;
        head->prior = node;
    }
    return head;
}

DLinkedList initDLinkedList(const int arr[], int len){
    DNode *head = malloc(sizeof(DNode));
    head->data = len;
    head->next = NULL;
    head->prior = NULL;
    DNode *p = head;
    for (int i = 0; i < len; ++i) {
        DNode *node = malloc(sizeof(DNode));
        node->data = arr[i];
        node->prior = p;
        node->freq = 0;
        node->next = NULL;
        p->next = node;
        p = p->next;
    }
    return head;
}

void initLinkedListY(LinkedList l1, LinkedList l2){
    LNode *pre1 = l1;
    LNode *pre2 = l2;
    for (int i = 15; i < 19; ++i) {
        LNode *node = malloc(sizeof(LNode));
        node->data = i;
        node->next = NULL;
        pre1->next = node;
        pre1 = node;
    }
    for (int i = 21; i < 28; ++i) {
        LNode *node = malloc(sizeof(LNode));
        node->data = i;
        node->next = NULL;
        pre2->next = node;
        pre2 = node;
    }
    for (int i = 3; i < 9; ++i) {
        LNode *node = malloc(sizeof(LNode));
        node->data = i;
        node->next = NULL;
        pre1->next = node;
        pre1 = node;
        pre2->next = node;
        pre2 = node;
    }
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
    printf("LinkedList:\t");
    LNode *head = L;
    while (L!=NULL){
        printf("%d\t",L->data);
        L= L->next;
        if(L==head){
            break;
        }
    }
    printf("\n");
}

void printDLinkedList(DLinkedList L){
    printf("DLinkedList:");
    DNode *head = L;
    while (L->next&&L->next!=head){
        printf("%d\t",L->next->data);
        L = L->next;
    }
    printf("\n");
}

void printLinkedListWithHead(LinkedList L){
    printf("LinkedListWithHead:");
    while (L->next!=NULL){
        printf("%d\t",L->next->data);
        L = L->next;
    }
    printf("\n");
}

LinkedList initLinkedListContainCycle(const int arr[], int len){
    LNode *head = malloc(sizeof(LNode));
    head->data = len;
    head->next = NULL;
    LNode *pre = head;
    LNode *tail = NULL;
    for (int i = 0; i < len; i++)
    {
        if (i==len/2)    
        {
            LNode *tail = malloc(sizeof(LNode));
            tail->data = arr[i];
            tail->next = pre;
            pre->next = tail;
            pre = pre->next;
            continue;
        }
        
        LNode *node = malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = pre->next;
        pre->next = node;
        pre = pre->next;
    }
    return head;
}

CharLinkedList initCharLinkedList(const char arr[], int len){
    LCharNode *head,*pre;
    for (int i = 0; i < len; i++)
    {
        if (i==0)
        {
            head = malloc(sizeof(LCharNode));
            head->data = arr[i];
            head->next = NULL;
            pre = head;
        }
        else
        {
            LCharNode *node = malloc(sizeof(LCharNode));
            node->data = arr[i];
            node->next = NULL;
            pre->next = node;
            pre = pre->next;
        }
    }
    return head;
}

/*****************************************************************************************************************/

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

/**
 * 给定一个带表头结点的单链表，设head为头指针，结点结构为（data，next) data 为整型元素，next为指针，
 * 试写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间（要求：不允许使用数组作为辅助空间）。
 * @param L
 */
void printAndFreeByAsc(LinkedList L);

/**
 * 将一个带头结点的单链表A分解为两个带头结点的单链表A和B,使得A表中含有原表中序号为奇数的元素，而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
 * @param A
 * @param B
 */
void splitLinkedList(LinkedList A, LinkedList B);

/**
 * 设C= {a1,b1,a2,b2,...,am,bn}为线性表，采用带头结点的hc单链表存放，
 * 设计一个就地算法，将其拆分为两个线性表，使得A= {a1,a2,...,am}，B={bn,...,b2,b1}
 * @param C
 * @param A
 * @param B
 */
void splitLinkedList2(LinkedList C, LinkedList A, LinkedList B);

/**
 * 在一个递增有序的线性表中，有数值相同的元素存在。
 * 若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素，
 * 例如(7, 10, 10, 21，30, 42, 42, 42, 51，70)将变为(7,10,21,30, 42, 51，70)。
 * @param L
 */
void distinctLinkedList(LinkedList L);

/**
 * 假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。
 * 请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。
 * @param l1
 * @param l2
 */
void mergeLinkedListDesc(LinkedList l1, LinkedList l2);

/**
 * 设A和B是两个单链表（带头结点），其中元素递增有序。设计一个算法从A和B中的公共元素产生单链表C，要求不破坏A,B的结点。
 * @param A
 * @param B
 * @param C
 */
void getCommonLinkedList(LinkedList A, LinkedList B, LinkedList C);

/**
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，求A与B的交集，并存放于A链表中。
 * @param A
 * @param B
 */
void findCommonNode(LinkedList A, LinkedList B);

/**
 * 两个整数序列A=a1,a2,a3,...,am和B=b1,b2,b3,...,bn已经存入两个单链表中，设计一个算法,判断序列B是否是序列A的连续子序列。
 * @param A
 * @param B
 */
void checkSubSequence(LinkedList A, LinkedList B);

/**
 * 设计一个算法用于判断带头结点的循环双链表是否对称。
 * @param L
 */
void checkSymmetry(DLinkedList L);

/**
 * 有两个循环单链表，链表头指针分别为h1和h2，编写一个函数将链表h2链接到链表h1之后，要求链接后的链表仍保持循环链表形式。
 * @param h1
 * @param h2
 */
void connectCycleLinkedList(LinkedList h1, LinkedList h2);

/**
 * 设有一个带头结点的循环单链表，其结点值均为正整数。
 * 设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点。
 * @param L
 */
void removeMinNodeInCycle(LinkedList L);

/**
 * 设头指针为L的带有表头结点的非循环双向链表，其每个结点中除有pred (前驱指针）、data .(数据）和next (后继指针）域外，还有一个访问频度域freq。
 * 在链表被启用前，其值均初始化为零。每当在链表中进行一次locate(L,x)运算时，令元素值为x的结点中freq域的值增1，
 * 并使此链表中结点保持按访问频度非增(递减）的顺序排列，同时最近访问的结点排在频度相同的结点前面，以便使频繁访问的结点总是靠近表头。
 * 试编写符合上述要求的locate(L,x)运算的算法，该 运算为函数过程，返回找到结点的地址，类型为指针型。
 * @param L
 * @param x
 * @return
 */
DNode * locate(DLinkedList L, int x);

/**
 * 已知一个带有表头结点的单链表,假设该链表只给出了头指针list.在不改变链表的前提下，请设计一个尽可能高效的算法，
 * 查找链表中倒数第k个位置上的结点(k为正整数)。若查找成功，算法输出该结点的data域的值，并返回1;否则，只返回0。
 * @param {LinkedList} list
 * @param {int} k
 * @return {*}
 */
int findFromBottom(LinkedList list, int k);

/**
 * 用单链表保存m个整数,结点的结构为[data] [link],且|data|小于等于n(n为正整数).
 * 现要求设计一个时间复杂度尽可能高效的算法,对于链表中data的绝对值相等的结点,仅保留第一次出现的结点而删除其余绝对值相等的结点.
 * @param {LinkedList} list
 * @param {int} n
 * @return {*}
 */
void distinctAbsoluteValue(LinkedList list, int n);

/**
 * 设计一个算法完成以下功能：判断一个链表是否有环，如果有，找出环的入口点并返回,否则返回NULL.
 * @param {LinkedList} list
 * @return {LNode *}
 */
LNode * checkCycle(LinkedList list);

/**
 *  设线性表L = (a1,a2,a3,...,an-2,an-1,an)采用带头结点的单链表保存,请设计一个空间复杂度为0(1)且时间上尽可能高效的算法，重新排列Z中的各结点,
 * 得到线性表L` = (a1,an,a2,an-1,a3,an-2,...)
 * @param {LinkedList} L
 * @return {*}
 */
void rearrange(LinkedList L);

#endif //DEMO1_MYLINKEDLIST_H
