#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int label;
    struct node *link;
} *VERTEX;

typedef VERTEX List[MAX];

void initialize(List);
void insert(List, int[]);
void displayList(List);
void displayEdges(List);

int main() {
    List L;
    initialize(L);

    int edges[][2] = {
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 4},
        {3, 4},
        {4, 5}
    };

    int numOfEdges = sizeof(edges) / sizeof(edges[0]);

    for(int i = 0; i < numOfEdges; i++) {
        insert(L, edges[i]);
    }

    printf("Adjacency List:\n");
    displayList(L);

    printf("\nList of Edges:\n");
    displayEdges(L);

    return 0;
}

void initialize(List L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insert(List L, int edge[2]) {
    VERTEX newnode = (VERTEX)malloc(sizeof(struct node));

    if(newnode != NULL) {
        newnode->label = edge[1];
        newnode->link = L[edge[0]];
        L[edge[0]] = newnode;
    }

    newnode = (VERTEX)malloc(sizeof(struct node));

    if(newnode != NULL) {
        newnode->label = edge[0];
        newnode->link = L[edge[1]];
        L[edge[1]] = newnode;
    }
}

void displayList(List L) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
            printf("%d ", trav->label);
        }
        printf("\n");
    }
}

void displayEdges(List L) {
    for(int i = 0; i < MAX; i++) {
        for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
            printf("(%d %d)\t", i, trav->label);
        }
    }
}