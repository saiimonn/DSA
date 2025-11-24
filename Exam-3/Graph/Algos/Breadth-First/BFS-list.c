#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef int Set[MAX];

typedef struct node {
    int label;
    struct node *link;
} *VERTEX;

typedef VERTEX Matrix[MAX];

typedef struct {
    int nodes[MAX];
    int front;
    int rear;
} Queue;

void bfs(Matrix, int);
void initQueue(Queue *);
bool isEmpty(Queue);
void enqueue(Queue *, int);
int dequeue(Queue *);

void initList(Matrix);
void insertEdge(Matrix, int[]);
void displayList(Matrix);
void displayEdges(Matrix);

int main() {    
    int edges[][2] = {
        {0, 1},
        {1, 4},
        {1, 2},
        {2, 3},
        {3, 4},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initList(M);

    for(int i = 0; i < size; i++) {
        insertEdge(M, edges[i]);
    }

    displayList(M);
    displayEdges(M);
    bfs(M, 0);
}

void initQueue(Queue *Q) {
    Q->front = 1;
    Q->rear = 0;
}

bool isEmpty(Queue Q) {
    return (Q.rear + 1) % MAX == Q.front;
}

void enqueue(Queue *Q, int x) {
    if((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->nodes[Q->rear] = x;
    }
}

int dequeue(Queue *Q) {
    int retval = -1;
    if(!isEmpty(*Q)) {
        retval = Q->nodes[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }
    return retval;
}

void initList(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        M[i] = NULL;
    }
}

void insertEdge(Matrix M, int edge[2]) {
    VERTEX newnode = (VERTEX)malloc(sizeof(struct node));

    if(newnode != NULL) {
        newnode->label = edge[1];
        newnode->link = M[edge[0]];
        M[edge[0]] = newnode;
    }

    newnode = (VERTEX)malloc(sizeof(struct node));

    if(newnode != NULL) {
        newnode->label = edge[0];
        newnode->link = M[edge[1]];
        M[edge[1]] = newnode;
    }
}

void displayList(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(VERTEX trav = M[i]; trav != NULL; trav = trav->link) {
            printf("[label: %d] ", M[i]->label);
        }
        printf("\n");
    }
}

void displayEdges(Matrix M) {
    printf("Edges: ");
    for(int i = 0; i < MAX; i++) {
        for(VERTEX trav = M[i]; trav != NULL; trav = trav->link) {
            if(trav->label > i) {
                printf("(%d %d)\t", i, trav->label);
            }
        }
    }
    printf("\n");
}

void bfs(Matrix M, int source) {
    Set visited = {};
    visited[source] = 1;

    Queue Q;
    initQueue(&Q);
    enqueue(&Q, source);

    printf("BFS: ");
    while(!isEmpty(Q)) {
        int node = dequeue(&Q);
        printf("%d ", node);

        for(VERTEX trav = M[node]; trav != NULL; trav = trav->link) {
            if(visited[trav->label] == 0) {
                visited[trav->label] = 1;
                enqueue(&Q, trav->label);
            }
        }
    }
}