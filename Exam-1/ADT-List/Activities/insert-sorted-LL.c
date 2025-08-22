//August 19, 2025 --- insert data from the LL while keeping it sorted.
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList;

void insertSorted(charList *L, char x) {
    charList *ptr;
    for(ptr = L; *ptr != NULL && (*ptr)->elem < x; ptr = &(*ptr)->link) {}
    charList newNode = (charList)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->elem = x;
        newNode->link = *ptr;
        *ptr = newNode;
    }
}

void read(charList L) {
    if(L != NULL) {
        charList ptr;
        for(ptr = L; ptr != NULL; ptr = ptr->link) printf("%c -> ", ptr->elem);
        printf("NULL ");
    }
}

int main() {
    charList L = NULL;

    insertSorted(&L, 'f');
    insertSorted(&L, 'd');
    insertSorted(&L, 'e');
    insertSorted(&L, 'a');
    insertSorted(&L, 'j');

    read(L);
}