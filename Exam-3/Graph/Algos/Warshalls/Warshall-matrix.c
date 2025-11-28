#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef int Matrix[MAX][MAX];

int** warshall(Matrix);
void displayWarshalls(int**);
void initialize(Matrix);
void insert(Matrix, int edge[2]);
void displayMatrix(Matrix);
void displayEdges(Matrix);

int main(){
    int edges[][2] = {
        {0, 1},  // Edge from 0 to 1 
        {0, 2},  // Edge from 0 to 2 
        {1, 2},  // Edge from 1 to 2 
        {1, 3},  // Edge from 1 to 3
        {2, 4},  // Edge from 2 to 4
        {4, 3}   // Edge from 4 to 3
    };

    int numOfEdges = sizeof(edges) / sizeof(edges[0]);
    
    Matrix M;
    initialize(M);

    for(int i = 0; i < numOfEdges; i++) {
        insert(M, edges[i]);
    }

    displayMatrix(M);

    int **warsh = warshall(M);
    printf("Warshalls:\n");
    displayWarshalls(warsh);
}

void initialize(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

int** warshall(Matrix C) {
    int **warshall = (int**)malloc(sizeof(int*) * MAX);

    int i, j, k;
    //copies contents of matrix C
    for(i = 0; i < MAX; i++) {
        warshall[i] = (int*)malloc(sizeof(int) * MAX);
        for(j = 0; j < MAX; j++) {
            warshall[i][j] = C[i][j];
        }
    }

    for(i = 0; i < MAX; i++) {
        warshall[i][i] = 0;
    }

    for(k = 0; k < MAX; k++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                /* 
                    if there's a path from i to k & a path from k to j, 
                    then there is a path from i to j
                */ 
                //if k == i and k == j, therefore i == j
                if(i != j) {
                    warshall[i][j] = warshall[i][j] || (warshall[i][k] && warshall[k][j]);
                }
            }
        }
    }

    return warshall;
}

void displayWarshalls(int **warsh) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d", warsh[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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