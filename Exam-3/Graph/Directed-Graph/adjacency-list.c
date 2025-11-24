#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node {
    int label;
    struct node *link;
} *VERTEX;

typedef VERTEX Matrix[MAX];

void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);
void displayEdges(Matrix);

int main() {
    int edges[][2] = {{1, 2}, {2, 3}, {3, 2}, {1, 3}};
    int MatrixSize = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);

    for(int i = 0; i < MatrixSize; i++) {
        insert(M, edges[i]);
    }

    displayMatrix(M);
    displayEdges(M);
}

void initialize(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        M[i] = NULL;
    }
}

/*
    edge[0] is the index, place the newnode at that index
    edge[1] is the label
*/
void insert(Matrix M, int edge[2]) {
    VERTEX temp = (VERTEX)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[1];
        temp->link = M[edge[0]];
        M[edge[0]] = temp; //places temp at the "head"
    }
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);

        VERTEX trav = M[i];

        if(trav != NULL) {
            for(; trav != NULL; trav = trav->link) {
                printf("%d ", trav->label);
            }
        } else {
            printf("EMPTY");
        }
        printf("\n");
    }
}

void displayEdges(Matrix M) {
    printf("Edges: ");
    for(int i = 0; i < MAX; i++) {
        for(VERTEX trav = M[i]; trav != NULL; trav = trav->link) {
            printf("(%d, %d) ", i, trav->label);
        }
    }
}