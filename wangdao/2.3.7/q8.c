/**
 * 给定一个带表头结点的单链表，设head为头指针，结点结构为(data,next)，data为整型元素，next为指针，试写出算法:按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间(要求:不允许使用数组作为辅助空间)。
 */

#include "../DataStruct.h"

IntLinkedList *quickSort(IntLinkedList *head, IntLinkedList *tail);

IntLinkedList *getTail(IntLinkedList *head);

IntLinkedList *partition(IntLinkedList *head, IntLinkedList *tail, IntLinkedList **newHead, IntLinkedList **newTail);

bool printAndFree(IntLinkedArray head);

// 快速排序，从小到大
IntLinkedList *quickSort(IntLinkedList *head, IntLinkedList *tail)
{
    if (head == NULL || head == tail)
    {
        return head;
    }

    IntLinkedList *newHead = NULL;
    IntLinkedList *newTail = NULL;

    // 分割链表，获取基准值节点
    IntLinkedList *pivot = partition(head, tail, &newHead, &newTail);

    // 如果轴不是新链表的头结点的话，递归排序轴左边
    if (pivot != newHead)
    {
        IntLinkedList *temp = newHead;
        while (temp->next != pivot)
        { // 找到左边的尾结点
            temp = temp->next;
        }
        temp->next = NULL;
        newHead = quickSort(newHead, temp);
        // 左边排序好后，重新接到轴上
        temp = getTail(newHead);
        temp->next = pivot;
    }

    // 右边继续递归
    pivot->next = quickSort(pivot->next, newTail);

    return newHead;
}

IntLinkedList *getTail(IntLinkedList *head)
{
    if (head == NULL)
        return NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

// 分割链表，返回轴结点
IntLinkedList *partition(IntLinkedList *head, IntLinkedList *tail, IntLinkedList **newHead, IntLinkedList **newTail)
{
    // 把尾结点作为轴
    IntLinkedList *pivot = tail;
    // 当前要操作结点的前置结点
    IntLinkedList *prev = NULL;
    // 当前要操作的结点
    IntLinkedList *current = head;
    // 指向轴右边的尾结点
    IntLinkedList *end = pivot;

    // 遍历链表，发现大于轴的结点就取出来放到轴的右边
    while (current != pivot)
    {
        if (current->data <= pivot->data)
        {
            if (*newHead == NULL)
            { // 分割之后新的头结点
                *newHead = current;
            }
            prev = current;
            // current指向下一个需要操作的结点
            current = current->next;
        }
        else
        {
            if (prev)
            { // 非处理头结点时，取出这个结点
                prev->next = current->next;
            }
            IntLinkedList *tmp = current->next;
            // 把大于轴的结点放到轴的右边（尾插法）
            current->next = NULL;
            end->next = current;
            end = current;
            // current指向下一个需要操作的结点
            current = tmp;
        }
    }
    // 遍历结束后，轴的左边都是小于轴的结点，轴的右边都是大于等于轴的结点

    // 更新新链表的尾节点
    if (*newHead == NULL)
    { // 正好轴是小的那个值的情况
        *newHead = pivot;
    }
    *newTail = end;

    return pivot;
}

bool printAndFree(IntLinkedArray head)
{
    IntLinkedArray current = head;
    while (current)
    {
        IntLinkedArray temp = current;
        current = temp->next;
        printf("%d\t", temp->data);
        free(temp);
    }
    return true;
}


int main()
{   
    //构造带头结点head的链表
    IntLinkedList list = initIntLinkedList(10, 5);
    //打印链表
    printIntLinkedArray(list.next);
    //快速排序
    list.next = quickSort(list.next, getTail(list.next));
    //打印并释放
    printAndFree(list.next);
    return 1;
}
