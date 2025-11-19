#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int left;
    int right;
} nodeType;

typedef int Set;

typedef struct {
    nodeType nodes[MAX];
    int avail;
} Tree;

void initVH(Tree *);
void insert(Tree *, Set *, int);
void delete(Tree *, Set *, int);
int member(Tree, Set, int);
int min(Tree, Set);
int max(Tree, Set);

int main() {
    Tree T;
    initVH(&T);
}

void initVH(Tree *T) {
    T->avail = 0;
    int i;
    for(i = 0; i < MAX - 1; i++) {
        T->nodes[i].left = -1;
        T->nodes[i].right = -1;
    }
    
}

void insert(Tree *T, Set *S, int x) {

}

void delete(Tree *T, Set *S, int x) {

}

int member(Tree T, Set S, int x) {
    for(; S != -1 && T.nodes[S].data != x;) {
        S = (x > T.nodes[S].data) ? T.nodes[S].right : T.nodes[S].left;
    }
    return (S != -1) ? 1 : 0;
}

int min(Tree T, Set S) {
    return (T.nodes[S].left == -1) ? T.nodes[S].data : min(T, T.nodes[S].left);
}

int max(Tree T, Set S){
    return (T.nodes[S].right == -1) ? T.nodes[S].data : min(T, T.nodes[S].right);
}