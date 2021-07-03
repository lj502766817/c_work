/*
 * @Author: lijia
 * @Date: 2021-06-14 14:48:33
 * @LastEditTime: 2021-07-03 17:20:48
 * @LastEditors: Please set LastEditors
 * @Description: 字符串匹配 KMP算法
 * @FilePath: \c_work\demo1\other\KMP\KMP_demo.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct SString{
    char *data;
    int len;
} SString;

/**
 * 生成next[j]数组
 * @param {int} *next
 * @param {SString} *pStr
 * @return {*}
 */
void getNext(int *next, SString pStr);

/**
 * 生成修正值next[j]数组
 * @param {int} *nextVal
 * @param {SString} *pStr
 * @return {*}
 */
void getNextVal(int *nextVal, SString pStr);

/**
 * 子串在主串的第一次出现的起始位序
 * @param {SString} *str
 * @param {SString} *pStr
 * @return {*}
 */
int indexOf(SString str, SString pStr);

int indexOf(SString str, SString pStr){
    int *next = malloc(pStr.len*sizeof(int));
    getNextVal(next,pStr);
    //字符串数组索引从0开始.
    int i=0,j=0;
    while (i<str.len&&j<pStr.len)
    {
        //如果模式串的第一位就不同,那么模式串和主串同时后移
        if(str.data[i]==pStr.data[j]||j<0)
        {
            //j从-1变0,i后移一位
            ++i;++j;
            
        } else
        {
            j=next[j];
        }
    }
    return j==pStr.len?i-pStr.len:-1;
    
}

void getNext(int *next, SString pStr){
    //第一位恒为-1
    next[0]=-1;
    //从第一位开始比较
    int index = 0;
    
    int k=-1;
    while (index<pStr.len-1)
    {   
        //1.k==-1的情况,即右滑到头了,那么直接next[j+1]=0
        //,即如果模式串的j+1位与主串的i位对不上,那么模式串直接滑到第一位与i比对
        //2.pk==pj的情况下,有next[j+1] = k+1
        if(k==-1||pStr.data[index]==pStr.data[k])
        {
            index++,k++;
            next[index]=k;
        }
        //pk!=pj的情况,将k表示的模式串右滑到next[k]继续比较.
        else
        {
            k = next[k];
        }
    }
    
}

void getNextVal(int *nextVal, SString pStr){
    nextVal[0]=-1;
    int index = 0;
    
    int k=-1;
    while (index<pStr.len-1)
    {   
        if(k==-1||pStr.data[index]==pStr.data[k])
        {
            index++,k++;
            //pj!=pnext[j]的情况
            if (pStr.data[index]!=pStr.data[k])
            {
                nextVal[index]=k;
            }
            //为了修正pj=pnext[j]的情况,因为这种情况下,如果子串的j位序与主串不匹配的话,那么在next[j]位序上一定和主串是不匹配的,因此直接比对next[next[j]]位序
            else
            {
                nextVal[index]=nextVal[k]; 
            }
        }
        else
        {
            k = nextVal[k];
        }
    }
    
}

int main(){
    printf("KMP!\n");
    char arr1[9] = {'a','b','a','b','c','a','c','c','a'};
    char arr2[5] = {'a','b','c','a','c'};
    SString str = {arr1,9};
    SString pStr = {arr2,5};
    int index = indexOf(str,pStr);
    printf("%d\n",index);
}

