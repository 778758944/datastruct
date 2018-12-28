#include "sort.h"


void swap(SqList * L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void BubbleSort(SqList * L) {
    int i, j;
    bool flag = true;

    for (i = 1; i < L->length && flag; i++) {
        flag = false;
        for (j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j+1]) {
                swap(L, j, j+1);
                flag = true;
            }
        }
    }
}

void SelectSort(SqList * L) {
    int i, j, min;

    for (i = 1; i < L->length; i++) {
        min = i;
        for (j = i+1; j < L->length; j++) {
            if (L->r[j] < L->r[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(L, i, min);
        }
    }
}

void InsertSort(SqList * L) {
    int i, j;

    //keypoint: Assume that the first card is on position
    for(i = 2; i < L->length; i++) {
        if (L->r[i] < L->r[i-1]) {
            L->r[0] = L->r[i];
            for (j=i-1; L->r[j] > L->r[0]; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j+1] = L->r[0];
        }
    }
}

void ShellSort(SqList * L) {
    int i, j;

    int increment = L -> length;
    do
    {
        increment = increment/3 + 1;
        for (i = increment + 1; i < L->length; i++) {
            if (L->r[i] < L->r[i - increment]) {
                L->r[0] = L->r[i];
                for (j = i - increment; L ->r[j] > L ->r[0] && j > 0; j -= increment) {
                    L->r[j + increment] = L->r[j];
                }
                L->r[j+increment] = L ->r[0];
            }
        }

    }while(increment > 1);
}

void HeapAdjust(SqList * L, int s, int m) {
    // m is the length of L;
    int temp, j;
    temp = L->r[s];
    // 寻找左右子节点
    for (j = 2*s; j < m; j *= 2) {
        if (j < m-1 && L->r[j] < L->r[j+1]) {
            ++j;
        }

        if (temp >= L->r[j]) {
            break;
        }

        L->r[s] = L->r[j];

        s = j;
    }
    L->r[s] = temp;
}

void HeapSort(SqList * L) {
    int i;
    for(i = (L->length-1)/2; i>0; i--) {
        HeapAdjust(L, i, L->length);
    }

    for(i = L -> length; i > 1; i--) {
        swap(L, 1, i);
        HeapAdjust(L, 1, i-1);
    }
}

void QuickSort(SqList * L) {
    QSort(L, 1, L->length);
}

void QSort(SqList * L, int low, int high) {
    int pivot;

    if ((high-low) > MAX_LENGTH_INSERT_SORT) {

        while(low < high) {
            pivot = Partition(L, low, high);
            QSort(L, low, pivot - 1);
            low = pivot + 1;
        }
    } else {
        InsertSort(L);
    }
}

int Partition(SqList * L, int low, int high) {
    int pivotKey;

    int m = low + (high - low) / 2;

    if (L->r[low] > L->r[high]) {
        swap(L, low, high);
    }

    if (L->r[high] < L->r[m]) {
        swap(L, m, high);
    }

    if (L->r[low] > L->r[m]) {
        swap(L, m, low);
    }

    pivotKey = L -> r[low];
    L->r[0] = pivotKey;

    while(low < high) {
        while (low < high && L->r[high] >= pivotKey) {
            high--;
        }

        // swap(L, low, high);
        L->r[low] = L->r[high];

        while (low < high && L->r[low] <= pivotKey) {
            low++;
        }

        L->r[high] = L->r[low];
    }

    L->r[low] = L -> r[0];

    return low;
}





