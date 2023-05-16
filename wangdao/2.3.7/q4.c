/**
 * 试编写在带头结点的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
 */

#include "../DataStruct.h"

bool delMin(IntLinkedList *list);

bool delMin(IntLinkedList *list)
{   
    //最后一个结点移除
    if (list->next&&list->next->next==NULL)
    {   
        printf("remove:%d\n",list->next->data);
        free(list->next);
        list->next=NULL;
        return true;
    }
    //把最小的结点往后移
    if (list->next->data<list->next->next->data)
    {
        int temp = list->next->data;
        list->next->data = list->next->next->data;
        list->next->next->data = temp;
    }
    delMin(list->next);
    
    return true;
}

int main()
{
    IntLinkedList list = initIntLinkedList(10,10);
    printIntLinkedArray(list.next);
    delMin(&list);
    printIntLinkedArray(list.next);
    return 1;
}
