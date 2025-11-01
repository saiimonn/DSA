#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct {
    int arr[MAX];
    int lastIdx;
} Tree;

void initTree(Tree *);
void insert(Tree *, int);
int deleteMin(Tree *);
void heapSort(Tree *);
void display(Tree);

int main() {
    Tree T;
    initTree(&T);
    
    insert(&T, 3); //0
    insert(&T, 5); //1
    insert(&T, 9); //2
    insert(&T, 8); //3
    insert(&T, 6); //4
    insert(&T, 9); //5
    insert(&T, 10); //6
    insert(&T, 10);  //7
    insert(&T, 18); //8
    insert(&T, 9);  //9
    insert(&T, 4);  //10

    display(T);
}

void initTree(Tree *T) {
    T->lastIdx = -1;
}

void insert(Tree *T, int x) {
    if(T->lastIdx + 1 < MAX) {
        T->arr[++T->lastIdx] = x;

        int child = T->lastIdx;
        int parent = (child - 1) / 2;

        while(child > 0 && T->arr[parent] > T->arr[child]) {
            int temp = T->arr[parent];
            T->arr[parent] = T->arr[child];
            T->arr[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

int deleteMin(Tree *T) {
    int temp = -1;
    if(T->lastIdx >= 0) {
        temp = T->arr[0];
        int data = T->arr[T->lastIdx--];

        int parent = 0;
        int left = parent * 2 + 1;
        int right = parent * 2 + 2;

        int child;

        child = (right <= T->lastIdx && T->arr[left] < T->arr[right]) ? left : right;
        
        while(child <= T->lastIdx && T->arr[child] < data) {
            int tempo = T->arr[parent];
            T->arr[parent] = T->arr[child];
            T->arr[child] = tempo;

            parent = child;
            left = parent * 2 + 1;
            right = parent * 2 + 2;

            child = (right <= T->lastIdx && T->arr[left] < T->arr[right]) ? left : right;  
        }

        T->arr[parent] = data;
    }
    return temp;
}

// void heapSort(Tree *T) {

// }

void display(Tree T) {
    printf("Unsorted: ");
    for(int i = 0; i <= T.lastIdx; i++) {
        printf("%d ", T.arr[i]);
    }

    printf("\nSorted: ");
    int temp;
    while((temp = deleteMin(&T)) != -1) {
        printf("%d ", temp);
    }
}