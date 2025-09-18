#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *link;
} *List;

typedef struct {
	List front;
	List rear;
} Queue;

int count = 0;

void initialize(Queue *);
void enqueueSorted(Queue *, int);
void enqueue(Queue *, int);
void dequeue(Queue *);
void read(Queue);

int main() {
	Queue Q;
	initialize(&Q);

	enqueueSorted(&Q, 32);
	enqueueSorted(&Q, 10);
	enqueueSorted(&Q, 43);
	enqueueSorted(&Q, 93);
	enqueueSorted(&Q, 81);
	enqueueSorted(&Q, 23);

	read(Q);
}

void initialize(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

void enqueueSorted(Queue *Q, int x) {
	int size = count;
	bool inserted = false;

	for(int i = 0; i < size; i++) {
		int tempFront = Q->front->data;
		dequeue(Q);

		if(!inserted && x < tempFront) {
			enqueue(Q, x);
			inserted = true;
		}

		enqueue(Q, tempFront);
	}

	if(!inserted) {
		enqueue(Q, x);
	}
}

void enqueue(Queue *Q, int x) {
	List newNode = (List)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = x;
		newNode->link = NULL;
		if(Q->front == NULL) {
			Q->front = newNode;
		} else {
			Q->rear->link = newNode;
		}
		Q->rear = newNode;
		count++;
	}
}

void dequeue(Queue *Q) {
	if(Q->front != NULL) {
		List temp = Q->front;
		Q->front = temp->link;
		free(temp);
		count--;
		if(Q->front == NULL) {
			Q->rear = NULL;
		}
	}
}

void read(Queue Q) {
	if(Q.front != NULL) {
		int rotations = count;
		for(int i = 0; i < rotations; i++) {
			int print = Q.front->data;
			dequeue(&Q);
			enqueue(&Q, print);
			printf("%d ", print);
		}
	}
}
