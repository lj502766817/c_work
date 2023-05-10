/**
 * 对长度为n的顺序表L,编写一个时间复杂度为O(n).空间复杂度为0(1)的算法，该算法删除线性表中所有值为x的数据元素。
 */

# include "../DataStruct.h"

bool delX(IntArray list, int x);

bool delX(IntArray list, int x)
{
    int k = 0;
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i]!=x)
        {
            list->data[k]=list->data[i];
            k++;
        }
    }
    list->length = k;
    return true;
}

int main()
{
    IntArray list = initIntSeqList(3,7);
    printIntSeqList(list);
    delX(list,2);
    printIntSeqList(list);
    return 1;
}
