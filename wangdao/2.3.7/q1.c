/**
 * 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。 
 */

#include "../DataStruct.h"

IntLinkedArray delX(IntLinkedArray list, int x);

IntLinkedArray delX(IntLinkedArray list, int x)
{
    if (!list)
    {
        return NULL;
    }
    
    if (list->data==x)
    {   
        IntLinkedArray result = delX(list->next,x);
        free(list);
        printf("remove:%d\n",x);
        return result;
    }
    else
    {
        list->next = delX(list->next,x);
        return list;
    }
    
}

int main()
{
    IntLinkedArray list = initIntLinkedArray(10,10);
    printIntLinkedArray(list);
    list = delX(list,5);
    printIntLinkedArray(list);
    return 1;
}
