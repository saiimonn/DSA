#include <stdio.h>
#include <stdlib.h>
#define MAX 8
#define INF 9999

typedef struct {
    int tail, head;
    int wgt;
} EdgeType;

typedef struct {
    EdgeType edges[MAX - 1]; //edges in the spanning tree is n - 1
    int edgeCount;
    int totalWgt;
} MST;

typedef int Set[MAX];
typedef int Matrix[MAX][MAX];

MST prims(Matrix, int);
void displayEdgeList(EdgeType[], int);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);

int main(){
    int edges[][3] = {
        {1, 6, 10},
        {1, 2, 28},
        {2, 3, 16},
        {2, 7, 14},
        {3, 4, 12},
        {4, 7, 18},
        {4, 5, 22},
        {5, 7, 24},
        {6, 5, 25},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);

    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }

    displayMatrix(M);

    MST p = prims(M, 1);
    printf("Minimum wgt: %d\n", p.totalWgt);

    printf("Edges: ");
    displayEdgeList(p.edges, p.edgeCount);
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
    printf("\n");
}

/*
    1. Initialization
    initialize the spanTree's edgeCount and weight to 0
    initialize visited set to 0 and mark the source node as visited
    initialize the number of edges (n - 1)

    2. Finding min weight
    while(edgeCount < number of edges and total weight < 9999)
    initialize minEdge weight to INF

    go to the i rows where visited[i] == 1. This is your tail
    go to j columns where visited[j] == 0. You are finding the min weight

    
*/
MST prims(Matrix M, int source) {
    MST spanTree = {.edgeCount = 0, .totalWgt = 0};

    Set visited = {0};
    visited[source] = 1;
    int numEdges = MAX - 1;

    while(spanTree.edgeCount < numEdges && spanTree.totalWgt < INF) {
        EdgeType minEdge = {.wgt = INF};

        for(int i = 0; i < MAX; i++) {
            // for every visited node in the graph,
            // check if their heads for the min weight
            if(visited[i] == 1) {
                for(int j = 0; j < MAX; j++) {
                    //if the head isn't visited yet and its
                    // weight is less than the current min weight
                    if(visited[j] == 0 && M[i][j] < minEdge.wgt) {
                        EdgeType temp = {i, j, M[i][j]};
                        minEdge = temp;
                    }
                }
            }
        }

        //in case the tail node has no more more unvisited heads
        if(minEdge.wgt != INF) {
            spanTree.edges[spanTree.edgeCount++] = minEdge;
            spanTree.totalWgt += minEdge.wgt;
            visited[minEdge.head] = 1;
        } else break;
    }

    return spanTree;
}

void displayEdgeList(EdgeType edges[], int size) {
    for(int i = 0; i < size; i++) { 
        printf("[(%d, %d) = %d] ", edges[i].tail, edges[i].head, edges[i].wgt);
    }
}