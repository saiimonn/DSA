#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Dictionary[MAX];

typedef enum { EMPTY, DELETED } status;

void initDict(Dictionary);
int hash(int);
void insert(Dictionary, int);

int main() {
    Dictionary D;
    initDict(D);
}

void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

int hash(int x) {
    return x % 10;
}

void insert(Dictionary D, int x) {
    int idx = hash(x);

    for(; D[idx] != EMPTY; idx = (idx + 1) % MAX) {}
    D[idx] = x;
}