#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
    char data;
    int link;
} Nodetype;

typedef struct {
    Nodetype Nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

void initializeVHV1(VirtualHeap *VH) {
    int A, max = MAX - 1;
    VH->avail = 0;
    for(A = VH->avail; A < max; A++) {
        VH->Nodes[A].link = A + 1;
    }
    VH->Nodes[A].link = -1;
}

void initializeVHV2(VirtualHeap *VH) {
    VH->avail = MAX - 1;
    int A;
    for(A = VH->avail; A >= 0; A--) {
        VH->Nodes[A].link = A - 1;
    }
}

void initList(List *L) {
    *L = -1;
}

int main() {
    VirtualHeap VH;
    List L;

    initializeVHV2(&VH);
    initList(&L);
}