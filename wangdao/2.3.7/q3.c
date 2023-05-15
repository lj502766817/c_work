/**
 * 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
 */

#include "../DataStruct.h"

void printFromTail(IntLinkedList *list);

void printFromTail(IntLinkedList *list)
{
    if (!list)
    {
        return;
    }
    
    if ((*list).next)
    {
        printFromTail((*list).next);
    }
    printf("%d\t",(*list).data);
}

int main()
{
    IntLinkedList list = initIntLinkedList(10,5);
    printIntLinkedArray(list.next);
    printFromTail(list.next);

}
