#include <stdio.h>
#include <stdlib.h>

#ifndef SET_CW_H
#define SET_CW_H

typedef unsigned char Set;

void initSet(Set *S) {
    *S = '\0';
}

void insert(Set *S, int pos) {
    *S |= 1 << pos;
}

void deleteBit(Set *S, int pos) {
    *S &= ~(1 << pos);
}

bool isMember(Set S, int pos) {
    return S >> pos & 1;
}

Set Union(Set A, Set B) {
    Set C;
    initSet(&C);

    C = A | B;
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    initSet(&C);

    C = A & B;
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    initSet(&C);

    C = A & ~(B);
    return C;
}

void display(Set S) {
    int stop = sizeof(S) * 8 - 1;

    for(; stop >= 0; stop--) {
        if(stop == 3) printf(" ");

        printf("%d ", S >> stop & 1);
    }
}

#endif