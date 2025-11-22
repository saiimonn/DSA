/*
    Parent-Pointer Implementation as described in the book
    an array, the elements of the array is the index of the parent

    - Initialization starts with all nodes with value -2
    - Root node will have element -1
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum { ROOT = -1, EMPTY = -2 };

typedef int Tree[MAX];

void initialize(Tree);
void insert(Tree, int, int);
int leftchild(Tree, int);
int rightsibling(Tree, int);
int parent(Tree, int);

int main() {
    Tree T;
    initialize(T);
}

void initialize(Tree T) {
    int i;
    for(i = 0; i < MAX; i++) {
        T[i] = EMPTY;
    }
}

void insert(Tree T, int nodeIdx, int parentIdx) {
    if(nodeIdx < MAX && nodeIdx >= 0 && T[parentIdx] != EMPTY) {
        T[nodeIdx] = parentIdx;
    }
}

int leftchild(Tree T, int idx) {
    int i;
    int found = 0;
    for(i = idx; i < MAX && !found; i++) {
        if(T[i] == idx) {
            found = 1;
        }
    }

    return(found) ? i : EMPTY;
}

int rightsibling(Tree T, int idx) {
    int i;
    int found = 0;
    for(i = leftchild(T, idx); i < MAX && !found; i++) {
        if(T[i] == idx) {
            found = 1;
        }
    }    
    return (found) ? i : EMPTY;
}

int parent(Tree T, int idx) {
    if(idx < MAX && idx >= 0) {
        return T[idx];
    }
}