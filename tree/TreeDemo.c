/*
 * @description: 
 * @Date: 2021-07-05 14:45:09
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-19 14:48:45
 * @FilePath: \c_work\demo1\tree\TreeDemo.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "MyTree.h"

void copyArray(BiTree *source, BiTree *target, int len);

void copyArray(BiTree *source, BiTree *target, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}

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
    t->lTag = 0;
    t->rTag = 0;
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
void checkComplete(BiTree t)
{
    //序列
    BiTree queue[50];
    int front = 0, rear = 0;

    queue[rear] = t;
    rear = (rear + 1 + 50) % 50;

    while (front != rear)
    {
        BiTree node = queue[front];
        front = (front + 1 + 50) % 50;
        //如果是空节点,检查后续队列中是否有非空结点
        if (node == NULL)
        {
            for (int i = front; i != rear; i = (i + 1 + 50) % 50)
            {
                if (queue[i] != NULL)
                {
                    printf("tree is not complete!\n");
                    return;
                }
            }
            printf("tree is complete!\n");
            return;
        }
        queue[rear] = node->lChild;
        rear = (rear + 1 + 50) % 50;
        queue[rear] = node->rChild;
        rear = (rear + 1 + 50) % 50;
    }
}

/**
 * f(t)=0  t为null
 * f(t)=f(t.left)+f(t.right)+1  t有两个子节点
 * f(t)=f(t.left)+f(t.right)   t为叶子结点或者只有一个子节点
 * ------------------------------------------------------
 * 也可以直接全部遍历然后用一个全局变量统计
*/
int countDoubleBranchNode(BiTree t)
{
    int cnt = 0;
    if (t == NULL)
    {
        return cnt;
    }
    if (t->lChild != NULL && t->rChild != NULL)
    {
        cnt = countDoubleBranchNode(t->lChild) + countDoubleBranchNode(t->rChild) + 1;
    }
    else
    {
        cnt = countDoubleBranchNode(t->lChild) + countDoubleBranchNode(t->rChild);
    }

    return cnt;
}

void exchangeLeftAndRight(BiTree t)
{
    if (t)
    {
        exchangeLeftAndRight(t->lChild);
        exchangeLeftAndRight(t->rChild);
        BiTree temp = t->lChild;
        t->lChild = t->rChild;
        t->rChild = temp;
    }
}

char getInPreTraversal(BiTree t, int k)
{
    //用栈来代替递归
    BiTree stack[50];
    int top = -1, index = 0;

    stack[++top] = t;
    while (top >= 0)
    {
        //出栈
        BiTree node = stack[top--];
        index++;
        if (index == k)
        {
            printf("index %d is:%c", k, node->value);
            return node->value;
        }
        if (node->rChild)
        {
            stack[++top] = node->rChild;
        }
        if (node->lChild)
        {
            stack[++top] = node->lChild;
        }
    }
}

/**
 * 采用层序遍历查看每个结点,当有结点的子结点需要删除时,就删除那个子结点并将结点被删除的子结点设置成NULL
*/
void deleteSubTreeX(BiTree t, char x)
{
    if (t->value == x)
    {
        deleteTree(t);
    }
    BiTree queue[50];
    int front = 0, rear = 0;

    queue[rear] = t;
    rear = (rear + 1 + 50) % 50;

    while (front != rear)
    {
        BiTree node = queue[front];
        front = (front + 1 + 50) % 50;

        if (node->lChild != NULL)
        {
            if (node->lChild->value == x)
            {
                deleteTree(node->lChild);
                node->lChild = NULL;
            }
            else
            {
                queue[rear] = node->lChild;
                rear = (rear + 1 + 50) % 50;
            }
        }

        if (node->rChild != NULL)
        {
            if (node->rChild->value == x)
            {
                deleteTree(node->rChild);
                node->rChild = NULL;
            }
            else
            {
                queue[rear] = node->rChild;
                rear = (rear + 1 + 50) % 50;
            }
        }
    }
}

/**
 * 采用后续遍历,用栈存储结点的父节点和祖先结点
*/
void getParentsByX(BiTree t, char x)
{
    BiTree stack[50];
    int top = -1;
    BiTree p = t, r = NULL;

    while (p || top >= 0)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->lChild;
        }
        else
        {
            p = stack[top];
            if (p->rChild && p->rChild != r)
            {
                p = p->rChild;
                stack[++top] = p;
                p = p->lChild;
            }
            else
            {
                top--;
                if (p->value == x)
                {
                    printf("find parents.\n");
                    break;
                }
                r = p;
                p = NULL;
            }
        }
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%c\t", stack[i]->value);
    }
}

