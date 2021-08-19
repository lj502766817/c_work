/*
 * @description: 
 * @Date: 2021-08-12 10:41:10
 * @LastEditors: lijia
 * @LastEditTime: 2021-08-12 14:04:06
 * @FilePath: \c_work\demo1\search\searchDemo.c
 */

#include <stdio.h>

typedef struct Node
{
    char data;
    struct Node *next;
}Node,*LinkedList;


/**
 * 递归的二分查找
*/
int binarySearch(int, int *, int);

/**
 * 链表优先查找
*/
int linkedPriorSearch(char, LinkedList);

/**
 * 顺序表优先查找
*/
int seqPriorSearch(char, char *, int);

int seqPriorSearch(char x, char *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (x==arr[i])
        {
            if (i>0)
            {
                arr[i]=arr[i-1];
                arr[i-1] = x;
            }
            return i+1;
        }
    }
    
    return -1;
}

int linkedPriorSearch(char x, LinkedList list)
{
    int index = 1;
    LinkedList p = list,pre = NULL;
    while (p)
    {
        if (p->data==x)
        {   
            if (pre)    //通过交换值来使查询到的结点前进
            {
                p->data = pre->data;
                pre->data = x;
            }
            return index;
        }
        
    }
    return -1;
}

//时间/空间复杂度O(log2(n)),两个都是递归深度
int binarySearch(int x, int *arr, int len)
{
    int binarySearchRecursive(int, int *, int, int);
    return binarySearchRecursive(x,arr,0,len-1);
}

int binarySearchRecursive(int x, int *arr, int low, int high)
{   
    if (low==high&&arr[low]!=x)
    {
        return -1;
    }
    
    int mid = (low+high)/2;
    if (x==arr[mid])
    {
        return mid+1;
    } else if (x<arr[mid])
    {
        return binarySearchRecursive(x,arr,low,mid-1);
    } else if (x>arr[mid])
    {
        return binarySearchRecursive(x,arr,mid+1,high);
    } 
}


int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // int index = binarySearch(12,a,10);
    printf("index: %d.\n",index);
    return 0;
}
