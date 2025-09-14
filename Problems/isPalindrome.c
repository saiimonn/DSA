#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 128

typedef struct node{
    char elem[MAX];
    int top;
}Stack;

void Push(Stack* S, char x);
void Pop(Stack* S);
char Top(Stack S);
void initStack(Stack* S);

bool isFull(Stack S);
bool isEmpty(Stack S);

// your task is this function!
bool isPalindrome(char palindrome[]);


int main(){
    char palindrome[MAX];
    printf("Enter string: ");
    scanf("%s", palindrome);

    printf("Palindrome? %s", (isPalindrome(palindrome)) ? "Yes!" : "No!");
}

bool isPalindrome(char palindrome[]){
    // implement here!
    Stack S;
    initStack(&S);

    int len = 0;
    while(palindrome[len] != '\0') {
        len++;
    }

    int i;
    for(i = 0; i < len; i++) {
        Push(&S, palindrome[i]);
    }

    int j;
    for(j = 0; j < len && palindrome[j] == Top(S); j++, Pop(&S)) {}

    return(j == len);
}

void Push(Stack* S, char x){
    if(isFull(*S) != true){
        S->elem[++S->top] = x;
    }

}

void Pop(Stack* S){
    if(isEmpty(*S) != true){
        S->top--;
    }
}

char Top(Stack S){
    return (isEmpty(S) != true) ? S.elem[S.top] : '\0';
}

void initStack(Stack* S){
    S->top = -1;
}

bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}
bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}