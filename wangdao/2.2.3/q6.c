/**
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
 */

#include "../DataStruct.h"

bool removeDuplication(IntArray list);

bool removeDuplication(IntArray list)
{   
    //双指针处理
    int idx=0;
    for (int i = 1; i < list->length; i++)
    {
        if (list->data[idx]!=list->data[i])
        {
            list->data[++idx] = list->data[i];
        }
    }
    list->length = idx+1;
    return true;
}

int main()
{
    IntArray list = initIntOrderedSeqList(10,15);
    printIntSeqList(list);
    removeDuplication(list);
    printIntSeqList(list);
    printf("%d",(*list).length);
    return 1;
}
