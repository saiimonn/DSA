#include <stdio.h>
#include <stdlib.h>
#define MAX 11

typedef struct {
    int arr[MAX];
    int top;
} Stack;

typedef int Matrix[MAX][MAX];
typedef int Set[MAX];

int full(Stack);
int empty(Stack);
void initStack(Stack *);
void push(Stack *, int);
int pop(Stack *);
void initMatrix(Matrix);
void insertEdge(Matrix, int[]);
void displayMatrix(Matrix);
void dfs(Matrix, int);

int main() {
    int edges[][2] = {
        {4, 5},
        {4, 6},
        {5, 1},
        {6, 5},
        {6, 3},
        {1, 3},
        {1, 2},
        {3, 0},
        {3, 2},
        {0, 2},
        {0, 1},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initMatrix(M);

    for(int i = 0; i < size; i++) {
        insertEdge(M, edges[i]);
    }

    displayMatrix(M);
    printf("\nDFS: ");

    dfs(M, 1);
}

void initStack(Stack *S) {
    S->top = -1;
}

int full(Stack S) {
    return S.top + 1 == MAX;
}

int empty(Stack S) {
    return S.top == -1;
}

void push(Stack *S, int x) {
    if(!full(*S)) {
        S->arr[++S->top] = x;
    }
}

int pop(Stack *S) {
    int retval = S->arr[S->top];
    S->top--;
    return retval;
}

void initMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

void insertEdge(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void dfs(Matrix M, int root) {
    Set visited = {0};
    Stack St;
    initStack(&St);
    push(&St, root);

    while(!empty(St)) {
        int node = pop(&St);
        if(visited[node]) continue;
        visited[node] = 1;
        printf("%d ", node);

        for(int i = 0; i < MAX; i++) {
            if(visited[i] == 0 && M[node][i] != 0) {
                push(&St, i);
            }
        }
    }
}