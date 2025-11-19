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
    /*
        Test Cases:
            1.) Has no children - free the target node directly
            2.) Has only left child - assign *A to the left child and free the target node
            3.) Has only right child - assign *A to the right child and free the target node
            4.) Has both children - find the successor node, swap its elem with the target node elem, and free the successor node
    */

    Set *A;

    for(A = S; *A != NULL && (*A)->elem != x;) { //traversal
        A = (x > (*A)->elem) ? &(*A)->RC : &(*A)->LC;
    }

    if(*A != NULL) {
        Set target = *A;

        if(target->RC != NULL && target->LC != NULL) { 
            Set *trav = &target->RC;
            while((*trav)->LC != NULL) {
                trav = &(*trav)->LC;
            }
            
            target->elem = (*trav)->elem;
            
            target = *trav;
            *trav = target->RC;  
        } else { 
            *A = (target->LC != NULL) ? target->LC : target->RC;
        }
        free(target);
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