/**
 * 后序遍历分别找到这两个结点的全部父节点,然后在这两组父节点中找相同的最近结点
 * ------------------------------------------------------------------
 * 可以只用一个辅助数组,既在比较进行找的时候用栈和辅助数组去找
*/
BiTree ancestor(BiTree root, char p, char q)
{
    BiTree stack[50], pAncestor[50], qAncestor[50];
    int top = -1, pLen = 0, qLen = 0;
    BiTree t = root, r = NULL;

    //进行后序遍历
    while (t || top >= 0)
    {
        if (t)
        {
            stack[++top] = t;
            t = t->lChild;
        }
        else
        {
            t = stack[top];
            if (t->rChild && t->rChild != r)
            {
                t = t->rChild;
                stack[++top] = t;
                t = t->lChild;
            }
            else
            {
                top--;
                if (t->value == p)
                {
                    //复制p的全部祖先结点
                    copyArray(stack, pAncestor, top + 1);
                    pLen = top + 1;
                }
                else if (t->value == q)
                {
                    //复制q的全部祖先结点
                    copyArray(stack, qAncestor, top + 1);
                    qLen = top + 1;
                }
                //pq的祖先结点全部找到,退出
                if (pLen > 0 && qLen > 0)
                {
                    break;
                }

                r = t;
                t = NULL;
            }
        }
    }

    int index = -1;
    for (int i = 0; i < (pLen > qLen ? qLen : pLen); i++)
    {
        //当两个不等时,前一位就是最近的相同祖先结点
        if (pAncestor[i] != qAncestor[i])
        {
            index = i - 1;
        }
        //处理包含的情况,如:p的祖先结点包含q的祖先结点
        else
        {
            index = i;
        }
    }

    if (index >= 0)
    {
        printf("ancestor is:%c.\n", pAncestor[index]->value);
    }
    else
    {
        printf("there is no common ancestor.\n");
    }

    return pAncestor[index];
}

//使用层序遍历得到每一层的宽度,然后得到最大宽度
int getWidth(BiTree b)
{
    BiTree queue[50];
    int front = 0, rear = 0, tempWidth = 0, maxWidth = 0;
    //记录每层的最右结点
    BiTree last = b;

    queue[rear] = b;
    rear = (rear + 1 + 50) % 50;

    while (front != rear)
    {
        BiTree node = queue[front];
        front = (front + 1 + 50) % 50;
        tempWidth++;

        //遍历到最右结点
        if (node == last)
        {
            maxWidth = tempWidth > maxWidth ? tempWidth : maxWidth;
            //设置下一层的最右结点
            if (node->lChild)
            {
                last = node->lChild;
            }
            if (node->rChild)
            {
                last = node->rChild;
            }
            tempWidth = 0;
        }

        //下层结点进队列
        if (node->lChild)
        {
            queue[rear] = node->lChild;
            rear = (rear + 1 + 50) % 50;
        }
        if (node->rChild)
        {
            queue[rear] = node->rChild;
            rear = (rear + 1 + 50) % 50;
        }
    }

    printf("the tree`s width is:%d", maxWidth);
}

/**
 * 由于是满二叉树,那么先序序列的头结点后面的结点一定是均分的左子树和右子树的先序序列.那么可以直接递归求出后序序列
*/
void getPostByPre(char pre[], int begin, int end)
{
    if (begin == end)
    {
        printf("%c\t", pre[begin]);
        return;
    }
    //处理左子树
    getPostByPre(pre, begin + 1, (end + begin + 1) / 2);
    //处理右子树
    getPostByPre(pre, (end + begin + 1) / 2 + 1, end);
    //最后输出头结点
    printf("%c\t", pre[begin]);
}

/**
 * 先进行先/中/后序遍历,从左到右找到叶子节点,然后串成一个链表
*/
BiTree getLeafNodeList(BiTree t)
{
    BiTree stack[50];
    int top = -1;
    BiTree head, pre = NULL, p = t;

    //进行中序遍历
    while (p || top >= 0)
    {
        //走到最左
        if (p)
        {
            stack[++top] = p;
            p = p->lChild;
        }
        else
        {
            //出栈
            p = stack[top--];
            //如果有右子树
            if (p->rChild)
            {
                //处理右子树头结点
                p = p->rChild;
            }
            //当前结点是叶子节点
            else
            {
                printf("assemble node:%c\t", p->value);
                //处理头结点
                if (pre == NULL)
                {
                    head = p;
                }
                else
                {
                    pre->rChild = p;
                }
                pre = p;
                //设置p为NUL,继续从栈中拿结点
                p = NULL;
            }
        }
    }
    pre->rChild = NULL;
    return head;
}

bool checkSimilarity(BiTree t1, BiTree t2)
{
    if ((t1 != NULL && t2 == NULL) || (t1 == NULL && t2 != NULL))
    {
        return false;
    }
    else if (t1 == NULL && t2 == NULL)
    {
        return true;
    }

    bool leftCheck = checkSimilarity(t1->lChild, t2->lChild);
    bool rightCheck = checkSimilarity(t1->rChild, t2->rChild);
    if (!(leftCheck && rightCheck))
    {
        return false;
    }
    return true;
}

BiTree inThread(BiTree t, BiTree pre);

