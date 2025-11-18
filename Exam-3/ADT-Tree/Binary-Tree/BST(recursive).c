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
void displayAscending(Set);

int main() {
    Set S = NULL;
    
    insert(&S, 10);
    insert(&S, 5);
    insert(&S, 20);
    insert(&S, 15);
    
    displayAscending(S);
    printf("\nmin: %d\n", min(S));
    printf("max: %d\n", max(S));

    delete(&S, 10);

    printf("\n");
    displayAscending(S);
    
    return 0;
}

void insert(Set *S, int x) {
    Set *A = S;
    if(*A == NULL) {
        *A = (Set)malloc(sizeof(struct node));
        (*A)->elem = x;
        (*A)->LC = NULL;
        (*A)->RC = NULL;
    } else if(x > (*A)->elem) {
        insert(&(*A)->RC, x);
    } else if(x < (*A)->elem) { //didn't use else cuz no duplicates
        insert(&(*A)->LC, x);
    }
}

void delete(Set *S, int x) {
    Set *A = S;

    if(*A == NULL) return;

    if(x > (*A)->elem) {
        delete(&(*A)->RC, x);
    } else if(x < (*A)->elem) {
        delete(&(*A)->LC, x);
    } else {
        Set target = *A;

        if(!target->LC && !target->RC) {
            free(target);
            *A = NULL;
        } else if(!target->RC) {
            *A = target->LC;
            free(target);
        } else if(!target->LC) {
            *A = target->RC;
            free(target);
        } else {
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
    if(S == NULL) {
        return 0;
    } else if(x == S->elem) {
        return 1;
    } else if(x > S->elem) {
        return member(S->RC, x);
    } else {
        return member(S->LC, x);
    }
}

int min(Set S) {
    if(S->LC == NULL) {
        return S->elem;
    } else {
        return min(S->LC);
    }
}

int max(Set S) {
    if(S->RC == NULL){
        return S->elem;
    } else {
        return max(S->RC);
    }
}

void displayAscending(Set S) {
    if(S != NULL) {
        displayAscending(S->LC);
        printf("%d ", S->elem);
        displayAscending(S->RC);
    }
}