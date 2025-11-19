#include <stdio.h>
#define MAX 15

typedef struct {
    int arr[MAX];
    int count;
} Tree;

typedef enum { EMPTY = -1 } TreeStat;

void initialize(Tree *);
void insert(Tree *, int);
void delete(Tree *, int);
void display(Tree);
int member(Tree, int);
int min(Tree);
int max(Tree);

int main() {
    Tree T;
    initialize(&T);

    insert(&T, 20);
    insert(&T, 5);
    insert(&T, 10);
    insert(&T, 15);

    display(T);
}

void initialize(Tree *T) {
    for(int i = 0; i < MAX; i++) {
        T->arr[i] = EMPTY;
    }
    T->count = 0;
}

void insert(Tree *T, int x) {
    if(T->count < MAX) {
        int idx = 0;
        int lc = idx * 2 + 1;
        int rc = lc + 1;

        while(idx < MAX && T->arr[idx] != EMPTY) {
            if(lc < MAX && x < T->arr[idx]) {
                idx = lc;
            } else if(rc < MAX && x > T->arr[idx]) {
                idx = rc;
            } else {
                break;
            }
            lc = idx * 2 + 1;
            rc = lc + 1;
        }

        T->count++;
        T->arr[idx] = x;
    }
}

void delete(Tree *T, int x) {

}

int member(Tree T, int x) {
    int idx = 0;
    int lc = idx * 2 + 1;
    int rc = lc + 1;

    while(idx < MAX && T.arr[idx] != x) {
        idx = (lc < MAX && x < T.arr[idx]) ? lc : rc;

        lc = idx * 2 + 1;
        rc = lc + 1;
    }

    return (idx < MAX) ? 1 : 0;
}

int min(Tree T) {
    int idx = 0;
    int lc = idx * 2 + 1;

    while(idx < MAX) {
        idx = lc;
        lc = idx * 2 + 1;
    }
    return T.arr[idx];
}

int max(Tree T) {
    int idx = 0;
    int rc = (idx * 2 + 1) + 1;

    while(idx < MAX) {
        idx = rc;
        rc = (idx * 2 + 1) + 1;
    }
    return T.arr[idx];
}

void display(Tree T) {
    for(int i = 0; i < MAX; i++) {
        printf("%d ", T.arr[i]);
    }
}