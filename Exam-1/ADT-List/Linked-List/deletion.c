#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node *link;
} *charList;

bool findElem(charList L, char x) {
    for(; L != NULL & L->elem != x; L = L->link) {}
    return (L != NULL) ? true : false;
}

void delete(charList *L, char x) {
    charList temp, *ptr;
    for(ptr = L; *ptr != NULL && (*ptr)->elem != x; ptr = &(*ptr)->link) {}
    if(*ptr != NULL) {
        temp = *ptr;
        *ptr = temp->link;
        free(temp);
    }
}

void deleteAllOccurrences(charList *L, char x) {
    charList temp, *ptr;
    for(ptr = L; ptr != NULL;) {
        if((*ptr)->elem == x) {
            temp = *ptr;
            *ptr = temp->link;
            free(temp);
        } else {
            ptr = &(*ptr)->link;
        }
    }
}

int main() {
    charList L;
}