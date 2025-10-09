#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SET_BV_H
#define SET_BV_H
#define MAX 10

typedef int Set[MAX];

void initSet(Set S) {
    S = {0};
}

void insert(Set S, int pos) {
    if(pos < 10 && pos >= 0) {
        S[pos] = 1;
    }
}

void deleteBit(Set S, int pos) {
    if(pos < 10 && pos >= 0) {
        S[pos] = 0;
    }
}

bool isMember(Set S, int pos) {
    return S[pos] == 1;
}

Set *Union(Set A, Set B) {
    Set *C = (Set*)calloc(1, sizeof(Set));

    if(C != NULL) {
        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] | B[i];
        }
    }
    return C;
}

Set *Intersection(Set A, Set B) {
    Set *C = (Set*)calloc(1, sizeof(Set));

    if(C != NULL) {
        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] & B[i];
        }
    }
    return C;
}

Set *Difference(Set A, Set B) {
    Set *C = (Set*)calloc(1, sizeof(Set));

    if(C != NULL) {
        for(int i = 0; i < MAX; i++) {
            (*C)[i] = A[i] & ~(B[i]);
        }
    }
}

void display(Set S) {
    printf("{ ");
    for(int i = 0; i < MAX; i++) {
        if(S[i] == 1) printf("%d ", i);
    }
    printf("}\n");
}

#endif