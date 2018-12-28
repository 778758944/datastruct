#include "binarytree.h"


int main(void) {
    BiTree *t;
    createBiTree(t);
    preOrderTraverse(*t);
    puts(" ");
    inOrderTraverse(*t);
    puts(" ");
    postOrderTraverse(*t);
    puts(" ");
    return 0;
}