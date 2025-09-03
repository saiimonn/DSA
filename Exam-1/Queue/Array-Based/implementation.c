#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int rear;
    int front;
} Queue;

void init(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *, int);
void read(Queue *);
int front(Queue);
bool empty(Queue);
bool full(Queue);

int main() {
    Queue Q;
    init(&Q);
}

void init(Queue *Q) {
    Q->rear = MAX - 1;
    Q->front = 0;
}

bool empty(Queue Q) {
    return ((Q.rear + 1) % MAX == Q.front) ? true : false;
}

bool full(Queue Q) {
    return ((Q.rear + 2) % MAX == Q.front) ? true : false;
}

int front(Queue Q) {
    if(!empty(Q)) {
        return Q.data[Q.front];
    }
}

void enqueue(Queue *Q, int x) {
    if(!full(*Q)) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = x;
    }
}

void dequeue(Queue *Q, int x) {
    if(!empty(*Q)) {
        Q->front = (Q->front + 1) % MAX;
    }
}