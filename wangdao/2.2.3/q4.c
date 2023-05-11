/**
 * 从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行
 */

#include "../DataStruct.h"

bool removeInterval(IntArray list, int s, int t);

bool removeInterval(IntArray list, int s, int t)
{
    if (s>=t||list->length<1||list->data[0]>t||list->data[list->length-1]<s)
    {
        return false;
    }
    
    int idx1 = 0;
    int idx2 = 0;

    for (int i = 0; i < list->length; i++)
    {   
        //停在s点
        if (list->data[i]<=s)
        {
            idx1=i;
        }
        //停在t点之前
        if (list->data[i]<t)
        {
            idx2 = i;
        }
        else
        {
            break;
        }
    }
    printf("%d-%d\n",idx1,idx2);
    //把t以及t之后的移到s后面
    while (idx2<list->length-1)
    {
        list->data[++idx1]=list->data[++idx2];
    }
    list->length = idx1+1;
    return true;

}

int main()
{
    IntArray list = initIntOrderedSeqList(100,10);
    printIntSeqList(list);
    removeInterval(list,20,40);
    printIntSeqList(list);
    return 1;
}
