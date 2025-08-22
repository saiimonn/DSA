//August 19, 2025 --- Delete all occurences of char x 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
} charList;

//time complexity: O(n)
void deleteAllOccur(charList *L, char x) {
    if(L->count != 0) {
        int j, e = 0;
        for(j = 0; j < L->count; j++) {
            if(L->elem[j] != x) {
                L->elem[e++] = L->elem[j];
            }
        }
        L->count = e;
    }
}

//time complexity: O(n^2)
void deleteAllOccurrences(charList *L, char x) {
    if(L->count != 0) {
        int i, j;
        for(i = 0; i < L->count; i++) {
            if(L->elem[i] == x) {
                L->count--;
                for(j = i; j < L->count; j++) {
                    L->elem[j] = L->elem[j + 1];
                }
                i--;
            }
        }
    }
}

void read(charList L) {
    if(L.count != 0) {
        int i;
        for(i = 0; i < L.count; i++) printf("%c ", L.elem[i]);
    }
}

int main(){
    charList L = {"usccebuc", 8};

    deleteAllOccurrences(&L, 'c');
    read(L);
}