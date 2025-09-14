#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

typedef struct {
    List top;
    VirtualHeap *VHeap;
} Stack;

void initialize(Stack *);

int allocSpace(Stack *);
void push(Stack *, int);

void deallocSpace(Stack *, int);
void pop(Stack *);

void read(Stack);

int main() {
    Stack S;
    initialize(&S);
}

void initialize(Stack *S) {
    S->top = -1;
    S->VHeap = (VirtualHeap*)malloc(sizeof(VirtualHeap) * MAX);
    if(S->VHeap != NULL) {
        S->VHeap->avail = 0;
        int i;
        for(i = 0; i < MAX - 1; i++) {
            S->VHeap->nodes[i].link = i + 1;
        }
        S->VHeap->nodes[i].link = -1;
    }
}

int allocSpace(Stack *S) {
    int idx = S->VHeap->avail;
    if(idx != -1) {
        S->VHeap->avail = S->VHeap->nodes[idx].link;
    }
    return idx;
}

void push(Stack *S, int x) {
    int idx = allocSpace(S);
    if(idx != -1) {
        
    }
}