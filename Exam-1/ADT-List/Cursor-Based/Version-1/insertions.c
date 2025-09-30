#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
    char elem;
    int link;
} Nodetype;

typedef struct {
    Nodetype nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

void initializeVH(VirtualHeap *VH) {
    VH->avail = 0;
    int max = MAX - 1, i;
    for(i = 0; i < max; i++) {
        VH->nodes[i].link = i + 1;
    }
    VH->nodes[i].link = -1;
}

void initializeList(List *L) {
    *L = -1;
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;
    if(idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }
    return idx;
}

void insertFirst(VirtualHeap *VH, List *L, char elem) {
    int idx = allocSpace(VH);
    if(idx != -1) {
        VH->nodes[idx].elem = elem;
        VH->nodes[idx].link = *L;
        *L = idx;
    }
}

void insertLast(VirtualHeap *VH, List *L, char elem) {
    int idx = allocSpace(VH);
    if(idx != -1) {
        VH->nodes[idx].elem = elem;
        VH->nodes[idx].link = -1;
        List *trav;
        for(trav = L; VH->nodes[*trav].link != -1; trav = &(VH->nodes[*trav].link)) {}
        VH->nodes[*trav].link = idx; //links the last node to the new node
        }
}

void insertSorted(VirtualHeap *VH, List *L, char elem) {
    int idx = allocSpace(VH);
    if(idx != -1) {
        VH->nodes[idx].elem = elem;
        VH->nodes[idx].link = -1;
        if(*L == -1 || elem <= VH->nodes[*L].elem) { // if the list is empty or if the value added is less than the first elem in the list.
            VH->nodes[idx].link = *L;
            *L = idx;
        } else {
            List *trav;
            for(trav = L; *trav != -1 && VH->nodes[*trav].elem < elem; trav = &(VH->nodes[*trav].link)) {}
            VH->nodes[idx].link = *trav;
            *trav = idx;
        }
    }
}

void read(VirtualHeap VH, List L) {
    for(; L != -1; L = VH.nodes[L].link) printf("%c -> ", VH.nodes[L].elem);
    printf("NULL ");
}

int main() {
    VirtualHeap VH;
    initializeVH(&VH);
    List L;
    initializeList(&L);

    insertLast(&VH, &L, 'c');
    insertLast(&VH, &L, 'y');

    read(VH, L);
}