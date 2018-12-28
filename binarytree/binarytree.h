#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 1

typedef char TElemeType;

typedef enum {Link, Thread} PointerTag;

typedef struct BiTNode {
    TElemeType data;
    struct BiTNode * lchild, *rchild;  
} BiTNode, * BiTree;

typedef struct BiThrNode {
    TElemeType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, * BiThrTree;

static BiThrTree pre;

void createBiTree(BiTree *t);
void preOrderTraverse(BiTree tree);
void inOrderTraverse(BiTree tree);
void postOrderTraverse(BiTree tree);

// 线索二叉树
void inThrreading(BiThrTree p);