#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H
#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initialize(Queue *Q) {
    Q->front = 0;
    Q->rear = MAX - 1;
}

bool isEmpty(Queue Q) {
	return (Q.rear + 1) % MAX == Q.front ? true : false;
}

bool isFull(Queue Q) {
	return (Q.rear + 2) % MAX == Q.front ? true : false;
}

void enqueue(Queue *Q, int x) {
	if(!isFull(*Q)) {
		Q->rear = (Q->rear + 1) % MAX;
		Q->data[Q->rear] = x;
	}
}

void dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		Q->front = (Q->front + 1) % MAX;
	}
}

int front(Queue Q) {
	return Q.data[Q.front];
}

void read(Queue Q) {
	for(; isEmpty(Q) != true; dequeue(&Q)) printf("%d ", front(Q));
}

#endif
