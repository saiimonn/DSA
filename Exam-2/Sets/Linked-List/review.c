#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *SET;

void insert(SET *, int);
void delete(SET *, int);
void read(SET);
SET Union(SET, SET);
SET Intersection(SET, SET);
SET Difference(SET, SET);

int main() {
    SET A = NULL;
    SET B = NULL;
    
    insert(&A, 4);
    insert(&A, 7);
    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 7);
    insert(&A, 3); 
    read(A);

    insert(&B, 4);
    insert(&B, 8);
    insert(&B, 9);
    insert(&B, 1);
    insert(&B, 10);
    read(B);

    SET U = Union(A, B);
    printf("========== UNION ===========\n");
    read(U);

    SET I = Intersection(A, B);
    printf("========== INTERSECTION ==========\n");
    read(I);

    SET D = Difference(A, B);
    printf("========== DIFFERENCE ==========\n");
    read(D);
}

void insert(SET *S, int x) {
    SET check;

    for(check = *S; check != NULL && check->data != x; check = check->link) {}

    if(check != NULL && check->data == x) {
        printf("Already in the set\n");
    } else {
        SET *trav;
        for(trav = S; *trav != NULL && (*trav)->data < x && (*trav)->data != x; trav = &(*trav)->link) {}

        SET newNode = (SET)malloc(sizeof(struct node));
        if(newNode != NULL) {
            newNode->data = x;
            newNode->link = (*trav);
            *trav = newNode;
        }
    }
}

void delete(SET *S, int x) {
    SET check;
    for(check = *S; check != NULL && check->data != x; check = check->link) {}

    if(check != NULL && check->data == x) {
        SET *trav;
        for(trav = S; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link) {}

        SET temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void read(SET S) {
    for(; S != NULL; S = S->link) printf("%d -> ", S->data);
    printf("NULL\n");
}

SET Union(SET A, SET B) {
    SET C = NULL;
    SET *cPtr = &C;

    while(A != NULL && B != NULL) {
        *cPtr = (SET)malloc(sizeof(struct node));
        if(A->data < B->data) {
            (*cPtr)->data = A->data;
            A = A->link;
        } else if(B->data < A->data) {
            (*cPtr)->data = B->data;
            B = B->link;
        } else {
            (*cPtr)->data = A->data;
            A = A->link;
            B = B->link;
        }
        (*cPtr)->link = NULL;
        cPtr = &(*cPtr)->link;
    }

    SET D = (A == NULL) ? B : A;
    while(D != NULL) {
        *cPtr = (SET)malloc(sizeof(struct node));
		(*cPtr)->data = D->data;
		(*cPtr)->link = NULL;
		cPtr = &(*cPtr)->link;
		D = D->link;
    }

    return C;
}

SET Intersection(SET A, SET B) {
    SET C = NULL;
    SET *cPtr = &C;

    while(A != NULL && B != NULL) {
        if(A->data == B->data) {
            *cPtr = (SET)malloc(sizeof(struct node));
            (*cPtr)->data = A->data;
            (*cPtr)->link = NULL;
            cPtr = &(*cPtr)->link;

            A = A->link;
            B = B->link;
        } else if(A->data < B->data) {
            A = A->link;
        } else {
            B = B->link;
        }
    }
    return C;
}

SET Difference(SET A, SET B) {
    SET C = NULL;
    SET *cPtr = &C;

    while(A != NULL && B != NULL) {
        if(A->data < B->data) {
            *cPtr = (SET)malloc(sizeof(struct node));
            (*cPtr)->data = A->data;
            (*cPtr)->link = NULL;
            cPtr = &(*cPtr)->link;

            A = A->link;
        } else if(B->data < A->data) {
            B = B->link;
        } else {
            A = A->link;
            B = B->link;
        }
    }

    while(A != NULL) {
        *cPtr = (SET)malloc(sizeof(struct node));
		(*cPtr)->data = A->data;
		(*cPtr)->link = NULL;
		cPtr = &(*cPtr)->link;
		A = A->link;
    }
    return C;
}