#include <stdio.h>

void selectionSort(int [], int);
void read(int [], int);

int main() {
    int arr[] = {10, 43, 18, 23, 13};
    int size = sizeof(arr) / sizeof(int);

    selectionSort(arr, size);
    read(arr, size);
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n ;j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void read(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}