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
void read(Stack);
int top(Stack);

int main() {
    Stack S;
    init(&S);

    push(&S, 'n');
    push(&S, 'i');
    push(&S, 'g');
    push(&S, 'g');
    push(&S, 'e');
    push(&S, 'r');

    read(S);
}

void init(Stack *S) {
    S->top = MAX - 1;
}

bool full(Stack S) {
    return (S.top == -1) ? true : false;
}

bool empty(Stack S) {
    return (S.top == MAX - 1) ? true : false;
}

void push(Stack *S, char x) {
    if(!full(*S)) {
        S->elem[S->top--] = x;
    }
}

void pop(Stack *S) {
    if(!empty(*S)) {
        S->top++;
    }
}

int top(Stack S) {
    return S.top + 1;
}

void read(Stack S) {
    while(!empty(S)) {
        int temp = top(S);
        printf("| %c | idx: %d\n", S.elem[temp], temp);
        pop(&S);
    }
}