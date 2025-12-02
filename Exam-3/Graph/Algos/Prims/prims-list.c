#include <stdio.h>
#include <stdlib.h>
#define MAX 8
#define INF 9999

typedef struct {
    int tail, head;
    int wgt;
} EdgeType;

typedef struct {
    EdgeType edges[MAX - 1];
    int edgeCount;
    int totalWgt;
} MST;

typedef struct node {
    int label;
    int wgt;
    struct node *link;
} *VERTEX;

typedef VERTEX List[MAX];
typedef int Set[MAX];

MST prims(List, int);
void initialize(List);
void insert(List, int[]);
void displayList(List);
void displayEdgeList(EdgeType[], int);

int main(){
    int edges[][3] = {
        {1, 2, 28},
        {1, 6, 10},
        {2, 3, 16},
        {2, 7, 14},
        {3, 4, 12},
        {4, 5, 22},
        {4, 7, 18},
        {5, 7, 24},
        {5, 6, 25},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    List L;
    initialize(L);

    for(int i = 0; i < size; i++) {
        insert(L, edges[i]);
    }

    displayList(L);

    MST p = prims(L, 1);

    printf("Minimum cost: %d\n", p.totalWgt);

    displayEdgeList(p.edges, p.edgeCount);
}

MST prims(List L, int source) {
    MST spanTree = {.edgeCount = 0, .totalWgt = 0};
    Set visited = {0};
    visited[source] = 1;
    int numEdges = MAX - 1;

    while(spanTree.edgeCount < numEdges && spanTree.totalWgt < INF) {
        EdgeType minEdge = {.wgt = INF};

        for(int i = 0; i < MAX; i++) {
            if(visited[i] == 1) {
                for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
                    if(visited[trav->label] == 0 && trav->wgt < minEdge.wgt) {
                        EdgeType temp = {i, trav->label, trav->wgt};
                        minEdge = temp;
                    }
                }
            }
        }

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

void initialize(List L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insert(List L, int edges[3]) {
    VERTEX new = (VERTEX)malloc(sizeof(struct node));

    if(new != NULL) {
        new->wgt = edges[2];
        new->label = edges[0];
        new->link = L[edges[1]];
        L[edges[1]] = new;
    }

    new = (VERTEX)malloc(sizeof(struct node));

    if(new != NULL) {
        new->wgt = edges[2];
        new->label = edges[1];
        new->link = L[edges[0]];
        L[edges[0]] = new;
    }
}

void displayList(List L) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
            printf("[%d | %d] ", trav->label, trav->wgt);
        }
        printf("\n");
    }
}