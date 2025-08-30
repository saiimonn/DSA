#include <stdbool.h>
#include <stdlib.h>
#ifndef STACK_LL_H
#define STACK_LL_H

typedef struct node {
    char elem;
    struct node *link;
} *StackLL;

void initializeLL(StackLL *S) {
    (*S) = NULL;
}

bool emptyLL(StackLL S) {
    return (S == NULL) ? true : false;
}

char topLL(StackLL S) {
    return S->elem;
}

void pushLL(StackLL *S, char x) {
    StackLL newNode = (StackLL)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->elem = x;
        newNode->link = *S;
        *S = newNode;
    }
}

void popLL(StackLL *S) {
    if(!emptyLL(*S)) {
        StackLL temp = *S;
        *S = temp->link;
        free(temp);
    }
}

void readLL(StackLL S) {
    while(!emptyLL(S)) {
        printf("|  %c  |\n", S->elem);
        popLL(&S);
    }
}

#endif