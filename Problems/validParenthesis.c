#include <stdio.h>
#include <stdbool.h>
#define MAX 20

typedef struct {
	char elems[MAX];
	int top;
} Stack;

void push(Stack *S, char x) {
	S->elems[++S->top] = x;
}

bool isEmpty(Stack S) {
	return (S.top == -1) ? true : false;
}

void pop(Stack *S) {
	S->top--;
}

char top(Stack S) {
	return S.elems[S.top];
}

bool isValid(char *s) {
	Stack st;
	st.top = -1;
	int i;

	for(i = 0; s[i] != '\0'; i++) {
		if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(&st, s[i]);
		} else {
			if(isEmpty(st)) return false;
			if(s[i] == top(st) + 1 || s[i] == top(st) + 2) {
				pop(&st);
			}
		}
	}

	return isEmpty(st);
}

int main() {
	printf("%s\n", (isValid("([{}])")) ? "Valid" : "Invalid");	
	printf("%s\n", (isValid("[(]") ? "Valid" : "Invalid"));
}
