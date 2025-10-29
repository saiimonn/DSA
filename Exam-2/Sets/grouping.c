#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Set[MAX];

void read(Set);
Set* Union(Set, Set);
Set* Intersection(Set, Set);
Set* Difference(Set, Set);

int main() {
    Set A = {1, 1, 0, 1, 0, 0, 1, 0, 1, 0}; // Person A
    Set B = {1, 0, 1, 1, 0, 1, 0, 0, 1, 0}; // Person B
    Set C = {0, 1, 1, 0, 1, 1, 0, 1, 0, 0}; // Person C

    printf("Set A: "); read(A);
    printf("Set B: "); read(B);
    printf("Set C: "); read(C);

    Set *AB = Intersection(A, B);
    Set *AC = Intersection(A, C);
    Set *BC = Intersection(B, C);
}

void read(Set S) {
    int i;
    printf("{ ");
    for(i = 0; i < MAX; i++) {
        printf("%d ", S[i]);
    }
    printf("}\n");
}

Set *Union(Set A, Set B) {
    Set *C = (Set*)calloc(1, sizeof(Set));
    int i;
    for(i = 0; i < MAX; i++) {
        (*C)[i] = A[i] | B[i];
    }
    return C;
}

Set *Intersection(Set A, Set B) {
    Set *C = (Set*)calloc(1, sizeof(Set));
    int i;
    for(i = 0; i < MAX; i++) {
        (*C)[i] = A[i] & B[i];
    }
    return C;
}

Set *Difference(Set A, Set B) {
    Set *C = (Set*)calloc(1, sizeof(Set));
    int i;
    for(i = 0; i < MAX; i++) {
        (*C)[i] = A[i] & (~B[i]);
    }
    return C;
}