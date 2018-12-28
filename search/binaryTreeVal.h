#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define LH 1
#define EH 0
#define RH -1

typedef int ElemType;


typedef struct BivTNode {
    ElemType data;
    struct BivTNode * lchild, * rchild;
    int bi;
} BivTNode, * BivTree;


void R_Rotate(BivTree T);
void L_Rotate(BivTree T);
void LeftBalance(BivTree T);
void RightBalance(BivTree T);
bool InsertAVL(BivTree *, ElemType e, bool * taller);
bool SearchBST(BivTree T, ElemType key, BivTree f, BivTNode * p);