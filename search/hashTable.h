#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASHSIZE 12
#define NULLKEY -32768

typedef int ElemType;
int m;

typedef struct {
    int * elem;
    int count;
} HashTable;

void InitHashTable(HashTable * H);
int Hash(ElemType key);
void InsertHash(HashTable * H, int key);
bool SearchHash(HashTable * H, int key, int * addr);