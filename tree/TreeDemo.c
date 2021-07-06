/*
 * @description: 
 * @Date: 2021-07-05 14:45:09
 * @LastEditors: lijia
 * @LastEditTime: 2021-07-05 16:22:26
 * @FilePath: \c_work\demo1\tree\TreeDemo.c
 */

#include <stdio.h>
#include "MyTree.h"

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

int main(){
    printf("hello tree.\n");
    int result = getCommonParent(4,5);
    printf("common parent is:%d\n",result);
}
