/**
 * 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn).编写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面。
 */

#include "../DataStruct.h"

bool reverse(IntArray list, int begin, int end);

bool reverse(IntArray list, int begin, int end)
{
    int temp;
    while (begin<end)
    {
        temp = list->data[begin];
        list->data[begin] = list->data[end];
        list->data[end] = temp;
        begin++;
        end--;
    }
    return true;
}

bool exchangePosition(IntArray list, int m, int n);

bool exchangePosition(IntArray list, int m, int n)
{
    //先将集合全部逆置
    reverse(list,0,m+n-1);
    //然后将m和n分别逆置
    reverse(list,0,n-1);
    reverse(list,n,m+n-1);
    return true;
}

int main()
{
    IntArray list = initIntSeqList(10,10);
    printIntSeqList(list);
    exchangePosition(list,4,6);
    printIntSeqList(list);
    return 1;
}
