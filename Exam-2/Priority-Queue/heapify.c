#include <stdio.h>
#define MAX 15

typedef struct {
    int elem[MAX];
    int lastNdx;
} Tree;

int main() {
    return 0;
}

void heapifyMin(Tree *T, int subroot) {
    int flag = 0;
    while(!flag) {
        int smallest = subroot;
        int right = subroot * 2 + 1;
        int left = left + 1;

        if(left <= T->lastNdx && T->elem[left] < T->elem[smallest]) smallest = left;
        if(right <= T->lastNdx && T->elem[right] < T->elem[smallest]) smallest = right;

        if(subroot == smallest) {
            flag = 1;
        } else {
            int temp = T->elem[smallest];
            T->elem[smallest] = T->elem[subroot];
            T->elem[subroot] = temp;

            subroot = smallest;
        }
    }
}

void heapifyMax(Tree *T, int subroot) {
    int flag = 0;
    while(!flag) {
        int largest = subroot;
        int left = subroot * 2 + 1;
        int right = left + 1;

        if(left <= T->lastNdx && T->elem[left] > T->elem[largest]) largest = left;
        if(right <= T->lastNdx && T->elem[right] > T->elem[largest]) largest = right;

        if(subroot == largest) {
            flag = 1;
        } else {
            int temp = T->elem[largest];
            T->elem[largest] = T->elem[subroot];
            T->elem[subroot] = temp;

            subroot = largest;
        }
    }
}