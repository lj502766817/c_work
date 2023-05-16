/**
 * 有一个带头结点的单链表L,设计一个算法使其元素递增有序。
 */

#include "../DataStruct.h"

IntLinkedList *popMax(IntLinkedList * list);

IntLinkedList *popMax(IntLinkedList * list)
{   
    IntLinkedList *p = list;
    int temp;
    while (p->next&&p->next->next)
    {
        if (p->next->data>p->next->next->data)
        {
            temp = p->next->next->data;
            p->next->next->data = p->next->data;
            p->next->data = temp;
        }
        p = p->next;
    }
    IntLinkedList * result = p->next;
    p->next = NULL;
    return result;
}

bool sort(IntLinkedList * list);

bool sort(IntLinkedList * list)
{
    IntLinkedList head = {0,NULL};
    IntLinkedList *p;
    while (list->next)
    {
        p = popMax(list);
        p->next = head.next;
        head.next = p;
    }
    list->next = head.next;
    return true;
}

int main()
{
    IntLinkedList list = initIntLinkedList(10,6);
    printIntLinkedArray(list.next);
    sort(&list);
    printIntLinkedArray(list.next);
    return 1;
}
