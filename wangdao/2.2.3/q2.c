/**
 * 设计一个高效算法，将顺序表Z的所有元素逆置，要求算法的空间复杂度为0(1)
 */
# include "../DataStruct.h"

void reverseSeq(IntArray list);

void reverseSeq(IntArray list)
{
    int idx1 = 0;
    int idx2 = list->length-1;
    int temp;
    while (idx1<idx2)
    {
        temp = list->data[idx1];
        list->data[idx1] = list->data[idx2];
        list->data[idx2] = temp;
        idx1++;
        idx2--;
    }
}

int main()
{
    IntArray list = initIntSeqList(10,5);
    printIntSeqList(list);
    reverseSeq(list);
    printIntSeqList(list);
    return 1;
}
