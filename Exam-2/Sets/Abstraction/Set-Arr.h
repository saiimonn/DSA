#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef SET_ARR_H
#define SET_ARR_H
#define MAX 10

typedef struct {
    int arr[MAX];
    int count;
} Set;

void initSet(Set *S) {
    S->count = 0;
}

bool isMember(Set S, int x) {
    if(S.count != 0) {
        int i;
        for(i = 0; i < S.count && S.arr[i] != x; i++) {}

        if(i != S.count) return true;
    }
    return false;
}

void insert(Set *S, int x) {
    if(S->count < MAX) {
        int i;
        for(i = 0; i < S->count && S->arr[i] != x; i++) {}

        if(i == S->count) S->arr[S->count++] = x;
    }
}

void deleteBit(Set *S, int x) {
    if(S->count != 0 && isMember(*S, x)) {
        int idx;
        for(idx = 0; idx < S->count && S->arr[idx] != x; idx++) {}

        int i;
        S->count--;
        for(i = idx; i < S->count; i++) {
            S->arr[i] = S->arr[i + 1];
        }
    }
}

Set Union(Set A, Set B) {
    Set C = A;

    int i;
    for(i = 0; i < B.count; i++) {
        if(!isMember(C, B.arr[i])) {
            C.arr[C.count++] = B.arr[i];
        }
    }
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    initSet(&C);

    int i;
    for(i = 0; i < A.count; i++) {
        int j;
        for(j = 0; j < B.count && B.arr[j] != A.arr[i]; j++) {}

        if(j != B.count) {
            C.arr[C.count++] = B.arr[i];
        }
    }
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    initSet(&C);

    int i;
    for(i = 0; i < A.count; i++) {
        int j;
        for(j = 0; j < B.count && B.arr[j] != A.arr[i]; j++) {}

        if(j == B.count) {
            C.arr[C.count++] = B.arr[i];
        }
    }
    return C;
}

void read(Set S) {
    if(S.count != 0) {
        int i;
        printf("{ ");
        for(i = 0; i < S.count; i++) printf("%d ", S.arr[i]);
    }
    printf("}\n");
}

#endif