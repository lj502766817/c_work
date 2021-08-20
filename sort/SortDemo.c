/*
 * @description: 
 * @Date: 2021-08-19 17:07:55
 * @LastEditors: lijia
 * @LastEditTime: 2021-08-20 10:48:09
 * @FilePath: \c_work\demo1\sort\SortDemo.c
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * 编写双向冒泡排序算法，在正反两个方向交替进行扫描,
 * 即第一趟把关键字最大的元素放在序列的最后面,第二趟把关键字最小的元素放在序列的最前面,如此反复进行。
*/
int twoWayBubble(int *, int);

/**
 * 已知线性表按顺序存储,且每个元素都是不相同的整数型元素,设计把所有奇数移动到所有偶数前边的算法(要求时间最少,辅助空间最少).
*/
int splitOddEven(int *, int);

int splitOddEven(int *arr, int len)
{
    
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
    int arr[10] = {3,5,3,84,19,9,10,11,45,1};
    // twoWayBubble(arr,10);
    printf("sort.\n");
}
