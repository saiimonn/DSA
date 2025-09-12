#include <stdbool.h>
#include <stdio.h>
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#define MAX 10

typedef struct {
	char elem[MAX];
	int top;
} Stack;

void initialize(Stack *S) {
	S->top = MAX;
}

bool empty(Stack S) {
	return (S.top == MAX) ? true : false;
}

bool full(Stack S) {
	return (S.top == 0) ? true : false;
}

void push(Stack *S, int x) {
	if(!full(*S)) {
		S->elem[--S->top] = x;
	}
}

void pop(Stack *S) {
	if(!empty(*S)) {
		S->top++;
	}
}

char top(Stack S) {
	return S.elem[S.top];
}

void read(Stack S) {
	while(!empty(S)) {
		printf("|  %c  |\n", top(S));
		pop(&S);
	}
}

#endif
