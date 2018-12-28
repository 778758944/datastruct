#include <stdio.h>
#include <stdlib.h>

void getNum(int *);

int main(void) {
    int * i;
    getNum(i);

    printf("num = %d\n", *i);
    return 0;
}


void getNum(int * num) {
    num = (int *) malloc(sizeof(int));

    *num = 1;
}