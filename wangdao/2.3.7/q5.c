/**
 * 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为0(1)。 
 */

#include "../DataStruct.h"

bool reverse(IntLinkedList *list);

bool reverse(IntLinkedList *list)
{
    IntLinkedList head={0,NULL};
    IntLinkedList *p;
    while (list->next)
    {
        p = list->next;
        list->next = list->next->next;
        p->next = head.next;
        head.next = p;
    }
    list->next = head.next;
    return true;
}

int main()
{
    IntLinkedList list = initIntLinkedList(5,5);
    printIntLinkedArray(list.next);
    reverse(&list);
    printIntLinkedArray(list.next);
    return 1;
}
