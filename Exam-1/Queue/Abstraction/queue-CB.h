#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef QUEUE_CB_H
#define QUEUE_CB_H
#define MAX 10

typedef struct {
	int data;
	int link;
} nodeType;

typedef struct {
	nodeType nodes[MAX];
	int avail;
} VirtualHeap;

typedef int List;

typedef struct {
	List front;
	List rear;
	VirtualHeap *Vheap;
} Queue;

void initialize(Queue *Q) {
	Q->front = -1;
	Q->rear = -1;
	Q->Vheap = (VirtualHeap*)malloc(sizeof(VirtualHeap));
	if(Q->Vheap != NULL) {
		Q->Vheap->avail = 0;
		int i;
		for(i = 0; i < MAX - 1; i++) {
			Q->Vheap->nodes[i].link = i + 1;
		}
		Q->Vheap->nodes[i].link = -1;
	}
}

int front(Queue Q) {
	return Q.Vheap->nodes[Q.front].data;
}

bool isEmpty(Queue Q) {
	return (Q.front == -1) ? true : false;
}

int allocSpace(Queue *Q) {
	int idx = Q->Vheap->avail;
	if(idx != -1) {
		Q->Vheap->avail = Q->Vheap->nodes[idx].link;
	}
	return idx;
}

void enqueue(Queue *Q, int x) {
	int idx = allocSpace(Q);
	if(idx != -1) {
		Q->Vheap->nodes[idx].data = x;
		Q->Vheap->nodes[idx].link = -1;
		if(Q->front == -1) {
			Q->front = idx;
		} else {
			Q->Vheap->nodes[Q->rear].link = idx;
		}
		Q->rear = idx;
	}
}

void deallocSpace(Queue *Q, int idx) {
	if(idx >= 0 && idx < MAX) {
		Q->Vheap->nodes[idx].link = Q->Vheap->avail;
		Q->Vheap->avail = idx;
	}
}

void dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		List temp = Q->front;
		Q->front = Q->Vheap->nodes[temp].link;
		deallocSpace(Q, temp);

		if(isEmpty(*Q)) {
			Q->rear = -1;
		}
	}
}

void read(Queue Q) {
	if(!isEmpty(Q)) {
		for(; isEmpty(Q) != true; dequeue(&Q)) printf("%d ", front(Q));
	}
}

#endif
