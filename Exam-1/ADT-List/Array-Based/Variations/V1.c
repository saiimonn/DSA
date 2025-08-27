#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int count;
} List;

void initialize(List *);

int main() {
    List L;
    initialize(&L);
}

void initialize(List *L) {
    L->count = 0;
}