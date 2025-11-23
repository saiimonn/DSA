/*
    My interpretation of a parent-pointer implementation
    an array of nodes with attributes data and parent.

    - Initialization starts with all nodes' attributes being -2
    - The root node will have a parent of -1
    - The parent of a node will be the index of an existing node (not -2)
*/ 

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum { ROOT = -1, EMPTY = -2 } Status;

typedef struct {
    int data;
    int parent;
} Node;

typedef Node Tree[MAX];

void initialize(Tree);
void insert(Tree, int, int, int);
void makenull(Tree);
int leftchild(Tree, int);
int rightsibling(Tree, int);
int parent(Tree, int);

int main() {
    Tree T;
    initialize(T);
    
    // Build a sample tree:
    //       0(A)
    //      /  \   \  //
    //     1(B) 2(C) 3(D)
    //    /     |
    //   4(E)   5(F)
    
    // Insert root node at index 0
    insert(T, 'A', 0, ROOT);
    
    // Insert children of root (B, C, D)
    insert(T, 'B', 1, 0);
    insert(T, 'C', 2, 0); 
    insert(T, 'D', 3, 0);
    
    // Insert children of B (E)
    insert(T, 'E', 4, 1);
    
    // Insert children of C (F)
    insert(T, 'F', 5, 2);
    
    // Test the functions
    printf("Tree Structure:\n");
    
    // Test leftchild - should find first child of each node
    printf("Left child of root (A): %c\n", T[leftchild(T, 0)].data);  // Should be B
    printf("Left child of B: %c\n", T[leftchild(T, 1)].data);         // Should be E
    printf("Left child of C: %c\n", T[leftchild(T, 2)].data);         // Should be F
    printf("Left child of D: %c\n", T[leftchild(T, 3)].data);         // Should be EMPTY
    
    printf("\n");
    
    // Test rightsibling - should find next sibling at same level
    printf("Right sibling of B: %c\n", T[rightsibling(T, 1)].data);   // Should be C
    printf("Right sibling of C: %c\n", T[rightsibling(T, 2)].data);   // Should be D
    printf("Right sibling of D: %c\n", rightsibling(T, 3));           // Should be EMPTY
    
    printf("\n");
    
    // Test parent
    printf("Parent of B: %c\n", T[parent(T, 1)].data);                // Should be A
    printf("Parent of E: %c\n", T[parent(T, 4)].data);                // Should be B
    printf("Parent of F: %c\n", T[parent(T, 5)].data);                // Should be C
    printf("Parent of root: %d\n", parent(T, 0));                     // Should be ROOT (-1)
    
    return 0;
}

void initialize(Tree T) {
    for(int i = 0; i < MAX; i++) {
        T[i].data = EMPTY;
        T[i].parent = EMPTY;
    }
}

void insert(Tree T, int data, int nodeIdx, int parentIdx) {
    T[nodeIdx].data = data;
    T[nodeIdx].parent = parentIdx;
}

void makenull(Tree T) {
    int i;
    for(i = 0; i < MAX; i++) {
        T[i].data = EMPTY;
        T[i].parent = EMPTY;
    }
}

int leftchild(Tree T, int idx) {
    int i;
    for(i = 0; i < MAX && T[i].parent != idx; i++) {}
    return (i != MAX) ? i : EMPTY;
}

int rightsibling(Tree T, int idx) {
    int i;
    for(i = idx + 1; i < MAX && T[i].parent != T[idx].parent; i++) {}

    return (i != MAX) ? i : EMPTY;
}

int parent(Tree T, int idx) {
    return T[idx].parent;
}