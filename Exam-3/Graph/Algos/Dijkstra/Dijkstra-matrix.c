#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef int Set[MAX];
typedef int Matrix[MAX][MAX];

int *dijkstra(Matrix, int);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);
void displayShortestPath(int[], int);

int main() {
    //[][0] = vertex 
    //[][1] = vertex
    //[][2] = weight
    int edges[][3] = {
        {0, 1, 10}, 
        {0, 3, 30}, 
        {0, 4, 100}, 
        {1, 2, 50}, 
        {2, 0, 20}, 
        {2, 4, 10}, 
        {3, 2, 20}, 
        {3, 4, 60}
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);


    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }   

    displayMatrix(M);

    int root = 0;
    int *shortestPath = dijkstra(M, root);
    displayShortestPath(shortestPath, root);
}

void initialize(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        int j;
        for(j = 0; j < MAX; j++) {
            M[i][j] = INF;
        }
    }
}

void insert(Matrix M, int edge[3]) {
    M[edge[0]][edge[1]] = edge[2];
}

void displayMatrix(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        int j;
        for(j = 0; j < MAX; j++) {
            (M[i][j] == INF) ? printf("INF ") : printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
}

int *dijkstra(Matrix M, int root) {
    int *shortestPath = (int*)malloc(sizeof(int) * MAX);

    if(shortestPath != NULL) {
        /*
            Initialized the set to have all 0's
            the index of root of the set will be 1
        */
        Set visited = {0};
        visited[root] = 1;


        /*
            Initialize the array
            All columns in the root's row will be added in the array
            shortestPath[root] = 0 because there is no shortest path from a vertex to itself.
        */
        for(int i = 0; i < MAX; i++) {
            shortestPath[i] = M[root][i];
        }
        shortestPath[root] = 0;

        for(int i = 1; i < MAX; i++) {
            int smallestIdx = -1;

            for(int j = 0; j < MAX; j++) {
                if(visited[j] == 0) {
                    // first condition: assigns smallestIdx to the first index that's not in the visited set
                    // second condition: compares current element and element of smallestIdx
                    if(smallestIdx == -1 || shortestPath[j] < shortestPath[smallestIdx]) {
                        smallestIdx = j;
                    }
                }
            }

            visited[smallestIdx] = 1;

            for(int k = 0; k < MAX; k++) {
                if(visited[k] == 0) {
                    int next = shortestPath[smallestIdx] + M[smallestIdx][k];
                    shortestPath[k] = (shortestPath[k] < next) ? shortestPath[k] : next;
                }
            }
        }
    }
    return shortestPath;
}

void displayShortestPath(int arr[], int root) {
    for(int i = 0; i < MAX; i++) {
        printf("Path from %d to %d: ", root, i);
        (arr[i] == INF) ? printf("NONE\n") : printf("%d\n", arr[i]);
    }
}