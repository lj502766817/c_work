/*
 * @description: 
 * @Date: 2021-08-19 17:07:55
 * @LastEditors: lijia
 * @LastEditTime: 2021-08-23 14:59:35
 * @FilePath: \c_work\demo1\sort\SortDemo.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * 编写双向冒泡排序算法，在正反两个方向交替进行扫描,
 * 即第一趟把关键字最大的元素放在序列的最后面,第二趟把关键字最小的元素放在序列的最前面,如此反复进行。
*/
int twoWayBubble(int *, int);

/**
 * 已知线性表按顺序存储,且每个元素都是不相同的整数型元素,设计把所有奇数移动到所有偶数前边的算法(要求时间最少,辅助空间最少).
*/
int splitOddEven(int *, int);

/**
 * 试编写一个算法，使之能够在数组L[1...n]中找出第k小的元素（即从小到大排序后处于第k个位置的元素）。
*/
int findMinK(int *, int , int, int);

/**
 * 已知由n(n>=2)个正整数构成的集合A{ak|0<=k<n}，将其划分为两个不相交的子集A1和A2，元素个数分别是n1和n2
 * ,A1和A2中的元素之和分别为S1和S2.设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大
*/
void split(int *,int);

//采用二分的思想,类似快速排序,先用pivot将集合分成两份,然后看pivot的位置是否在n/2处,如果不在就在多的那一边继续拆分.
//时间复杂度为O(n),空间复杂度为O(1)
void split(int *arr,int len)
{
    
}

//可以使用从前/后的冒泡,或者先排序再找第k个,不过时间复杂度都是O(nlogn)以上,或者采用小顶堆,时间复杂度为O(n+klogn)
//下面是一个基于快速排序的划分思想,平均时间复杂度为O(n),空间复杂度为划分的规模
int findMinK(int *arr, int begin, int end, int k)
{   
    if (begin==end)
    {
        return arr[end];
    }

    int i=begin,j=end,pivot = arr[begin];
    while (i<j) //将数组切割成两部分
    {
        while (i<j&&arr[j]>=pivot)
        {
            j--;
        }
        arr[i] = arr[j];

        while (i<j&&arr[i]<=pivot)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    if (k==i)
    {
        return i;
    } else if (k<i)
    {   //在左边进行递归
        return findMinK(arr,begin,i-1,k);
    }else if (k>i)
    {   //在右边进行递归
        return findMinK(arr,i+1,end,k);
    }
    
    
    
}

int splitOddEven(int *arr, int len)
{
    int temp,i=0,j=len-1;
    while (i<j)
    {
        while (i<j) //从后往前找到一个奇数
        {
            if (arr[j]%2==1)
            {
                temp = arr[j];
                break;
            }
            j--;  
        }
        while (i<j) //从前往后找到一个偶数
        {
            if (arr[i]%2==0)
            {   
                //交换奇偶
                arr[j]=arr[i];
                arr[i] = temp;
                break;
            }
            i++;
        }
    }
    
    
    return 1;
}

int twoWayBubble(int *arr, int len){
    bool flag = false;  //是否做过换位
    int pre=0,last=len-1;
    for (int i = 0; i <len; i++)
    {
        if (i%2==0)
        {
            //正向冒泡
            for (int j = pre; j < last; j++)
            {
                if (arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    flag = true;
                }
            }
            last--;
        } else
        {
            //反向冒泡
            for (int j = last; j > pre ; j--)
            {
                if (arr[j]<arr[j-1])
                {
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    flag = true;
                } 
            }
            pre--;
        }

        if (!flag)
        {
            break;
        }
    }
    return 1;
}

int main(){
    void printArr(int *, int);
    int arr[10] = {12,5,3,84,45,9,10,11,19,1};
    int arr1[5] = {1,3,5,7,2};
    // twoWayBubble(arr,10);
    // splitOddEven(arr1,5);
    int result = findMinK(arr,0,9,4);
    printf("result:%d.\n",result);
    printArr(arr,10);
    printf("sort.\n");
}

void printArr(int *arr, int len)
{   printf("arr:");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
