#include <stdio.h>
#include <stdbool.h>
#ifndef ADT_ARR_H
#define ADT_ARR_H
#define MAX 10

typedef struct {
	int data[MAX];
	int count;
} List;

void initialize(List *);
void insertFirst(List *, int);
void insertLast(List *, int);
void insertSorted(List *, int);
void deleteData(List *, int);
void deleteAllOccur(List *, int);
void read(List);
void makeNull(List *);

bool isFull(List);
bool isEmpty(List);

void bubbleSort(List *);
void selectionSort(List *);
void insertionSort(List *);

void initialize(List *L) {
	L->count = 0;
}

bool isFull(List L) {
	return (L.count == MAX) ? true : false;
}

bool isEmpty(List L) {
	return (L.count == 0) ? true : false;
}

void insertFirst(List *L, int x) {
	if(!isFull(*L)) {
		int i;
		for(i = L->count; i >= 0; i--) {
			L->data[i] = L->data[i - 1];
		}

		L->data[0] = x;
		L->count++;
	}
}

void insertLast(List *L, int x) {
	if(!isFull(*L)) {
		L->data[L->count++] = x;
	}
}

void insertSorted(List *L, int x) {
	if(!isFull(*L)) {
		int i;
		for(i = L->count - 1; i >= 0 && L->data[i] > x; L->data[i + 1] = L->data[i], i--) {}
		L->data[i + 1] = x;
		L->count++;
	}
}

void deleteData(List *L, int x) {
	if(!isEmpty(*L)) {
		int idx;
		for(idx = 0; idx < L->count && L->data[idx] != x; idx++) {}

		if(idx != L->count) {
			L->count--;
			int i;
			for(i = idx; i < L->count; L->data[i] = L->data[i + 1], i++) {}
		}
	}
}

void deleteAllOccur(List *L, int x) {
	if(!isEmpty(*L)) {
		int i, e = 0;
		for(i = 0; i < L->count; i++) {
			if(L->data[i] != x) {
				L->data[e++] = L->data[i];
			}
		}
		L->count = e;
	}
}

void read(List L) {
	if(!isEmpty(L)) {
		int i;
		for(i = 0; i < L.count; i++) {
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
}

void makeNull(List *L) {
	L->count = 0;
}

void bubbleSort(List *L) {
	if(!isEmpty(*L)) {
		int i, j;
		for(i = 0; i < L->count - 1; i++) {
			for(j = 0; j < L->count - i - 1; j++) {
				if(L->data[j] > L->data[j + 1]) {
					int temp = L->data[j];
					L->data[j] = L->data[j + 1];
					L->data[j + 1] = temp;
				}
			}
		}
	}
}

void selectionSort(List *L) {
	if(!isEmpty(*L)) {
		for(int i = 0; i < L->count - 1; i++) {
			int min = i;

			for(int j = i + 1; j < L->count; j++) {
				if(L->data[j] < L->data[min]) {
					min = j;
				}
			}

			int temp = L->data[i];
			L->data[i] = L->data[min];
			L->data[min] = temp;
		}
	}
}

void insertionSort(List *L) {
	if(!isEmpty(*L)) {
		for(int i = 0; i < L->count; i++) {
			int key = L->data[i];
			int j = i - 1;

			while(j >= 0 && key < L->data[j]) {
				L->data[j + 1] = L->data[j];
				--j;
			}
			L->data[j + 1] = key;
		}
	}
}

#endif ADT_ARR_H
