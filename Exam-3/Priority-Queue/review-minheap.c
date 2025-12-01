#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//minheap
typedef struct {
    int arr[MAX];
    int lastIdx;
} Heap;

void initialize(Heap *H) {
    H->lastIdx = -1;
}

void insert(Heap *H, int x) {
    if(H->lastIdx + 1 < MAX) {
        H->arr[++H->lastIdx] = x;
        int child = H->lastIdx;
        int parent = (child - 1) / 2;
        
        while(child > 0 && H->arr[parent] > H->arr[child]) {
            int temp = H->arr[parent];
            H->arr[parent] = H->arr[child];
            H->arr[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

int delete(Heap *H) {
    int min = -1;
    if(H->lastIdx >= 0) {
        min = H->arr[0];
        int data = H->arr[H->lastIdx--];
        int parent = 0;
        int left = parent * 2 + 1;
        int right = left + 1;
        int child = (right <= H->lastIdx && H->arr[left] < H->arr[right]) ? left : right;

        while(child <= H->lastIdx && H->arr[child] < data) {
            int temp = H->arr[child];
            H->arr[child] = H->arr[parent];
            H->arr[parent] = temp;

            parent = child;
            left = parent * 2 + 1;
            right = left + 1;
            child = (right <= H->lastIdx && H->arr[left] < H->arr[right]) ? left : right;
        }
        H->arr[parent] = data;
    }
    return min;
}

int main() {
    Heap H;
    initialize(&H);

    printf("Inserting values into MinHeap:\n");
    insert(&H, 40);
    insert(&H, 20);
    insert(&H, 10);
    insert(&H, 60);
    insert(&H, 30);
    insert(&H, 50);

    printf("Heap array after inserts:\n");
    for (int i = 0; i <= H.lastIdx; i++) {
        printf("%d ", H.arr[i]);
    }
    printf("\n");

    printf("\nDeleting elements from MinHeap:\n");
    while (H.lastIdx >= 0) {
        int x = delete(&H);
        printf("Deleted: %d\n", x);
    }

    return 0;
}
