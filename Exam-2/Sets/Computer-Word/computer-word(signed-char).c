#include <stdio.h>
#include <stdbool.h>

typedef signed char Set;

void init(Set *);
void insert(Set *, int);
void delete(Set *, int);
bool isMember(Set, int);
void displayBits(Set);
void displaySet(Set);
Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
    Set A, B, C;
    init(&A);
    init(&B);

    printf("=== INSERT ELEMENTS ===\n");
    insert(&A, 0);
    insert(&A, 7);  // sign bit (MSB)
    insert(&B, 3);
    insert(&B, 7);  // sign bit too

    printf("A = ");
    displayBits(A);
    printf("B = ");
    displayBits(B);

    printf("\nA = ");
    displaySet(A);
    printf("B = ");
    displaySet(B);

    printf("\n=== UNION ===\n");
    C = Union(A, B);
    displayBits(C);
    displaySet(C);

    printf("\n=== INTERSECTION ===\n");
    C = Intersection(A, B);
    displayBits(C);
    displaySet(C);

    printf("\n=== DIFFERENCE ===\n");
    C = Difference(A, B);
    displayBits(C);
    displaySet(C);

    return 0;
}

void init(Set *S) {
    *S = '\0';
}

void insert(Set *S, int pos) {
    *S |= 1 << pos;
}

void delete(Set *S, int pos) {
    *S &= ~(1 << pos);
}

bool isMember(Set S, int pos) {
    return S >> pos & 1;
}

void displayBits(Set S) {
    unsigned char mask = 1 << (sizeof(S) * 8 - 1);

    for(; mask > 0; mask >>= 1) {
        printf("%d", (S & mask) ? 1 : 0);
    }
    printf("\t(Decimal: %4d)\n", S);
}

void displaySet(Set S) {
    printf("{ ");
    for(int i = 0; i < 8; i++) {
        if(isMember(S, i)) printf("%d ", i);
    }
    printf("}\n");
}

Set Union(Set A, Set B) {
    return A | B;
}

Set Intersection(Set A, Set B) {
    return A & B;
}

Set Difference(Set A, Set B) {
    return A & ~(B);
}