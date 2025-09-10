#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *List;

typedef struct {
    List front;
    List rear;
    int count;
} Queue;

void initQueue(Queue *);
void enqueue(Queue *, char);
void dequeue(Queue *);
char front(Queue);
void print(Queue);

int main() {
    Queue Q;
    initQueue(&Q);

    enqueue(&Q, 'D'); //front
    enqueue(&Q, 'C');
    enqueue(&Q, 'I');
    enqueue(&Q, 'S');
    enqueue(&Q, 'M'); //rear

    print(Q);
}

void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
    Q->count = 0;
}

void enqueue(Queue *Q, char x) {
    List newNode = (List)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->elem = x;
        newNode->link = NULL;
        if(Q->front == NULL) {
            Q->front = newNode;
        } else {
            Q->rear->link = newNode;
        }
        Q->rear = newNode;
        Q->count++;
    }
}

void dequeue(Queue *Q) {
    if(Q->front != NULL) {
        List temp = Q->front;
        Q->front = temp->link;
        free(temp);
        if(Q->front == NULL) {
            Q->rear = NULL;
        }
        Q->count--;
    }
}

char front(Queue Q) {
    return (Q.front != NULL) ? Q.front->elem : '\0';
}

void print(Queue Q) {
    if(Q.front != NULL) {
        int i;
        for(i = 0; i < Q.count; i++) {
            char x = Q.front->elem;
            dequeue(&Q);
            enqueue(&Q, x);
            printf("%c ", x);
        }
    }
}