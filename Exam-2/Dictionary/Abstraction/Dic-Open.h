#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DIC_OPEN_H
#define DIC_OPEN_H
#define MAX 10

typedef struct node {
	int elem;
	struct node *link;
} *LIST;

typedef LIST Dictionary[MAX];

void initDict(Dictionary D) {
	for(int i = 0; i < MAX; i++) {
		D[i] = NULL;	
	}
}

int hash(int x) {
	return x % MAX;
}

void insert(Dictionary D, int x) {
	int idx = hash(x);

	LIST *trav;
	for(trav = &D[idx]; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link) {}

	if(*trav == NULL) {
		LIST newNode = (LIST)malloc(sizeof(struct node));
		if(newNode != NULL) {
			newNode->elem = x;
			newNode->link = NULL;
			*trav = newNode;
		}
	}
}

void deleteMember(Dictionary D, int x) {
	int idx = hash(x);

	LIST *trav;
	for(trav = &D[idx]; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link) {}

	if(*trav != NULL) {
		LIST temp = *trav;
		*trav = temp->link;
		free(temp);
	}
}

bool isMember(Dictionary D, int x) {
	int idx = hash(x);

	LIST trav;
	for(trav = D[idx]; trav != NULL && trav->elem != x; trav = trav->link) {}

	return trav == NULL;
}	

void read(Dictionary D) {
	for(int i = 0; i < MAX; i++) {
		printf("[%d] -> ", i);
		LIST trav;
		for(trav = D[i]; trav != NULL; trav = trav->link) printf("%d -> ", trav->elem);
		printf("NULL\n");
	}
}	

#endif
