#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAX];
    int avail;
} VirtualHeap;

typedef int Stack;

void initVH(VirtualHeap *);
void initStack(Stack *); 
int allocSpace(VirtualHeap *);
void deallocSpace(VirtualHeap *, int);

bool empty(Stack);
bool full(VirtualHeap);

void push(VirtualHeap *, Stack *, char);
void pop(VirtualHeap *, Stack *);
int top(VirtualHeap, Stack);
void read(VirtualHeap, Stack);

int main() {
    VirtualHeap VH;
    initVH(&VH);

    Stack S;
    initStack(&S);

    push(&VH, &S, 'M');
    push(&VH, &S, 'S');
    push(&VH, &S, 'I');
    push(&VH, &S, 'C');
    push(&VH, &S, 'D');

    read(VH, S);
}

//-------------- Initialization -----------------------

void initVH(VirtualHeap *VH) {
    VH->avail = 0;
    int i;
    for(i = 0; i < MAX - 1; i++) {
        VH->nodes[i].link = i + 1;
    }
    VH->nodes[i].link = -1;
}

void initStack(Stack *S) {
    *S = -1;
}

//-----------------------------------------------------

bool empty(Stack S) {
    return (S == -1) ? true : false;
}

bool full(VirtualHeap VH) {
    return (VH.avail == -1) ? true : false;
}

// ------------- INSERTION / DELETION -----------------

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;
    if(idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }
    return idx;
}

void deallocSpace(VirtualHeap *VH, int idx) {
    if(idx >= 0 && idx < MAX ) {
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void push(VirtualHeap *VH, Stack *S, char x) {
    if(!full(*VH)) {
        int new = allocSpace(VH);
        if(new != -1) {
            VH->nodes[new].elem = x;
            VH->nodes[new].link = *S;
            *S = new;
        }
    }
}

void pop(VirtualHeap *VH, Stack *S) {
    if(!empty(*S)) {
        int temp = *S;
        *S = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

// ----------------------------------------------------

int top(VirtualHeap VH, Stack S) {
    if(!empty(S)) {
        return VH.nodes[S].elem;
    }
    return -1;
}

void read(VirtualHeap VH, Stack S) {
    while(!empty(S)) {
        printf("|  %c  |\n", VH.nodes[S].elem);
        pop(&VH, &S);
    }
}