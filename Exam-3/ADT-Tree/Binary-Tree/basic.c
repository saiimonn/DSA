#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *RC;
    struct node *LC;
} *Set;

void conception(Set *, int);
void abortion(Set *, int);
int whereU(Set, int);
int youngun(Set);
int oldahh(Set);
void inorder(Set);

int main() {
    Set S = NULL;
    
    printf("=== Testing Set Operations ===\n\n");
    
    // Test conception (insertion)
    printf("1. Inserting elements into the set:\n");
    conception(&S, 10);
    conception(&S, 5);
    conception(&S, 20);
    conception(&S, 15);
    conception(&S, 30);
    conception(&S, 3);
    conception(&S, 7);

    abortion(&S, 20);

    inorder(S);
    
    return 0;
}

void conception(Set *S, int x) {
    Set *A;
    for(A = S; *A != NULL;) {
        A = (x > (*A)->elem) ? &(*A)->RC : &(*A)->LC;
    }

    *A = (Set)malloc(sizeof(struct node));
    (*A)->elem = x;
    (*A)->LC = NULL;
    (*A)->RC = NULL;
}

void abortion(Set *S, int x) {
    Set *A;

    for(A = S; *A != NULL && (*A)->elem != x;) {
        A = (x > (*A)->elem) ? &(*A)->RC : &(*A)->LC;
    }

    if (*A != NULL) {
        Set target = *A;

        if(target->RC != NULL && target->LC != NULL) {
            Set *trav;
            for(trav = &target->RC; *trav != NULL && (*trav)->LC != NULL; trav = &(*trav)->LC) {}

            target->elem = (*trav)->elem;

            target = *trav;
            *trav = target->RC;
        } else {
            *A = (target->LC == NULL) ? target->RC : target->LC;
        }
        free(target);
    }
}

int whereU(Set S, int x) {
    Set A;
    for(A = S; A != NULL && A->elem != x;) {
        A = (x > A->elem) ? A->RC : A->LC;
    }

    return (A != NULL) ? 1 : 0;
}

int youngun(Set S) {
    for(; S->LC != NULL; S = S->LC) {}

    return S->elem;
}

int oldahh(Set S) {
    for(; S->RC != NULL; S = S->RC) {}

    return S->elem;
}

void inorder(Set S) { //prints in ascending order (left subree, root, right subtree)
    if(S != NULL) {
        inorder(S->LC);
        printf("%d ", S->elem);
        inorder(S->RC);
    }
}