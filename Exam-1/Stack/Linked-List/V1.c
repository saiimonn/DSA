#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//View 1: Top element is stored in element pointed by Stack *S || top is head
typedef struct node {
    char elem;
    struct node *link;
} *Stack;

void init(Stack *);
void push(Stack *, char);
void pop(Stack *);
void read(Stack);
int top(Stack);
bool empty(Stack);

int main() {
    Stack S;
    init(&S);

    push(&S, 'r');
    push(&S, 'e');
    push(&S, 'g');
    push(&S, 'g');
    push(&S, 'i');
    push(&S, 'n');

    read(S);
}

void init(Stack *S) {
    (*S) = NULL;
}

bool empty(Stack S) {
    return (S == NULL) ? true : false;
}

void push(Stack *S, char x) {
    Stack newNode = (Stack)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->elem = x;
        newNode->link = *S;
        *S = newNode;
    }
}

void pop(Stack *S) {
    if(!empty(*S)) {
        Stack temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

int top(Stack S) {
    return S->elem;
}

void read(Stack S) {
    while(!empty(S)) {
        printf("| %c |\n", top(S));
        pop(&S);
    }
}