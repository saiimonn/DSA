#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SET_LL_H
#define SET_LL_H

typedef struct node {
    int elem;
    struct node *link;
} *Set;

void initSet(Set *S) {
    *S = NULL;
}

bool isMember(Set S, int x) {
    if(S != NULL) {
        for(; S != NULL && S->elem != x; S = S->link) {}

        if(S != NULL) return true;
    }
    return false;
}

void insert(Set *S, int x) {
    Set *trav;
    for(trav = S; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link) {}

    if(*trav == NULL) {
        Set newNode = (Set)malloc(sizeof(struct node));
        if(newNode != NULL) {
            newNode->elem = x;
            newNode->link = NULL;
            *trav = newNode;
        }
    }
}

void deleteBit(Set *S, int x) {
    Set *trav;
    for(trav = S; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link) {}

    if(*trav != NULL) {
        Set temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

Set Union(Set A, Set B) {
    Set C;
    Set *cPtr = &C;

    while(A != NULL && B != NULL) {
        *cPtr = (Set)malloc(sizeof(struct node));

        if(A->elem < B->elem) {
            (*cPtr)->elem = A->elem;
            A = A->link;
        } else {
            if(A->elem == B->elem) {
                A = A->link;
            }
            (*cPtr)->elem = B->elem;
            B = B->link;
        }
        (*cPtr)->link = NULL;
        cPtr = &(*cPtr)->link;
    }

    Set D = (A != NULL) ? A : B;
    while(D != NULL) {
        *cPtr = (Set)malloc(sizeof(struct node));

        (*cPtr)->elem = D->elem;
        (*cPtr)->link = NULL;
        cPtr = &(*cPtr)->link;
        D = D->link;
    }

    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    Set *cPtr = &C;

    while(A != NULL && B != NULL) {
        
    }
}

void display(Set S) {
    printf("{ ");
    for(Set print = S; print != NULL; print = print->link) printf("%d ", print->elem);
    printf("}\n");
}

#endif