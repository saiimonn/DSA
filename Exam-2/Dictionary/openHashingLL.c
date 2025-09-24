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
void delete(Dictionary, int);
void printDict(Dictionary);

int main() {
    Dictionary D;
    initDict(D);

    insert(D, 15);
    insert(D, 25);
    insert(D, 35);
    insert(D, 7);
    insert(D, 17);
    insert(D, 27);

    printDict(D);

    delete(D, 7);
    delete(D, 25);

    printDict(D);

    return 0;
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

    List *trav;
    for(trav = &D[idx]; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->next) {}

    if(*trav == NULL) {
        List newNode = (List)malloc(sizeof(LL));
        if(newNode != NULL) {
            newNode->elem = x;
            newNode->next = NULL;
            *trav = newNode;   
        }
    }
}

void delete(Dictionary D, int x) {
    int idx = hash(x);

    List *trav;
    for(trav = &D[idx]; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->next) {}

    if(*trav != NULL) {
        List temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void printDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        printf("[%d] -> ", i);
        List trav = D[i];
        for(; trav != NULL; trav = trav->next) printf("%d -> ", trav->elem);
        printf("NULL\n");
    }
    printf("\n");
}