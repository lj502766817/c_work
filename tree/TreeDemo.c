/*
 * @description: 
 * @Date: 2021-07-05 14:45:09
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-14 19:45:56
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
int getCommonParent(int i, int j)
{
    while (i != j)
    {
        if (i > j)
        {
            i = i / 2;
        }
        else
        {
            j = j / 2;
        }
    }
    return i;
}

void subTraversal(BiTree t, int cnt)
{
    printf("subTraversal:\t");
    //指向当前栈顶
    int index = -1;
    //用来存放需要回溯的结点
    BiTree arr[cnt];
    //表示正在访问的结点
    BiTree p = t;
    //表示刚访问的结点
    BiTree r = NULL;
    while (p || index >= 0)
    {
        //先一直走到最左边
        if (p != NULL)
        {
            arr[++index] = p;
            p = p->lChild;
        }
        else
        {
            //获得栈顶结点
            p = arr[index];
            //右结点存在并且右结点没有被访问过,往右走
            if (p->rChild && p->rChild != r)
            {
                p = p->rChild;
                arr[++index] = p;
                //继续往左走
                p = p->lChild;
            }
            //右边没有,或者已经处理完成,输出该节点,并设置已访问指针,将p重置为NULL来获取下一个栈顶的结点
            else
            {
                index--;
                printf("%c\t", p->value);
                r = p;
                p = NULL;
            }
        }
    }
}

void seqTraversal(BiTree t, int cnt)
{
    BiTree queue[cnt];
    //使用栈进行逆向输出
    char stack[cnt];
    int front = 0, rear = 0, top = -1;
    queue[rear] = t;
    rear = (rear + 1 + cnt) % cnt;
    //使用队列进行正向的层序遍历
    while (front != rear)
    {
        BiTree node = queue[front];
        front = (front + 1 + cnt) % cnt;
        //值放入栈中
        stack[++top] = node->value;
        //放入左子结点
        if (node->lChild != NULL)
        {
            queue[rear] = node->lChild;
            rear = (rear + 1 + cnt) % cnt;
        }
        //放入右子结点
        if (node->rChild != NULL)
        {
            queue[rear] = node->rChild;
            rear = (rear + 1 + cnt) % cnt;
        }
    }

    printf("SeqTraversal:");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\t", stack[i]);
    }
}

/**
 * 使用层序遍历
*/
int height(BiTree t)
{
    if (t == NULL)
    {
        return 0;
    }
    //标志层数
    int level = 0;
    //队列用来进行层序遍历
    BiTree queue[50];
    int front = 0, rear = 0;
    queue[rear] = t;
    rear = (rear + 1 + 50) % 50;
    //标志每层最右的结点
    BiTree last = queue[(rear - 1 + 50) % 50];

    while (front != rear)
    {
        BiTree node = queue[front];
        front = (front + 1 + 50) % 50;
        //放入左子结点
        if (node->lChild != NULL)
        {
            queue[rear] = node->lChild;
            rear = (rear + 1 + 50) % 50;
        }
        //放入右子结点
        if (node->rChild != NULL)
        {
            queue[rear] = node->rChild;
            rear = (rear + 1 + 50) % 50;
        }
        //如果访问到当前层最右元素那么层数加一,并且设置下一层的最右元素
        //此时,下一层的元素已经全部进入队列中
        if (node == last)
        {
            level++;
            //下一层的最右结点一定是访问到当前层最右结点时,队列中的队尾元素
            last = queue[(rear - 1 + 50) % 50];
        }
    }
    printf("height:%d", level);
    return level;
}

BiTree buildTree(char pre[], int preLen, char mid[], int midLen)
{
    BiTree t = malloc(sizeof(BiTreeNode));
    char head = pre[0];
    t->value = head;
    t->lChild = NULL;
    t->rChild = NULL;
    //如果先序和中序都是一个结点,直接返回
    if (preLen == 1 || midLen == 1)
    {
        return t;
    }

    //找到父节点在中序遍历中的位置
    int index;
    for (int i = 0; i < midLen; i++)
    {
        if (t->value == mid[i])
        {
            index = i;
            break;
        }
    }
    //生成左子树
    int leftNum = index;
    if (leftNum > 0)
    {
        char midLeft[leftNum], preLeft[leftNum];
        //处理中序遍历
        for (int i = 0; i < index; i++)
        {
            midLeft[i] = mid[i];
        }
        //处理先序遍历
        for (int i = 1, j = 0; j < leftNum; i++, j++)
        {
            preLeft[j] = pre[i];
        }
        t->lChild = buildTree(preLeft, leftNum, midLeft, leftNum);
    }
    //生成右子树
    int rightNum = midLen - 1 - index;
    if (rightNum > 0)
    {
        char midRight[rightNum], preRight[rightNum];
        //处理中序遍历
        for (int i = index + 1, j = 0; j < rightNum; i++, j++)
        {
            midRight[j] = mid[i];
        }
        //处理先序遍历
        for (int i = leftNum + 1, j = 0; j < rightNum; i++, j++)
        {
            preRight[j] = pre[i];
        }
        t->rChild = buildTree(preRight, rightNum, midRight, rightNum);
    }

    return t;
}

/**
 * 进行层序遍历,并且把空节点也加入队列,根据完全二叉树的性质,队列中的空节点之后不能有非空结点的存在
*/
void checkComplete(BiTree t){
    //序列
    BiTree queue[50];
    int front=0,rear=0;

    queue[rear]=t;
    rear = (rear+1+50)%50;

    while (front!=rear)
    {
        BiTree node = queue[front];
        front = (front+1+50)%50;
        //如果是空节点,检查后续队列中是否有非空结点
        if (node==NULL)
        {
            for (int i = front; i!=rear; i=(i+1+50)%50)
            {
               if (queue[i]!=NULL)
                {
                    printf("tree is not complete!\n");
                    return ;
                } 
            }
            printf("tree is complete!\n");
            return ;
        }
        queue[rear]=node->lChild;
        rear = (rear+1+50)%50;
        queue[rear]=node->rChild;
        rear = (rear+1+50)%50;
    }
    
}

int main()
{
    printf("hello tree.\n");
    // int result = getCommonParent(4,5);
    // printf("common parent is:%d\n",result);
    // BiTree t = creatTree();
    // subTraversal(t,10);
    // seqTraversal(t,10);
    // height(t);
    char pre[6]={'a','b','d','e','c','f'};
    char mid[6]={'d','b','e','a','c','f'};
    BiTree t = buildTree(pre,6,mid,6);
    // seqTraversal(t,10);
    checkComplete(t);
}
