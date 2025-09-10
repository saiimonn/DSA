#include <stdio.h>
#include <stdbool.h>
#define MAX 10

//View 1: The stack implementation starts at idx MAX - 1 and stops at idx 0 (if empty: MAX - 1, full: -1)
typedef struct {
    char elem[MAX];
    int top;
} Stack;

void init(Stack *);
bool full(Stack);
bool empty(Stack);
void push(Stack *, char);
void pop(Stack *);
void read(Stack *);
int top(Stack);

int main() {
    Stack S;
    init(&S);

    push(&S, 'D');
    push(&S, 'C');
    push(&S, 'I');
    push(&S, 'S');
    push(&S, 'M'); //top. idx MAX - 1

    read(&S);
}

void init(Stack *S) {
    S->top = MAX;
}

bool full(Stack S) {
    return (S.top == -1) ? true : false;
}

bool empty(Stack S) {
    return (S.top == MAX) ? true : false;
}

void push(Stack *S, char x) {
    if(!full(*S)) {
        S->elem[--S->top] = x;
    }
}

void pop(Stack *S) {
    if(!empty(*S)) {
        S->top++;
    }
}

int top(Stack S) {
    return S.top;
}

void read(Stack *S) {
    Stack temp;
    init(&temp);

    while(!empty(*S)) {
        char x = S->elem[top(*S)];
        printf("|  %c  | index: %d\n", x, top(*S));
        push(&temp, x);
        pop(S);
    }

    while(!empty(temp)) {
        push(S, temp.elem[temp.top]);
        pop(&temp);
    }
}
