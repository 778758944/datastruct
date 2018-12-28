#include "binarytree.h"

void createBiTree(BiTree *t) {
    TElemeType ch;
    /*
    while (getchar() == '\n') {
        continue;
    }
    */
    puts("please enter a char");
    scanf("%c", &ch);


    if (ch == '#') {
        *t = NULL;
    } else {
        *t = malloc(sizeof(BiTNode));
        if (!*t) {
            exit(OVERFLOW);
        }

        (*t)->data = ch;
        createBiTree(& (*t) -> lchild);
        puts("now right");
        createBiTree(& (*t) -> rchild);
    }
}

void preOrderTraverse(BiTree tree) {
    if (tree == NULL) {
        return;
    }

    printf("%c", tree->data);
    preOrderTraverse(tree->lchild);
    preOrderTraverse(tree->rchild);
}

void inOrderTraverse(BiTree tree) {
    if (tree == NULL) {
        return;
    }
    inOrderTraverse(tree->lchild);
    printf("%c", tree->data);
    inOrderTraverse(tree->rchild);
}

void postOrderTraverse(BiTree tree) {
    if (tree == NULL) {
        return;
    }

    postOrderTraverse(tree->lchild);
    postOrderTraverse(tree->rchild);
    printf("%c", tree->data);
}

void inThrreading(BiThrTree p) {
    if (p) {
        inThrreading(p->lchild);

        if (!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
        } 

        if (!pre -> rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
        }

        pre = p;
        inThrreading(p->rchild);
    }
}