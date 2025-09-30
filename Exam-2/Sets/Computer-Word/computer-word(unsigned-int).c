#include <stdio.h>
#define MAX (sizeof(unsigned int) * 8 - 1)

typedef unsigned int Set;
typedef enum {TRUE, FALSE} boolean;

void initSet(Set *);
void insert(Set *, int);
void delete(Set *, int);
void displayBit(Set);
void displaySet(Set);
boolean isMember(Set, int);

Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
    Set S;
    initSet(&S);

    display(S);

    insert(&S, 31);
    insert(&S, 4);
    insert(&S, 16);

    displayBit(S);

    delete(&S, 4);

    displayBit(S);
}

void initSet(Set *S) {
    *S = 0;
}

void insert(Set *S, int pos) {
    *S |= 1 << pos;
}

void delete(Set *S, int pos) {
    *S &= ~(1 << pos);
}

void displayBit(Set S) {
    int mask = MAX;

    for(; mask >= 0; mask--) {
        printf("%d", S >> mask & 1);
        if(mask % 4 == 0) printf(" ");
    }
    printf("\n");
}

void displaySet(Set S) {
    int mask = MAX;

    for(; mask >= 0; mask--) {
        if(S >> mask & 1) printf("%d", mask);
    }
    printf("\n");
}

boolean isMember(Set S, int pos) {
    return (S >> pos & 1) ? TRUE : FALSE;
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