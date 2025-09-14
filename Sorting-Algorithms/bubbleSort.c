#include <stdio.h>

void bubbleSort(int [], int);
void read(int [], int);

int main() {
    int arr[] = {318, 314, 401, 173, 180};
    int size = sizeof(arr) / sizeof(int);

    bubbleSort(arr, size);
    read(arr, size);
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void read(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}