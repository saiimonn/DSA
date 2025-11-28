#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
#define INF 9999

typedef struct node {
    int label;
    struct node *link;
} *VERTEX;

typedef VERTEX List[MAX];

void Floyds(List);
void initialize(List);
void insert(List, int[]);
void displayList(List);

int main() {
    int edges[][2] = {
        {0, 1},
        {0, 2},  
        {1, 2},  
        {1, 3},  
        {2, 4},  
        {4, 3}   
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    List L;
    initialize(L);
    for(int i = 0; i < size; i++) {
        insert(L, edges[i]);
    }

    displayList(L);
    Floyds(L);
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
            printf("[%d] -> ", trav->label);
        }
        printf("NULL\n");
    }
}

void Floyds(List L) {
    int matrix[MAX][MAX];

    int i, j, k;
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            matrix[i][j] = (i == j) ? 0 : INF;
        }
    }

    for(i = 0; i < MAX; i++) {
        for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
            matrix[i][trav->label] = 1;
        }
    }

    for(k = 0; k < MAX; k++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                if(i != j) {
                    matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
                }
            }
        }
    }

    printf("\nFloyd-Warshall shi:\n");
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            if(matrix[i][j] == INF) printf("INF ");
            else printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}