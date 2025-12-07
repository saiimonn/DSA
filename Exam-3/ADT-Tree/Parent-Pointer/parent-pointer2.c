/*
    Parent-Pointer Implementation as described in the book
    an array, the elements of the array is the index of the parent

    - Initialization starts with all nodes with value -2
    - Root node will have element -1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef enum { ROOT = -1, EMPTY = -2 } Status;

typedef int Tree[MAX];

void initialize(Tree);
void insert(Tree, int, int);
void makenull(Tree);
int leftchild(Tree, int);
int rootIndex(Tree);
int leftMost(Tree);
int rightMost(Tree);
int rightsibling(Tree, int);
int parent(Tree, int);

int main() {
    Tree T;
    initialize(T);
    
    // Build the tree structure using parent pointers
    // Tree structure:
    //       0 (root)
    //      / | \  //
    //     1  2  3
    //    /   |
    //   4    5
    
    // Set root node (index 0 has parent ROOT)
    T[0] = ROOT;
    
    // Insert children
    insert(T, 1, 0);  // Node 1 is child of 0
    insert(T, 2, 0);  // Node 2 is child of 0  
    insert(T, 3, 0);  // Node 3 is child of 0
    insert(T, 4, 1);  // Node 4 is child of 1
    insert(T, 5, 2);  // Node 5 is child of 2
    
    // Display the tree array
    printf("Tree array (index -> parent):\n");
    for(int i = 0; i < MAX; i++) {
        if(T[i] == ROOT) {
            printf("T[%d] = ROOT\n", i);
        } else if(T[i] == EMPTY) {
            printf("T[%d] = EMPTY\n", i);
        } else {
            printf("T[%d] = %d\n", i, T[i]);
        }
    }
    
    printf("\nTesting tree operations:\n");
    
    // Test leftchild
    printf("Left child of 0: %d\n", leftchild(T, 0));  // Should be 1
    printf("Left child of 1: %d\n", leftchild(T, 1));  // Should be 4
    printf("Left child of 2: %d\n", leftchild(T, 2));  // Should be 5
    printf("Left child of 3: %d\n", leftchild(T, 3));  // Should be EMPTY
    
    printf("\n");
    
    // Test rightsibling  
    printf("Right sibling of 1: %d\n", rightsibling(T, 1));  // Should be 2
    printf("Right sibling of 2: %d\n", rightsibling(T, 2));  // Should be 3
    printf("Right sibling of 3: %d\n", rightsibling(T, 3));  // Should be EMPTY
    printf("Right sibling of 4: %d\n", rightsibling(T, 4));  // Should be EMPTY
    
    printf("\n");
    
    // Test parent
    printf("Parent of 1: %d\n", parent(T, 1));  // Should be 0
    printf("Parent of 4: %d\n", parent(T, 4));  // Should be 1
    printf("Parent of 5: %d\n", parent(T, 5));  // Should be 2
    printf("Parent of 0: %d\n", parent(T, 0));  // Should be ROOT

    printf("The leftmost child is: %d\n", leftMost(T)); //should be 4
    printf("The rightmost child is: %d\n", rightMost(T)); //should be 3
    
    return 0;
}

void initialize(Tree T) {
    int i;
    for(i = 0; i < MAX; i++) {
        T[i] = EMPTY;
    }
}

void insert(Tree T, int nodeIdx, int parentIdx) {
    if(nodeIdx < MAX && nodeIdx >= 0 && T[parentIdx] != EMPTY) {
        T[nodeIdx] = parentIdx;
    }
}

void makenull(Tree T) {
    int i;
    for(i = 0; i < MAX; i++) {
        T[i] = EMPTY;
    }
}

int leftchild(Tree T, int idx) {
    int i;
    for(i = idx; i < MAX && T[i] != idx; i++) {}

    return(i != MAX) ? i : EMPTY;
}

int rightsibling(Tree T, int idx) {
    int i;
    for(i = idx + 1; i < MAX && T[i] != T[idx]; i++) {}    
    return (i != MAX) ? i : EMPTY;
}

int rootIndex(Tree T) {
    int retval = EMPTY;
    for(int i = 0; i < MAX; i++) {
        if(T[i] == ROOT) retval = i;
    }
    return retval;
}

int leftMost(Tree T) {
    if(rootIndex(T) != EMPTY) {
        int retval = 0;
        int prev;

        while(retval != EMPTY) {
            prev = retval;
            retval = leftchild(T, retval);    
        }

        return prev;
    }
    return EMPTY;
}

int rightMost(Tree T) {
    int last = EMPTY;
    for(int i = 0; i < MAX; i++) {
        if(T[i] == 0) last = i;
    }
    return last;
}

int parent(Tree T, int idx) {
    if(idx < MAX && idx >= 0) {
        return T[idx];
    }
    return -1;
}