#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList;

void insertLast(charList *L, char x) {
    charList *ptr;
    for(ptr = L; *ptr != NULL; ptr = &(*ptr)->link) {}

    charList newNode = (charList)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->elem = x;
        newNode->link = *ptr;
        *ptr = newNode;
    }
}

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

void insertFirst(charList *L, char x) {
    charList newNode = (charList)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->elem = x;
        newNode->link = *L;
        *L = newNode;
    }
}

void read(charList ptr) {
    for(; ptr != NULL; ptr = ptr->link) printf("%c -> ", ptr->elem);
    printf("NULL");
}

int main() {
    charList list;

    insertFirst(&list, 'x');
    insertLast(&list, 'v');
    insertFirst(&list, 's');
    insertLast(&list, 'u');
    insertSorted(&list, 'i');

    read(list);
}