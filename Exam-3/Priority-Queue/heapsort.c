#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

void heapify(int arr[], int size, int parent) {
    int min = parent;
    int left = parent * 2 + 1;
    int right = left + 1;

    if(left < size && arr[left] < arr[right]) min = left;
    if(right < size && arr[right] < arr[left]) min = right;

    if(min != parent) {
        int temp = arr[min];
        arr[min] = arr[parent];
        arr[parent] = temp;
        heapify(arr, size, min);
    }
}

void heapSort(int arr[], int size) {
    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(arr, size, i);
    }

    int lastIdx = size - 1;

    while(lastIdx >= 0) {
        int temp = arr[lastIdx];
        arr[lastIdx] = arr[0];
        arr[0] = temp;

        heapify(arr, lastIdx--, 0);
    }
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

}