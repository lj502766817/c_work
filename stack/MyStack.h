/*
 * @Author: lijia
 * @Date: 2021-06-20 22:25:29
 * @LastEditTime: 2021-06-24 13:49:04
 * @LastEditors: lijia
 * @Description: 栈算法题
 * @FilePath: \c_work\demo1\stack\MyStack.h
 */

#include <stdbool.h>
#include "../linkedList/MyLinkedList.h"

#ifndef DEMO1_MYSTACK_H
#define DEMO1_MYSTACK_H


struct SharingSeqStack {
    int data[50];
    int top[2];
} sharingSeqStack={{0},{-1,50}};

struct TagSeqQueue {
    int data[10];
    int tag;
    int front;
    int rear;
} tagSeqQueue={{0},0,0,0};

typedef struct Stack{
    char *data;
    int top;
    int size;
} Stack;

void initStack(Stack *stack, int size);

bool push(Stack *stack, char value);

bool pop(Stack *stack, char * value);

bool stackOverflow(Stack * stack);

bool stackEmpty(Stack *stack);

/**************************************************** Implementation *************************************************************/

void initStack(Stack *stack, int size){
    stack->data = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
    {
        stack->data[i]=0;
    }
    stack->size = size;
    stack->top = -1;
}

bool push(Stack *stack, char value){
    if(stack->top==(stack->size-1)){
        printf("stack is full.\n");
        return false;
    }
    stack->data[++(stack->top)]=value;
    return true;
}

bool pop(Stack *stack, char * value){
    if(stack->top==-1){
        printf("stack is empty.\n");
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

bool stackOverflow(Stack * stack){
    return stack->top==(stack->size-1);
}

bool stackEmpty(Stack *stack){
    return stack->top==-1;
}


/*****************************************************************************************************************/

/**
 * 查看出入栈操作是否合法,arr = {I,O,I,I},I表示进栈,O表示出栈
 * @param {char} arr
 * @param {int} len
 * @return {*}
 */
int checkStackOpt(char arr[],int len);

/**
 * 设单链表的表头指针为L,结点结构由data和next两个域构成,其中data域为字符型.试设计算法判断该链表的全部n个字符是否中心对称。
 * 例如xyx、xyyx都是中心对称。
 * @param {CharLinkedList} L
 * @param {int} n
 * @return {*}
 */
int checkCharListSymmetry(CharLinkedList L, int n);

/**
 * 共享栈入栈
 * @param {int} i
 * @param {int} value
 * @return {*}
 */
int pushSharingSeqStack(int i, int value);

/**
 * 共享栈出栈
 * @param {int} i
 * @param {int *} value
 * @return {*}
 */
int popSharingSeqStack(int i, int * value);

/**
 * 若希望循环队列中的元素都能得到利用，则需设置一个标志域tag，
 * 并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的队列状态是“空”还是“满”。
 * 试编写与此结构相应的入队和出队算法。
*/
int enQueueWithTag(int value);
int deQueueWithTap(int * value);

/**
 * 假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号，
 * 编写一个算法来判别表达式中的括号是否配对，以字符“\0” 作为算术表达式的结束符
 * @param {char} arr
 * @return {*}
 */
void brecktCompletion(char arr[]);

/**
 * 按下图所示铁道进行车厢调度（注意，两侧铁道均为单向行驶道，火车调度站有一个用于调度的“栈道”），
 * 火车调度站的入口处有《节硬座和软座车厢（分别用H和S表示）等待调度，试编写算法，
 * 输出对这《节车厢进行调度的操作（即入栈或出栈操作）序列，以使所有的软座车厢都被调整到硬座车厢之前。
 * 
 *      ------------------------------------------------------------
 * 
 *          <---------                        <---------
 *                                  
 *      ------------------              -----------------------------
 *                        |  ^     |   |
 *                        |  |     V   |
 *                        |            |
 *                        |            |
 * @param {char} arr
 * @param {int} len
 * @return {*}
 */
void trainScheduale(char arr[], int len);

#endif //DEMO1_MYSTACK_H
