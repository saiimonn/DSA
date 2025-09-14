#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef STACK_LL_H
#define STACK_LL_H

typedef struct node {
	char data;
	struct node *link;
} *Stack;

void initialize(Stack *S) {
	*S = NULL;
}

bool empty(Stack S) {
	return (S == NULL) ? true : false;
}

bool full() {
	return false;
}

void push(Stack *S, char x) {
	Stack newNode = (Stack)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = x;
		newNode->link = *S;
		*S = newNode;
	}
}

void pop(Stack *S) {
	if(!empty(*S)) {
		Stack temp = *S;
		*S = (*S)->link;
		free(temp);
	}
}

char top(Stack S) {
	return (empty(S)) ? '\0' : S->data;
}

void read(Stack S) {
	while(!empty(S)) {
		printf("|  %c  |\n", top(S));
		pop(&S);
	}
}

#endif
