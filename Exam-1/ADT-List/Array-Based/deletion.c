#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char elem[SIZE];
    int count;
} charList;

void deleteOnce(charList *L, char x) {
        int idx;
        for(idx = 0; idx < L->count && L->elem[idx] != x; idx++) {}

        if(idx < L->count) {
            L->count--;
            for(int i = idx; i < L->count; i++) {
                L->elem[i] = L->elem[i + 1];
            }
        }
}

void deleteAllOccur(charList *L, char x) {
    int j, e = 0;
    for(j = 0; j < L->count; j++) {
        if(L->elem[j] != x) {
            L->elem[e++] = L->elem[j];
        }
    }
    L->count = e;
}

int main() {
    charList L = {"uscuscusc", 9};

    deleteAllOccur(&L, 'c');

    printf("%s", L.elem);
}