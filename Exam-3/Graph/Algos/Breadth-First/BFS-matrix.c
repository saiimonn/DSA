#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef int Set[MAX];

typedef struct {
    int nodes[MAX];
    int front;
    int rear;
} Queue;

typedef int Matrix[MAX][MAX];

void bfs(Matrix, int);
void initQueue(Queue *);
bool isEmpty(Queue);
void enqueue(Queue *, int);
int dequeue(Queue *);

void initMatrix(Matrix);
void insertEdge(Matrix, int[]);
void displayMatrix(Matrix);
void displayEdges(Matrix);

int main() {
    int edges[][2] = {
        {0, 1},
        {1, 4},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initMatrix(M);

    for(int i = 0; i < size; i++) {
        insertEdge(M, edges[i]);
    }

    displayMatrix(M);
    printf("\n");
    displayEdges(M);

    printf("\n");
    bfs(M, 0);
}

void initMatrix(Matrix M) {
    int i;
    for(i = 0; i < MAX; i++) {
        int j;
        for(j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

void insertEdge(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++){
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
}

void displayEdges(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(M[i][j] == 1) printf("(%d %d)\t", i, j);
        }
    }
}

void initQueue(Queue *Q) {
    Q->front = 1;
    Q->rear = 0;
}

void enqueue(Queue *Q, int x) {
     if((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->nodes[Q->rear] = x;
     }
}

bool isEmpty(Queue Q) {
    return (Q.rear + 1) % MAX == Q.front;
}

int dequeue(Queue *Q) {
    int retval = -1;
    if(!isEmpty(*Q)) {
        retval = Q->nodes[Q->front];
        Q->front = (Q->front + 1) % MAX; 
    }
    return retval;
}

void bfs(Matrix M, int source) {
    //1. initialization
    Set visited = {};
    Queue Q;
    initQueue(&Q);

    //2. enqueue source node 
    enqueue(&Q, source);

    while(!isEmpty(Q)) {
        int node = dequeue(&Q);
        printf("%d ", node);

        for(int i = 0; i < MAX; i++) {
            //if not visited and its value in the matrix is not 0: mark as visited and enqueue i
            if(visited[i] == 0 && M[node][i] != 0) {
                visited[i] = 1;
                enqueue(&Q, i);
            }
        }
    }
}