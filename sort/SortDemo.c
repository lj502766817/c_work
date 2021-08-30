/*
 * @description: 
 * @Date: 2021-08-19 17:07:55
 * @LastEditors: lijia
 * @LastEditTime: 2021-08-30 14:24:37
 * @FilePath: \c_work\demo1\sort\SortDemo.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode{
    int data; //数据域
    struct LNode *next;//指针域
}LNode,*LinkedList;

typedef enum Color {RED=1,WHITE,BLUE} color;

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
void split(int *, int);

/**
 * 荷兰国旗问题:设有一个仅由红、白、蓝三种颜色的条块组成的条块序列，请编写一个时间复杂度为O(n)的算法，
 * 使得这些条块按红、白、蓝的顺序排好，即排成荷兰国旗图案。
*/
void theDutchFlag(int *, int);

/**
 * 编写一个算法,在基于单链表表示的待排序关键字序列上进行简单选择排序.
*/
void selectSort(LinkedList);

/**
 * 试设计一个算法,判断一个数据序列是否构成一个小根堆
*/
bool checkMinDump(int *, int);

/**
 * 设顺序表用数组A[]表示，表中元素存储在数组下标在1~m+n的范围内，前m个元素递增有序，后n个元素递增有序，设计一个算法，使得整个顺序表有序。
*/
void sortList(int *, int, int);

/**
 * 有一种简单的排序算法，称为计数排序（count sorting )。这种排序算法对一个待排序的表(用数组表示）进行排序，
 * 并将排序结果存放到另一个新的表中。必须注意的是，表中所有待排序的关键码互不相同，计数排序算法针对表中的每个记录，
 * 扫描待排序的表一趟，统计表中有多少个记录的关键码比该记录的关键码小，假设针对某个记录统计出的计数值为c，
 * 则这个记录在新有序表中的合适存放位置即为c。
*/
void countSort(int *,int *,int);

/**
 * 设有一个数组中存放了一个无序的关键序列K1,K2,...,Kn。现要求将Kn放在将元素排序后的正确位置上，试编写实现该功能的算法，要求比较关键字的次数不超过n。
*/
void findLocation(int *, int);

//以Kn为轴做一轮快速排序,最后能确定Kn的位置
void findLocation(int *arr, int len)
{
    int pivot = arr[len-1];
    int i = 0,j=len-1;
    while (i<j)
    {
        while (i<j&&arr[i]<pivot)
        {
            i++;
        }
        arr[j]=arr[i];
        while (i<j&&arr[j]>pivot)
        {
            j--;
        }
        arr[i]=arr[j];
    }
    arr[i]=pivot;
}

//时间复杂度O(n^2),空间复杂度O(n)
void countSort(int *a,int *b,int len)
{
    for (int i = 0; i < len; i++)
    {   
        int cnt=0;
        for (int j = 0; j < len; j++)
        {
            if (a[i]>a[j])
            {
                cnt++;
            }
        }
        b[cnt]=a[i];
    }
    
}

//可以使用并归排序,时间复杂度O(m+n),空间复杂度O(m+n).或者前m项已经排序好的插入排序,时间复杂度为O(mn),空间复杂度为O(1)
void sortList(int *arr, int m, int n)
{
    //采用插入排序
    for (int i = m+1; i <= m+n; i++)
    {
        arr[0] = arr[i];
        for (int j = i-1; arr[j]>arr[0]; j--)   //从后往前插入
        {
            arr[j+1] = arr[j]; //j后移
            arr[j] = arr[0];
        }
    }
}

bool checkMinDump(int *arr, int len)
{
    for (int i = (len)/2; i > 0; i--)
    {
        if (arr[i-1]>arr[2*i-1])
        {   
            printf("not minDump.\n");
            return false;
        }
        if (2*i!=len&&arr[i-1]>arr[2*i])   //如果有右结点,就检查右结点 
        {
            printf("not minDump.\n");
            return false;
        }
    }
    printf("is minDump.\n");
    return true;
}

void selectSort(LinkedList list)
{
    LinkedList p = list,temp,target;
    while (p)
    {   
        temp=p,target=p;
        int tempData = p->data;
        while (temp)    //找到值最小的结点
        {
            if (temp->data<tempData)
            {
                tempData = temp->data;
                target = temp;
            }
            temp = temp->next;
        }
        //交换数据
        target->data = p->data;
        p->data = tempData;
        //下一轮选择排序
        p = p->next;
    }
    
}

//遍历线性表,然后设置三个指针,j表示当前扫描的元素,保证i前面的都是红色的,k后面的都是蓝色的
void theDutchFlag(int *arr, int len)
{
    int i=0,j=0,k=len-1,temp;
    while (j<k)
    {
        switch(arr[j]){
            case RED:   //如果是红色,此时红色指针i停在白色上,交换i和j的值,然后i和j继续前进
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;j++;
                break;
            case WHITE: //如果是白色工作指针继续前移找其他颜色,红色指针i停在白色上
                j++;
                break;
            case BLUE:  //如果是蓝色,交换k和j的值,把蓝色到后面,由于此时指针k有可能停在蓝色上,则j不动,k往后走
                temp= arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
                k--;
                break;
        }
    }
    
}

//采用二分的思想,类似快速排序,先用pivot将集合分成两份,pivot左边的都是小于pivot的项,pivot右边的都是大于pivot的项,
//然后看pivot的位置是否在n/2处,如果不在就在多的那一边继续拆分,只需要进行拆分,不用考虑排序
//时间复杂度为O(n),空间复杂度为O(1)
void split(int *arr, int len)
{
    int location=0,begin=0,end=len-1;
    while (location!=len/2)
    {
        int pivot = arr[begin],i=begin,j=end;
        while (i<j)
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
            arr[j]=arr[i];
        }
        arr[i]=pivot;
        location = i;
        if (location>len/2)
        {
            end = location-1;
        }else if (location<len/2)
        {
            begin = location+1;
        }
    }
    
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
    int arr[10] = {0,1,3,5,7,9,2,4,6,8};
    int arr1[5] = {1,3,5,7,2};
    int arr2[15] = {1,3,1,2,2,3,2,1,2,3,2,1,2,3,3};
    int arr3[7] = {23,5,68,52,60,72,71};
    int arr4[10] = {0};
    LinkedList p1 = malloc(sizeof(LNode));p1->data = 3;p1->next = NULL;
    LinkedList p2 = malloc(sizeof(LNode));p2->data = 8;p2->next = p1;
    LinkedList p3 = malloc(sizeof(LNode));p3->data = 6;p3->next = p2;
    LinkedList p4 = malloc(sizeof(LNode));p4->data = 11;p4->next = p3;
    // twoWayBubble(arr,10);
    // splitOddEven(arr1,5);
    // int result = findMinK(arr,0,9,4);
    // printf("result:%d.\n",result);
    // split(arr,10);
    // theDutchFlag(arr2,15);
    // selectSort(p4);
    // checkMinDump(arr3,7);
    // sortList(arr,5,4);
    // countSort(arr,arr4,10);
    // findLocation(arr1,5);
    printArr(arr1,5);
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
