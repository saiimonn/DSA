#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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
    int max = MAX - 1, a;
    for(a = 0; a < max; a++) {
        VH->nodes[a].link = a + 1;
    }
    VH->nodes[a].link = -1;
}

void initializeList(List *L) {
    *L = -1;
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;
    if(idx != -1) {
        VH->avail = VH->nodes[idx].link;
        return idx;
    }
}

void deallocSpace(VirtualHeap *VH, int idx) {
    if(idx >= 0 && idx < MAX) {
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void deleteElem(VirtualHeap *VH, List *L, char elem) {
    if(*L != -1) {
        List *i;
        for(i = L; *i != -1 && VH->nodes[*i].elem != elem; i = &(VH->nodes[*i].link)) {}
        if(*i != -1) {
            List temp = *i;
            *i = VH->nodes[*i].link; //links to the deleted nodes' link
            deallocSpace(VH, temp);
        }
    }
}

void insertFirst(VirtualHeap *VH, List *L, char elem) {
    int new = allocSpace(VH);
    if(new != -1) {
        VH->nodes[new].elem = elem;
        VH->nodes[new].link = *L;
        *L = new;
    }
}

void read(VirtualHeap VH, List L) {
    if(L != -1) {
        for(; L != -1; L = VH.nodes[L].link) printf("%c -> ", VH.nodes[L].elem);
        printf("NULL ");
    }
}

int main() {
    VirtualHeap VH;
    initializeVH(&VH);

    List L;
    initializeList(&L);

    insertFirst(&VH, &L, 'a');
    insertFirst(&VH, &L, 'x');
    insertFirst(&VH, &L, 'h');
    insertFirst(&VH, &L, 't');
    insertFirst(&VH, &L, 'u');
    insertFirst(&VH, &L, 'q');

    read(VH, L);

    deleteElem(&VH, &L, 'q');
    deleteElem(&VH, &L, 'a');
    deleteElem(&VH, &L, 'h');
}