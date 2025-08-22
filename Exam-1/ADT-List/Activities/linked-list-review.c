//August 14, 2025
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList;

void insertFirst(charList *L, char data) {
    charList newNode = (charList)malloc(sizeof(struct node));
    newNode->elem = data;
    newNode->link = *L;
    *L = newNode;
}

void print(charList L) {
    if(!L) return;

    for(; L != NULL; L = L->link) printf("%c -> ", L->elem);
    printf("NULL\n");
}

void deleteOnce(charList *L, char x) {
    if(!(*L)) {
        printf("empty\n");
    } else {
        charList temp, *ptr;
        for(ptr = L; *ptr != NULL && (*ptr)->elem != x; ptr = &(*ptr)->link) {}
        if(*ptr != NULL) {
            temp = *ptr;
            *ptr = temp->link;
            free(temp);
        } else {
            printf("Not found\n");
        }
    }
}

int main() {
    charList A = NULL;

    deleteOnce(&A, 'a'); //empty

    insertFirst(&A, 'f');
    insertFirst(&A, 'p');
    insertFirst(&A, 's');
    insertFirst(&A, 'u');

    deleteOnce(&A, 'u'); //delete first
    print(A);
    deleteOnce(&A, 'p'); //delete middle
    print(A);
    deleteOnce(&A, 'f'); //delete last
    print(A);

    deleteOnce(&A, 'z'); //not found
}