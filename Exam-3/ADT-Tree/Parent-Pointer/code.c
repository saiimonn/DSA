#include <stdio.h>
#define MAX 10
#define ROOT -1
#define EMPTY -2

typedef struct {
    int data;
    int parent;
} Node;

typedef Node Tree[MAX];

void initTree(Tree);
void insert(Tree, int, int, int);
int parent(Tree, int);

int main() {
    Tree T;
    initTree(T);
}

void initTree(Tree T) {
    int i;
    for(i = 0; i < MAX; i++) {
        T[i].data = EMPTY;
        T[i].parent = EMPTY;
    }
}

int parent(Tree T, int idx) {
    return T[idx].parent;
}

void insert(Tree T, int idx, int data, int parent) {
	if(idx >= 0 && idx < MAX) {
		T[idx].data = data;
		T[idx].parent = parent;
	}
}
