#include "binaryTreeVal.h"


void R_Rotate(BivTree T) {
    BivTNode * L;
    L = T -> lchild;
    T -> lchild = L -> rchild;
    L -> rchild = T;
    T = L;
}

void L_Rotate(BivTree T) {
    BivTNode * R;
    R = T -> rchild;
    T -> rchild = R -> lchild;
    R -> lchild = T;
    T = R;
}


void LeftBalance(BivTree T) {
    BivTNode * L, *Lr;
    L = T -> lchild;

    switch (L->bi) {
        case LH:
            T->bi = L->bi = EH;
            L_Rotate(T);
        break;

        case RH:
            Lr = L -> rchild;
            switch(Lr->bi) {
                case LH:
                    T -> bi = RH;
                    L -> bi = EH;
                    break;

                case EH:
                    T -> bi = L -> bi = EH;
                    break;

                case RH:
                    T -> bi = EH;
                    L -> bi = LH;
                    break;
            }

            Lr -> bi = EH;

            L_Rotate(L);
            R_Rotate(T);
    }
}

void RightBalance(BivTree T) {
    BivTNode *R, *Rl;

    R = T -> rchild;

    switch (R -> bi) {
        case RH:
            T -> bi = R -> bi = EH;
            L_Rotate(T);
            break;

        case LH:
            Rl = R -> lchild;
            switch (Rl -> bi) {
                case RH:
                    T -> bi = LH;
                    R->bi = EH;
                break;

                case EH:
                    T->bi = R->bi = EH;
                break;

                case LH:
                    T->bi = EH;
                    R->bi = RH;

                break;
            }

            Rl->bi = EH;
            R_Rotate(R);
            L_Rotate(T);
    }
}


bool InsertAVL(BivTree * T, ElemType e, bool * taller) {
    // printf("T.data = %d\n", (*T)->data);
    if (!*T) {
        (*T) = (BivTree) malloc(sizeof(BivTNode));
        (*T) ->data = e;
        (*T)->lchild = (*T) -> rchild = NULL;
        (*T) -> bi = EH;
        *taller = true;
    } else {
        printf("T.data = %d\n", (*T)->data);
        if (e == (*T) ->data) {
            *taller = false;
            return false;
        }

        if (e < (*T) -> data) {
            if (! InsertAVL(&(*T) -> lchild, e, taller)) {
                return false;
            }

            puts("deal with val");
            printf("e = %d\n", e);
            printf("taller = %d\n", *taller);

            printf("t.data = %d\n", (*T)->data);
            printf("t.bi = %d\n", (*T)->bi);

            if (*taller) {
                printf("dede");
                switch ((*T) -> bi) {
                    case LH:
                        printf("left high");
                        LeftBalance((*T));
                        *taller = false;
                    break;

                    case EH:
                        (*T) -> bi = LH;
                        *taller = true;
                        break;

                    case RH:
                        (*T) -> bi = EH;
                        *taller = false;
                        break;
                }
            } 
        } else {
            if (!InsertAVL(&(*T)->rchild, e, taller)) {
                return false;
            }

            if (*taller) {
                switch((*T)->bi) {
                    case LH:
                        (*T) -> bi = EH;
                        *taller = false;
                        break;

                    case EH:
                        (*T) -> bi = RH;
                        *taller = true;

                    case RH:
                        RightBalance(*T);
                        *taller = false;
                        break;
                }
            }
        }

    }

    return true;
}

bool SearchBST(BivTree T, ElemType key, BivTree f, BivTNode * p) {
    if (!T) {
        p = f;
        return false;
    } else if (key == T->data) {
        p = T;
        return true;
    } else if (key < T->data) {
        return SearchBST(T->lchild, key, f, p);
    } else {
        return SearchBST(T->rchild, key, f, p);
    }
}





