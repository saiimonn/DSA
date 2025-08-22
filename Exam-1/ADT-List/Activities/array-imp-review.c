//Aug 12, 2025
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char elem[SIZE];
    int count;
} charList;

void print(charList L) {
    if(L.count == 0) {
        return;
    }

    for(int i = 0; i < L.count; i++) printf("%c ", L.elem[i]);
    printf("\n");
}

void deleteOnce(charList *L, char x) {
    if(L->count == 0) {
        printf("empty\n");
    } else {
        int idx;
        for(idx = 0; idx < L->count && L->elem[idx] != x; idx++) {}

        if(idx != L->count) {
            for(int j = idx; j < L->count; L->elem[j] = L->elem[j + 1], j++) {}
            L->count--;
        } else {
            printf("Not found\n");
        }
    }
}

int main() {
    charList L = {"uscp", 4};
    
    deleteOnce(&L, 'u'); //delete first
    print(L);
    deleteOnce(&L, 'f'); //not found
    deleteOnce(&L, 'c'); //delete middle
    print(L);
    deleteOnce(&L, 'p'); //delete last
    print(L);
    
    deleteOnce(&L, 's');
    
    deleteOnce(&L, 'x'); //empty
    print(L);
    
    charList empty;
}