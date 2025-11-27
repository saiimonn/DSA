#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef enum { VISITED = 1, UNVISITED = 0 } Status;

typedef struct node {
    int label;
    struct node *link;
} *VERTEX;

typedef VERTEX List[MAX];
typedef int Set[MAX];

void dfs(List, Set, int);
void initialize(List);
void insert(List, int[]);
void displayList(List);

int main(){
        int edges[][2] = { //depends on the arrangement of the nodes in the list
        {4, 6},
        {4, 5},
        {5, 1},
        {6, 5},
        {6, 3},
        {1, 3},
        {3, 0},
        {3, 2},
        {1, 2},
        {0, 1},
        {2, 0},
        {0, 2},
    }; //prints 4 5 1 2 0 3 6
    int size = sizeof(edges) / sizeof(edges[0]);
    
    List L;
    initialize(L);
    Set S = {0};
    
    for(int i = 0; i < size; i++) {
        insert(L, edges[i]);
    }
    displayList(L);

    printf("\nDFS: ");
    dfs(L, S, 4);
}

void initialize(List L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insert(List L, int edge[2]) {
    VERTEX newnode = (VERTEX)malloc(sizeof(struct node));
    
    if(newnode != NULL) {
        newnode->label = edge[1];
        newnode->link = L[edge[0]];
        L[edge[0]] = newnode;
    }
}

void displayList(List L) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(VERTEX trav = L[i]; trav != NULL; trav = trav->link) {
            printf("%3d -> ", trav->label);
        }
        printf("NULL\n");
    }
}

void dfs(List L, Set visited, int source) {
    visited[source] = VISITED;
    printf("%d ", source);

    for(VERTEX trav = L[source]; trav != NULL; trav = trav->link) {
        if(visited[trav->label] == UNVISITED) {
            dfs(L, visited, trav->label);
        }
    }
}