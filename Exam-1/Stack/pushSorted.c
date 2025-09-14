#include "Activities/Abstraction/stack-array.h"

void pushSorted(Stack *, char);

int main() {
    Stack S;
    initialize(&S);

    pushSorted(&S, 'd');
    pushSorted(&S, 'b');
    pushSorted(&S, 'a');
    pushSorted(&S, 'c');
    pushSorted(&S, 'e');

    read(S);
}

void pushSorted(Stack *S, char x) {
    if(!full(*S)) {
        Stack temp;
        initialize(&temp);

        for(; empty(*S) != true && top(*S) < x; push(&temp, top(*S)), pop(S)) {}

        push(S, x);

        for(; empty(temp) != true; push(S, top(temp)), pop(&temp)) {}
    }
}