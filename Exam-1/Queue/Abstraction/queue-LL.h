#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef QUEUE_LL_H
#define QUEUE_LL_H

typedef struct node {
	int data;
	struct node *link;
} *LL;

typedef struct {
	LL front;
	LL rear;
} Queue;

void initialize(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

bool isEmpty(Queue Q) {
	return (Q.front == NULL) ? true : false;
}

bool isFull() {
	return false;
}

void enqueue(Queue *Q, int x) {
	LL newNode = (LL)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = x;
		newNode->link = NULL;
		if(Q->front == NULL) {
			Q->front = newNode;
		} else {
			Q->rear->link = newNode;
		}
		Q->rear = newNode;
	}
}

void dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		LL temp = Q->front;
		Q->front = Q->front->link;
		free(temp);
		if(Q->front == NULL) {
			Q->rear = NULL;
		}
	}
}

int front(Queue Q) {
	return Q.front->data;
}

void read(Queue Q) {
	if(!isEmpty(Q)) {
		for(; isEmpty(Q) != true; dequeue(&Q)) printf("%d ", front(Q));
	}
}

#endif
