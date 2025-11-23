#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum { EMPTY = -1, NOTEXIST = -2 } Status;

typedef struct {
    int LC; //the index
    int RC; //the index
} Nodes;

typedef Nodes Tree[MAX];

int parent(Tree, int);
int leftmostchild(Tree, int);
int rightsibling(Tree, int);
int root(Tree);
int label(int);
void makenull(Tree);
void preorder(Tree, int);
void inorder(Tree, int);
void postorder(Tree, int);

int main() {
    Tree T;
    makenull(T);
    
    // Build the tree structure:
    //       0 (root)
    //      / \ //
    //     1   4
    //    / \   \ //
    //   2   3   5
    //          /
    //         6
    
    // Set up the tree relationships:
    // Node 0: LC=1, RC=EMPTY (1 is left child, no right sibling)
    T[0].LC = 1;
    T[0].RC = EMPTY;
    
    // Node 1: LC=2, RC=4 (2 is left child, 4 is right sibling)
    T[1].LC = 2;
    T[1].RC = 4;
    
    // Node 2: LC=EMPTY, RC=3 (no left child, 3 is right sibling)
    T[2].LC = EMPTY;
    T[2].RC = 3;
    
    // Node 3: LC=EMPTY, RC=EMPTY (leaf node)
    T[3].LC = EMPTY;
    T[3].RC = EMPTY;
    
    // Node 4: LC=5, RC=EMPTY (5 is left child, no right sibling)
    T[4].LC = 5;
    T[4].RC = EMPTY;
    
    // Node 5: LC=6, RC=EMPTY (6 is left child, no right sibling)
    T[5].LC = 6;
    T[5].RC = EMPTY;
    
    // Node 6: LC=EMPTY, RC=EMPTY (leaf node)
    T[6].LC = EMPTY;
    T[6].RC = EMPTY;
    
    // Display tree structure
    printf("Tree Structure (LC = Left Child, RC = Right Sibling):\n");
    for(int i = 0; i < 7; i++) {
        printf("Node %d: LC=%d, RC=%d\n", i, T[i].LC, T[i].RC);
    }
    
    printf("\nTesting tree operations:\n");
    
    // Test parent function
    printf("Parent of node 1: %d\n", parent(T, 1));  // Should be 0
    printf("Parent of node 2: %d\n", parent(T, 2));  // Should be 1
    printf("Parent of node 4: %d\n", parent(T, 4));  // Should be 1
    printf("Parent of node 6: %d\n", parent(T, 6));  // Should be 5
    
    printf("\n");
    
    // Test leftmostchild function
    printf("Leftmost child of 0: %d\n", leftmostchild(T, 0));  // Should be 1
    printf("Leftmost child of 1: %d\n", leftmostchild(T, 1));  // Should be 2
    printf("Leftmost child of 4: %d\n", leftmostchild(T, 4));  // Should be 5
    printf("Leftmost child of 3: %d\n", leftmostchild(T, 3));  // Should be NOTEXIST
    
    printf("\n");
    
    // Test rightsibling function
    printf("Right sibling of 1: %d\n", rightsibling(T, 1));  // Should be 4
    printf("Right sibling of 2: %d\n", rightsibling(T, 2));  // Should be 3
    printf("Right sibling of 4: %d\n", rightsibling(T, 4));  // Should be EMPTY
    printf("Right sibling of 0: %d\n", rightsibling(T, 0));  // Should be EMPTY
    
    printf("\n");
    
    // Test root and label functions
    printf("Root node: %d\n", root(T));              // Should be 0
    printf("Label of node 3: %d\n", label(3));    // Should be 3
    
    // printf("\n");
    
    // // Test tree traversals
    // printf("Preorder traversal: ");
    // preorder(T, root(T));
    // printf("\n");
    
    // printf("Inorder traversal: ");
    // inorder(T, root(T));
    // printf("\n");
    
    // printf("Postorder traversal: ");
    // postorder(T, root(T));
    // printf("\n");
    
    return 0;
}

int parent(Tree T, int node) {
    int i;
    for(i = 0; (i < MAX) && (T[i].LC != node || T[i].RC != node); i++) {}
    return(i < MAX) ? i : NOTEXIST;
}

int leftmostchild(Tree T, int node) {
    return(node >= 0 && T[node].LC != EMPTY) ? T[node].LC : NOTEXIST;
}

int rightsibling(Tree T, int node) {
    return (node >= 0 && T[node].RC != EMPTY) ? T[node].RC : NOTEXIST; 
}

int label(int node) {
    return node;
}

int root(Tree T) {
    return 0;
}

void makenull(Tree T) {
    int i;
    for(i = 0; i < MAX; i++) {
        T[i].LC = EMPTY;
        T[i].RC = EMPTY;
    }
}

// void preorder(Tree T, int node) {

// }

// void inorder(Tree T, int node) {

// }

// void postorder(Tree T, int node) {

// }