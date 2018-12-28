#include "search.h"


int Binary_Search(int * a, int n, int key) {
    int low, high, mid;

    low = 1;
    high = n;

    while (low <= high) {
        mid = low + (high-low) * (key - a[low])/(a[high] - a[low]);
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return 0;
}


int Fibonacci_Search(int * a, int n, int key) {
    int low, high, mid, i, k;
    low = 1;
    high = n;
    k = 0;

    // calculate n position in F
    while (n > F[k] - 1) {
        k++;
    }

    for (i = n; n < F[k] - 1; i++) {
        a[i] = a[n];
    }

    while (low <= high) {
        mid = low + F[k-1] -1;

        if (key < a[mid]) {
            high = mid -1;
            k = k - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
            k = k - 2;
        } else {
            if (mid <= n) {
                return mid;
            } else {
                return n;
            }
        }
    }

    return 0;


}

bool SearchBST(BiTree T, ElemType key, BiTree f, BiTNode * p) {
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


bool InsertBST(BiTree T, ElemType key) {
    BiTNode * p, *s;

    if (!SearchBST(T, key, NULL, p)) {
        s = (BiTNode *) malloc(sizeof(BiTNode));
        s->lchild = s->rchild = NULL;
        s->data = key;

        if (!p) {
            T = s;
        } else if (key < p->data) {
            p->lchild = s;
        } else {
            p->rchild = s;
        }
        return true;
    } else {
        return false;
    }


}

bool DeleteBST(BiTree t, ElemType key) {
    if (!t) {
        return false;
    } else {
        if (key == t->data) {
            return Delete(t);
        } else if (key < t->data) {
            return DeleteBST(t->lchild, key);
        } else {
            return DeleteBST(t->rchild, key);
        }
    }
}

bool Delete(BiTNode * p) {
    BiTNode *q, *s;

    if (p->lchild == NULL) {
        q = p;
        p = p->rchild;
        free(q);
    } else if (p->rchild == NULL) {
        q = p;
        p = p -> lchild;
        free(q);
    } else {
        q = p;
        s = p -> lchild;
        while (s -> rchild) {
            q = s;
            s = s ->rchild;
        }

        p -> data = s -> data;

        if (q != p) {
            q -> rchild = s -> lchild;
        } else {
            q -> lchild = s -> lchild;
        }

        free(s);
    }

    return true;
}