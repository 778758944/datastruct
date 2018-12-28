#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
#define MAX_LENGTH_INSERT_SORT 7

typedef struct {
    int r[MAXSIZE];
    int length;
} SqList;

void swap(SqList * L, int i, int j);
void BubbleSort(SqList * L);
void SelectSort(SqList * L);
void InsertSort(SqList * L);
void ShellSort(SqList * L);
void HeapAdjust(SqList * L, int s, int m);
void HeapSort(SqList * L);


void QuickSort(SqList * L);
void QSort(SqList * L, int low, int high);
int Partition(SqList * L, int low, int high);