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
} IntSeqList,*IntSqList;



int getRandInt(int max);

int getRandInt(int max)
{
    int num;
    return rand() % max + 1;
}

IntSqList initIntSeqList(int maxData, int len);

IntSqList initIntSeqList(int maxData, int len)
{   
    if (len>MAX_SIZE)
    {
        return NULL;
    }
    
    srand(time(NULL));
    IntSqList seq = malloc(sizeof(IntSeqList));
    seq->MaxSize=MAX_SIZE;
    seq->length = len;
    seq->data = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++)
    {   
        seq->data[i]= getRandInt(maxData);
    }
    return seq;
}

bool printIntSeqList(IntSqList list);

bool printIntSeqList(IntSqList list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d\t",list->data[i]);
    }
    printf("\n");
}



#endif //WANGDAO_DATASTRUCT_H
