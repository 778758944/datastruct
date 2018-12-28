#include "hashTable.h"

void InitHashTable(HashTable * H) {
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (ElemType *) malloc(sizeof(ElemType) * m);

    for (i = 0; i < m; i++) {
        H->elem[i] = NULLKEY;
    }
}


int Hash(ElemType key) {
    return ((int) key) % m;
}

void InsertHash(HashTable * H, int key) {
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY) {
        addr = (addr+1) % m;
    }

    H->elem[addr] = key;
}

bool SearchHash(HashTable * H, int key, int * addr) {
    *addr = Hash(key);

    while (H->elem[*addr] != key) {
        *addr = (*addr+1) % m;

        if (H->elem[*addr] == NULLKEY || *addr == Hash(key)) {
            return false;
        }
    }

    return true;
}



