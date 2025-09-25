#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef int Dictionary[MAX];

typedef enum { EMPTY, DELETED } status;

void initDict(Dictionary);
int hash(int);
void insert(Dictionary, int);
void delete(Dictionary, int);
bool isMember(Dictionary, int);
void printDict(Dictionary);

int main() {
    Dictionary D;
    initDict(D);

    insert(D, 42);
    insert(D, 18);
    insert(D, 94);
    insert(D, 47);
    insert(D, 10);
    insert(D, 48);
    insert(D, 58);

    printDict(D);

    delete(D, 42);
    delete(D, 10);
    delete(D, 58);

    printDict(D);

    insert(D, 42);
    printDict(D);
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

    for(; D[idx] != EMPTY && D[idx] != DELETED; idx = (idx + 1) % MAX) {}
    D[idx] = x;
}

void delete(Dictionary D, int x) {
    int idx = hash(x);

    int stop = (idx + MAX - 1) % MAX;
    int i;
    for(i = idx; i != stop && D[i] != EMPTY && D[i] != x; i = (i + 1) % MAX) {}

    if(D[i] == x) {
        D[i] = DELETED;
    }
}

bool isMember(Dictionary D, int x) {
    int idx = hash(x);

    int stop = (idx + MAX - 1) % MAX;
    int i;
    for(i = idx; i != stop && D[i] != EMPTY && D[i] != x; i = (i + 1) % MAX) {}

    return (D[i] == x) ? true : false;
}

void printDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        if(D[i] == EMPTY) {
            printf("[%d] - EMPTY", i);
        } else if(D[i] == DELETED) {
            printf("[%d] - DELETED", i);
        } else {
            printf("[%d] - %d", i, D[i]);
        }
        printf("\n");
    }
    printf("\n");
}