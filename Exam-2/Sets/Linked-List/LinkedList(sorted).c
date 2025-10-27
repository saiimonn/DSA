/* Write the definition of datatype SET using singly linked list
 * Write the code for each of the following operations assuming sets are sorted
 * 
 * Union
 * Intersection
 * Difference
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int elem;
	struct node *next;
} *SET;

void read(SET);
void insert(SET *, int);
SET Union(SET, SET);
SET Intersection(SET, SET);
SET Difference(SET, SET);

int main() {
	SET A = NULL;
	SET B = NULL;

	// ---------- TEST CASES ----------
	// A = {1, 3, 5, 7, 9}
	insert(&A, 1);
	insert(&A, 3);
	insert(&A, 5);
	insert(&A, 7);
	insert(&A, 9);

	// B = {3, 4, 7, 10}
	insert(&B, 3);
	insert(&B, 4);
	insert(&B, 7);
	insert(&B, 10);

	printf("Set A: ");
	read(A);
	printf("Set B: ");
	read(B);

	// ---------- UNION ----------
	SET U = Union(A, B);
	printf("\nUnion (A ∪ B): ");
	read(U);

	// ---------- INTERSECTION ----------
	SET I = Intersection(A, B);
	printf("Intersection (A ∩ B): ");
	read(I);

	// ---------- DIFFERENCE ----------
	SET D = Difference(A, B);
	printf("Difference (A - B): ");
	read(D);

	return 0;
}

void insert(SET *S, int x) { //fix thi
	SET *trav = S;
	for(; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->next) {}

	if(*trav == NULL) {
		SET newNode = (SET)malloc(sizeof(struct node));
		newNode->elem = x;
		newNode->next = NULL;
		*trav = newNode;
	}
}

void read(SET S) {
	SET trav;
	for(trav = S; trav != NULL; trav = trav->next) printf("%d -> ", trav->elem);
	printf("NULL\n");
}

SET Union(SET A, SET B) {
	SET C = NULL;
	SET *cPtr = &C;

	while(A != NULL && B != NULL) {
		*cPtr = (SET)malloc(sizeof(struct node));
		
		if(A->elem < B->elem) {
			(*cPtr)->elem = A->elem;
			A = A->next;
		} else {
			if(A->elem == B->elem) {
				A = A->next;
			}
			(*cPtr)->elem = B->elem;
			B = B->next;
		}
		(*cPtr)->next = NULL;
		cPtr = &(*cPtr)->next;
	}

	SET D = (A != NULL) ? A : B;
	while(D != NULL) {
		*cPtr = (SET)malloc(sizeof(struct node));
		(*cPtr)->elem = D->elem;
		(*cPtr)->next = NULL;
		cPtr = &(*cPtr)->next;
		D = D->next;
	}

	return C;
}

SET Intersection(SET A, SET B) {
	SET C = NULL;
	SET *cPtr = &C;

	while(A != NULL && B != NULL) {
		if(A->elem == B->elem) {
			*cPtr = (SET)malloc(sizeof(struct node));
			if(cPtr != NULL) {
				(*cPtr)->elem = A->elem;
				(*cPtr)->next = NULL;
				cPtr = &(*cPtr)->next;

				A = A->next;
				B = B->next;
			}
		} else if (A->elem < B->elem) {
			A = A->next;
		} else {
			B = B->next;
		}
	}
	return C;
}

SET Difference(SET A, SET B) {
	SET C = NULL;
	SET *cPtr = &C;

	while(A != NULL && B != NULL) {
		if(A->elem < B->elem) {
			*cPtr = (SET)malloc(sizeof(struct node));
			(*cPtr)->elem = A->elem;
			(*cPtr)->next = NULL;
			cPtr = &(*cPtr)->next;

			A = A->next;
		} else if(A->elem == B->elem) {
			A = A->next;
			B = B->next;
		} else {
			B = B->next;
		}
	}

	while(A != NULL) {
		*cPtr = (SET)malloc(sizeof(struct node));
		(*cPtr)->elem = A->elem;
		(*cPtr)->next = NULL;
		cPtr = &(*cPtr)->next;
		A = A->next;
	}

	return C;
}