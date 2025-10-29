#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
#define MAXMAX 20

typedef enum { EMPTY = -10, DELETED = -20, FULL = -30 } DicStatus;

typedef struct {
    int data;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAXMAX];
    int avail;
} Dictionary;

void init(Dictionary *);
int hash(int);
int allocSpace(Dictionary *);
void insert(Dictionary *, int);
void deallocSpace(Dictionary *, int);
void deleteElem(Dictionary *, int);
void read(Dictionary);

int main() {
    Dictionary D;
    init(&D);

    insert(&D, 44);
    insert(&D, 24);
    insert(&D, 4);
    insert(&D, 84);

    read(D);

    deleteElem(&D, 24);
    read(D);
}

void init(Dictionary *D) {
    int i;
    for(i = 0; i < MAX; i++) {
        D->nodes[i].data = EMPTY;
        D->nodes[i].link = -1;
    }

    for(i = MAX; i < MAXMAX - 1; i++) {
        D->nodes[i].link = i + 1;
    }
    D->nodes[i].link = -1;
    D->avail = MAX;
}

int hash(int x) {
    return abs(x % MAX);
}

int allocSpace(Dictionary *D) {
    int idx = D->avail;

    if(idx != -1) {
        D->avail = D->nodes[idx].link;
    }
    return idx;
}

void insert(Dictionary *D, int x) {
    int hashVal = hash(x);

    if(D->nodes[hashVal].data == EMPTY || D->nodes[hashVal].data == DELETED) {
        D->nodes[hashVal].data = x;
    } else {
        int idx = allocSpace(D);

        if(idx != -1) {
            D->nodes[idx].data = x;
            D->nodes[idx].link = -1;

            int *trav;
            for(trav = &D->nodes[hashVal].link; *trav != -1 && D->nodes[*trav].data < x; trav = &(D->nodes[*trav].link)) {}

            D->nodes[idx].link = *trav;
            *trav = idx;
        }
    }
}

void deallocSpace(Dictionary *D, int idx) {
    if(idx >= 0 && idx < MAXMAX) {
        D->nodes[idx].link = D->avail;
        D->avail = idx;
    }
}

void deleteElem(Dictionary *D, int x) {
    int hashVal = hash(x);

    if(D->nodes[hashVal].data == x) {
        D->nodes[hashVal].data = DELETED;
    } else {
        int i;
        for(i = hashVal; i != -1 && D->nodes[D->nodes[i].link].data != x; i = D->nodes[i].link) {}

        if(i != -1) {
            int temp = D->nodes[i].link;
            D->nodes[i].link = D->nodes[temp].link;
            deallocSpace(D, temp);
        }
    }
}

void read(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        printf("[%2d] -> ", i);

        if (D.nodes[i].data == EMPTY) {
            printf("EMPTY\n");
        } else {
            int link = i;
            while (link != -1) {
                if (D.nodes[link].data == DELETED) {
                    printf("DELETED");
                } else {
                    printf("%d", D.nodes[link].data);
                }

                link = D.nodes[link].link;
                if (link != -1) {
                    printf(" -> ");
                }
            }
            printf("\n");
        }
    }
}