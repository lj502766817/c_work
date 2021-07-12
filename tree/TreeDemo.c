/*
 * @description: 
 * @Date: 2021-07-05 14:45:09
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-12 16:20:33
 * @FilePath: \c_work\demo1\tree\TreeDemo.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "MyTree.h"

//数组初始值长度
const int DEFAULT_LENGTH = 10;

/**
 * 首先在一个二叉树中,任意两个非根结点的结点是一定有公共祖先节点的.又可知一个结点i的父节点是i/2取整.
 * 如果i>j,那么i是在j右兄弟或者j的下级结点,那么看i的父节点(i/2),如果i/2==j的话,那么i/2就是最近结点.
 * 如果i/2!=j的话,那么就可以继续那i=2/i去和j继续比较.j同理.
*/
int getCommonParent(int i,int j){
    while (i!=j)
    {
        if (i>j)
        {
            i=i/2;
        }else
        {
            j = j/2;
        }
    }
    return i;
}

void subTraversal(BiTree t, int cnt){
    printf("subTraversal:\t");
    //指向当前栈顶
    int index=-1;
    //用来存放需要回溯的结点
    BiTree arr[cnt];
    //表示正在访问的结点
    BiTree p=t;
    //表示刚访问的结点
    BiTree r=NULL;
    while (p||index>=0) 
    {   
        //先一直走到最左边
        if (p!=NULL)
        {
            arr[++index]=p;
            p=p->lChild;
        }
        else
        {
            //获得栈顶结点
            p=arr[index];
            //右结点存在并且右结点没有被访问过,往右走
            if (p->rChild&&p->rChild!=r)
            {
                p = p->rChild;
                arr[++index]=p;
                //继续往左走
                p = p->lChild;
            }
            //右边没有,或者已经处理完成,输出该节点,并设置已访问指针,将p重置为NULL来获取下一个栈顶的结点
            else
            {   
                index--;
                printf("%c\t",p->value);
                r=p;
                p=NULL;
            } 
        }
    } 
}

void seqTraversal(BiTree t, int cnt){
    BiTree queue[cnt];
    char stack[cnt];
    int front=0,rear=0,top=-1;
    queue[rear]=t;
    rear = (rear+1+cnt)%cnt;
    //使用队列进行正向的层序遍历
    while (front!=rear)
    {
        BiTree node = queue[front];
        front = (front+1+cnt)%cnt;
        //值放入栈中
        stack[++top]=node->value;
        //放入左子结点
        if (node->lChild!=NULL)
        {
            queue[rear]=node->lChild;
            rear = (rear+1+cnt)%cnt;
        }
        //放入右子结点
        if (node->rChild!=NULL)
        {
            queue[rear]=node->rChild;
            rear = (rear+1+cnt)%cnt;
        }
    }
    
    printf("SeqTraversal:");
    for (int i = top; i >=0; i--)
    {
        printf("%c\t",stack[i]);
    }
    
}

int main(){
    printf("hello tree.\n");
    // int result = getCommonParent(4,5);
    // printf("common parent is:%d\n",result);
    BiTree t = creatTree();
    // subTraversal(t,10);
    seqTraversal(t,10);
}
