#include <stdio.h>
#include "stack-LL.h"

int main() {
	Stack S;
	initialize(&S);

	push(&S, 'H');
	push(&S, 'E');
	push(&S, 'L');
	push(&S, 'L');
	push(&S, 'O');

	read(S);
}
