#include "sort.h"

int main(void) {
    SqList L = {
        {0,9, 1, 5, 8, 3, 7, 4, 6, 2},
        9,
    };

    // BubbleSort(&L);
    // SelectSort(&L);
    // InsertSort(&L);
    // ShellSort(&L);
    // HeapSort(&L);
    QuickSort(&L);
    for (int i = 1; i <= L.length; i++) {
        printf("%d\n", L.r[i]);
    }
    return 0;
}
