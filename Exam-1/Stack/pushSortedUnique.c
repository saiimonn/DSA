#include "Activities/Abstraction/stack-array.h"

void pushSortedUnique(Stack *, char);

int main() {
	Stack S;
	initialize(&S);


    pushSortedUnique(&S, 'd');
    pushSortedUnique(&S, 'b');
    pushSortedUnique(&S, 'a');
    pushSortedUnique(&S, 'c');
    pushSortedUnique(&S, 'b'); // duplicate, should NOT be inserted
    pushSortedUnique(&S, 'e');

	read(S);
}

void pushSortedUnique(Stack *S, char x) {
	if(!full(*S)) {
		Stack search = *S;
		for(; empty(search) != true && top(search) != x; pop(&search)) {}

		if(empty(search)) {
			Stack temp;
			initialize(&temp);

			for(; empty(*S) != true && top(*S) < x; push(&temp, top(*S)), pop(S)) {}

			push(S, x);

			for(; empty(temp) != true; push(S, top(temp)), pop(&temp)) {}
		}
	}
}