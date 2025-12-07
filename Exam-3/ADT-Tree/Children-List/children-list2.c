#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int node;
    struct node *link;
} *List;

typedef struct {
    List children[MAX];
    int root;
} Tree;

void initialize(Tree *);
void insert(Tree *, int, int);
int leftchild(Tree, int);
int rightsibling(Tree, int);
int parent(Tree, int);
void displayTree(Tree);

int main() {
    Tree T;
    initialize(&T);

    // Define root
    T.root = 0;

    // Build the tree structure:
    //        0
    //      / | \ //
    //     1  2  3
    //    /
    //   4

    insert(&T, 0, 1);
    insert(&T, 0, 2);
    insert(&T, 0, 3);
    insert(&T, 1, 4);

    printf("Tree (Adjacency List Format):\n");
    displayTree(T);

    printf("\nTesting Operations:\n");

    printf("Left child of 0: %d\n", leftchild(T, 0));
    printf("Left child of 1: %d\n", leftchild(T, 1));
    printf("Left child of 2: %d\n", leftchild(T, 2));
    printf("Left child of 3: %d\n", leftchild(T, 3));

    printf("\nRight sibling of 1: %d\n", rightsibling(T, 1));
    printf("Right sibling of 2: %d\n", rightsibling(T, 2));
    printf("Right sibling of 3: %d\n", rightsibling(T, 3));
    printf("Right sibling of 4: %d\n", rightsibling(T, 4));

    printf("\nParent of 1: %d\n", parent(T, 1));
    printf("Parent of 4: %d\n", parent(T, 4));
    printf("Parent of 3: %d\n", parent(T, 3));
    printf("Parent of 0: %d\n", parent(T, 0)); // Should remain -1

    return 0;
}


void initialize(Tree *T) {
    for(int i = 0; i < MAX; i++) {
        T->children[i] = NULL;
    }
}

void insert(Tree *T, int parentIdx, int childIdx) {
    if((parentIdx < MAX && parentIdx >= 0) && (childIdx < MAX && childIdx >= 0)) {
        List newchild = (List)malloc(sizeof(struct node));
        if(newchild != NULL) {
            newchild->node = childIdx;
            newchild->link = T->children[parentIdx];
            T->children[parentIdx] = newchild;
        }
    }
}

int leftchild(Tree T, int parentIdx) {
    if(parentIdx >= 0 && parentIdx < MAX && T.children[parentIdx] != NULL) {
        return T.children[parentIdx]->node;
    }
    return -1;
}

int rightsibling(Tree T, int childIdx) {
    int retval = -1;
    if(childIdx >= 0 && childIdx < MAX) {
        for(int i = 0; i < MAX; i++) {
            List trav;
            for(trav = T.children[i]; trav != NULL && trav->node != childIdx; trav = trav->link) {}

            if(trav != NULL && trav->link != NULL) retval = trav->link->node;
        }
    }
    return retval;
}

int parent(Tree T, int childIdx) {
    int retval = -1;
    if(childIdx >= 0 && childIdx < MAX) {
        for(int i = 0; i < MAX; i++) {
            List trav;
            for(trav = T.children[i]; trav != NULL && trav->node != childIdx; trav = trav->link) {}

            if(trav != NULL) retval = i;
        }
    }
    return retval;
}

void displayTree(Tree T) {
    for(int i = 0; i < MAX; i++) {
        List trav;
        printf("[%d]: ", i);
        for(trav = T.children[i]; trav != NULL; trav = trav->link) {
            printf("[%d] -> ", trav->node);
        }
        printf("\n");
    }
}