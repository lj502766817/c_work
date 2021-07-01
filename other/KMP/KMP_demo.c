/*
 * @Author: lijia
 * @Date: 2021-06-14 14:48:33
 * @LastEditTime: 2021-07-01 19:25:34
 * @LastEditors: lijia
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
    getNext(next,pStr);
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

void next(int *next, SString pStr){
    
}

void nextVal(int *nextVal, SString pStr){
    
}

int main(){
    printf("KMP!\n");
    
}

