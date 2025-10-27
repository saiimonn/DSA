#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Set;

typedef struct {
    int data;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAX];
    int avail;
} Vheap;

void initVH(Vheap *);
void insert(Vheap *, Set *, int);
void delete(Vheap *, Set *, int);
void read(Vheap, Set);

int allocSpace(Vheap *);
void deallocSpace(Vheap *, int);

Set Union(Set, Set, Vheap *);
Set Intersection(Set, Set, Vheap *);
Set Difference(Set, Set, Vheap *);

int main() {
    Vheap VH;
    initVH(&VH);

    Set A = -1;
    Set B = -1;

    insert(&VH, &A, 32);
    insert(&VH, &A, 51);
    insert(&VH, &A, 12);
    insert(&VH, &A, 67);
    insert(&VH, &A, 29);

    insert(&VH, &B, 13);
    insert(&VH, &B, 3);
    insert(&VH, &B, 10);

    read(VH, A);
    read(VH, B);

    Set U = Union(A, B, &VH);
    read(VH, U);
}

void initVH(Vheap *VH) {
    VH->avail = 0;
    int i;

    for(i = 0; i < MAX - 1; i++) {
        VH->nodes[i].link = i + 1;
    }
    VH->nodes[i].link = -1;
}

int allocSpace(Vheap *VH) {
    int idx = VH->avail;

    if(idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }
    return idx;
}

void deallocSpace(Vheap *VH, int idx) {
    if(idx >= 0 && idx < MAX) {
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void insert(Vheap *VH, Set *S, int x) {
    Set *trav;

    for(trav = S; *trav != -1 && VH->nodes[*trav].data != x; trav = &VH->nodes[*trav].link) {}

    if(*trav == -1) {
        Set temp = allocSpace(VH);

        if(temp != -1) {
            VH->nodes[temp].data = x;
            VH->nodes[temp].link = -1;
            *trav = temp;
        }
    }
}

void delete(Vheap *VH, Set *S, int x) {
    Set *trav;

    for(trav = S; *trav != -1 && VH->nodes[*trav].data != x; trav = &VH->nodes[*trav].link) {}

    if(*trav != -1) {
        Set temp = *trav;
        *trav = VH->nodes[temp].link;
        deallocSpace(VH, x);
    }
}

void read(Vheap VH, Set S) {
    for(Set curr = S; curr != -1; curr = VH.nodes[curr].link) printf("%d -> ", VH.nodes[curr].data);
    printf("NULL\n");
}

Set Union(Set A, Set B, Vheap *VH) {
    Set C = -1;
    Set *trav = &C;

    for(Set curr = A; curr != -1; curr = VH->nodes[curr].link) {
        Set idx = allocSpace(VH);

        if(idx != -1) {
            VH->nodes[idx].data = VH->nodes[curr].data;
            *trav = idx;
            trav = &VH->nodes[idx].link;
        }
    }

    *trav = -1;

    for(Set curr = B; curr != -1; curr = VH->nodes[curr].link) {
        insert(VH, &C, VH->nodes[curr].data);
    }

    return C;
}