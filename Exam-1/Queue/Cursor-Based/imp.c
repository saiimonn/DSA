#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	char elem;
	int link;
} nodeType;

typedef struct {
	nodeType nodes[MAX];
	int avail;
} virtualHeap;

typedef int List;

typedef struct {
	List front;
	List rear;
} Queue;

void initVH(virtualHeap *);
void initQueue(Queue *);

int allocSpace(virtualHeap *);
void deallocSpace(virtualHeap *, Queue *);

void enqueue(virtualHeap *, Queue *, char);
void dequeue(virtualHeap *, Queue *);

int main() {
	virtualHeap VH;
	initVH(&VH);

	Queue Q;
	initQueue(&Q);
}

void initVH(virtualHeap *VH) {
	VH->avail = 0;
	int i;
	for(i = 0; i < MAX - 1; i++) {
		VH->nodes[i].link = i + 1;
	}
	VH->nodes[i].link = -1;
}

void initQueue(Queue *Q) {
	Q->front = -1;
	Q->rear = -1;
}

int allocSpace(virtualHeap *VH) {
	int idx = VH->avail;
	if(idx != -1) {
		VH->avail = VH->nodes[idx].link;
	}
	return idx;
}

void deallocSpace(virtualHeap *VH) {
	
}

void enqueue(virtualHeap *VH, Queue *Q, char x) {
	int idx = allocSpace(VH);
	if(idx != -1) {
		VH->nodes[idx].elem = x;
		VH->nodes[idx].link = -1;
		if(Q->front == -1) {
			Q->front = idx;
		}
		Q->rear = idx;
	}
}

void dequeue(virtualHeap *VH, Queue *Q) {
	if(Q->front != -1) {		
		List temp = Q->front;
		deallocSpace(&temp); 
	}
} 
