#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int rear;
    int front;
    int count;
} Queue;

void init(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);
void read(Queue);
int front(Queue);
bool empty(Queue);
bool full(Queue);

int main() {
    Queue Q;
    init(&Q);

    enqueue(&Q, 123);
    enqueue(&Q, 141);
    enqueue(&Q, 362);

    dequeue(&Q);

    read(Q);
}

void init(Queue *Q) {
    Q->rear = MAX - 1;
    Q->front = 0;
    Q->count = 0;
}

bool empty(Queue Q) {
    return ((Q.rear + 1) % MAX == Q.front) ? true : false;
}

bool full(Queue Q) {
    return ((Q.rear + 2) % MAX == Q.front) ? true : false;
}

int front(Queue Q) {
    return (!empty(Q)) ? Q.data[Q.front] : -1; // breh
}

void enqueue(Queue *Q, int x) {
    if(!full(*Q)) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = x;
        Q->count++;
    }
}

void dequeue(Queue *Q) {
    if(!empty(*Q)) {
        Q->front = (Q->front + 1) % MAX;
        Q->count--;
    }
}

void read(Queue Q) {
    if(!empty(Q)) {
        int i;
        for(i = 0; i < Q.count; i++) {
            int print = Q.data[Q.front];
            dequeue(&Q);
            enqueue(&Q, print);
            printf("%d ", print);
        }
    }
}