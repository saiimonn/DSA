#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	int data;
	int link;
} nodeType;

typedef struct {
	nodeType nodes[MAX];
	int avail;
} VirtualHeap;

typedef int List;

typedef struct {
	List head;
	VirtualHeap *Vheap;
} CursorList;

void initialize(CursorList *);

int allocSpace(CursorList *);
void insertFirst(CursorList *, int);
void insertLast(CursorList *, int);
void insertSorted(CursorList *, int);

void deallocSpace(CursorList *, int);
void deleteFirst(CursorList *);
void deleteLast(CursorList *);
void deleteElem(CursorList *, int);
void deleteAllOccur(CursorList *, int);

void read(CursorList);

int main() {
	CursorList CB;
}

void initialize(CursorList *CB) {
	CB->head = -1;
	CB->Vheap = (VirtualHeap*)malloc(sizeof(VirtualHeap));
	if(CB->Vheap != NULL) {
		CB->Vheap->avail = 0;
		int i;
		for(i = 0; i < MAX - 1; i++) {
			CB->Vheap->nodes[i].link = i + 1;
		}
		CB->Vheap->nodes[i].link = -1;
	}
}

int allocSpace(CursorList *CB) {
	int idx = CB->Vheap->avail;
	if(idx != -1) {
		CB->Vheap->avail = CB->Vheap->nodes[idx].link;
	}
	return idx;
}

void insertFirst(CursorList *CB, int x) {
	int idx = allocSpace(CB);
	if(idx != -1) {
		CB->Vheap->nodes[idx].data = x;
		CB->Vheap->nodes[idx].link = CB->head;
		CB->head = idx;
	}
}

void insertLast(CursorList *CB, int x) {
	int idx = allocSpace(CB);
	if(idx != -1) {
		CB->Vheap->nodes[idx].data = x;
		CB->Vheap->nodes[idx].link = -1;
		if(CB->head == -1) {
			CB->head = idx;
		} else {
			List trav;
			for(trav = CB->head; CB->Vheap->nodes[trav].link != -1; trav = CB->Vheap->nodes[trav].link) {}
			CB->Vheap->nodes[trav].link = idx;
		}
	}
}

void insertSorted(CursorList *CB, int x) {
	int idx = allocSpace(CB);
	if(idx != -1) {
		CB->Vheap->nodes[idx].data = x;
		
		if(CB->head == -1 || x <= CB->Vheap->nodes[CB->head].data) {
			CB->Vheap->nodes[idx].link = CB->head;
			CB->head = idx;
		} else {
			List *trav;
			for(trav = &CB->head; *trav != -1 && CB->Vheap->nodes[*trav].data < x; trav = &(CB->Vheap->nodes[*trav].link)) {}
			CB->Vheap->nodes[idx].link = *trav;
			*trav = idx;
		}
	}
}

void deallocSpace(CursorList *CB, int idx) {
	if(idx >= 0 && idx < MAX) {
		CB->Vheap->nodes[idx].link = CB->Vheap->avail;
		CB->Vheap->avail = idx;
	}
}

void deleteFirst(CursorList *CB) {
	if(CB->head != -1) {
		List temp = CB->head;
		CB->head = CB->Vheap->nodes[CB->head].link;
		deallocSpace(CB, temp);
	}
}

void deleteLast(CursorList *CB) {
	if(CB->head != -1) {
		List trav;
		for(trav = CB->head; CB->Vheap->nodes[CB->Vheap->nodes[trav].link].link != -1; trav = CB->Vheap->nodes[trav].link) {}
		
		List lastNode = CB->Vheap->nodes[trav].link;
		CB->Vheap->nodes[trav].link = -1;
		deallocSpace(CB, trav);
	}
}
