/**
 * 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
 */
# include "../DataStruct.h"

bool delMin(IntArray list, int *x);

bool delMin(IntArray list, int *x)
{
    if (list->length<1)
    {
        return false;
    }
    int minIdx = 0;
    for (int i = 1; i < list->length; i++)
    {
        if (list->data[i]<list->data[minIdx])
        {
            minIdx = i;
        }
    }
    *x = list->data[minIdx];
    list->data[minIdx] = list->data[--list->length];
    return true;
}

int main()
{
    IntArray seq = initIntSeqList(10,5);
    printIntSeqList(seq);
    int x;
    delMin(seq,&x);
    printf("min:%d\n",x);
    printIntSeqList(seq);
    return 1; 
}
