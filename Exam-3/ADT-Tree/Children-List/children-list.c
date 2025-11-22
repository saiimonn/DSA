#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum { ROOT = -1, EMPTY = -2 } Status;

typedef struct node {
    int data;
    struct node *link;
} *Node;

typedef Node Tree[MAX];

void initialize(Tree);
void insert(Tree, int, int);
int leftchild(Tree, int);
int rightsibling(Tree, int);
int parent(Tree, int);
void displayTree(Tree);

int main() {
    Tree T;
    
    initialize(T);
    
    printf("=== Testing Tree Operations ===\n\n");
    
    // Insert root node
    insert(T, 10, ROOT);  // Root node
    
    // Insert children
    insert(T, 5, 0);   // Child of node at index 0
    insert(T, 15, 0);  // Another child of node at index 0
    
    // Insert more nodes
    insert(T, 3, 1);   // Child of node at index 1
    insert(T, 7, 1);   // Another child of node at index 1
    insert(T, 12, 2);  // Child of node at index 2
    insert(T, 20, 2);  // Another child of node at index 2
    insert(T, 1, 0);
    
    // Display tree structure
    displayTree(T);
    
    // Test functions
    printf("\n1. Testing parent function:\n");
    printf("   Parent of 5: index %d\n", parent(T, 5));
    printf("   Parent of 15: index %d\n", parent(T, 15));
    printf("   Parent of 3: index %d\n", parent(T, 3));
    printf("   Parent of 7: index %d\n", parent(T, 7));
    printf("   Parent of 12: index %d\n", parent(T, 12));
    printf("   Parent of 20: index %d\n", parent(T, 20));
    printf("   Parent of 99: %d\n", parent(T, 99));
    
    printf("\n2. Testing rightsibling function:\n");
    printf("   Right sibling of 5: %d\n", rightsibling(T, 5));
    printf("   Right sibling of 15: %d\n", rightsibling(T, 15));
    printf("   Right sibling of 3: %d\n", rightsibling(T, 3));
    printf("   Right sibling of 7: %d\n", rightsibling(T, 7));

    printf("\n3. Testing leftchild function:\n");
    printf("    Left child of 10: %d\n", leftchild(T, 0));
    printf("    Left child of 12: %d\n", leftchild(T, 2));
    
    return 0;
}

void initialize(Tree T) {
    for(int i = 0; i < MAX; i++) {
        T[i] = NULL;
    }
}

void insert(Tree T, int data, int parentIdx){
    if(parentIdx == ROOT) {
        // Find first empty slot for root
        for(int i = 0; i < MAX; i++) {
            if(T[i] == NULL) {
                T[i] = malloc(sizeof(struct node));
                T[i]->data = data;
                T[i]->link = NULL;
                return;
            }
        }
    } else if(parentIdx >= 0 && parentIdx < MAX) {
        // Add to existing parent's child list
        Node *ptr = &T[parentIdx];
        while(*ptr != NULL) {
            ptr = &(*ptr)->link;
        }
        *ptr = malloc(sizeof(struct node));
        (*ptr)->data = data;
        (*ptr)->link = NULL;
    }
}

int leftchild(Tree T, int parentIdx) {
    if(parentIdx >= 0 && parentIdx < MAX && T[parentIdx] != NULL && T[parentIdx]->link != NULL) {
        return T[parentIdx]->link->data;
    }
    return -1;
}

int rightsibling(Tree T, int x) {
    for(int i = 0; i < MAX; i++) {
        Node ptr = T[i];
        while(ptr != NULL && ptr->link != NULL) {
            if(ptr->data == x) {
                return ptr->link->data;
            }
            ptr = ptr->link;
        }
    }
    return -1;
}

int parent(Tree T, int x) {
    for(int i = 0; i < MAX; i++) {
        Node ptr = T[i];
        while(ptr != NULL) {
            if(ptr->data == x) {
                return i;
            }
            ptr = ptr->link;
        }
    }
    return -1;
}

void displayTree(Tree T) {
    printf("Tree Structure:\n");
    for(int i = 0; i < MAX; i++) {
        if(T[i] != NULL) {
            printf("  Index %d: ", i);
            Node ptr = T[i];
            while(ptr != NULL) {
                printf("%d", ptr->data);
                ptr = ptr->link;
                if(ptr != NULL) printf(" -> ");
            }
            printf("\n");
        }
    }
}