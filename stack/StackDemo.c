/*
 * @Author: lijia
 * @Date: 2021-06-20 22:25:17
 * @LastEditTime: 2021-06-23 15:07:52
 * @LastEditors: lijia
 * @Description: 栈算法题
 * @FilePath: \c_work\demo1\stack\StackDemo.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "MyStack.h"

int main(){
    printf("hello Stack\n");
    
    char arr[8] = {'I','O','I','O','I','O','I'};
    CharLinkedList charList = initCharLinkedList(arr,7);
    int p=0;
    
    // int result = checkStackOpt(arr,8);
    // printf("result:%d\n",result);
    // checkCharListSymmetry(charList,7);
    // pushSharingSeqStack(0,22);
    // pushSharingSeqStack(1,18);
    // popSharingSeqStack(1,&p);
    // enQueueWithTag(12);
    // deQueueWithTap(&p);
    return 0;
}

int checkStackOpt(char arr[],int len){
    int mark = 0;
    for (int i = 0; i < len; i++)
    {
        if ('I'==arr[i])
        {
            mark++;
        }
        else if ('O'==arr[i])
        {
            mark--;
        }
        else
        {
            return 0;
        }
        
        if (mark<0)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * 将链表的前一半元素存入栈中,然后栈中元素依次出栈和链表的后一半元素做比较.有元素不同则不对称,否则如果栈空则说明对称
 * 时间复杂度O(n),空间复杂度O(n)
*/
int checkCharListSymmetry(CharLinkedList L, int n){
    char arr[n/2];
    LCharNode *p = L;
    //链表前一半元素进栈
    for (int i = 0; i < n/2; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }
    //元素总数是奇数,p进一位
    if(n%2==1)
    {
        p = p->next;
    }
    for (int i = n/2-1; i >= 0; i--)
    {
        if (arr[i]!=p->data)
        {   
            printf("L is not symmetrical\n");
            return 0;
        }
        p = p->next;
        
    }
    printf("L is symmetrical\n");
    return 1;
}

int pushSharingSeqStack(int i, int value){
    if(sharingSeqStack.top[1]-sharingSeqStack.top[0]==1){
        printf("stack is full.\n");
        return 0;
    }
    
    if (i==0)
    {
       //操作s1栈
       sharingSeqStack.data[++sharingSeqStack.top[i]]=value;
    }else if (i==1)
    {
        //操作s2栈
        sharingSeqStack.data[--sharingSeqStack.top[i]]=value;
    }else{
        printf("stack opt number is wrong.\n");
        return 0;
    }
    
    return 1;
}

int popSharingSeqStack(int i, int * value){

    if (i<0||i>1)
    {
        printf("stack opt number is wrong.\n");
        return 0;
    }
    

    if(i==0&&sharingSeqStack.top[0]==-1){
        printf("stack is empty.\n");
        return 0;
    }else if (i==1&&sharingSeqStack.top[1]==50)
    {
        printf("stack is empty.\n");
        return 0;
    }
    
    switch (i){
        case 0: *value = sharingSeqStack.data[sharingSeqStack.top[0]--]; break;
        case 1: *value = sharingSeqStack.data[sharingSeqStack.top[1]++]; break;
    }
        
    return 1;
}

int enQueueWithTag(int value){
    if ((tagSeqQueue.front==tagSeqQueue.rear)&&tagSeqQueue.tag==1)
    {
        printf("queue is full.\n");
        return 0;
    }
    tagSeqQueue.data[tagSeqQueue.rear]=value;
    tagSeqQueue.rear = (tagSeqQueue.rear+1)%10;
    if (tagSeqQueue.rear==tagSeqQueue.front)
    {
        tagSeqQueue.tag=1;
    }
    return 1;
}

int deQueueWithTap(int * value){
    if ((tagSeqQueue.front==tagSeqQueue.rear)&&tagSeqQueue.tag==0)
    {
        printf("queue is empty\n");
        return 0;
    }
    *value = tagSeqQueue.data[tagSeqQueue.front];
    tagSeqQueue.front = (tagSeqQueue.front+1)%10;
    if (tagSeqQueue.front==tagSeqQueue.rear)
    {
        tagSeqQueue.tag==0;
    }
    return 1;
}

