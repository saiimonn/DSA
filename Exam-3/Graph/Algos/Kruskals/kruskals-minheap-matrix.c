#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MAX_EDGE 20
#define INF 9999

typedef int Matrix[MAX][MAX];

typedef struct {
    int tail, head;
    int wgt;
} EdgeType;

typedef struct {
    EdgeType edges[MAX_EDGE];
    int lastNdx;
} MinHeapList;

typedef struct {
    MinHeapList List;
    int cost;
} MST;


MST kruskals(Matrix);
void initMatrix(Matrix);
void insert(Matrix, EdgeType);

void heapify(MinHeapList *, int);
void insertHeap(MinHeapList *, EdgeType);
EdgeType deleteMin(MinHeapList *);
MinHeapList createHeap(Matrix);

int main() {

}

MST kruskals(Matrix M) {
    MST k = {{.lastNdx = -1}, .cost = 0};
    MinHeapList prioqueue = createHeap(M);

    int comp[MAX];
    for(int i = 0;i < MAX; i++) {
        comp[i] = i;
    }

    while(prioqueue.lastNdx >= 0) {
        EdgeType min = deleteMin(&prioqueue);

        if(comp[min.tail] != comp[min.head]) {
            int change = comp[min.tail];

            for(int i = 0;i < MAX; i++) {
                if(comp[i] == change) {
                    comp[i] = comp[min.head];
                }
            }

            insertHeap(&k.List, min);
            k.cost += min.wgt;
        }
    }
    return k;
}

MinHeapList createHeap(Matrix M) {
    MinHeapList heap = {.lastNdx = -1};

    for(int i = 0; i < MAX; i++) {
        for(int j = i + 1; j < MAX; j++) {
            if(M[i][j] != INF) {
                insertHeap(&heap, (EdgeType){i, j, M[i][j]});
            }
        }
    }
}

void insertHeap(MinHeapList *L, EdgeType edge){
    if(L->lastNdx + 1 < MAX) {
        // int child = ++L->lastNdx;
        // int parent = (child - 1) / 2;

        // while(child > 0 && L->edges[parent].wgt > L->edges[child].wgt) {
        //     L->edges[child] = L->edges[parent];
        //     child = parent;
        //     parent = (child - 1) / 2;
        // }
        // L->edges[child] = edge;
        L->edges[++L->lastNdx] = edge;
        int child = L->lastNdx;
        int parent = (child - 1) / 2;

        while(child > 0 && L->edges[parent].wgt > L->edges[child].wgt) {
            EdgeType temp = L->edges[parent];
            L->edges[parent] = L->edges[child];
            L->edges[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

void heapify(MinHeapList *L, int parent) {
    int smallest = parent;
    int left = smallest * 2 + 1;
    int right = left + 1;

    if(left <= L->lastNdx && L->edges[left].wgt < L->edges[right].wgt) {
        smallest = left;
    }

    if(right <= L->lastNdx && L->edges[right].wgt < L->edges[left].wgt) {
        smallest = right;
    }

    if(smallest != parent) {
        EdgeType temp = L->edges[smallest];
        L->edges[smallest] = L->edges[parent];
        L->edges[parent] = temp;
        heapify(L, smallest);
    }
}

void initMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = INF;
        }
    }
}

void insert(Matrix M, EdgeType edge) {
    M[edge.tail][edge.head] = edge.wgt;
    M[edge.head][edge.tail] = edge.wgt;
}