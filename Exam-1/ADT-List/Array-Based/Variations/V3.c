#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//List is a struct with variables count and arrSize, a pointer of the first elem of a dynamically allocated array.
typedef struct {
    int *elemPtr;
    int count;
    int arrSize;
} List;

void initialize(List *);
void resize(List *);
void insertFirst(List *, int);
void insertLast(List *, int);
void insertSorted(List *, int);
void deleteElem(List *, int);
void deleteAllOccur(List *, int);
void read(List);

void read(List);

int main() {
    List L;

    initialize(&L);

    insertSorted(&L, 123);
    insertSorted(&L, 134);
    insertSorted(&L, 14);
    insertSorted(&L, 133);
    insertSorted(&L, 315);
    insertSorted(&L, 315);

    deleteElem(&L, 133);
    deleteAllOccur(&L, 315);

    read(L);
}

void initialize(List *L) {
    L->elemPtr = (int*)malloc(sizeof(int) * 4);
    L->count = 0;
    L->arrSize = 4;
}

void resize(List *L) {
    L->arrSize *= 2;
    L->elemPtr = realloc(L->elemPtr, L->arrSize * sizeof(int));
}

void insertFirst(List *L, int x) {
    if(L->count == L->arrSize) {
        resize(L);
    }

    int i;
    for(i = L->count; i > 0; L->elemPtr[i] = L->elemPtr[i - 1], i--) {}
    L->elemPtr[0] = x;
    L->count++;

    printf("elem: %d - count: %d - arrSize: %d\n", L->elemPtr[0], L->count, L->arrSize);
}

void insertLast(List *L, int x) {
    if(L->count == L->arrSize) {
        resize(L);
    }

    L->elemPtr[L->count++] = x;
    printf("elem: %d - count: %d - arrSize: %d\n", L->elemPtr[L->count - 1], L->count, L->arrSize);
}

void insertSorted(List *L, int x) {
    if(L->count == L->arrSize) {
        resize(L);
    }

    int i;
    for(i = L->count - 1; i >= 0 && L->elemPtr[i] > x; L->elemPtr[i + 1] = L->elemPtr[i], i--) {}
    L->elemPtr[i + 1] = x;
    L->count++;

    printf("elem: %d - count: %d - arrSize: %d\n", L->elemPtr[i + 1], L->count, L->arrSize);
}

void deleteElem(List *L, int x) {
    if(L->count != 0) {
        int idx;
        for(idx = 0; idx < L->count && L->elemPtr[idx] != x; idx++) {}

        if(idx < L->count) {
            L->count--;
            int i;
            for(i = idx; i < L->count; L->elemPtr[i] = L->elemPtr[i + 1] ,i++) {}
        }
    }
}

void deleteAllOccur(List *L, int x) {
    if(L->count != 0) {
        int i, e = 0;
        for(i = 0; i < L->count; i++) {
            if(L->elemPtr[i] != x) {
                L->elemPtr[e++] = L->elemPtr[i];
            }
        }
        L->count = e;
    }
}

void read(List L) {
    if(L.count != 0) {
        int i;
        for(i = 0; i < L.count; i++) printf("%d ", L.elemPtr[i]);
        printf("\n");
    }
}