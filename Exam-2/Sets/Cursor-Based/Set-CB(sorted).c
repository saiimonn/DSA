#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int List;

typedef struct {
    int data;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAX];
    int avail;
    List head;
} Set;

void initSet(Set *);
void insert(Set *, int);
void deleteBit(Set *, int);
bool isMember(Set, int);
void read(Set);

int allocSpace(Set *);
void deallocSpace(Set *, int);

Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
    Set A, B;
    initSet(&A);
    initSet(&B);

    // Insert elements into Set A
    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);
    insert(&A, 7);
    insert(&A, 9);

    // Insert elements into Set B
    insert(&B, 2);
    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 7);
    insert(&B, 10);

    printf("Set A: ");
    read(A);

    printf("Set B: ");
    read(B);

    // Test deleteBit
    printf("\nDeleting 5 from Set A...\n");
    deleteBit(&A, 5);
    printf("Set A after deletion: ");
    read(A);

    // Test Union
    Set U = Union(A, B);
    printf("\nUnion of A and B: ");
    read(U);

    // Test Intersection
    Set I = Intersection(A, B);
    printf("Intersection of A and B: ");
    read(I);

    // Test Difference (A - B)
    Set D = Difference(A, B);
    printf("Difference of A - B: ");
    read(D);

    return 0;
}

void initSet(Set *S) {
    S->head = -1;
    S->avail = 0;
    int i;
    for(i = 0; i < MAX - 1; i++) {
        S->nodes[i].link = i + 1;
    }
    S->nodes[i].link = -1;
}

bool isMember(Set S, int x) {
    if(S.head != -1) {
        List trav;
        for(trav = S.head; trav != -1 && S.nodes[trav].data != x; trav = S.nodes[trav].link) {}

        if(trav != -1) return true;
    }
    return false;
}

int allocSpace(Set *S) {
    int idx = S->avail;
    if(idx != -1) {
        S->avail = S->nodes[idx].link;
    }
    return idx;
}

void insert(Set *S, int x) {
    List *trav;
    for(trav = &S->head; *trav != -1 && S->nodes[*trav].data < x && S->nodes[*trav].data != x; trav = &(S->nodes[*trav].link)) {}

    int idx = allocSpace(S);
    if(idx != -1) {
        S->nodes[idx].data = x;
        S->nodes[idx].link = *trav;
        *trav = idx;
    }
}

void deallocSpace(Set *S, int x) {
    if(x >= 0 && x < MAX ) {
        S->nodes[x].link = S->avail;
        S->avail = x;
    }
}

void deleteBit(Set *S, int x) {
    if(S->head != -1) {
        List *trav;
        for(trav = &S->head; *trav != -1 && S->nodes[*trav].data != x; trav = &(S->nodes[*trav].link)) {}

        if(*trav != -1) {
            List temp = *trav;
            *trav = S->nodes[temp].link;
            deallocSpace(S, temp);
        }
    }
}

Set Union(Set A, Set B) {
    Set C;
    initSet(&C);
    
    int i = A.head, j = B.head, cCount = 0;
    while(i != -1 && j != -1) {
        if(A.nodes[i].data < B.nodes[j].data) {
            C.nodes[cCount++].data = A.nodes[i].data;
            i = A.nodes[i].link;
        } else if(B.nodes[j].data < A.nodes[i].data) {
            C.nodes[cCount++].data = B.nodes[j].data;
            j = B.nodes[j].link;
        } else {
            C.nodes[cCount++].data = A.nodes[i].data;
            i = A.nodes[i].link;
            j = B.nodes[j].link;
        }
    }

    Set D = (i == -1) ? B : A;
    int l = (i == -1) ? j : i;

    while(l != -1) {
        C.nodes[cCount++].data = D.nodes[l].data;
        l = D.nodes[l].link;
    }

    //links the nodes in set C
    for(int k = 0; k < cCount - 1; k++) {
        C.nodes[k].link = k + 1;
    }
    C.nodes[cCount - 1].link = -1;
    C.head = 0;
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    initSet(&C);

    int i = A.head, j = B.head, cCount = 0;
    while(i != -1 && j != -1) {
        if(A.nodes[i].data < B.nodes[j].data) {
            i = A.nodes[i].link;
        } else if(B.nodes[j].data < A.nodes[i].data) {
            j = B.nodes[j].link;
        } else {
            C.nodes[cCount++].data = A.nodes[i].data;
            i = A.nodes[i].link;
            j = B.nodes[j].link;
        }
    }

    for(int k = 0; k < cCount - 1; k++) {
        C.nodes[k].link = k + 1;
    }
    C.nodes[cCount - 1].link = -1;
    C.head = 0;
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    initSet(&C);

    int i = A.head, j = B.head, cCount = 0;
    while(i != -1 && j != -1) {
        if(A.nodes[i].data < B.nodes[j].data) {
            C.nodes[cCount++].data = A.nodes[i].data;
            i = A.nodes[i].link;
        } else if(B.nodes[j].data < A.nodes[i].data) {
            C.nodes[cCount++].data = B.nodes[j].data;
            j = B.nodes[j].link;
        } else {
            i = A.nodes[i].link;
            j = B.nodes[j].link;
        }
    }

    Set D = (i == -1) ? B : A;
    int l = (i == -1) ? j : i;

    while(l != -1) {
        C.nodes[cCount++].data = D.nodes[l].data;
        l = D.nodes[l].link;
    }

    for(int k = 0; k < cCount - 1; k++) {
        C.nodes[k].link = k + 1;
    }
    C.nodes[cCount - 1].link = -1;
    C.head = 0;
    return C;
}

void read(Set S) {
    printf("{ ");
    if(S.head != -1) {
        List trav;
        for(trav = S.head; trav != -1; trav = S.nodes[trav].link) printf("%d ", S.nodes[trav].data);
    }
    printf("}\n");
}