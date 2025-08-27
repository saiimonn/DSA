#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//List is a pointer to a struct
typedef struct node {
    int elements[MAX];
    int count;
} *List;

void initialize(List *);
void insertFirst(List *, int);
void insertLast(List *, int);
void insertSorted(List *, int);
void deleteElem(List *, int);
void deleteAllOccur(List *, int);
void read(List);

int main() {
    List L;

    initialize(&L);

    insertLast(&L, 32);
    insertLast(&L, 18);
    insertSorted(&L, 22);
    insertSorted(&L, 33);
    insertSorted(&L, 15);
    insertSorted(&L, 15);

    deleteElem(&L, 22);
    deleteAllOccur(&L, 15);

    read(L);
}

void initialize(List *L) {
    (*L) = (List)malloc(sizeof(struct node));
    if((*L) != NULL) {
        (*L)->count = 0;
    }
}

void insertFirst(List *L, int x) {
    if((*L)->count != MAX) {
        int i;
        for(i = (*L)->count; i >= 0; i--) {
            (*L)->elements[i] = (*L)->elements[i - 1];
        }
        (*L)->elements[0] = x;
        (*L)->count++;
    }
}

void insertLast(List *L, int x) {
    if((*L)->count != MAX) {
        (*L)->elements[(*L)->count++] = x;
    }
}

void insertSorted(List *L, int x) {
    if((*L)->count != MAX) {
        int i;
        for(i = (*L)->count - 1; i >= 0 && (*L)->elements[i] > x; (*L)->elements[i + 1] = (*L)->elements[i], i--) {}
        (*L)->elements[i + 1] = x;
        (*L)->count++;
    }
}

void deleteElem(List *L, int x) {
    if((*L)->count != 0) {
        int idx;
        for(idx = 0; idx < (*L)->count && (*L)->elements[idx] != x; idx++) {}
        if(idx != (*L)->count) {
            (*L)->count--;
            int i;
            for(i = idx; i < (*L)->count; i++) {
                (*L)->elements[i] = (*L)->elements[i + 1];
            }
        }
    }
}

void deleteAllOccur(List *L, int x) {
    if((*L)->count != 0) {
        int i, e = 0;
        for(i = 0; i < (*L)->count; i++) {
            if((*L)->elements[i] != x) {
                (*L)->elements[e++] = (*L)->elements[i];
            }
        }
        (*L)->count = e;
    }
}

void read(List L) {
    if(L->count != 0) {
        int i;
        for(i = 0; i < L->count; i++) printf("%d ", L->elements[i]);
        printf("\n");
    }
}