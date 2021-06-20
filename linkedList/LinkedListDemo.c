/*
 * @description: 链表
 * @Date: 2021-06-02 19:39:55
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-06-20 21:15:51
 */
#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

int main(){
    printf("hello LinkedList\n");
    int a[] = {1,2,3,4,5,6};
    int b[] = {1,-3,-5,7,9,5,-1,18};
    int c[] = {11,12,8,14,15};
    LinkedList L= initLinkedList(a,6);
    LinkedList LWithHead = initLinkedListWithHead(a,6);
    LinkedList LWithHead1 = initLinkedListWithHead(b,8);
    LinkedList LWithHead2 = initLinkedListWithHead(c,5);
    LNode *l1 = malloc(sizeof(LNode));
    l1->next = NULL;
    l1->data = 0;
    LNode *l2 = malloc(sizeof(LNode));
    l2->next = NULL;
    l2->data = 0;

    DLinkedList cDl = initCycleDLinkedList(a,6);
    DLinkedList cDl1 = initDLinkedList(a,6);

    LinkedList h1 = initCycleLinkedList(a,6);
    LinkedList h2 = initCycleLinkedList(c,5);
    LinkedList cl = initCycleLinkedListWithHead(c,5);

    LinkedList hasCycle = initLinkedListContainCycle(a,6);
    // initLinkedListY(l1,l2);
    // deleteValueX(L,3);
    // printLinkedList(L);
    // removeValueX(LWithHead,3);
    // printLinkedListWithHead(LWithHead);
    // printListReverse(LWithHead);
    // deleteMin(LWithHead);
    // reverseLinkedListWithHead(LWithHead);
    // ascendLinkedListWithHead(LWithHead);
    // removeBetween(LWithHead,2,8);
    // findSameNode(l1,l2);
    // printAndFreeByAsc(LWithHead);
    // splitLinkedList(LWithHead1,l1);
    // splitLinkedList2(LWithHead,l1,l2);
    // distinctLinkedList(LWithHead1);
    // mergeLinkedListDesc(LWithHead1,LWithHead2);
    // getCommonLinkedList(LWithHead1,LWithHead2,l1);
    // findCommonNode(LWithHead1,LWithHead2);
    // checkSubSequence(LWithHead1,LWithHead2);
    // checkSymmetry(cDl);
    // connectCycleLinkedList(h1,h2);
    // removeMinNodeInCycle(cl);
    // locate(cDl1,4);
    // locate(cDl1,4);
    // findFromBottom(LWithHead,3);
    // distinctAbsoluteValue(LWithHead1, 20);
    // checkCycle(hasCycle);
    rearrange(LWithHead);
    return 1;
}

/*
 * 相当于从最后开始检查,每次返回的链表都是已经删除了X的链表,时间复杂度为O(n),采用了递归,每轮递归的额外空间为常量,空间复杂度为O(n)
 */
LinkedList deleteValueX(LinkedList L, int X){
    //终态返回
    if(L==NULL){
        return L;
    }
    //检查后一个结点
    LinkedList last = deleteValueX(L->next,X);
    if(L->data==X){
        //如果当前结点需要被删除就返回后面的结点
        free(L);
        return last;
    } else {
        //将后面的结点拼接在当前结点上,然后返回当前结点
        L->next = last;
        return L;
    }
}

/*
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
void removeValueX(LinkedList L, int x){
    if(L->next==NULL){
        return;
    }
    while (L->next!=NULL){
        if(L->next->data==x){
            LNode *p = L->next;
            L->next = p->next;
            free(p);
        } else{
            L=L->next;
        }
    }
}

/*
 * 法1:采用头插法,逆序一个链表.时间复杂度为O(n),空间复杂度为O(n)
 * 法2:先进后出,采用可以使用栈,考虑到栈的思想,可以使用递归进行操作.时间复杂度为O(n),空间复杂度为O(n)
 */
void printListReverse(LinkedList L){
    void printListReverse2(LinkedList L);
    printListReverse2(L);
    void printListReverse1(LinkedList L);
    printListReverse1(L);
}

void printListReverse1(LinkedList L){
    LinkedList head = malloc(sizeof(LNode));
    head->next=NULL;
    head->data=0;
    while (L->next!=NULL){
        //取出一个node
        LNode *temp = L->next;
        L->next = temp->next;
        //将这个node用头插法放到新链表下
        temp->next = head->next;
        head->next = temp;
    }
    printLinkedListWithHead(head);
}

void printListReverse2(LinkedList L){
    if(L==NULL){
        return;
    }
    printListReverse2(L->next);
    printf("%d\t",L->data);
}

