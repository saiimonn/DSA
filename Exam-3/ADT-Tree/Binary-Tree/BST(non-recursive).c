#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *RC;
    struct node *LC;
} *Set;

void insert(Set *, int);
void delete(Set *, int);
int member(Set, int);
int min(Set);
int max(Set);
void inorder(Set);
void postorder(Set);
void preorder(Set);

int main() {
    Set S = NULL;
    
    
    insert(&S, 10);
    insert(&S, 5);
    insert(&S, 20);
    insert(&S, 15);
    insert(&S, 30);
    insert(&S, 3);
    insert(&S, 7);

    printf("Preorder: ");
    preorder(S);

    printf("\nInorder: ");
    inorder(S);

    printf("\nPostorder: ");
    postorder(S);
    
    return 0;
}

void insert(Set *S, int x) {
    Set *A;
    for(A = S; *A != NULL;) {
        A = (x > (*A)->elem) ? &(*A)->RC : &(*A)->LC;
    }

    *A = (Set)malloc(sizeof(struct node));
    (*A)->elem = x;
    (*A)->LC = NULL;
    (*A)->RC = NULL;
}

void delete(Set *S, int x) {
    Set *A = S;
    while (*A != NULL && (*A)->elem != x) {
        A = (x > (*A)->elem) ? &(*A)->RC : &(*A)->LC;
    }

    if (*A != NULL) {
        Set target = *A;

        if(!target->LC && !target->RC) { //test case: no children
            free(target);
            *A = NULL;
        } else if (!target->LC) { //test case: only right child
            *A = target->RC;
            free(target);
        } else if(!target->RC) { //test case: only left child
            *A = target->LC;
            free(target);
        } else { //test case: has two children
            Set *B = &target->RC;
            while((*B)->LC != NULL) {
                B = &(*B)->LC;
            }

            target->elem = (*B)->elem;

            Set temp = *B;
            *B = (temp->RC != NULL) ? temp->RC : NULL;
            free(temp);
        }
    }
}

int member(Set S, int x) {
    Set A;
    for(A = S; A != NULL && A->elem != x;) {
        A = (x > A->elem) ? A->RC : A->LC;
    }

    return (A != NULL) ? 1 : 0;
}

int min(Set S) {
    for(; S->LC != NULL; S = S->LC) {}

    return S->elem;
}

int max(Set S) {
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

void postorder(Set S) {
    if(S != NULL) {
        postorder(S->LC);
        postorder(S->RC);
        printf("%d ", S->elem);
    }
}

void preorder(Set S) {
    if(S != NULL) {
        printf("%d ", S->elem);
        preorder(S->LC);
        preorder(S->RC);
    }
}