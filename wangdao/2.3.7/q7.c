/**
 * 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值( 作为函数参数给出)之间的元素的元素(若存在)。
 */

#include "../DataStruct.h"

bool removeBetween(IntLinkedList *list, int a, int b);

bool removeBetween(IntLinkedList *list, int a, int b)
{

    if (!list->next)
    {
        return true;
    }

    if (list->next->data>a&&list->next->data<b)
    {
        IntLinkedList *p = list->next;
        list->next = list->next->next;
        printf("remove:%d\n",p->data);
        free(p);
        removeBetween(list,a,b);
    }
    else
    {
        removeBetween(list->next,a,b);
    }
    return true;
}

int main()
{
    IntLinkedList list = initIntLinkedList(10,10);
    printIntLinkedArray(list.next);
    removeBetween(&list,4,8);
    printIntLinkedArray(list.next);
    return 1;
}
