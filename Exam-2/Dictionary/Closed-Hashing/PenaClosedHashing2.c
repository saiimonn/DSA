#include <stdio.h>
#include <stdlib.h>
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
void delete(Dictionary *, int);

void read(Dictionary);

int main() {
    Dictionary D;
    init(&D);

    printf("========== INITIAL STATE ==========\n");
    read(D);

    printf("\n========== INSERTION TESTS ==========\n");
    int values1[] = {25, 35, 15, 45, 5, 55, 65, 75, 85, 95};
    int n1 = sizeof(values1) / sizeof(values1[0]);
    for (int i = 0; i < n1; i++) {
        insert(&D, values1[i]);
    }

    printf("\nAfter inserting first batch:\n");
    read(D);

    printf("\n========== COLLISION + SECOND BATCH ==========\n");
    int values2[] = {-12, 102, 47, 68, -33, 90, 23, 57, 81, -44};
    int n2 = sizeof(values2) / sizeof(values2[0]);
    for (int i = 0; i < n2; i++) {
        insert(&D, values2[i]);
    }

    printf("\nAfter inserting second batch:\n");
    read(D);

    printf("\n========== DELETION TESTS ==========\n");
    printf("Deleting head node (25)\n");
    delete(&D, 25);
    read(D);

    printf("\nDeleting middle node (102)\n");
    delete(&D, 102);
    read(D);

    printf("\nDeleting tail node (95)\n");
    delete(&D, 95);
    read(D);

    printf("\nDeleting head of another chain (5)\n");
    delete(&D, 5);
    read(D);

    printf("\n========== FINAL DICTIONARY ==========\n");
    read(D);

    printf("\n========== AVAIL LIST STATUS ==========\n");
    int temp = D.avail;
    printf("Avail list: ");
    while (temp != -1) {
        printf("%d ", temp);
        temp = D.nodes[temp].link;
    }
    printf("\n");

    return 0;
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
    return abs(x) % MAX;
}

// ---------- INSERTION ----------
// This inserts at the end of the chain (worst case: O(n))
int allocSpace(Dictionary *D) {
    int idx = D->avail;
    if(idx != -1) {
        D->avail = D->nodes[idx].link;
    }
    return idx;
}

void insert(Dictionary *D, int x) {
    int key = hash(x);

    if(D->nodes[key].data == EMPTY || D->nodes[key].data == DELETED) {
        D->nodes[key].data = x;
    } else {
        int idx = allocSpace(D);

        if(idx != -1) {
            int i;
            for(i = key; D->nodes[i].link != -1; i = D->nodes[i].link) {}
            D->nodes[idx].data = x;
            D->nodes[idx].link = -1;
            D->nodes[i].link = idx;
        }
    }
}
// ------------------------------

void deallocSpace(Dictionary *D, int idx) {
    if(idx >= 0 && idx < MAXMAX) {
        D->nodes[idx].link = D->avail;
        D->avail = idx;
    }
}

void delete(Dictionary *D, int x) {
    int key = hash(x);

    if(D->nodes[key].data == x) {
        D->nodes[key].data = DELETED;
    } else {
        int i;
        for(i = key; i != -1 && D->nodes[D->nodes[i].link].data != x; i = D->nodes[i].link) {}

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