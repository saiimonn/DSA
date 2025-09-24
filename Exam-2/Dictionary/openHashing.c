#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int elem;
    struct node *next;
} LL, *List;

typedef List Dictionary[MAX];

void initDict(Dictionary);
int hash(int);
void insert(Dictionary, int);

int main() {

}

void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

int hash(int x) {
    return x % 10;
}

void insert(Dictionary D, int x) {
    int idx = hash(x);

    
}