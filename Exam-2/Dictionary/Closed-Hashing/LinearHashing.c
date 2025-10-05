#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int Dictionary[MAX];

typedef enum { EMPTY = -1, DELETED = -2} status;

void initDict(Dictionary);
int hash(int);
void insert(Dictionary, int);
void delete(Dictionary, int);
int isMember(Dictionary, int);
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
    insert(D, -4);
    printDict(D);
}

void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

int hash(int x) {
    return abs(x % 10);
}

void insert(Dictionary D, int x) {
    if(isMember(D, x) == -10) {
        int idx = hash(x), deletedPos = -3;
        int i;
        for(i = 0; i < MAX && D[idx] != EMPTY; idx = (idx + 1) % MAX, i++) {
            if(deletedPos == -3 && D[idx] == DELETED) {
                deletedPos = idx;
            }
        }

        if(i != MAX) {
            D[idx] = x;
        } else if(deletedPos != -3) {
            D[deletedPos] = x;
        }
    }
}

void delete(Dictionary D, int x) {
    int idx = isMember(D, x);
    if(idx != -10) {
        D[idx] = DELETED;
    } else {
        printf("Not there");
    }
}

int isMember(Dictionary D, int x) {
    int idx = hash(x);
    int start = hash(x);

    bool isFull = false;
    while(!isFull && D[idx] != x && D[idx] != EMPTY) {
        idx = (idx + 1) % MAX;
        if(idx == start) {
            isFull = true;
        }
    }

    return (D[idx] == x) ? idx : -10;
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