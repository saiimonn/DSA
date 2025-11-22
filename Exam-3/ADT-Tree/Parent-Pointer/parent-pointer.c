/*
    My interpretation of a parent-pointer implementation
    an array of nodes with attributes data and parent.

    - Initialization starts with all nodes' attributes being -2
    - The root node will have a parent of -1
    - The parent of a node will be the index of an existing node (not -2)
*/ 

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum { ROOT = -1, EMPTY = -2 } Status;

typedef struct {
    int data;
    int parent;
} Node;

typedef Node Tree[MAX];

void initialize(Tree);
void insert(Tree, int, int, int);
int leftchild(Tree, int);
int rightsibling(Tree, int);
int parent(Tree, int);

int main() {
    Tree T;
    initialize(T);


}

void initialize(Tree T) {
    for(int i = 0; i < MAX; i++) {
        T[i].data = EMPTY;
        T[i].parent = EMPTY;
    }
}

void insert(Tree T, int data, int nodeIdx, int parentIdx) {
    T[nodeIdx].data = data;
    T[nodeIdx].parent = parentIdx;
}

int leftchild(Tree T, int idx) {
    int i;
    int found = 0;
    for(i = 0; i < MAX && !found; i++) {
        if(T[i].parent == idx) {
            found = 1;
        }
    }

    if(found) return i;
}

int rightsibling(Tree T, int idx) {
    int i;
    for(i = idx; i < MAX && T[i].parent != T[idx].parent; i++) {}

    return (i != MAX) ? i : EMPTY;
}

int parent(Tree T, int idx) {
    return T[idx].parent;
}