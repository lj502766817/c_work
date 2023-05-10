#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#ifndef WANGDAO_DATASTRUCT_H

#define WANGDAO_DATASTRUCT_H
#define MAX_SIZE 50

//顺序表
typedef struct {
    int MaxSize,length;
    int *data;
} IntSeqList,*IntArray;

IntArray initIntSeqList(int maxData, int len);

IntArray initIntOrderedSeqList(int maxData, int len);

IntArray initIntOrderedSeqList(int maxData, int len)
{   
    if (len>MAX_SIZE)
    {
        return NULL;
    }
    
    srand(time(NULL));
    IntArray seq = malloc(sizeof(IntSeqList));
    seq->MaxSize=MAX_SIZE;
    seq->length = len;
    seq->data = malloc(len*sizeof(int));
    seq->data[0] = rand() % (maxData/2) + 1;

    for (int i = 1; i < len; i++)
    {   
        seq->data[i] = rand() % maxData + 1;
    }

    //选择排序
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (seq->data[i] > seq->data[j]) {
                int temp = seq->data[i];
                seq->data[i] = seq->data[j];
                seq->data[j] = temp;
            }
        }
    }
    return seq;
}

IntArray initIntSeqList(int maxData, int len)
{   
    if (len>MAX_SIZE)
    {
        return NULL;
    }
    
    srand(time(NULL));
    IntArray seq = malloc(sizeof(IntSeqList));
    seq->MaxSize=MAX_SIZE;
    seq->length = len;
    seq->data = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
    {   
        seq->data[i]= rand() % maxData + 1;
    }
    return seq;
}

void printIntSeqList(IntArray list);

void printIntSeqList(IntArray list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d\t",list->data[i]);
    }
    printf("\n");
}



#endif //WANGDAO_DATASTRUCT_H
