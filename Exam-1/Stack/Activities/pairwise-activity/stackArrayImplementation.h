#include <stdbool.h>
#include <stdio.h>
#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#define MAX 10

typedef struct {
    char elem[MAX];
    int top;
} StackArray;

void initialize(StackArray *S) {
    S->top = MAX - 1;
}

bool full(StackArray S) {
    return (S.top == -1) ? true : false; 
}

bool empty(StackArray S) {
    return (S.top == MAX - 1) ? true : false;
}

int top(StackArray S) {
    return S.top + 1;
}

void push(StackArray *S, char x) {
    if(!full(*S)) {
        S->elem[S->top--] = x;
    }
}

void pop(StackArray *S) {
    if(!empty(*S)) {
        S->top++;
    }
}

void read(StackArray S) {
    while(!empty(S)) {
        int temp = top(S);
        printf("|  %c  | idx: %d\n", S.elem[temp], temp);
        pop(&S);
    }
}

#endif