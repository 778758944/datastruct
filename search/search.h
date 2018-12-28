#include <stdio.h>
#include <stdbool.h>

static int F[100] = {0, 1, 1, 2, 3, 5, 8, 13, 21};

typedef int ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode * lchild, * rchild;
} BiTNode, * BiTree;

int Binary_Search(int * a, int n, int key);

int Fibonacci_Search(int * a, int n, int key);

bool SearchBST(BiTree T, ElemType key, BiTree f, BiTNode * p);
bool InsertBST(BiTree T, ElemType key);
bool DeleteBST(BiTree T, ElemType key);
bool Delete(BiTNode * t);