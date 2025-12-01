#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node {
    int label;
    struct node *link;
} *VERTEX;
typedef VERTEX List[MAX];
typedef int Matrix[MAX][MAX];

void initialize(List);
void insert(List, int[]);
void displayList(List);

int main() {
    int edges[][2] = {{1, 2}, {2, 3}, {3, 2}, {1, 3}};
    int ListSize = sizeof(edges) / sizeof(edges[0]);

    List L;
    initialize(L);

    for(int i = 0; i < ListSize; i++) {
        insert(L, edges[i]);
    }

    displayList(L);

    Matrix M;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }

    for(int i = 0; i < MAX; i++) {
        for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
            M[i][trav->label] = 1;
        }
    }

    printf("\nList converted to Matrix:\n");
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
}

void initialize(List M) {
    int i;
    for(i = 0; i < MAX; i++) {
        M[i] = NULL;
    }
}

/*
    edge[0] is the index, place the newnode at that index
    edge[1] is the label
*/
void insert(List M, int edge[2]) {
    VERTEX temp = (VERTEX)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[1];
        temp->link = M[edge[0]];
        M[edge[0]] = temp; //places temp at the "head"
    }
}

void displayList(List M) {
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