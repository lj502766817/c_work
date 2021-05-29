#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MyDemo.h"

/**
 * 打印顺序表
 * @param list
 */
void printList(SeqList *list);

/**
 * 转置数组
 * @param arr
 * @param begin
 * @param end
 */
void exchange(int arr[], int begin, int end);

/**
 * 打印数组
 * @param arr
 * @param len
 */
void printArr(int arr[], int len);

/**
 * 二分查找,返回查找值的index
 * @param array
 * @param len
 * @param index
 * @return 是否找到
 */
bool binarySearch(ElemType array[], int len, int *index);

int main() {
    printf("Hello, World!\n");
//    int num = fibonacciRecursion(5);
//    num = fibonacciNonrecursion(5);

    ElemType *data = (ElemType *) malloc(10 * sizeof(ElemType));
    data[0].value = 3;
    data[1].value = 2;
    data[2].value = 1;
    data[3].value = 2;
    data[4].value = 8;
    data[5].value = 11;
    data[6].value = 7;
    data[7].value = 4;
    data[8].value = 2;
    data[9].value = 8;
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    list->MaxSize = 100;
    list->Length = 10;
    list->data = data;

    ElemType *data1 = (ElemType *) malloc(10 * sizeof(ElemType));
    data1[0].value = 1;
    data1[1].value = 3;
    data1[2].value = 5;
    data1[3].value = 7;
    data1[4].value = 9;
    data1[5].value = 11;
    data1[6].value = 13;
    data1[7].value = 15;
    data1[8].value = 17;
    data1[9].value = 19;
    SeqList l1 = {InitSize, 10, data1};

    ElemType data2[11] = {{2},
                          {4},
                          {6},
                          {8},
                          {10},
                          {12},
                          {14},
                          {16},
                          {18},
                          {20},
                          {22}};
    SeqList l2 = {InitSize, 11, data2};

    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

//    ElemType *target = (ElemType*) malloc(sizeof(ElemType));
//    delMin(list,target);
//    reverseList(list);
//    delValueX(list, 2);
//    delBetween(list,1,4);
//    delBetweenAndEqual(list,1,8);
//    removeDuplicative(list);
//    mergeSeqList(&l1,&l2);
//    exchangeArray(arr,10,5,5);

    return 0;
}

void printList(SeqList *list) {
    printf("printList:");
    for (int i = 0; i < list->Length; ++i) {
        printf("%d\t", list->data[i].value);
    }
}

void exchange(int *arr, int begin, int end) {
    for (int i = begin, j = end; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArr(int arr[], int len) {
    printf("printArr:");
    for (int i = 0; i < len; ++i) {
        printf("%d\t", arr[i]);
    }
}

int fibonacciRecursion(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    int num = fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
    printf("num:%d\n", num);
    return num;
}

int fibonacciNonrecursion(int n) {
    int store[2] = {1, 1};
    if (n == 1 || n == 2) {
        return 1;
    }
    int num = 0;
    for (int i = 3; i <= n; ++i) {
        num = store[0] + store[1];
        store[0] = store[1];
        store[1] = num;
    }
    printf("num:%d\n", num);
    return num;
}

bool delMin(SeqList *list, ElemType *e) {
    if (list->Length < 1) {
        return false;
    }
    int minIndex = 0;
    for (int i = 1; i < list->Length; ++i) {
        if (list->data[i].value < list->data[minIndex].value) {
            minIndex = i;
        }
    }
    e->value = list->data[minIndex].value;
    printf("minIndex:%d\n", minIndex);
    list->data[minIndex] = list->data[list->Length - 1];
    list->Length--;
    return true;
}

bool reverseList(SeqList *list) {
    ElemType elem;
    for (int i = 0; i <= list->Length / 2 - 1; ++i) {
        elem = list->data[i];
        list->data[i] = list->data[list->Length - 1 - i];
        list->data[list->Length - 1 - i] = elem;
    }
    printList(list);
    return true;
}

bool delValueX(SeqList *list, int x) {
    int findCnt = 0;
    int i = 0;
    while (i < list->Length) {
        if (list->data[i].value == x) {
            findCnt++;
        } else {
            list->data[i - findCnt] = list->data[i];
        }
        i++;
    }
    list->Length -= findCnt;
    printList(list);
    return true;
}

bool delBetween(SeqList *list, int s, int t) {
    if (list->Length < 1 || s >= t) {
        return true;
    }
    int len = 0;
    int i = 0;
    while (i < list->Length) {
        //在s和t之间的就跳过,不在的就往前挪到到正确位置
        if (list->data[i].value <= s || list->data[i].value >= t) {
            list->data[len] = list->data[i];
            len++;
        } else {
            printf("remove:%d\n", list->data[i].value);
        }
        i++;
    }
    list->Length = len;
    printList(list);
    return true;
}

bool delBetweenAndEqual(SeqList *list, int s, int t) {
    if (list->Length < 1 || s >= t) {
        return true;
    }
    int len = 0;
    int i = 0;
    while (i < list->Length) {
        //在s和t之间的就跳过,不在的就往前挪到到正确位置
        if (list->data[i].value < s || list->data[i].value > t) {
            list->data[len] = list->data[i];
            len++;
        } else {
            printf("remove:%d\n", list->data[i].value);
        }
        i++;
    }
    list->Length = len;
    printList(list);
    return true;
}

bool removeDuplicative(SeqList *list) {
/*    //每移除一个重复项,遍历长度减一,因为已经把后面的队列前移了
    for (int i = 0; i < list->Length; ++i) {
        int mark = list->data[i].value;
        int removeCnt=0;
        int j=i+1;
        //对当前值后面的顺序表做根据值删除的操作
        while (j<list->Length){
            if(list->data[j].value==mark){
                removeCnt++;
            } else{
                list->data[j-removeCnt]=list->data[j];
            }
            j++;
        }
        list->Length-=removeCnt;
    } //由于是有序表相同的元素一定在一起 */
    int i, j;
    for (i = 0, j = 1; j < list->Length; j++) {
        if (list->data[i].value != list->data[j].value) {
            //不相同则查看下一个元素
            list->data[++i] = list->data[j];
        }
    }
    list->Length = i + 1;
    printList(list);
    return true;
}

SeqList mergeSeqList(SeqList *l1, SeqList *l2) {
    SeqList merge;
    merge.Length = l1->Length + l2->Length;
    merge.data = (ElemType *) malloc((l1->Length + l2->Length) * sizeof(ElemType));
    int i = 0, j = 0, k = 0;
    while (true) {
        if (i < l1->Length && j < l2->Length) {
            //两个列表逐步比较
            if (l1->data[i].value < l2->data[j].value) {
                merge.data[k] = l1->data[i];
                i++;
            } else {
                merge.data[k] = l2->data[j];
                j++;
            }
        } else {
            if (i >= l1->Length && j < l2->Length) {
                //l1放完,l2没放完
                merge.data[k] = l2->data[j];
                j++;
            } else if (j >= l2->Length && i < l1->Length) {
                //l2放完,l1没放完
                merge.data[k] = l1->data[i];
                i++;
            } else {
                break;
            }
        }
        k++;
    }
    printList(&merge);
    return merge;
}

bool exchangeArray(int arr[], int len, int m, int n) {
    exchange(arr, 0, len - 1);
    exchange(arr, 0, m - 1);
    exchange(arr, m, m + n - 1);
    printArr(arr, len);
}

bool handleValueX(SeqList *list) {


    return true;
}
