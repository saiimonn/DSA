#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int count;
} Set;

void initSet(Set *);
void insert(Set *, int);
void delete(Set *, int);
void read(Set);
bool isMember(Set, int);

Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
    Set A;
    Set B;
    initSet(&A);
    initSet(&B);

    insert(&A, 7);
    insert(&A, 4);
    insert(&A, 1);
    insert(&A, 3);
    printf("Set A: ");
    read(A);

    insert(&B, 8);
    insert(&B, 1);
    insert(&B, 3);
    insert(&B, 6);
    printf("Set B: ");
    read(B);

    Set U = Union(A, B);
    printf("Union: ");
    read(U);

    Set I = Intersection(A, B);
    printf("Intersection: ");
    read(I);

    Set D = Difference(A, B);
    printf("Difference: ");
    read(D);
}

void initSet(Set *S) {
    S->count = 0;
}

bool isMember(Set S, int x) {
    if(S.count != 0) {
        int i;
        for(i = 0; i < S.count && S.arr[i] != x; i++) {}

        if(i < S.count) return true;
    }
    return false;
}

void insert(Set *S, int x) {
    if(S->count < MAX && !isMember(*S, x)) {
            int i;
            for(i = S->count - 1; i >= 0 && S->arr[i] > x; S->arr[i + 1] = S->arr[i], i--) {}
            S->arr[i + 1] = x;
            S->count++;
    }
}

void delete(Set *S, int x) {
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
    Set C;
    initSet(&C);

    int i = 0, j = 0;

    while(i < A.count && j < B.count) {
        if(A.arr[i] < B.arr[j]) {
            C.arr[C.count++] = A.arr[i++];
        } else if(B.arr[j] < A.arr[i]) {
            C.arr[C.count++] = B.arr[j++];
        } else {
            C.arr[C.count++] = A.arr[i];
            i++;
            j++;
        }
    }

    Set D = (i == A.count) ? B : A;
    int l = (i == A.count) ? j : i;

    while(l < D.count) {
        C.arr[C.count++] = D.arr[l++];
    }

    // int i;
    // for(i = 0; i < B.count; i++) {
    //     if(!isMember(C, B.arr[i])) {
    //         C.arr[C.count++] = B.arr[i];
    //     }
    // }
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    initSet(&C);

    int i = 0, j = 0;
    while(i < A.count && j < B.count) {
        if(A.arr[i] < B.arr[j]) {
            i++;
        } else if(B.arr[j] < A.arr[i]) {
            j++;
        } else {
            C.arr[C.count++] = A.arr[i++];
            j++;
        }
    }

    // int i;
    // for(i = 0; i < A.count; i++) {
    //     if(isMember(B, A.arr[i])) {
    //         C.arr[C.count++] = A.arr[i];
    //     }
    // }
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    initSet(&C);

    int i = 0, j = 0;

    while(i < A.count && j < B.count) {
        if(A.arr[i] < B.arr[j]) {
            C.arr[C.count++] = A.arr[i++];
        } else if(B.arr[j] < A.arr[i]) {
            C.arr[C.count++] = B.arr[j++];
        } else {
            i++;
            j++;
        }
    }

    Set D = (i == A.count) ? B : A;
    int l = (i == A.count) ? j : i;

    while(l < D.count) {
        C.arr[C.count++] = D.arr[l++];
    }

    // int i;
    // for(i = 0; i < A.count; i++) {
    //     if(!isMember(B, A.arr[i])) {
    //         C.arr[C.count++] = A.arr[i];
    //     }
    // }
    return C;
}

void read(Set S) {
    printf("{ ");
    if(S.count != 0) {
        int i;
        for(i = 0; i < S.count; i++) printf("%d ", S.arr[i]);
    }
    printf("}\n");
}