#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
#define INF 9999

typedef int Matrix[MAX][MAX];

int **floyds(Matrix);
void displayfloyds(int **);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);


int main() {
    int edges[][3] = {
        {0, 1, 2},  // Edge from 0 to 1 with weight 2
        {0, 2, 4},  // Edge from 0 to 2 with weight 4
        {1, 2, 1},  // Edge from 1 to 2 with weight 1
        {1, 3, 7},  // Edge from 1 to 3 with weight 7
        {2, 4, 3},  // Edge from 2 to 4 with weight 3
        {4, 3, 2}   // Edge from 4 to 3 with weight 2
    };

    int numOfEdges = sizeof(edges) / sizeof(edges[0]);
    
    Matrix M;
    initialize(M);

    for(int i = 0; i < numOfEdges; i++) {
        insert(M, edges[i]);
    }

    displayMatrix(M);

    int **floyd= floyds(M);
    printf("\nfloyds:\n");
    displayfloyds(floyd);

    return 0;
}

int **floyds(Matrix M) {
    int **floyds = (int**)malloc(sizeof(int*) * MAX);

    int i, j, k;
    for(i = 0; i < MAX; i++) {
        floyds[i] = (int*)malloc(sizeof(int) * MAX);
        memcpy(floyds[i], M[i], sizeof(int) * MAX);
    }

    for(k = 0; k < MAX; k++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                int wgt = floyds[i][k] + floyds[k][j];
                floyds[i][j] = (wgt < floyds[i][j]) ? wgt : floyds[i][j];
            }
        }
    }
    return floyds;
}

void displayfloyds(int **flyd) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            (flyd[i][j] == INF) ? printf("INF ") : printf("%3d ", flyd[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 

void initialize(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++){
            M[i][j] = INF;
        }
    }
}

void insert(Matrix M, int edge[3]) {
    M[edge[0]][edge[1]] = edge[2];
    M[edge[1]][edge[0]] = edge[2];
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            (M[i][j] == INF) ? printf("INF ") : printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
}