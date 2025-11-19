#include <stdio.h>
#define MAX 10

int binarySearch(int [], int);

int main(){ 
    int arr[MAX] = {2, 6, 8, 13, 14, 18, 21, 24, 27, 30};

    printf("%s", (binarySearch(arr, 14) ? "Found\n" : "Not Found\n"));
    printf("%s", (binarySearch(arr, 22) ? "Found\n" : "Not Found\n"));
}

int binarySearch(int arr[], int x) {
    int low = 0;
    int high = MAX - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(x > arr[mid]) {
            low = mid + 1;
        } else if(x < arr[mid]) {
            high = mid - 1;
        } else {
            return 1;
        }
    }
    return 0;
}