#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct {
    int arr[MAX];
    int lastIdx;
} MaxHeap;

void initTree(MaxHeap *);
void insert(MaxHeap *, int);
int deleteMax(MaxHeap *);
void display(MaxHeap);

int main() {
    MaxHeap M;
    initTree(&M);

    insert(&M, 3); //0
    insert(&M, 5); //1
    insert(&M, 9); //2
    insert(&M, 8); //3
    insert(&M, 6); //4
    insert(&M, 9); //5
    insert(&M, 10); //6
    insert(&M, 10);  //7
    insert(&M, 18); //8
    insert(&M, 9);  //9
    insert(&M, 4);  //10

    display(M);
}

void initTree(MaxHeap *M) {
    M->lastIdx = -1;
}

void insert(MaxHeap *M, int x) {
    if(M->lastIdx + 1 < MAX) {
        M->arr[++M->lastIdx] = x;

        int child = M->lastIdx;
        int parent = (child - 1) / 2;

        while(child > 0 && M->arr[parent] < M->arr[child]) {
            int temp = M->arr[child];
            M->arr[child] = M->arr[parent];
            M->arr[parent] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

int deleteMax(MaxHeap *M) {
    int temp = -1;

    if(M->lastIdx >= 0) {
        temp = M->arr[0];
        int data = M->arr[M->lastIdx--];
        
        int parent = 0;
        int left = parent * 2 + 1;
        int right = left + 1;

        int child = (M->arr[right] > M->arr[left]) ? right : left;

        while(child <= M->lastIdx && M->arr[child] > data) {
            M->arr[parent] = M->arr[child];

            parent = child;
            left = parent * 2 + 1;
            right = left + 1;

            child = (M->arr[right] > M->arr[left]) ? right : left;
        }
        M->arr[parent] = data;
    }
    return temp;
}

void display(MaxHeap M) {
    printf("Unsorted: ");
    for(int i = 0; i <= M.lastIdx; i++) {
        printf("%d ", M.arr[i]);
    }

    printf("\nSorted: ");
    int temp;
    while((temp = deleteMax(&M)) != -1) {
        printf("%d ", temp);
    }
}