#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef STACK_CB_H
#define STACK_CB_H
#define MAX 10

typedef struct {
	char elem;
	int link;
} nodeType;

typedef struct {
	nodeType nodes[MAX];
	int avail;
} VirtualHeap;

typedef int List;

typedef struct {
	List elemPtr;
	VirtualHeap *Vheap;
} Stack;

void initialize(Stack *S) {
	S->elemPtr = -1;
	S->Vheap = (VirtualHeap*)malloc(sizeof(VirtualHeap) * MAX);
	if(S->Vheap != NULL) {
		S->Vheap->avail = 0;
		int i;
		for(i = 0; i < MAX - 1; i++) {
			S->Vheap->nodes[i].link = i + 1;
		}
		S->Vheap->nodes[i].link = -1;
	}
}

bool empty(Stack S) {
	return (S.elemPtr == -1) ? true : false;
}

int allocSpace(Stack *S) {
	int idx = S->Vheap->avail;
	if(idx != -1) {
		S->Vheap->avail = S->Vheap->nodes[idx].link;
	}
	return idx;
}

void deallocSpace(Stack *S, int idx) {
	if(idx >= 0 && idx < MAX) {
		S->Vheap->nodes[idx].link = S->Vheap->avail;
		S->Vheap->avail = idx;
	}
}

void push(Stack *S, int x) {
	int idx = allocSpace(S);
	if(idx != -1) {
		S->Vheap->nodes[idx].elem = x;
		S->Vheap->nodes[idx].link = S->elemPtr;
		S->elemPtr = idx;
	}
}

void pop(Stack *S) {
	if(!empty(*S)) {
		List temp = S->elemPtr;
		S->elemPtr = S->Vheap->nodes[temp].link;
		deallocSpace(S, temp);
	}
}

char top(Stack S) {
	return S.Vheap->nodes[S.elemPtr].elem;
}

void read(Stack S) {
	while(!empty(S)) {
		printf("|  %c  |\n", top(S));
		pop(&S);
	}
}

#endif
