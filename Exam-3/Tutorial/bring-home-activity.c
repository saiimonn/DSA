#include <stdio.h>
#include <stdlib.h>
#define MAX 9
#define INF 9999

typedef int Matrix[MAX][MAX];
typedef int Set[MAX];

int *dijkstraAlgorithm(Matrix, int);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);

/*
    A B C D E F G H I
    0 1 2 3 4 5 6 7 8
  0 
  1
  2
  3
  4
  5
  6
  7
  8
*/

int main() {
    //[vertex a, vertex b, weight between]
    int edges[][3] = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 7, 11},
        {1, 2, 8},
        {7, 8, 7},
        {7, 6, 1},
        {2, 8, 2},
        {2, 5, 4},
        {2, 3, 7},
        {6, 8, 6},
        {6, 5, 2},
        {5, 3, 14},
        {5, 4, 10},
        {3, 4, 9},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);

    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }

    displayMatrix(M);

    int *d = dijkstraAlgorithm(M, 3);

    printf("\nShortest path from D to all vertices:\n");
    for(int i = 0; i < MAX; i++) {
        printf("D to %c: %d\n", i + 65 ,d[i]);
    }
}

void initialize(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
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
            if(M[i][j] == INF) printf("INF ");
            else printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
}

int *dijkstraAlgorithm(Matrix M, int source) {
    Set visited = {0};
    visited[source] = 1;

    int *distance = (int*)malloc(sizeof(int) * MAX);

    for(int i = 0; i < MAX; i++) {
        distance[i] = M[source][i];
    }
    distance[source] = 0;

    for(int i = 0; i < MAX; i++) {
        int smallestIdx = -1;

        for(int j = 0; j < MAX; j++) {
            if(!visited[j] && (smallestIdx == -1 || distance[j] < distance[smallestIdx])) {
                smallestIdx = j;
            }
        }

        visited[smallestIdx] = 1;

        for(int k = 0; k < MAX; k++) {
            if(visited[k] == 0) {
                int wgt = distance[smallestIdx] + M[smallestIdx][k];
                distance[k] = (wgt < distance[k]) ? wgt : distance[k];
            }
        }
    }

    return distance;
}