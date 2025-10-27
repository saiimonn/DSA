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
    Set C = A;
    
    List trav;
    for(trav = B.head; trav != -1; trav = B.nodes[trav].link) {
        if(!isMember(C, B.nodes[trav].data)) {
            insert(&C, B.nodes[trav].data);
        }
    }
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    initSet(&C);

    List trav;
    for(trav = B.head; trav != -1; trav = B.nodes[trav].link) {
        if(isMember(A, B.nodes[trav].data)) {
            insert(&C, B.nodes[trav].data);
        }
    }
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    initSet(&C);

    List trav;
    for(trav = B.head; trav != -1; trav = B.nodes[trav].link) {
        if(!isMember(A, B.nodes[trav].data)) {
            insert(&C, B.nodes[trav].data);
        }
    }
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