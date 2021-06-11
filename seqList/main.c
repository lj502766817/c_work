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
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int A[6] = {11,13,15,17,19,21};
    int B[6] = {2,4,6,8,20,22};
    int c[8] = {0,5,5,3,5,1,5,7};

//    ElemType *target = (ElemType*) malloc(sizeof(ElemType));
//    delMin(list,target);
//    reverseList(list);
//    delValueX(list, 2);
//    delBetween(list,1,4);
//    delBetweenAndEqual(list,1,8);
//    removeDuplicative(list);
//    mergeSeqList(&l1,&l2);
//    exchangeArray(arr,10,5,5);
//    handleValueX(&l2,4);
//    cycleMove(arr,10,3);
//    findMid(A,B,6);
//    findMainEle(c,8);
    findNotAppearNum(c,8);
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

bool handleValueX(SeqList *list,int x) {
    //二分查找
    int begin=0,end=list->Length-1,mid;
    while (begin<=end){
        //找到中间位置,用减法防止溢出
        mid = begin+(end-begin)/2;
        if(list->data[mid].value==x){
            //找到x跳出循环
            break;
        }
        if(list->data[mid].value>x){
            //去mid的左边查
            end=mid-1;
        } else{
            //mid的右边查
            begin=mid+1;
        }
    }
    //找到x的情况,如果是最后一位就不往后移
    if(mid!=list->Length-1&&list->data[mid].value==x){
        ElemType temp = list->data[mid];
        list->data[mid]=list->data[mid+1];
        list->data[mid+1]=temp;
    }
    //没有找到x的情况,将x插入end+1的位置,后续元素后移
    if(begin>end){
        int i;
        for (i = list->Length-1; i >end ; --i) {
            list->data[i+1]=list->data[i];
        }
        list->data[i+1].value=x;
        list->Length+=1;
    }
    printList(list);

    return true;
}

/*
 * 循环左移将数组分为(a,b)两块,先分别将a,b逆置,得到的数组是(-a,-b),然后将整个数组逆置得到的-(-a,-b)就是循环左移后的数组
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
bool cycleMove(int *arr,int len, int n){
    exchange(arr,0,n-1);
    exchange(arr,n,len-1);
    exchange(arr,0,len-1);
    printArr(arr,len);
    return true;
}

/*
 * 法1:将两个序列进行合并炒作到中位,则合并到总长的一半时就是中位数,时间复杂度为O(n),空间复杂度为O(1)
 * 法2:先找到两个升序序列A,B的中位数a,b,1.如果a=b则直接返回,2.如果a<b则舍去A较小的一半和B较大的一半,3.如果a>b则舍去A较大的一半和B较小的一半,重复1,2,3直到A,B剩一个元素,较小的那个就是中位数.
 *     时间复杂度为O(log2(n)),空间负责度为O(1)
 */
bool findMid(int A[], int B[], int len){
    int value;
    int findMid1(const int A[], const int B[], int len);
    value = findMid1(A,B,len);
    printf("mid value:%d\n",value);
    int findMid2(int A[], int B[], int len);
    value = findMid2(A,B,len);
    printf("mid value:%d\n",value);
    return true;
}
int findMid1(const int A[], const int B[], int len){
    int i=0,j=0,mid=0;
    int midValue;
    while (mid<=len-1){
        if(A[i]<=B[j]){
            midValue=A[i];
            i++;
        } else{
            midValue=B[j];
            j++;
        }
        mid++;
    }
    return midValue;
}
int findMid2(int A[], int B[], int len){
    int s1=0,d1=len-1,m1,s2=0,d2=len-1,m2;
    //两个序列都只剩一个数时跳出循环
    while (s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A[m1]==B[m2]){
            //中位数相等直接返回
            return A[m1];
        }
        //舍去A小的一半和B大的一半,并保证A,B长度一致
        if(A[m1]<B[m2]){
            if((s1+d1)%2==0){
                //元素个数是奇数,A去掉中位数前面的元素,B去掉中位数后面的元素
                s1=m1;
                d2=m2;
            } else{
                //元素个数是偶数,A去掉中位数前面元素以及中位数,B去掉中位数后面元素
                s1=m1+1;
                d2=m2;
            }
        }
        //舍去A大的一半和B小的一半
        else{
            //同上
            if((s1+d1)%2==0){
                d1=m1;
                s2=m2;
            } else{
                d1=m1;
                s2=m2+1;
            }
        }
    }
    return A[s1]>B[s2]?B[s2]:A[s1];
}

/*
 * 主元素的个数是超过总数的一半的,采用对消法.
 * 首先,选取候选的主元素,依次遍历序列,将遇到的第一个数保存在num中,并设置计数为1,然后查看下一个数,如果和num相同就计数加1,不同就计数减1.
 * 当计数为减到0时,设置下一个数为num,并设置计数为1,继续遍历完成.然后,再次遍历数组,检查得到的num出现的次数是否超过总数的一半.
 * 时间复杂度为O(n),空间复杂度为O(1)
 */
int findMainEle(const int *list, int len){
    int num,cnt=0;
    //选取可能的主元素
    for (int i = 0; i < len; ++i) {
        if(cnt==0){
            num = list[i];
            ++cnt;
        } else{
            if(num==list[i]){
                ++cnt;
            } else{
                --cnt;
            }
        }
    }
    //判断是否是主元素
    cnt=0;
    for (int i = 0; i < len; ++i) {
        if(list[i]==num){
            ++cnt;
        }
    }
    if(cnt>len/2){
        printf("main element is:%d",num);
        return num;
    }
    return -1;
}

/*
 * 在时间上高效就需要牺牲空间,设置一个备用数组a[n],初始值全为0,a[0]表示1,...,a[n]表示n+1,然后遍历数组arr,如果arr中出现了由a表示的数,则设置a对应位置的值为1.
 * 最后遍历a,当找到a里值为0的位置时,没有出现的最小数就是i+1.
 * 时间复杂度为O(n),空间复杂度为O(n)
 */
bool findNotAppearNum(const int *arr, int len){
    //初始化备用数组a
    int *a= malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        a[i]=0;
    }
    //遍历arr
    for (int i = 0; i < len; ++i) {
        if(1<=arr[i]&&arr[i]<=len+1){
            //arr的值在1到n+1之间
            a[arr[i]-1]=1;
        }
    }
    //查找空出来的数
    int i=0;
    while (i<len){
        if(a[i]==0){
            break;
        }
        i++;
    }
    ++i;
    printf("num is:%d",i);
    return true;
}


