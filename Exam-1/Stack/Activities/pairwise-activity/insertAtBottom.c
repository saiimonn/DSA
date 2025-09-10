#include "stackArrayImplementation.h"

void insertBottom(StackArray *S, char x) {
    StackArray temp;
    initialize(&temp);

    while(!empty(*S)) {
        int idx = top(*S);
        push(&temp, S->elem[idx]);
        pop(S);
    }

    push(S, x);

    while(!empty(temp)) {
        int idx = top(temp);
        push(S, temp.elem[idx]);
        pop(&temp);
    }
}

int main() {
    StackArray S;

    initialize(&S);

    push(&S, 'e');
    push(&S, 'i');
    push(&S, 'r');
    push(&S, 'r');
    push(&S, 'a');
    push(&S, 'c');

    insertBottom(&S, 's');

    read(S);
}