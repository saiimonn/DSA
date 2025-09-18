#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef ADT_CB_H
#define ADT_CB_H
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
bool isEmpty(CursorList);
bool isFull(CursorList);

int allocSpace(CursorList *);
void deallocSpace(CursorList *, int);

void insertFirst(CursorList *, int);
void insertLast(CursorList *, int);
void insertSorted(CursorList *, int);

void deleteElem(CursorList *, int);
void deleteAllOccur(CursorList *, int);

void read(CursorList);
void makeNull(CursorList *);

void initialize(CursorList *CL) {
	CL->head = -1;
	CL->Vheap = (VirtualHeap*)malloc(sizeof(VirtualHeap));
	if(CL->Vheap != NULL) {
		CL->Vheap->avail = 0;
		int i;
		for(i = 0; i < MAX - 1;i++) {
			CL->Vheap->nodes[i].link = i + 1;
		}
		CL->Vheap->nodes[i].link = -1;
	}
}

bool isEmpty(CursorList CL) {
	return(CL.head == -1) ? true : false;
}

bool isFull(CursorList CL) {
	return (CL.Vheap->avail = -1) ? true : false;
}

int allocSpace(CursorList *CL) {
	int idx = CL->Vheap->avail;
	if(idx != -1) {
		CL->Vheap->avail = CL->Vheap->nodes[idx].link;
	}
	return idx;
}

void insertFirst(CursorList *CL, int x) {
	int idx = allocSpace(CL);
	if(idx != -1) {
		CL->Vheap->nodes[idx].data = x;
		CL->Vheap->nodes[idx].link = CL->head;
		CL->head = idx;
	}
}

void insertLast(CursorList *CL, int x) {
	int idx = allocSpace(CL);
	if(idx != -1) {
		CL->Vheap->nodes[idx].data = x;
		CL->Vheap->nodes[idx].link = -1;
		if(CL->head == -1) {
			CL->head = idx;
		} else {
			 List *trav;
			for(trav = &CL->head; *trav != -1; trav = &(CL->Vheap->nodes[*trav].link)) {}

			CL->Vheap->nodes[idx].link = *trav;
			*trav = idx;
		}
	}
}

void insertSorted(CursorList *CL, int x) {
	int idx = allocSpace(CL);
	if(idx != -1) {
		CL->Vheap->nodes[idx].data = x;

		if(CL->head == -1 || x <= CL->Vheap->nodes[CL->head].data) {
			CL->Vheap->nodes[idx].link = CL->head;
			CL->head = idx;
		} else {
			List *trav;
			for(trav = &CL->head; *trav != -1 && CL->Vheap->nodes[*trav].data < x; trav = &(CL->Vheap->nodes[*trav].link)) {}
			CL->Vheap->nodes[idx].link = *trav;
			*trav = idx;
		}
	}
}

void deallocSpace(CursorList *CL, int idx) {
	if(idx >= 0 && idx < MAX) {
		CL->Vheap->nodes[idx].link = CL->Vheap->avail;
		CL->Vheap->avail = idx;
	}
}

void deleteElem(CursorList *CL, int x) {
	if(!isEmpty(*CL)) {
		List *trav;
		for(trav = &CL->head; *trav != -1 && CL->Vheap->nodes[*trav].data != x; trav = &(CL->Vheap->nodes[*trav].link)) {}

		if(*trav != -1) {
			List temp = *trav;
			*trav = CL->Vheap->nodes[temp].link;
			deallocSpace(CL, temp);
		}
	}
}

void deleteAllOccur(CursorList *CL, int x) {
	if(!isEmpty(*CL)) {
		List *trav;
		for(trav = &CL->head; *trav != -1; trav = &(CL->Vheap->nodes[*trav].link)) {
			if(CL->Vheap->nodes[*trav].data == x) {
				List temp = *trav;
				*trav = CL->Vheap->nodes[temp].link;
				deallocSpace(CL, temp);
			}
		}
	}
}

void read(CursorList CL) {
	if(!isEmpty(CL)) {
		List trav;
		for(trav = CL.head; trav != -1; trav = CL.Vheap->nodes[trav].link) printf("%d ", CL.Vheap->nodes[trav].data);
		printf("\n");
	}
}

void makeNull(CursorList *CL) {
	while(CL->head != -1) {
		List temp = CL->head;
		CL->head = CL->Vheap->nodes[temp].link;
		deallocSpace(CL, temp);
	}
}

#endif
