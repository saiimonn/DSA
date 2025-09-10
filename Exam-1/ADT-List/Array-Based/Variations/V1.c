#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char data[MAX];
    int count;
} List;

void initialize(List *);
void insertFirst(List *, char);
void insertLast(List *, char);
void insertSorted(List *, char);
void deleteOnce(List *, char );
void deleteAllOccur(List *, char);
void read(List);

int main() {
    List L;
    initialize(&L);

    insertLast(&L, 'A');
    insertLast(&L, 'B');
    insertFirst(&L, 'C');
    insertSorted(&L, 'D');

    printf("After insertions: ");
    read(L);

    deleteOnce(&L, 'B');
    printf("After deleting B once: ");
    read(L);

    insertLast(&L, 'C');
    insertLast(&L, 'C');
    deleteAllOccur(&L, 'C');
    printf("After deleting all C: ");
    read(L);

    return 0;
}

void initialize(List *L) {
    L->count = 0;
}

void insertFirst(List *L, char x) {
    if(L->count != MAX) {
        int i;
        for(i = L->count; i > 0; i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[0] = x;
        L->count++;
    }
}

void insertLast(List *L, char x) {
    if(L->count != MAX) {
        L->data[L->count++] = x;
    }
}

void insertSorted(List *L, char x) {
    if(L->count != MAX) {
        int i;
        for(i = L->count - 1; i >= 0 && L->data[i] > x; L->data[i + 1] = L->data[i], i--){}
        L->data[i + 1] = x;
        L->count++;
    }
}

void deleteOnce(List *L, char x) {
    if(L->count != 0) {
        int idx;
        for(idx = 0; idx < L->count && L->data[idx] != x; idx++) {}

        if(idx != L->count) {
            L->count--;
            int i;
            for(i = idx; i < L->count; L->data[i] = L->data[i + 1], i++) {}
        }
    }
}

void deleteAllOccur(List *L, char x) {
    if(L->count != 0) {
        int i, e = 0;
        for(i = 0; i < L->count; i++) {
            if(L->data[i] != x) {
                L->data[e++] = L->data[i];
            }
        }
        L->count = e;
    }
}

void read(List L) {
    if(L.count != 0) {
        int i;
        for(i = 0; i < L.count; i++) printf("%c ", L.data[i]);
        printf("\n");
    }
}