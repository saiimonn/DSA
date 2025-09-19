#include <stdio.h>
#include <stdbool.h>
#ifndef QUEUE_ARR_CW_H
#define QUEUE_ARR_CW_H
#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initialize(Queue *Q) {
    Q->front = MAX - 1;
    Q->rear = 0;
}

bool isEmpty(Queue Q) {
    return (Q.rear - 1 + MAX) % MAX == Q.front;
}

bool isFull(Queue Q) {
    return (Q.rear - 2 + MAX) % MAX == Q.front;
}

void enqueue(Queue *Q, int x) {
    if(!isFull(*Q)) {
        Q->rear = (Q->rear - 1 + MAX) % MAX;
        Q->data[Q->rear] = x;
    }
}

void dequeue(Queue *Q) {
    if(!isEmpty(*Q)) {
        Q->front = (Q->front - 1 + MAX) % MAX;
    }
}

int front(Queue Q) {
    return Q.data[Q.front];
}

void read(Queue Q) {
    for(; !isEmpty(Q); dequeue(&Q)) printf("%d ", front(Q));
}

#endif