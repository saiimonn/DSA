#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef struct {
    int tail, head;
    int wgt;
} EdgeType;

typedef struct node {
    EdgeType node;
    struct node *link;
} *EdgeList;

typedef struct {
    EdgeList nodes;
    int totalWgt;
} MST;

typedef int Matrix[MAX][MAX];

EdgeList createEdgeList(Matrix M);
MST kruskals(Matrix M);
void displayEdgeList(EdgeList edges);

void initializeMatrix(Matrix);
void insertAtMatrix(Matrix, int[]);
void displayMatrix(Matrix);

int main() {
    int edges[][3] = {
        {0, 1, 2},  
        {0, 2, 4},  
        {1, 2, 1},  
        {1, 3, 7},  
        {2, 4, 3},  
        {4, 3, 2}   
    };
    int size = sizeof(edges) / sizeof(edges[0]);
    
    Matrix M;
    initializeMatrix(M);

    for(int i = 0; i < size; i++) {
        insertAtMatrix(M, edges[i]);
    }

    displayMatrix(M);

    EdgeList eList = createEdgeList(M);
    printf("Initial edge list: ");
    displayEdgeList(eList);

    MST krus = kruskals(M);
    printf("Min wgt: %d\n", krus.totalWgt);

    printf("MCT Edges: ");
    displayEdgeList(krus.nodes);
}

EdgeList createEdgeList(Matrix M) {
    EdgeList edges = NULL;

    for(int i = 0; i < MAX; i++) {
        for(int j = i + 1; j < MAX; j++) { // skips the mirror and the diagonal
            if(M[i][j] != INF) {
                EdgeType e = {i, j, M[i][j]};

                EdgeList temp = (EdgeList)malloc(sizeof(struct node));

                if(temp != NULL) {
                    EdgeList *trav;
                    for(trav = &edges; *trav != NULL && (*trav)->node.wgt < e.wgt; trav = &(*trav)->link) {}

                    temp->node = e;
                    temp->link = *trav;
                    *trav = temp;
                }
            }
        }
    }
    return edges;
}

void displayEdgeList(EdgeList edges) {
    for(; edges != NULL; edges = edges->link) {
        printf("[(%d, %d) = %d] ", edges->node.tail, edges->node.head, edges->node.wgt);
    }
    printf("\n");
}

MST kruskals(Matrix M) {
    MST minCost= {.nodes = NULL, .totalWgt = 0};
    int treeGrp[MAX];

    for(int i = 0; i < MAX; i++) {
        treeGrp[i] = i;
    }

    EdgeList edges = createEdgeList(M);

    while (edges != NULL) {
        EdgeList temp = edges;
        edges = edges->link;

        int u = temp->node.tail;
        int v = temp->node.head;

        if(treeGrp[u] != treeGrp[v]) {
            minCost.totalWgt += temp->node.wgt;

            int change = treeGrp[u];

            for(int i = 0; i < MAX; i++) {
                if(treeGrp[i] == change) {
                    treeGrp[i] = treeGrp[v];
                }
            }

            temp->link = minCost.nodes;
            minCost.nodes = temp;
        } else {
            free(temp);
        }
    }
    return minCost;
}

void initializeMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = INF;
        }
    }
}

void insertAtMatrix(Matrix M, int edge[3]) {
    M[edge[0]][edge[1]] = edge[2];
    M[edge[1]][edge[0]] = edge[2];
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j =0 ; j < MAX; j++) {
            (M[i][j] == INF) ? printf("INF ") : printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}