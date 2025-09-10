#include <stdio.h>
#include <stdbool.h>
#define MAX 10

//View 2: Stack implementation starts at idx 0 and ends at MAX - 1 (if empty: -1, full: MAX)
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
    push(&S, 'M'); //top. idx 0

    read(&S);
}

void init(Stack *S) {
    S->top = -1;
}

bool full(Stack S) {
    return (S.top == MAX) ? true : false;
}

bool empty(Stack S) {
    return (S.top == -1) ? true : false;
}

int top(Stack S) {
    return S.top;
}

void push(Stack *S, char x) {
    if(!full(*S)) {
        S->elem[++S->top] = x;
    }
}

void pop(Stack *S) {
    if(!empty(*S)) {
        S->top--;
    }
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
