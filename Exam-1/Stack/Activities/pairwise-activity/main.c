#include <stdio.h>
#include "stackArrayImplementation.h"
#include "stackLinkedListImplementation.h"
#include "stackCursorBasedImplementation.h"

int main() {
    VirtualHeap VH;
    initVH(&VH);

    Stack S;
    initStack(&S);

    pushCB(&VH, &S, 'n');
    pushCB(&VH, &S, 'i');
    pushCB(&VH, &S, 'g');
    pushCB(&VH, &S, 'g');
    pushCB(&VH, &S, 'e');
    pushCB(&VH, &S, 'r');

    printf("Cursor-Based: \n");

    readCB(VH, S);

    StackArray St;

    initialize(&St);

    push(&St, 'D');
    push(&St, 'C');
    push(&St, 'I');
    push(&St, 'S');
    push(&St, 'M');

    printf("Array: \n");

    read(St);

    StackLL sta;

    initializeLL(&sta);

    pushLL(&sta, 'n');
    pushLL(&sta, 'i');
    pushLL(&sta, 'g');
    pushLL(&sta, 'g');
    pushLL(&sta, 'e');
    pushLL(&sta, 'r');
    pushLL(&sta, 's');

    printf("Linked List: \n");

    readLL(sta);
}