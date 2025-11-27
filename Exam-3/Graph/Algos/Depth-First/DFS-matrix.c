#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

typedef enum { VISITED = 1, UNVISITED = 0 } Status;
typedef int Set[MAX];
typedef int Matrix[MAX][MAX];

void dfs(Matrix, Set, int);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);

int main() {
    int edges[][2] = { //arrangement of insertions doesn't matter in the matrix, output will always be the same
        {4, 5},
        {4, 6},
        {5, 1},
        {6, 5},
        {6, 3},
        {1, 3},
        {3, 2},
        {3, 0},
        {0, 1},
        {1, 2},
        {0, 2},
        {2, 0},
    }; //output: 4 5 1 2 0 3 6
    int size = sizeof(edges) / sizeof(edges[0]);
    
    Matrix M;
    initialize(M);

    Set S = {};
    
    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }
    displayMatrix(M);

    printf("\nDFS: ");
    dfs(M, S, 4);
}

void initialize(Matrix M) {
    for(int i = 0;i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

void insert(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
}

void dfs(Matrix M, Set visited, int source) {
    visited[source] = VISITED;
    printf("%d ", source);
    
    for(int i = 0; i < MAX; i++) {
        if(M[source][i] == 1 && visited[i] == UNVISITED) {
            dfs(M, visited, i);
        }
    }
}