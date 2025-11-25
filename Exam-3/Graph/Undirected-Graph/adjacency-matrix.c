#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int Matrix[MAX][MAX];

void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);
void displayEdges(Matrix);

int main() {
    int edges[][2] = {
        {0, 1},
        {0, 3},
        {1, 3},
        {1, 4},
        {2, 1},
        {3, 1},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);

    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }
    displayMatrix(M);
    displayEdges(M);
}

void initialize(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX;  j++) {
            M[i][j] = 0;
        }
    }
}

void insert(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
    M[edge[1]][edge[0]] = 1;
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
}

void displayEdges(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(M[i][j] == 1) {
                printf("(%d %d)\t", i, j);
            }
        }
    }
}