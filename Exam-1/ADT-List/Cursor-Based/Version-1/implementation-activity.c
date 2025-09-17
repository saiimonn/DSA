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
    int i, max = MAX - 1;
    for(i = 0; i < max; i++) {
        VH->nodes[i].link = i + 1;
    }
    VH->nodes[i].link = -1;
}

void initList(List *L) {
    *L = -1;
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;
    if(idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }
    return idx;
}

void insertFirst(VirtualHeap *VH, List *L, char x) {
    int idx = allocSpace(VH);
    if(idx != -1) {
        VH->nodes[idx].elem = x;
        VH->nodes[idx].link = *L;
        *L = idx;
    }
}

void insertLast(VirtualHeap *VH, List *L, char x) {
    int idx = allocSpace(VH);
    if(idx != -1) {
        VH->nodes[idx].elem = x;
        VH->nodes[idx].link = -1;
        if(*L == -1) {
            *L = idx;
        } else {
            List *trav;
            for(trav = L; VH->nodes[*trav].link != -1; trav = &(VH->nodes[*trav].link)) {}
            VH->nodes[*trav].link = idx;
        }
    }
}

//new insertSorted
void insertSorted(VirtualHeap *VH, List *L, char x) {
    int idx = allocSpace(VH);
    if(idx != -1) {
        VH->nodes[idx].elem = x;
        VH->nodes[idx].link = -1;
        if(*L == -1 || x <= VH->nodes[*L].elem) {
            VH->nodes[idx].link = *L;
            *L = idx;
        } else {
            List *trav;
            for(trav = L; *trav != -1 && VH->nodes[*trav].elem < x; trav = &(VH->nodes[*trav].link)) {}
            VH->nodes[idx].link = *trav;
            *trav = idx;
        }
    }
}

void deallocSpace(VirtualHeap *VH, int idx) {
    if(idx >= 0 && idx < MAX) {
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void deleteElem(VirtualHeap *VH, List *L, char x) {
    if(*L != -1) {
        List *i;
        for(i = L; *i != -1 && VH->nodes[*i].elem != x; i = &(VH->nodes[*i].link)) {}
        if(*i != -1) {
            List temp = *i;
            *i = VH->nodes[*i].link;
            deallocSpace(VH, temp);
        }
    }
}

void read(VirtualHeap VH, List L) {
    if(L != -1) {
        for(; L != -1; L = VH.nodes[L].link) printf("%c -> ", VH.nodes[L].elem);
        printf("NULL\n");
    }
}

int main() {
    VirtualHeap VH;
    initializeVH(&VH);

    List L;
    initList(&L);

    insertLast(&VH, &L, 'c');
    insertLast(&VH, &L, 'g');
    insertLast(&VH, &L, 'D');
    read(VH, L);
}
