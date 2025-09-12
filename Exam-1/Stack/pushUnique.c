#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	char elems[MAX];
	int top;
} Stack;

void initialize(Stack *);
bool isEmpty(Stack);
bool isFull(Stack);
void pushUnique(Stack *, char);
void pop(Stack *);
int top(Stack);
void read(Stack);

int main() {
	Stack S;
	initialize(&S);

    pushUnique(&S, 'f');
    pushUnique(&S, 'y');
    pushUnique(&S, 'h');
    pushUnique(&S, 'i');
    pushUnique(&S, 'q');

    read(S);

    pushUnique(&S, 'u');

    read(S);
}

void initialize(Stack *S) {
	S->top = MAX;
}

bool isEmpty(Stack S) {
	return S.top == MAX;
}

bool isFull(Stack S) {
	return S.top == 0;
}

int top(Stack S) {
	return S.elems[S.top];
}

void pop(Stack *S) {
	if(!isEmpty(*S)) {
		S->top++;
	}
}

void pushUnique(Stack *S, char x) {
	if(!isFull(*S)) {
		Stack temp = *S;
		for(; isEmpty(temp) != true && top(*S) != x; pop(&temp)) {}
		if(isEmpty(temp)) S->elems[--S->top] = x;
	}
}

void read(Stack S) {
    while(!isEmpty(S)) {
        printf("|  %c  |\n", top(S));
        pop(&S);
    }
    printf("\n");
}