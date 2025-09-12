#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	int elems[MAX];
	int rear;
	int front;
} Queue;

int count = 0;

void initialize(Queue *);
void enqueueSorted(Queue *, int);
void dequeue(Queue *);
void read(Queue);

int main() {
	Queue Q;
	initialize(&Q);

	enqueueSorted(&Q, 4);
	enqueueSorted(&Q, 7);
	enqueueSorted(&Q, 2);
	enqueueSorted(&Q, 8);

	read(Q);
}

void initialize(Queue *Q) {
	Q->front = 0;
	Q->rear = MAX - 1;
}

bool isEmpty(Queue Q) {
	return (Q.rear + 1) % MAX == Q.front;
}

bool isFull(Queue Q) {
	return (Q.rear + 2) % MAX == Q.front;
}

void enqueue(Queue *Q, int x) {
	if(!isFull(*Q)) {
		Q->rear = (Q->rear + 1) % MAX;
		Q->elems[Q->rear] = x;
		count++;
	}
}

void enqueueSorted(Queue *Q, int x) { 
	if(!isFull(*Q)) {
		int i, rotation = count;
		int inserted = 0;

		for(i = 0; i < rotation; i++) {
			int temp = Q->elems[Q->front]; //removes the front elem, compares x to it, inserts if x < temp. 
			dequeue(Q);					   //will keep rotating until i == rotation, keeping the original array form.

			if(!inserted && x < temp) {
				enqueue(Q, x);
				inserted = 1;
			}

			enqueue(Q, temp);
		}

		if(!inserted) {
			enqueue(Q, x);
		}
	}
}

void dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		Q->front = (Q->front + 1) % MAX;
		count--;
	}
}

void read(Queue Q) {
	if(!isEmpty(Q)) {
		int i;
		int n = count;
		for(i = 0; i < n; i++) {
			int temp = Q.elems[Q.front];
			Q.front = (Q.front + 1) % MAX;
			printf("%d ", temp);
		}
	}
}