/*
 * 遍历找出节点,然后删除.时间复杂度为O(n),空间复杂度为O(1)
 */
void deleteMin(LinkedList L){
    LinkedList head = L;
    LNode *preNode=L;
    int temp = L->next->data;
    //遍历找出最小节点的前一个节点
    while (L->next!=NULL){
        if(L->next->data<temp){
            preNode=L;
            temp = L->next->data;
        }
        L = L->next;
    }
    //删除最小节点
    LNode *p = preNode->next;
    preNode->next = preNode->next->next;
    free(p);
    printLinkedListWithHead(head);
}

/*
 * 采用头插法,重新遍历构建链表.时间复杂度为O(n),空间复杂度为O(1)
 */
void reverseLinkedListWithHead(LinkedList L){
    LNode *temp = malloc(sizeof(LNode));
    LNode *p;
    temp->next = L->next;
    L->next = NULL;
    while (temp->next!=NULL){
        p = temp->next;
        temp->next = temp->next->next;
        p->next = L->next;
        L->next=p;
    }

    printLinkedListWithHead(L);
}

/*
 * 采用直接插入排序,时间复杂度为O(n),空间复杂度为O(1)
 */
void ascendLinkedListWithHead(LinkedList L){
    LNode *newHead = malloc(sizeof(LNode));
    newHead->next = L->next->next;
    newHead->data = L->next->data;
    L->next->next=NULL;

    while (newHead->next!=NULL){
        //遍历取出一个元素
        LNode *node = newHead->next;
        newHead->next = newHead->next->next;
        node->next = NULL;
        //插入到新的L中
        LNode *temp = L;
        while (true){
            //最后一个节点直接放在后面
            if(temp->next==NULL){
                temp->next=node;
                break;
            }
            //小于当前节点的后一位,就插入到当前节点的后面
            if(node->data<temp->next->data){
                node->next = temp->next;
                temp->next = node;
                break;
            }
            temp = temp->next;
        }
    }

    printLinkedListWithHead(L);
}

/*
 * 直接遍历无序链表,时间复杂度为O(n)
 */
void removeBetween(LinkedList L, int begin, int end){
    LNode *head = L;
    //遍历检查下一个节点
    while (head->next!=NULL){
        if(head->next->data>begin&&head->next->data<end){
            //下个节点的值在范围里,删除
            LNode *p = head->next;
            head->next = head->next->next;
            free(p);
        } else{
            //指向下一个节点
            head = head->next;
        }
    }

    printLinkedListWithHead(L);
}

/*
 * 两个单链表有公共节点,则这两个链表的拓扑结构应该是Y型的,考虑到两个链表可能长短不一,则可以先算出两个链表的长度差,
 * 长的链表先遍历差值的那一段到两个链表剩下的长度相同,然后两个链表一起按相同速度遍历,找到相同的接点.
 * 时间复杂度为O(l1+l2),空间复杂度为O(1)
 */
