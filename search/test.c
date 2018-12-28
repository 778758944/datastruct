#include "search.h"

int main(void) {
    int a[100] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};

    int index = Fibonacci_Search(a, 10, 62);
    printf("index = %d\n", index);
    return 0;
}