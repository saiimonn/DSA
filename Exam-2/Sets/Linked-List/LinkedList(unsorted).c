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

	read(A);
	read(B);
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
	SET *trav;
	for(trav = S; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->next) {}

	if(*trav == NULL) {
		SET newNode = (SET)malloc(sizeof(struct node));
		newNode->elem = x;
		newNode->next = NULL;
		*trav = newNode;
	}
}

void read(SET S) {
	for(SET print = S; print != NULL; print = print->next) printf("%d ", print->elem);
	printf("}\n");
}
