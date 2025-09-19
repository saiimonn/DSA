#include <stdio.h>

#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int top;
} Stack;

void init(Stack *S);
void push(Stack *S, int x);
void pop(Stack *S);
int top(Stack S);
int canSeeBoard(int column[], int length); // TODO

int main()
{
    int len;
    int col[SIZE];
    printf("How many students in a column: ");
    scanf("%d", &len);

    printf("Enter the heights of the students (in inches): \n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &col[i]);
    }
    printf("In this column, only %d student(s) can see the board.\n", canSeeBoard(col, len));
}

int canSeeBoard(int column[], int length)
{
    int canSee = 1;

    Stack s;
    init(&s);

    for(int i = length - 1; i >= 0; i--) {
        push(&s, column[i]);
    }

    int tallest = column[0];

    for(; s.top != -1; pop(&s)) {
        if(top(s) > tallest) {
            canSee++;
            tallest = top(s);
        }
    }
    return canSee;
}

void init(Stack *S)
{
    S->top = -1;
}

void push(Stack *S, int x)
{
    if (S->top != SIZE - 1)
    {
        S->arr[++(S->top)] = x;
    }
}

void pop(Stack *S)
{
    if (S->top != -1)
    {
        S->top--;
    }
}

int top(Stack S)
{
    return (S.top != -1) ? S.arr[S.top] : -1;
}
