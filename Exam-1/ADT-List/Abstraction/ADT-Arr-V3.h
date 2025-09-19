#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef ADT_ARR_V3_H
#define ADT_ARR_V3_H

typedef struct {
	int *elemPtr;
	int count;
	int arrSize;
} List;

int main() {
	List L;
	initialize(&L);
}

void initialize(List *L) {
	L->elemPtr = (int*)malloc(sizeof(int) * 5);
	if(L->elemPtr != NULL) {
		L->count = 0;
		L->arrSize = 5;
	}
}

bool isEmpty(List L) {
	return L.count == 0;
}

void resize(List *L) {
	L->arrSize *= 2;
	L->elemPtr = realloc(L->elemPtr, L->arrSize * sizeof(int));
}

void insertFirst(List *L, int x) {
	if(L->count == L->arrSize) {
		resize(L);
	}

	int i;
	for(i = L->count; i >= 0; L->elemPtr[i] = L->elemPtr[i - 1], i--) {}

	L->elemPtr[0] = x;
	L->count++;
}

void insertLast(List *L, int x) {
	if(L->count == L->arrSize) {
		resize(L);
	}

	L->elemPtr[L->count++] = x;
}

void insertSorted(List *L, int x) {
	if(L->count == L->arrSize) {
		resize(L);
	}

	int i;
	for(i = L->count; i >= 0 && L->elemPtr[i] > x; L->elemPtr[i + 1] = L->elemPtr[i], i--) {}

	L->elemPtr[i + 1] = x;
	L->count++;
}

void deleteElem(List *L, int x) {
	if(!isEmpty(*L)) {
		int idx;
		for(idx = 0; idx < L->count && L->elemPtr[idx] != x; idx++) {}

		if(idx != L->count) {
			L->count--;
			int i;
			for(i = idx; i < L->count; L->elemPtr[i] = L->elemPtr[i + 1], i++) {}
		}
	}
}

void deleteAllOccur(List *L, int x) {
	if(!isEmpty(*L)) {
		int i, e = 0;
		for(i = 0; i < L->count; i++) {
			if(L->elemPtr[i] != x) {
				L->elemPtr[e++] = L->elemPtr[i];
			}
		}
		L->count = e;
	}
}

void read(List L) {
	if(!isEmpty(L)) {
		int i;
		
		for(i = 0; i < L.count; i++) printf("%d ", L.elemPtr[i]);
	}
}

#endif
