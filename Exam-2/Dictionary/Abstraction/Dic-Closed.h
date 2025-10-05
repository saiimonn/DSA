#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DIC_CLOSED_H
#define DIC_CLOSED_H
#define MAX 10

typedef int Dictionary[MAX];

typedef enum { EMPTY = -1, DELETED = -2, NOTEXIST = -3 } status;

void initDict(Dictionary D) {
	for(int i = 0; i < MAX; i++) {
		D[i] = EMPTY;
	}
}

int hash(int x) {
	return abs(x % MAX);
}

bool isMember(Dictionary D, int x) {
	int idx = hash(x);
	int stop = hash(x);
	bool isFull = false;

	while(!isFull && D[idx] != x && D[idx] != EMPTY) {
		idx = (idx + 1) % MAX;
		if(idx == stop) {
			isFull = true;
		}
	}

	return (D[idx] == x) ? idx : NOTEXIST;
}

void insert(Dictionary D, int x) {
	if(isMember(D, x) != NOTEXIST) {
		int idx = hash(x), deleteIdx = -4;
		int i;

		for(i = 0; i < MAX && D[idx] != x && D[idx] != EMPTY; idx = (idx + 1) % MAX, i++) {
			if(deleteIdx == -4 && D[idx] == DELETED) {
				deleteIdx = idx;
			}
		}

		if(i != MAX) {
			D[idx] = x;	
		} else if(deleteIdx != -4) {
			D[deleteIdx] = x;
		}
	}
}

void deleteMember(Dictionary D, int x) {
	int idx = isMember(D, x);

	if(idx != NOTEXIST) {
		D[idx] = DELETED;
	}
}

#endif
