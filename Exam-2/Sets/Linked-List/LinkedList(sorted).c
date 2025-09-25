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

void populate(SET *);
void read(SET);
void insert(SET *, int);
SET Union(SET, SET);
SET Intersection(SET, SET);
SET Difference(SET, SET);

int main() {
	SET A = NULL;
	SET B = NULL;

	populate(&A);
	populate(&B);

	SET U = Union(A, B); //Elements in A and B
	read(U);

	SET I = Intersection(A, B); //Elements in A that are in B
	read(I);

	SET D = Difference(A, B); //Elements in A that are not in B
	read(D);
}

void populate(SET *S) {
	int size;
	printf("Enter number of elements: ");
	scanf("%d", &size);

	for(int i = 0; i < size; i++) {
		int inp;
		printf("Enter element: ");
		scanf("%d", &inp);

		insert(S, inp);
	}
}

void insert(SET *S, int x) {
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

	SET Atrav;
	for(Atrav = A; Atrav != NULL; Atrav = Atrav->next) {
		SET Btrav;
		for(Btrav = B; Btrav != NULL && Btrav->elem != Atrav->elem; Btrav = Btrav->next) {}

		if(Btrav != NULL) {
			insert(&C, Btrav->elem);
		}
	}

	return C;
}

SET Difference(SET A, SET B) {
	SET C = NULL;

	SET Atrav;
	for(Atrav = A; Atrav != NULL; Atrav = Atrav->next) {
		SET Btrav;
		for(Btrav = B; Btrav != NULL && Btrav->elem != Atrav->elem; Btrav = Btrav->next) {}

		if(Btrav == NULL) {
			insert(&C, Atrav->elem);	
		}
	}
	return C;
}
