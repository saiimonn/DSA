#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef ADT_LL_H
#define ADT_LL_H

typedef struct node {
	int data;
	struct node *link;
} *List;

void initialize(List *);
void insertFirst(List *, int);
void insertLast(List *, int);
void insertSorted(List *, int);
void deleteElem(List *, int);
void deleteAllOccur(List *, int);

bool isEmpty(List);
bool isFull();
void makeNull(List *);
void read(List);

void sort(List *);

void initialize(List *L) {
	*L = NULL;
}

bool isEmpty(List L) {
	return (L == NULL) ? true : false;
}

bool isFull() {
	return false;
}

void insertFirst(List *L, int x) { 
	List newNode = (List)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = x;
		newNode->link = *L;
		*L = newNode;
	}
}

void insertLast(List *L, int x) {
	List *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->link) {}

	List newNode = (List)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = x;
		newNode->link = *trav;
		*trav = newNode;
	}
}

void insertSorted(List *L, int x) {
	List *trav;
	for(trav = L; *trav != NULL && (*trav)->data < x; trav = &(*trav)->link) {}

	List newNode = (List)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = x;
		newNode->link = *trav;
		*trav = newNode;
	}
}

void deleteElem(List *L, int x) {
	if(!isEmpty(*L)) {
		List *trav;
		for(trav = L; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link) {}

		if(*trav != NULL) {
			List temp = *trav;
			*trav = temp->link;
			free(temp);
		}
	}
}

void deleteAllOccur(List *L, int x) {
	if(!isEmpty(*L)) {
		List *trav;
		for(trav = L; *trav != NULL; trav = &(*trav)->link) {
			if((*trav)->data == x) {
				List temp = *trav;
				*trav = temp->link;
				free(temp);
			}
		}
	}
}

void makeNull(List *L) {
	if(!isEmpty(*L)) {
		List temp;
		while(*L != NULL) {
			temp = *L;
			*L = temp->link;
			free(temp);
		}
	}
}

void read(List L) {
	if(!isEmpty(L)) {
		for(; L != NULL; L = L->link) printf("%d -> ", L->data);
		printf("NULL\n");
	}
}

void sort(List *L) {
	if(!isEmpty(*L)) {
		for(List i = *L; i->link != NULL; i = i->link) {
			for(List j = i->link; j != NULL; j = j->link) {
				if(j->data < i->data) {
					int temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
	}
}

#endif
