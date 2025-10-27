#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define MAXPRIME 10

typedef enum { EMPTY = -10, DELETED = -20, FULL = -30} DictStatus;

typedef struct {
    int data;
    int link;
} nodeType;

typedef struct {
    nodeType arr[MAX];
    int avail;
} Dictionary;

void init(Dictionary *);
int hash(int);
void insert(Dictionary *, int);
void delete(Dictionary *, int);
void display(Dictionary);

int main() {
    Dictionary D;
    init(&D);

    printf("=== INSERTING ELEMENTS ===\n");
    insert(&D, 15);
    insert(&D, 25);
    insert(&D, 35);
    insert(&D, 45);
    insert(&D, 12);
    insert(&D, 22);
    insert(&D, 32);
    insert(&D, 7);
    insert(&D, 17);
    insert(&D, 27);
    insert(&D, 37);
    insert(&D, 47);

    display(D);

    printf("\n=== DELETING ELEMENTS ===\n");
    delete(&D, 12);
    delete(&D, 27);
    delete(&D, 100); // non-existent

    printf("\n=== AFTER DELETION ===\n");
    display(D);

    printf("\n=== INSERTING AGAIN ===\n");
    insert(&D, 52);
    insert(&D, 62);
    insert(&D, 72); //will be inserted directly at DELETED position cuz no more space in vheap

    display(D);

    return 0;
}

void init(Dictionary *D) {
    int i;
    for(i = 0; i < MAXPRIME; i++) { // initialized from index 0 to 9
        D->arr[i].data = EMPTY;
        D->arr[i].link = -1;
    }

    for(i = MAXPRIME; i < MAX; i++){ //initialize from indexes 10 to 19
        D->arr[i].data = EMPTY;
        D->arr[i].link = i + 1;
    }

    D->arr[i - 1].link = -1;
    D->avail = MAXPRIME;
}

int hash(int val) {
    return abs(val) % MAXPRIME;
}

//This inserts at the start of the chain (worst case: O(1))
void insert(Dictionary *D, int x) {
    int hashVal = hash(x), space = -9999;
    if(D->arr[hashVal].data == EMPTY) { 
        D->arr[hashVal].data = x; // if the data in D->arr[hashval] is marked as EMPTY, insert directly
    } else {
        space = D->avail; //if it's not EMPTY (occupied OR deleted), it's a synonym. Therefore allocate space in the VHeap
        if(space != -1) {
            D->avail = D->arr[space].link;
            D->arr[space].data = x;
            D->arr[space].link = D->arr[hashVal].link;
            D->arr[hashVal].link = space;
        } else if(D->arr[hashVal].data == DELETED) { //if there is no more available space in the VHeap, insert at the hashVal if it's DELETED
            D->arr[hashVal].data = x;
        }
    }
}

void delete(Dictionary *D, int x) {
    int hashVal = hash(x);
    int *idx;
    for(idx = &hashVal; *idx != -1 && D->arr[*idx].data != x; idx = &D->arr[*idx].link) {}

    if(*idx != -1) {
        if(*idx == hashVal) {
            D->arr[*idx].data = DELETED;
        } else {
            int temp = *idx;
            *idx = D->arr[temp].link;
            D->arr[temp].link = D->avail;
            D->avail = temp;
        }
        printf("Deleted\n");
    } else {
        printf("Does not exist\n");
    }
}

void display(Dictionary D) {
    for(int i = 0; i < MAXPRIME; i++) {
        int idx;
        printf("[%d]: %d -> ", i, D.arr[i].data);
        for(idx = D.arr[i].link; idx != -1; idx = D.arr[idx].link) {
            printf("%d -> ", D.arr[idx].data);
        }
        printf("NULL\n");
    }
}