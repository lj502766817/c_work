/*
 * @description: 
 * @Date: 2021-07-05 14:30:22
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-19 14:22:35
 * @FilePath: \c_work\demo1\tree\MyTree.h
 */

#ifndef DEMO1_MYTREE_H
#define DEMO1_MYTREE_H

#include <stdbool.h>
#include <math.h>

typedef struct BiTreeNode{
    char value;
    struct BiTreeNode *lChild,*rChild;
    int lTag,rTag;
}BiTreeNode,*BiTree;

double log2(double x);

/**
 * 先序遍历构建树,value在a-z
*/
BiTree creatTree();

void deleteTree(BiTree t);

/**
 * 精度丢失风险
*/
double log2(double x){
    if(x==0){
        return 0;
    }
    double base = 2;
    double a = log(x);
    double b = log(base);
    return a/b;
}

BiTree creatTree(){
    char value[10];
    printf("enter value:");
    scanf("%s",value);
    if (value[0]>122||value[0]<97)
    {
        return NULL;
    }
    else
    {
        BiTree t = malloc(sizeof(BiTreeNode));
        t->value=value[0];
        t->lChild = creatTree();
        t->rChild = creatTree();
    }
}

/**
 * 递归方式后序遍历删除树
*/
void deleteTree(BiTree t){
    if (t)
    {
        deleteTree(t->lChild);
        deleteTree(t->rChild);
        printf("delete node:%c\n",t->value);
        free(t);
    } 
}

/**
 * 已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点的最近的公共祖先结点的值。
 * @param {int} i
 * @param {int} j
 * @return {*}
 */
int getCommonParent(int i,int j);

/**
 * 编写后序遍历二叉树的非递归算法。
 * @param {BiTree} t
 * @param {int} cnt
 * @return {*}
 */
void subTraversal(BiTree t, int cnt);

/**
 * 试给出二叉树的自下而上、从右到左的层次遍历算法。
 * @param {BiTree} t
 * @param {int} cnt
 * @return {*}
 */
void seqTraversal(BiTree t, int cnt);

/**
 * 假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度。
 * @param {*}
 * @return {*}
 */
int height(BiTree t);

/**
 * 设一棵二叉树中各结点的值互不相同,其先序遍历序列和中序遍历序列分别存于两个一维数组A[1...n]和B[1...n]中,试编写算法建立该二叉树的二叉链表.
 * @param {char} pre
 * @param {int} preLen
 * @param {char} mid
 * @param {int} midLen
 * @return {*}
 */
BiTree buildTree(char pre[], int preLen, char mid[], int midLen);

/**
 * 二叉树按二叉链表形式存储，写一个判别给定二叉树是否是完全二叉树的算法.
 * @param {BiTree} t
 * @return {*}
 */
void checkComplete(BiTree t);

/**
 * 假设二叉树采用二叉链表存储结构存储，试设计一个算法，计算一棵给定二叉树的所有双分支结点个数。
 * @param {BiTree} t
 * @return {*}
 */
int countDoubleBranchNode(BiTree t);

/**
 * 设树召是一棵采用链式结构存储的二叉树，编写一个把树t中所有结点的左、右子树进行交换的函数。
 * @param {BiTree} t
 * @return {*}
 */
void exchangeLeftAndRight(BiTree t);

/**
 * 假设二叉树采用二叉链存储结构存储，设计一个算法，求先序遍历序列中第k(1<=k<=二叉树中结点个数)个结点的值。
 * @param {BiTree} t
 * @param {int} k
 * @return {char}
 */
char getInPreTraversal(BiTree t, int k);

/**
 * 已知二叉树以二叉链表存储,编写算法完成:对于树中每个元素值为x的结点,删去以它为根的子树,并释放相应的空间。
 * @param {BiTree} t
 * @param {char} x
 * @return {*}
 */
void deleteSubTreeX(BiTree t, char x);

/**
 * 在二叉树中查找值为X的结点，试编写算法（用C语言）打印值为x的结点的所有祖先，假设值为x的结点不多于一个。
 * @param {BiTree} t
 * @param {char} x
 * @return {*}
 */
void getParentsByX(BiTree t, char x);

/**
 * 设一棵二叉树的结点结构为（LLINK, INFO, RLINK)，ROOT为指向该二叉树根结点的指针，p和q分别为该二叉树中任意两个结点的值，试编写算法找到p和q的最近公共祖先结点r。
 * @param {BiTree} root
 * @param {char} p
 * @param {char} q
 * @return {*}
 */
BiTree ancestor(BiTree root, char p, char q);

/**
 * 假设二叉树采用二叉链表存储结构,设计一个算法,求非空二叉树b的宽度（即具有结点数最多的那一层的结点个数)。
 * @param {BiTree} b
 * @return {*}
 */
int getWidth(BiTree b);

/**
 * 设有一棵满二叉树（所有结点值均不同） ， 已知其先序序列为pre,设计一个算法求其后序序列post。
 * @param {char} pre
 * @param {int} begin 数组下标
 * @param {int} end 数组下标
 * @return {*}
 */
void getPostByPre(char pre[], int begin, int end);

/**
 * 设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表， 表头指针为head。二叉树按二叉链表方式存储， 链接时用叶结点的右指针域来存放单链表指针。
 * @param {BiTree} t
 * @return {*}
 */
BiTree getLeafNodeList(BiTree t);

/**
 * 试设计判断两棵二叉树是否相似的算法。 所谓二叉树t1和t2相似， 指的是t1和t2都是空的二叉树或都只有一个根结点;
 * 或t1的左子树和t2的左子树是相似的， 且t1的右子树和t2的右子树是相似的
 * @param {BiTree} t1
 * @param {BiTree} t2
 * @return {*}
 */
bool checkSimilarity(BiTree t1, BiTree t2);

/**
 * 将树进行中序线索化
 * @param {BiTree} t
 * @return {*}
 */
void createInThreadByMid(BiTree t);

/**
 * 写出在中序线索二叉树里查找指定结点在后序序列的前驱结点的算法
 * @param {BiTree} thread
 * @return {*}
 */
BiTree findPreNode(BiTree thread);

/**
 * 二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和.给定一棵二叉树T,采用二叉链表存储，结点结构为[left,weight,right]
 * 其中叶结点的weight域保存该结点的非负权值。设root为指向T的根结点的指针,请设计求T的WPL的算法
 * @param {BiTree} root
 * @return {*}
 */
void calculateWPL(BiTree root);

/**
 * 请设计一个算法,将给定的表达式树(二叉树)转换为等价的中缀表达式(通过括号反映操作符的计算次序)并输出
 * @param {BiTree} root
 * @param {int} deep
 * @return {*}
 */
void getInfixExpression(BiTree root, int deep);

#endif //DEMO1_MYTREE_H
