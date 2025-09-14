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

void pop(Stack *S) {
	S->top--;
}

bool isValid(char *s) {
	Stack st;
	st.top = -1;
	int i;

	for(i = 0; s[i] != '\0'; i++) {
		if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(&st, s[i]);
		} else {
			if( st.top == -1 
			|| (s[i] == ')' && st.elems[st.top] != '(')
			|| (s[i] == ']' && st.elems[st.top] != '[')
     		|| (s[i] == '}' && st.elems[st.top] != '{')
			) {
				return false;
			}
			pop(&st);
		}
	}
	return st.top == -1;
}

int main() {
	printf("%s\n", (isValid("([{}])")) ? "Valid" : "Invalid");	
	printf("%s\n", (isValid("[(]") ? "Valid" : "Invalid"));
}
