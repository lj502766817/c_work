/**
 * 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。
 */

#include "../DataStruct.h"

bool delX(IntLinkedList *list, int x);

bool delX(IntLinkedList *list, int x)
{
    IntLinkedList *p = list;
    while (p->next)
    {
        if (p->next->data==x)
        {
            IntLinkedList *r = p->next;
            p->next=p->next->next;
            free(r);
            printf("remove:%d\n",x);
        }
        else
        {
            p = p->next;
        }
        
    }
    return true;
}

int main()
{
    IntLinkedList list = initIntLinkedList(8,10);
    printIntLinkedArray(list.next);
    delX(&list,5);
    printIntLinkedArray(list.next);
    return 1;
}
