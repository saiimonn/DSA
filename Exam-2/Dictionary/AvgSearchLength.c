#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Dictionary[MAX];

typedef enum { EMPTY } status;

void initDict(Dictionary);
int insert(Dictionary, char, int);
void printDict(Dictionary);
int searchLength(int, int);

int main() {
    Dictionary D;
    initDict(D);

    char elems[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int hashes[] = {1, 4, 9, 9, 0, 3, 4, 3};

    int n = 8;
    int totalSL = 0;
    int actualLocs[n];

    for(int i = 0; i < n; i++) {
        actualLocs[i] = insert(D, elems[i], hashes[i]);
    }

    printDict(D);

    printf("\nSearch Length:\n");
    for(int i = 0; i < n; i++) {
        int SL = searchLength(actualLocs[i], hashes[i]);
        totalSL += SL;
        printf("%c: Hash = %d, Location = %d, SL = %d\n", elems[i], hashes[i], actualLocs[i], SL);
    }

    double avgSL = (double) totalSL / n;
    printf("\nAvg Search Length: %.2lf\n", avgSL);
}

void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

int insert(Dictionary D, char elem, int hashVal) {
    int idx = hashVal;

    for(; D[idx] != EMPTY; idx = (idx + 1) % MAX) {}
    D[idx] = elem;
    return idx;
}

int searchLength(int actualLoc, int hashVal) {
    if(actualLoc >= hashVal) {
        return actualLoc - hashVal + 1;
    } else {
        return (MAX - hashVal + actualLoc + 1);
    }
}

void printDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        if(D[i] == EMPTY) {
            printf("[%d] EMPTY", i);
        } else {
            printf("[%d] %c", i, D[i]);
        }
        printf("\n");
    }
}