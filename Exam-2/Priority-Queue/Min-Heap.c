#include <stdio.h>
#define MAX 15

typedef struct {
    int arr[MAX];
    int lastIdx;
} MinHeap;

void initTree(MinHeap *);
void insert(MinHeap *, int);
int deleteMin(MinHeap *);
void display(MinHeap);

int main() {
    MinHeap M;
    initTree(&M);

    insert(&M, 3); //0
    insert(&M, 5); //1
    insert(&M, 9); //2
    insert(&M, 8); //3
    insert(&M, 6); //4
    insert(&M, 9); //5
    insert(&M, 10); //6
    insert(&M, 10); //7
    insert(&M, 18); //8
    insert(&M, 9);  //9
    insert(&M, 4);  //10

    display(M);
}

void initTree(MinHeap *M) {
    M->lastIdx = -1;
}

void insert(MinHeap *M, int x) {
    if(M->lastIdx + 1 < MAX) {
        M->arr[++M->lastIdx] = x;

        int child = M->lastIdx;
        int parent = (child - 1) / 2;

        while(child > 0 && M->arr[parent] > M->arr[child]) {
            int temp = M->arr[parent];
            M->arr[parent] = M->arr[child];
            M->arr[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

int deleteMin(MinHeap *M) {
    int temp = -1;
    if(M->lastIdx >= 0) {
        temp = M->arr[0];
        int data = M->arr[M->lastIdx--];

        int parent = 0;
        int left = parent * 2 + 1;
        int right = left + 1;
        int child = (right <= M->lastIdx && M->arr[left] < M->arr[right]) ? left : right;

        while(child <= M->lastIdx && M->arr[child] < data) {
            int tempo = M->arr[parent];
            M->arr[parent] = M->arr[child];
            M->arr[child] = tempo;

            parent = child;
            left = parent * 2 + 1;
            right = left + 1;
            child = (right <= M->lastIdx && M->arr[left] < M->arr[right]) ? left : right;
        }
        M->arr[parent] = data;
    }
    return temp;
}

void display(MinHeap M) {
    printf("Unsorted: ");
    for(int i = 0; i <= M.lastIdx; i++) {
        printf("%d ", M.arr[i]);
    }

    printf("\nSorted: ");
    int temp;
    while((temp = deleteMin(&M)) != -1) {
        printf("%d ", temp);
    }
}