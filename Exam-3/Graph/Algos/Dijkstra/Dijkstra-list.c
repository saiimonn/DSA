#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef struct node{
    int label;
    int weight;
    struct node *link;
} *VERTEX;

typedef VERTEX Matrix[MAX];
typedef int Set[MAX];

int *dijkstra(Matrix, int);
void displayShortestPath(int[], int);
void initialize(Matrix);
void insert(Matrix, int[]);
void displayList(Matrix);


int main(){
    int edges[][3] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {4, 3, 2},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initialize(M);

    for(int i = 0; i < size; i++) {
        insert(M, edges[i]);
    }
    displayList(M);

    printf("\n");
    int root = 0;
    int *dj = dijkstra(M, root);
    displayShortestPath(dj, root);
}

void initialize(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        M[i] = NULL;
    }
}

void insert(Matrix M, int edge[3]) {
    VERTEX temp = (VERTEX)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->label = edge[1];
        temp->weight = edge[2];
        temp->link = M[edge[0]];
        M[edge[0]] = temp;
    }
}

void displayList(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(VERTEX trav = M[i]; trav != NULL; trav = trav->link) {
            printf("[label: %d weight: %d] ", trav->label, trav->weight);
        }
        printf("\n");
    }
}

int *dijkstra(Matrix M, int root) {
    int *shortestPath = (int*)malloc(sizeof(int) * MAX);

    if(shortestPath != NULL) {
        Set visited = {0};
        visited[root] = 1;

        for(int i = 0; i < MAX; i++) {
            shortestPath[i] = INF;
        }

        for(VERTEX trav = M[root]; trav != NULL; trav = trav->link) {
            shortestPath[trav->label] = trav->weight;
        }
        shortestPath[root] = 0;

        for(int i = 1; i < MAX; i++) {
            int min = INF;
            int minNode;

            for(int j = 0; j < MAX; j++) {
                //if not visited and its value is less than min
                if(visited[j] == 0 && shortestPath[j] < min) {
                    min = shortestPath[j];
                    minNode = j;
                }
            }

            if(min != INF) { //if there is a minimum
                visited[minNode] = 1;

                for(int j = 0; j < MAX; j++) {
                    if(visited[j] == 0) {
                        VERTEX trav;

                        for(trav = M[minNode]; trav != NULL && trav->label != j; trav = trav->link) {}

                        if(trav != NULL) {
                            shortestPath[j] = (trav->weight + min < shortestPath[j]) ? trav->weight + min : shortestPath[j];
                        }
                    }
                }
            } else {
                printf("Graph not connected\n");
            }
        }
    }
    return shortestPath;
}

void displayShortestPath(int arr[], int root) {
    printf("\nDijkstra's Paths from %d:\n", root);
    for(int i = 0; i < MAX; i++) {
        
        printf("Path from %d to %d: ", root, i);
        (arr[i] == 0) ? printf("NONE\n") : printf("%d\n", arr[i]);
    }
}