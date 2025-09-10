#include <stdbool.h>
#include <stdlib.h>
#ifndef STACK_CURSOR_H
#define STACK_CURSOR_H
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

int allocSpace(VirtualHeap *VH) {
    int new = VH->avail;
    if(new != -1) {
        VH->avail = VH->nodes[new].link;
    }
    return new;
}

void deallocSpace(VirtualHeap *VH, int x) {
    if(x >= 0 && x < MAX) {
        VH->nodes[x].link = VH->avail;
        VH->avail = x;
    }
}

bool emptyStack(Stack S) {
    return (S == -1) ? true : false;
}

bool fullStack(VirtualHeap VH) {
    return (VH.avail == -1) ? true : false;
}

void pushCB(VirtualHeap *VH, Stack *S, char x) {
    if(!fullStack(*VH)) {
        int new = allocSpace(VH);
        if(new != -1) {
            VH->nodes[new].elem = x;
            VH->nodes[new].link = *S;
            *S = new;
        }
    }
}

void popCB(VirtualHeap *VH, Stack *S) {
    if(!emptyStack(*S)) {
        int temp = *S;
        *S = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

int topCB(VirtualHeap VH, Stack S) {
    if(!emptyStack(S)) {
        return VH.nodes[S].elem;
    }
    return -1;
}

void readCB(VirtualHeap VH, Stack S) {
    while(!emptyStack(S)) {
        printf("|  %c  |\n", VH.nodes[S].elem);
        popCB(&VH, &S);
    }
}




#endif