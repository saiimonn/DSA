#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
    int label;
    int weight;
    struct node *link;
} *VERTEX;

typedef VERTEX Matrix[MAX];

int *dijkstra(Matrix, int);
void displayShortestPath(int[], int);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayList(Matrix);


int main(){
    int edges[][3] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {4, 3, 2},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);

    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }
    displayList(M);
}

void initialize(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        M[i] = NULL;
    }
}

void insert(Matrix M, int edge[3]) {
    VERTEX temp = (VERTEX)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[1];
        temp->weight = edge[2];
        temp->link = M[edge[0]];
        M[edge[0]] = temp;
    }

    temp = (VERTEX)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[0];
        temp->weight = edge[2];
        temp->link = M[edge[1]];
        M[edge[1]] = temp;
    }
}

void displayList(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(VERTEX trav = M[i]; trav != NULL; trav = trav->link) {
            printf("[label: %d weight: %d] ", trav->label, trav->weight);
        }
        printf("\n");
    }
}