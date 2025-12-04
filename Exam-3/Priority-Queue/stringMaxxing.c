#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25
#define MAX_STR 100

typedef struct {
    char words[MAX][MAX_STR];
    int lastIdx;
} Heap;

void initialize(Heap *H) {
    H->lastIdx = -1;
}

void insert(Heap *H, char *name) {
    if(H->lastIdx + 1 < MAX) {
        strcpy(H->words[++H->lastIdx], name);
        int child = H->lastIdx;
        int parent = (child - 1) / 2;

        while(child > 0 && strcmp(H->words[parent], H->words[child]) > 0) {
            char temp[MAX_STR];
            strcpy(temp, H->words[parent]);
            strcpy(H->words[parent], H->words[child]);
            strcpy(H->words[child], temp);

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

void display(Heap H) {
    for(int i = 0; i <= H.lastIdx; i++) {
        printf(" %s\n", H.words[i]);
    }
}

int main() {
    Heap H;
    initialize(&H);

    insert(&H, "serendipity");
    insert(&H, "petrichor");
    insert(&H, "supine");
    insert(&H, "solitude");
    insert(&H, "aurora");
    insert(&H, "idyllic");
    insert(&H, "clinomania");
    insert(&H, "pluviophile");
    insert(&H, "euphoria");
    insert(&H, "sequoia");
    insert(&H, "sumptuous");
    insert(&H, "angst");
    insert(&H, "nadir");
    insert(&H, "lassir");
    insert(&H, "mellifluous");
    insert(&H, "languor");

    display(H);
}