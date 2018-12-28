#include "binaryTreeVal.h"

int main(void) {
    BivTree tree = NULL;
    BivTNode * node;
    int i;
    ElemType a[10] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    bool taller;
    for (i = 0; i < 10; i++) {
        printf("i = %d\n", i);
        InsertAVL(&tree, a[i], &taller);
    }

    puts("tree created");

    printf("root data is %d\n", tree->data);

    // SearchBST(tree, 8, NULL, node);

    // printf("node.data = %d\n", node ->data);
    
    return 0;
}