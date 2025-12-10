#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

void maxHeapify(int arr[], int size, int parent) {
    int max = parent;
    int left = parent * 2 + 1;
    int right = left + 1;

    if(left < size && arr[left] > arr[max]) max = left;
    if(right < size && arr[right] > arr[max]) max = right;

    if(max != parent) {
        int temp = arr[max];
        arr[max] = arr[parent];
        arr[parent] = temp;
        maxHeapify(arr, size, max);
    }
}

void maxHeapSort(int arr[], int size) {
    for(int i = (size - 1) / 2; i >= 0; i--){
        maxHeapify(arr, size, i);
    }

    int lastIdx = size - 1;

    while(lastIdx >= 0) {
        printf("%d ", arr[0]);
        int temp = arr[lastIdx];
        arr[lastIdx] = arr[0];
        arr[0] = temp;

        maxHeapify(arr, lastIdx--, 0);
    }
}

void minHeapify(int arr[], int size, int parent) {
    int min = parent;
    int left = parent * 2 + 1;
    int right = left + 1;

    if(left < size && arr[left] < arr[min]) min = left;
    if(right < size && arr[right] < arr[min]) min = right;

    if(min != parent) {
        int temp = arr[min];
        arr[min] = arr[parent];
        arr[parent] = temp;
        minHeapify(arr, size, min);
    }
}

void minHeapSort(int arr[], int size) {
    for(int i = (size - 1) / 2; i >= 0; i--) {
        minHeapify(arr, size, i);
    }

    int lastIdx = size - 1;

    while(lastIdx >= 0) {
        printf("%d ", arr[0]);
        int temp = arr[0];
        arr[0] = arr[lastIdx];
        arr[lastIdx] = temp;

        minHeapify(arr, lastIdx--, 0);
    }
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 3, 17, 8, 34, 25, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    minHeapSort(arr, size);
    printf("\n\nHeap sort using minheap:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    maxHeapSort(arr, size);
    printf("\n\nHeap sort using maxheap:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}