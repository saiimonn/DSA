#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef int Matrix[MAX][MAX];

void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);
void displayPairs(Matrix);

int main() {
    int edges[][2] = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {3, 1}};
    int size = sizeof(edges) / sizeof(edges[0]); // 24 / 8 = 3

    Matrix M;
    initialize(M);

    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }

    displayMatrix(M);
    displayPairs(M);
}

void initialize(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        int j;
        for(j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

void insert(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
}

void displayMatrix(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        int j;
        for(j = 0; j < MAX; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void displayPairs(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        int j;
        for(j = 0; j < MAX; j++) {
            if(M[i][j] == 1) {
                printf("(%d %d) ", i, j);
            }
        }
    }
}