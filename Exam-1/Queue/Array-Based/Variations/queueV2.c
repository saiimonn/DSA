#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    char data[MAX];
    int front;
    int rear;
    int count;
} *Queue;

void initQueue(Queue *);
void enqueue(Queue *, char);
void dequeue(Queue *);
void read(Queue *);


int main() {
    Queue Q;
    initQueue(&Q);

    enqueue(&Q, 'D');
    enqueue(&Q, 'C');
    enqueue(&Q, 'I');
    enqueue(&Q, 'S');
    enqueue(&Q, 'M');

    read(&Q);
}

void initQueue(Queue *Q) {
    *Q = (Queue)malloc(sizeof(struct node));
    if((*Q) != NULL) {
        (*Q)->front = 0;
        (*Q)->rear = MAX - 1;
        (*Q)->count = 0;
    }
}

void enqueue(Queue *Q, char x) {
    if(((*Q)->rear + 2) % MAX != (*Q)->front) {
        (*Q)->rear = ((*Q)->rear + 1) % MAX;
        (*Q)->data[(*Q)->rear] = x;
        (*Q)->count++;
    }
}

void dequeue(Queue *Q) {
    if(((*Q)->rear + 1) % MAX != (*Q)->front) {
        (*Q)->front = ((*Q)->front + 1) % MAX;
        (*Q)->count--;
    }
}

void read(Queue *Q) {
    if(((*Q)->rear + 1) % MAX != (*Q)->front) {
        int i;
        for(i = 0; i < (*Q)->count; i++) {
            char x = (*Q)->data[(*Q)->front];
            dequeue(Q);
            enqueue(Q, x);
            printf("%c ", x);
        }
    }
}