BiTree inThread(BiTree t, BiTree pre)
{
    if (t != NULL)
    {
        //递归线索化左子树
        pre = inThread(t->lChild, pre);
        //没有左子树,建立前驱线索
        if (t->lChild == NULL)
        {
            t->lChild = pre;
            t->lTag = 1;
        }
        //为前驱结点建立后继
        if (pre != NULL && pre->rChild == NULL)
        {
            pre->rChild = t;
            pre->rTag = 1;
        }
        pre = t;
        //递归线索化右子树
        pre = inThread(t->rChild, pre);

        return pre;
    }
    //空树直接返回传进来的前驱
    return pre;
}

void createInThreadByMid(BiTree t)
{
    BiTree pre = NULL;
    if (t != NULL)
    {
        pre = inThread(t, pre);
        pre->rChild = NULL;
        pre->rTag = 1;
    }
}

/**
 * 如果结点有右子结点,那么在后序序列的前驱一定是右子树的头结点.如果只有左子结点的话,那么在后序序列的前驱一定是左子树的头结点.
 * 需要重点考虑的是叶子结点的情况,如果叶子节点是整个树中最左边的结点,那么没有前驱结点.
 * 如果是不是说最左边,那么就找父节点的左子树的头结点,这个结点一定是叶子节点的前驱结点
*/
BiTree findPreNode(BiTree thread)
{
    //有右子树
    if (thread->rTag == 0)
    {
        return thread->rChild;
    }
    //有左子树
    if (thread->lTag == 0)
    {
        return thread->lChild;
    }
    //thread是中序序列中的第一个结点,既最左边的结点,在后序序列中没有前驱结点
    if (thread->lChild == NULL)
    {
        return NULL;
    }
    //考虑其他叶子节点的情况,考虑到单链的情况,一直往上找祖先结点,一直到这个祖先结点有左子树,此时左子树的头结点就是后序序列的中的前驱,或者找到单链的头结点,那么直接返回NULL
    while (thread->lTag == 1 && thread->lChild != NULL)
    {
        thread = thread->lChild;
    }
    //存在左子树
    if (thread->lTag == 0)
    {
        return thread->lChild;
    }

    return NULL;
}

/**
 * 主要思想,先通过遍历找到叶子结点,然后看叶子结点是到根路径的长度,然后计算带权路径长.
 * 这里使用非递归后续遍历,因为非递归的后续遍历可以很容易计算叶子结点到根节点的路径长,从而算得带权路径长.
 * ------------------------------------------------
 * 也能用前序遍历和层序遍历
*/
void calculateWPL(BiTree root)
{
    BiTree stack[50];
    int top = -1,wpl=0;
    BiTree p = root,r=NULL;

    while (p||top>=0)
    {
        if (p)
        {
            stack[++top]=p;
            p = p->lChild;
        }
        else
        {
            BiTree node = stack[top];
            //有没处理的右子树
            if (node->rChild&&node->rChild!=r)
            {
                p = node->rChild;
                stack[++top]=p;
                p = p->lChild;
            }
            //右子树已经处理或者为叶子结点
            else
            {
                top--;
                //处理叶子结点的情况
                if (node->rChild==NULL)
                {
                    wpl += (top+1)*node->value;
                }
                p=NULL;
                r=node;
            }
        }
    }

    printf("WPL is:%d",wpl);
}

/**
 * 通过中序遍历进行输出,只在根节点和叶子结点加上括号
*/
void getInfixExpression(BiTree root, int deep){
    if (root==NULL)
    {
        return;
    }
    //只要根节点和叶子结点不加括号
    if (!(deep==1||(root->lChild==NULL&&root->rChild==NULL)))
    {
        printf("(");
    }
    getInfixExpression(root->lChild,deep+1);
    printf("%c",root->value);
    getInfixExpression(root->rChild,deep+1);
    if (!(deep==1||(root->lChild==NULL&&root->rChild==NULL)))
    {
        printf(")");
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
    char pre[6] = {'a', 'b', 'd', 'e', 'c', 'f'};
    char mid[6] = {'d', 'b', 'e', 'a', 'c', 'f'};
    char pre1[7] = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    char pre2[5] = {'h', 'i', 'j', 'k', 'l'};
    char mid2[5] = {'j', 'i', 'k', 'h', 'l'};
    char pre3[8] = {'*','+','a','b','*','c','-','d'};
    char mid3[8] = {'a','+','b','*','c','*','-','d'};

    BiTree t = buildTree(pre, 6, mid, 6);
    BiTree t2 = buildTree(pre2, 5, mid2, 5);
    BiTree t3 = buildTree(pre3,8,mid3,8);
    // seqTraversal(t,10);
    // checkComplete(t);
    // int cnt = countDoubleBranchNode(t);
    // printf("%d",cnt);
    // exchangeLeftAndRight(t);
    // seqTraversal(t,10);
    // getInPreTraversal(t,1);
    // deleteTree(t);
    // deleteSubTreeX(t,'f');
    // ancestor(t,'f','b');
    // getWidth(t);
    // getPostByPre(pre1,0,6);
    // getLeafNodeList(t);
    // bool result = checkSimilarity(t,t2);
    // printf("%d",result);
    // createInThreadByMid(t);
    // calculateWPL(t);
    getInfixExpression(t3,1);
}
