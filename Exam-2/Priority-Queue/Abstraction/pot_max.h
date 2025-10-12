#include <stdio.h>
#ifndef POT_MAX_H
#define POT_MAX_H
#define MAX 20

typedef struct {
    int elem[MAX];
    int lastNdx;    
} Tree;

void initTree(Tree *T) {
    T->lastNdx = -1;
}

void insert(Tree *T, int x) {
    if(T->lastNdx + 1 < MAX) {
        T->elem[++T->lastNdx] = x;

        int child = T->lastNdx;
        int parent = (child - 1) / 2;

        while(child > 0 && T->elem[parent] < T->elem[child]) {
            int temp = T->elem[parent];
            T->elem[parent] = T->elem[child];
            T->elem[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        } 
    }
}

int deleteTop(Tree *T) {
    int temp = -1;
    if(T->lastNdx >= 0) {
        temp = T->elem[0];
        int data = T->elem[T->lastNdx--];

        int parent = 0;
        int left = parent * 2 + 1;
        int right = left + 1;

        int child = (right <= T->lastNdx && T->elem[left] > T->elem[right]) ? left : right;

        while(child <= T->lastNdx && T->elem[child] > data) {
            int swap = T->elem[parent];
            T->elem[parent] = T->elem[child];
            T->elem[child] = swap;

            parent = child;
            left = parent * 2 + 1;
            right = left + 1;

            child = (right <= T->lastNdx && T->elem[left] > T->elem[right]) ? left : right;
        }
        T->elem[parent] = data;
    }
    return temp;
}

void heapify(Tree *T, int subroot) {
    int flag = 0;
    while(!flag) {
        int largest = subroot;
        int left = subroot * 2 + 1;
        int right = left + 1;

        if(right <= T->lastNdx && T->elem[left] > T->elem[largest]) largest = left;
        if(right <= T->lastNdx && T->elem[right] > T->elem[largest]) largest = right;

        if(subroot == largest) {
            flag = 1;
        } else {
            int swap = T->elem[subroot];
            T->elem[subroot] = T->elem[largest];
            T->elem[largest] = swap;

            subroot = largest;
        }
    }
}

void display(Tree T) {
    printf("Unsorted: ");
    for(int i = 0; i <= T.lastNdx; i++) {
        printf("%d ", T.elem[i]);
    }

    printf("\nSorted: ");
    int temp;
    while((temp = deleteTop(&T)) != -1) {
        printf("%d ", temp);
    }
}

#endif