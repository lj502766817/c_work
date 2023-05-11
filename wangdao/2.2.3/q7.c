/**
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
 */

#include "../DataStruct.h"

IntArray merge(IntSeqList list1, IntSeqList list2);

IntArray merge(IntSeqList list1, IntSeqList list2)
{
    IntArray newList = malloc(sizeof(IntArray));
    newList->MaxSize = MAX_SIZE;
    newList->length = list1.length+list2.length;
    newList->data = malloc(sizeof(int)*newList->length);

    int i=0;
    int j=0;
    int k=0;
    //两个有序集合一一对比,小的那个放到新集合里
    while (i<list1.length&&j<list2.length)
    {
        if (list1.data[i]<list2.data[j])
        {
            newList->data[k++]=list1.data[i++];
        }
        else
        {
            newList->data[k++]=list2.data[j++];
        }
    }
    //多出来的那个直接缀在新集合后面
    if (i<list1.length)
    {
        for (int l = k; l < newList->length; l++,i++)    
        {
            newList->data[l]=list1.data[i];
        }
    }
    else
    {
        for (int l = k; l < newList->length; l++,j++)    
        {
            newList->data[l]=list2.data[j];
        }
    }

    return newList;
}

int main()
{
    IntArray list1 = initIntOrderedSeqList(8,6);
    IntArray list2 = initIntOrderedSeqList(11,5);
    IntArray list3 = merge(*list1,*list2);
    printIntSeqList(list1);
    printIntSeqList(list2);
    printIntSeqList(list3);
    return 1;
}
