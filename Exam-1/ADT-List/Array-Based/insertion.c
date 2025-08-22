#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    int data[SIZE];
    int count;
} List;

void initList(List *list) {
    list->count = 0;
}

int isFull(List *list) {
    return list->count == SIZE;
}

int isEmpty(List *list) {
    return list->count == 0;
}

void insert(List *list, int data) {
    if(isFull(list)) return;

    for(int i = list->count; i > 0; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[0] = data;
    list->count++;
}

void print(List *list) {
    if(isEmpty(list)) return;

    for(int i = 0; i < list->count; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    List L;

    initList(&L);
    insert(&L, 10);
    insert(&L, 20);

    print(&L);
}