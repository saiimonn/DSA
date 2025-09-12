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
} VirtualHeap;

typedef int List;

typedef struct {
	List front;
	List rear;
} Queue;

void initVH(VirtualHeap *);
void initQueue(Queue *);

int allocSpace(VirtualHeap *);
void deallocSpace(VirtualHeap *);

void enqueue(VirtualHeap *, Queue *, char);
void dequeue(VirtualHeap *, Queue *);
char front(VirtualHeap , Queue);

int main() {
	VirtualHeap VH;
	initVH(&VH);

	Queue Q;
	initQueue(&Q);
}

void initVH(VirtualHeap *VH) {
	VH->avail = 0;
	int i;
	for( i = 0; i < MAX - 1; i++) {
		VH->nodes[i].link = i + 1;
	}
	VH->nodes[i].link = -1;
}

void initQueue(Queue *Q) {
	Q->front = -1;
	Q->rear = -1;
}

int allocSpace(VirtualHeap *VH) {
	int idx = VH->avail;
	if(idx != -1) {
		VH->avail = VH->nodes[idx].link;
	}
	return idx;
}

void deallocSpace(VirtualHeap *VH) {
	
}

void enqueue(VirtualHeap *VH, Queue *Q, char x) {
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

void dequeue(VirtualHeap *VH, Queue *Q) {
	if(Q->front != -1) {
		
	}
}

char front(VirtualHeap VH, Queue Q) {
	return (Q.front != -1) ? VH.nodes[Q.front].elem : '\0';
}