void findSameNode(LinkedList l1, LinkedList l2){
    int len1=0,len2=0,diff=0;
    LNode *temp1 = l1,*temp2=l2;
    //计算两个链表的长度
    while (temp1->next!=NULL){
        ++len1;
        temp1 = temp1->next;
    }
    while (temp2->next!=NULL){
        ++len2;
        temp2 = temp2->next;
    }
    //从头开始,较长的链表先移动差值的单位
    temp1 = l1,temp2=l2;
    if(len1>len2){
        diff = len1-len2;
        for (int i = 0; i < diff; ++i) {
            temp1 = temp1->next;
        }
    } else{
        diff = len2-len1;
        for (int i = 0; i < diff; ++i) {
            temp2 = temp2->next;
        }
    }

    //两个链表剩下的长度相同,开始同步遍历
    while (temp1->next!=NULL&&temp2->next!=NULL){
        if(temp1->next==temp2->next){
            printf("find same node:%d",temp1->next->data);
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

}

/*
 * 每次遍历链表找到最小的结点,然后删除该节点,直到剩下一个头结点.时间复杂度为O(n^2),空间复杂度为O(1)
 * 如果不设置数组的限制,可以把链表复制到数组里,然后用O(nlog(n))的时间复杂度算法排序,然后输出
 */
void printAndFreeByAsc(LinkedList L){
    LNode *pre = L,*temp = L;
    while (L->next!=NULL){
        //找最小的节点
        while (temp->next!=NULL){
            if(pre->next->data>temp->next->data){
                pre=temp;
            }
            temp = temp->next;
        }
        //删除节点
        printf("delete node:%d\n",pre->next->data);
        pre->next = pre->next->next;
        //重置
        pre = L,temp = L;
    }
}

/*
 * 遍历A链表,将偶数序号的节点采用尾插法拼接到B上,时间复杂度为O(n),空间复杂度为O(1).
 */
void splitLinkedList(LinkedList A, LinkedList B){
    int index=0;
    LNode *temp1=A,*temp2=B;
    while (temp1->next!=NULL){
        ++index;
        if(index%2==0){
            //把A的偶数节点取出移到B上,此时就相当于A节点已经往前移动了一步
            temp2->next=temp1->next;
            temp1->next = temp1->next->next;
            temp2 = temp2->next;
            temp2->next=NULL;
        } else{
            //没有取出节点,A手动前进一步
            temp1 = temp1->next;
        }
    }

    printLinkedListWithHead(A);
    printLinkedListWithHead(B);
}

/*
 * 每次取出C中的第一个结点直到全部取完,将序号为奇数的结点采用尾插法插入A中,将序号为偶数的结点采用头插法插入B中.
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
void splitLinkedList2(LinkedList C, LinkedList A, LinkedList B){
    int index = 0;
    LNode *temp=A;
    while (C->next!=NULL){
        ++index;
        //取出一个节点
        LNode *node = C->next;
        C->next = C->next->next;
        node->next=NULL;

        if(index%2==0){
            //偶数结点插入B
            node->next = B->next;
            B->next = node;
        } else{
            //奇数结点插入A
            temp->next = node;
            temp = temp->next;
        }
    }

    printLinkedListWithHead(A);
    printLinkedListWithHead(B);

}

/*
 * 遍历链表,如果当前结点值等于下一个结点的值就移除下一个节点,不然就往下一个结点移动.
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
void distinctLinkedList(LinkedList L){
    LNode *p = L->next;
    while (p->next!=NULL){
        if(p->data==p->next->data){
            LNode *node = p->next;
            p->next = p->next->next;
            free(node);
        } else{
            p = p->next;
        }
    }

    printLinkedListWithHead(L);
}

/*
 * 从两个链表(长度分别为m,n)从头遍历取出结点,并对比大小,然后采用头插法插入新链表里.
 * 时间复杂度为O(m)(假设m>n),空间复杂度为O(1)
 */
void mergeLinkedListDesc(LinkedList l1, LinkedList l2){
    LNode *head = malloc(sizeof(LNode));
    head->data=0;
    head->next=NULL;
    LNode *node;
    while (l1->next!=NULL&&l2->next!=NULL){
        //同时依次遍历两个链表
        if(l1->next->data<l2->next->data){
            node = l1->next;
            l1->next = l1->next->next;
            node->next=NULL;
        } else{
            node = l2->next;
            l2->next = l2->next->next;
            node->next=NULL;
        }
        //将取出的结点插入新链表
        node->next = head->next;
        head->next = node;

    }
    //处理余下的那条链表剩下的结点
    while (l1->next!=NULL){
        node = l1->next;
        l1->next = l1->next->next;
        node->next=NULL;
        node->next = head->next;
        head->next = node;
    }
    while (l2->next!=NULL){
        node = l2->next;
        l2->next = l2->next->next;
        node->next=NULL;
        node->next = head->next;
        head->next = node;
    }

    printLinkedListWithHead(head);
}

/*
 * 从头开始依次遍历A和B,每次拿一个结点进行比较.
 * 当碰到元素相同的结点时,生成一个结点用尾插法插入C中,当元素不同时,值较小的那个取下个节点再次进行比较,直到一个链表完全遍历完.
 * 时间复杂度为O(n),空间复杂度为O(n)
 */
void getCommonLinkedList(LinkedList A, LinkedList B, LinkedList C){
    LNode *p = A->next,*q = B->next,*pre = C;
    while (p&&q){
        if(p->data==q->data){
            //生成结点
            LNode *node = malloc(sizeof(LNode));
            node->next=pre->next;
            node->data = p->data;
            //尾插法
            pre->next = node;
            pre=node;
            continue;
        }
        //值小的结点前进
        if(p->data<q->data){
            p = p->next;
        } else{
            q = q->next;
        }
    }

    printLinkedListWithHead(C);
}

/*
 * 从头开始遍历A和B,依次从A和B取一个结点进行比较.如果元素相同,则A继续取下一个节点与B进行比较,
 * 当元素不同时,如果A的元素小,则A删除那个结点,如果B元素小,则B继续取下一个节点.直到一个链表完全遍历完成.完成后如果A没有遍历完则舍去剩下的结点.
 * (并归的思想)时间复杂度为O(n),空间复杂度为O(1)
 */
void findCommonNode(LinkedList A, LinkedList B){
    LNode *head = A;
    while (head->next&&B->next){
        //相同则继续向后比较
        if(head->next->data==B->next->data){
            head = head->next;
            B = B->next;
            continue;
        }
        //如果A的结点小于B,则舍去A的结点,此时相当于A前进了一个结点
        if(head->next->data<B->next->data){
            LNode *p = head->next;
            head->next = head->next->next;
            free(p);
        } else{
            //B前进一个结点
            B = B->next;
        }
    }
    //如果A没有遍历完,则舍去剩下的结点
    if(head->next){
        head->next = NULL;
    }

    printLinkedListWithHead(A);
}

/*
 * 法1:KMP算法,时间复杂度为O(m+n),空间复杂度为O(n),详见kmp算法解析demo
 * 法2:从A和B的第一个结点开始遍历,依次选出一个结点,如果相同,则继续看后继结点,如果A,B的后继结点中有不相同的,那么A回到初始结点的后继结点,B回到初始结点继续比较.知道比较完成或者A终结.
 * 时间复杂度为O(m*n),空间复杂度为O(1)
 */
void checkSubSequence(LinkedList A, LinkedList B){
    LNode *p = A->next,*temp = A->next,*q = B->next;
    while (temp){
        if(temp->data!=q->data){
            //有结点值不同,B回到初始结点,A回到初始结点的下个结点
            temp = p->next;
            p = p->next;
            q = B->next;
            continue;
        }
        if(temp->data==q->data){
            //结点值相同,继续比较后继结点
            temp = temp->next;
            q = q->next;
        }
        if(q==NULL){
            //B比较完成,结束
            printf("B是A的子串!\n");
            break;
        }
    }
}

/*
 * p从头部开始遍历,q从尾部开始遍历,直到p,q相同(奇数结点)或者p,q相邻(偶数结点)时结束,如果其中有p的值不等于q则不对称.
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
void checkSymmetry(DLinkedList L){
    DNode *p = L->next,*q = L->prior;
    while (true){
        if(p->data!=q->data){
            printf("循环双链表L不对称");
            break;
        }
        if(p==q||p->next==q){
            printf("循环双链表L对称");
            break;
        }
        p = p->next;
        q = q->prior;
    }
}

/*
 * 将h1的指向作为头指针,h2的指向左右尾指针 时间复杂度为O(1),空间复杂度为O(1)
 */
void connectCycleLinkedList(LinkedList h1, LinkedList h2){
    LNode *node = h2->next;
    //将h2的下一个接点指向h1的下一个结点,此时原本h2的链断开
    h2->next = h1->next;
    //将h1的下一个结点指向h2原本的下一个结点,从新构成一个h1和h2的新循环
    h1->next = node;

    printLinkedList(h1);
}

/*
 * 当循环单链表不为空时,每次循环一轮,找出最小节点然后删掉.
 * 时间复杂度为O(n^2),空间复杂度为O(1)
 */
void removeMinNodeInCycle(LinkedList L){
    while (L->next!=L){
        LNode *temp = L->next;
        LNode *minPre = L;
        //找到最小结点的前置结点
        while (temp->next!=L){
            if(temp->data>temp->next->data){
                minPre = temp;
            }
            temp =temp->next;
        }
        //删除最小的结点
        LNode *min = minPre->next;
        printf("delete node:%d\n",min->data);
        minPre->next = min->next;
        free(min);
    }
    printf("All node has been deleted,remove head node\n");
    free(L);
}

/*
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
DNode * locate(DLinkedList L, int x){
    DNode *node = L->next;
    //循环找到值和x相同的结点
    while (node->next!=NULL){
        if(node->data!=x){
            node = node->next;
            continue;
        }    
        //将结点按freq的值进行从新排序,往前移动
        printf("find node address:0x%x\n",node);
        //TODO: 可以先把这个结点摘出来,然后找到需要插入的位置再重新插入
        while (node->prior!=L&&node->freq>=node->prior->freq)
        {
            DNode *pre = node->prior;
            node->prior = pre->prior;
            pre->prior->next = node;
            pre->next = node->next;
            node->next->prior = pre;
            node->next = pre;
            pre->next = node;
            printf("move node\n");
        }
        return node;
    }
    //找不到就返回null
    printf("not found\n");
    return NULL;
}

/*
 * 设置两个指针p,q.p指针先移动,当p移动到第k个位置的时候,q开始移动.
 * 然后两个指针同步移动,当p移动到最后一个结点的时候,q就在倒数第k个结点上
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
int findFromBottom(LinkedList list, int k){
    LNode *p=list,*q=list;
    int index = 0;
    //获得倒数第k个结点
    while (p->next)
    {
        ++index;
        if (index>=k)
        {
            q = q->next;
        }
        p= p->next;
    }
    //判断结点是否存在
    if (q!=list)
    {
        printf("find %dth from bottom is:%d",k,q->data);
        return 1;
    }
    printf("not found\n");
    return 0;
}

/*
 * 由于要求时间复杂度尽可能高效,则可以采用用空间换时间的方式.
 * 首先建立一个长度为n+1的数组,已数组下标作为链表值的绝对值,并设置数组的初始值为0.
 * 然后依次遍历链表,如果链表的值的绝对值对应的数组上的值为0则,数组值加1,否则将链表该节点删掉.
 * 时间复杂度为O(m),空间复杂度为O(n)
 */
void distinctAbsoluteValue(LinkedList list, int n){
    LNode *p = list;
    // 初始化数组
    int *a = malloc(n*sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        a[i]=0;
    }
    while (p->next!=NULL)
    {   
        //获得绝对值
        int value = p->next->data<0?-(p->next->data):p->next->data;
        //检查是否出现过
        if(a[value]==0)
        {
            a[value]=1;
            p = p->next;
        }
        else
        {
            //删除节点
            LNode *node = p->next;
            p->next = p->next->next;
            free(node);
        }
        
    }
    printLinkedListWithHead(list);
}

/**
 * 1.判断是否有环:设置两个指针,一个fast一个slow,slow每次走一步,slow=slow->next,fast每次走两步,fast=fast->next->next.
 * 假如有环的话fast一定比slow先进环,并且在环里循环,当slow进环后,fast已经转过n圈并且在一点碰到slow.
 * 假如没有环,那么fast会走到NULL,并且不会碰到slow.
 * 即只要fast和slow能相遇就能证明链表有环.
 * 2.找到环的入口:可知fast的速度是slow速度的两倍,即fast走过的路程是slow的两倍,即fast_D = 2*slow_D.
 * 设从链表头到环入口的长度是len,相遇点距离环入口的距离是x,环的长度是r,则slow_D = len + x,fast_D = len + nr + x.
 * 可以算得len = nr-x.则可以设置两个指针,cursor在头结点,meet在fast指针和slow指针相遇的点.
 * 然后cursor和meet同时移动,相遇的点就是环的入口
*/
LNode * checkCycle(LinkedList list){
    LNode *fast = list,*slow = list;
    //如果fast能走到底则没有环
    while (fast)
    {
        //fast每次前进2步,slow每次前进1步
        fast = fast->next->next;
        slow = slow->next;
        //fast和slow在环内相遇
        if (fast==slow)
        {
            printf("list has existed a cysle!\n");
            LNode *cursor = list;
            LNode *meet = fast;
            while (true)
            {
                if(cursor==meet)
                {
                    printf("find the entry node:0x%x ,data:%d\n",meet,meet->data);
                    return meet;
                }
                cursor = cursor->next;
                meet = meet->next;
            }
        }
    }
    printf("there is no cycle!\n");
    return NULL;
}

/**
 * 首先在头结点设置两个指针 fast和slow,fast一次前进两个结点,slow一次前进1一个结点.这样当fast走到最后的时候,slow就正好处于中点.这样通过slow将原来的链表分成两段L1,L2.
 * 然后通过空间复杂度为O(1)的算法将L2逆置.最后依次从L1和L2取结点构建新链表L`.
 * 时间复杂度为O(n),空间复杂度为O(1)
*/
void rearrange(LinkedList L){
    LNode *fast = L,*slow = L;
    //通过步长不等的两个指针找到链表的中点
    while (fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    //拆分成两个链表.
    LNode *L1 = malloc(sizeof(LNode));
    LNode *L2 = malloc(sizeof(LNode));
    L1->next = L->next;
    L2->next = slow->next;
    slow->next = NULL;
    //将L2进行原地逆置
    reverseLinkedListWithHead(L2);
    //从L1,L2依次取出结点构成新的L`
    LNode *pre = L;
    while (L1->next)
    {   
        //从L1取出node1
        LNode *node1 = L1->next;
        L1->next = L1->next->next;
        node1->next = NULL;
        //从L2取出node2
        LNode *node2 = L2->next;
        L2->next = L2->next->next;
        node2->next = NULL;
        //构建L`
        node1->next = node2;
        pre->next = node1;
        pre = pre->next->next;
    }
    
    printLinkedListWithHead(L);
}


