/**
 * 从顺序表中删除其值在给定值s与t之间(包含s和t，要求s<t)的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。 
 */
#include "../DataStruct.h"

bool removeInterval(IntArray list, int s, int t);

bool removeInterval(IntArray list, int s, int t)
{
    if (s>=t||list->length<1)
    {
        return false;
    }
    //双指针,快指针找不在s与t之间的值,慢指针写入正确的值
    int idx = 0;
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i]<s||list->data[i]>t)
        {
            list->data[idx] = list->data[i];
            idx++;
        }
    }
    list->length = idx;
    return true;
}

int main()
{
    IntArray list = initIntSeqList(88,10);
    printIntSeqList(list);
    removeInterval(list,20,40);
    printIntSeqList(list);
    return 1;
}
