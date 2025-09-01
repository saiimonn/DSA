#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int *elemPtr;
    int count;
    int arrSize;
} *List;

void initialize(List *);
void resize(List *);
void insertFirst(List *, int);
void insertLast(List *, int);
void insertSorted(List *, int);
void deleteElem(List *, int);
void deleteAllOccur(List *, int);
void read(List);

int main() {
    List L;
    initialize(&L);

    insertLast(&L, 322);
    insertFirst(&L, 141);
    insertLast(&L, 324);
    insertSorted(&L, 333);
    insertSorted(&L, 100);
    insertSorted(&L, 150);

    deleteElem(&L, 100);
    deleteAllOccur(&L, 322);

    read(L);
}

void initialize(List *L) {
    (*L) = (List)malloc(sizeof(struct node));
    if((*L) != NULL) {
        (*L)->count = 0;
        (*L)->arrSize = 4;
        (*L)->elemPtr = (int*)malloc(sizeof(int) * 4);
    }
}

void resize(List *L) {
    (*L)->arrSize *= 2;
    (*L)->elemPtr = realloc((*L)->elemPtr, (*L)->arrSize * sizeof(int));
}

void insertFirst(List *L, int x) {
    if((*L)->count == (*L)->arrSize) {
        resize(L);
    }

    int i;
    for(i = (*L)->count; i > 0; (*L)->elemPtr[i] = (*L)->elemPtr[i - 1], i--) {}
    (*L)->elemPtr[0] = x;
    (*L)->count++;
}

void insertLast(List *L, int x) {
    if((*L)->count == (*L)->arrSize) {
        resize(L);
    }

    (*L)->elemPtr[(*L)->count++] = x;
}

void insertSorted(List *L, int x) {
    if((*L)->count == (*L)->arrSize) {
        resize(L);
    }

    int i;
    for(i = (*L)->count - 1; i >= 0 && (*L)->elemPtr[i] > x; (*L)->elemPtr[i + 1] = (*L)->elemPtr[i], i--) {}

    (*L)->elemPtr[i + 1] = x;
    (*L)->count++;
}

void deleteElem(List *L, int x) {
    if((*L)->count != 0) {
        int idx;
        for(idx = 0; idx < (*L)->count && (*L)->elemPtr[idx] != x; idx++) {}

        if(idx < (*L)->count) {
            (*L)->count--;
            int i;
            for(i = idx; i < (*L)->count; (*L)->elemPtr[i] = (*L)->elemPtr[i + 1], i++) {}
        }
    }
}

void deleteAllOccur(List *L, int x) {
    if((*L)->count != 0) {
        int i, e = 0;
        for(i = 0; i < (*L)->count; i++) {
            if((*L)->elemPtr[i] != x) {
                (*L)->elemPtr[e++] = (*L)->elemPtr[i];
            }
        }
        (*L)->count = e;
    }
}

void read(List L) {
    if(L->count != 0) {
        int i;
        for(i = 0; i < L->count; i++) printf("%d ", L->elemPtr[i]);
        printf("\n");
    }
}