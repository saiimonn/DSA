#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef signed int Set;

void init(Set *);
void insert(Set *, int);
void delete(Set *, int);
void displayBits(Set);
void displaySet(Set);
bool isMember(Set, int);

Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
    Set A, B, C;

    printf("=== INITIALIZATION ===\n");
    init(&A);
    init(&B);

    printf("A = ");
    displayBits(A);
    printf("B = ");
    displayBits(B);

    printf("\n=== INSERT ELEMENTS ===\n");
    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);

    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 6);

    printf("A = ");
    displayBits(A);
    printf("B = ");
    displayBits(B);

    printf("\nA = ");
    displaySet(A);
    printf("B = ");
    displaySet(B);

    printf("\n=== MEMBERSHIP TEST ===\n");
    printf("Is 3 in A? %s\n", isMember(A, 3) ? "Yes" : "No");
    printf("Is 4 in A? %s\n", isMember(A, 4) ? "Yes" : "No");

    printf("\n=== DELETE ELEMENT ===\n");
    delete(&A, 3);
    printf("A after deleting 3: ");
    displayBits(A);
    printf("A = ");
    displaySet(A);

    printf("\n=== UNION ===\n");
    C = Union(A, B);
    printf("A ∪ B = ");
    displaySet(C);
    displayBits(C);

    printf("\n=== INTERSECTION ===\n");
    C = Intersection(A, B);
    printf("A ∩ B = ");
    displaySet(C);
    displayBits(C);

    printf("\n=== DIFFERENCE ===\n");
    C = Difference(A, B);
    printf("A − B = ");
    displaySet(C);
    displayBits(C);

    return 0;
}

void init(Set *S) {
    *S = 0;
}

void insert(Set *S, int pos) {
    *S |= (1 << pos);
}

void delete(Set *S, int pos) {
    *S &= ~(1 << pos);
}

bool isMember(Set S, int pos) {
    return S >> pos & 1;
}

void displayBits(Set S) {
    int mask = sizeof(S) * 8 - 1;

    for(; mask >= 0; mask--) {
        printf("%d", S >> mask & 1);
        if(mask % 8 == 0) printf(" ");
    }
}

void displaySet(Set S) {
    int mask = sizeof(S) * 8 - 1;

    printf("{ ");
    for(; mask >= 0; mask--) {
        if(S >> mask & 1) printf("%d ", mask);
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