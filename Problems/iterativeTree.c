// Write your boilerplate code here...#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} *treeNode;

typedef treeNode Tree;

typedef struct node2{
    treeNode data;
    struct node2 *next;
} *List;

typedef List Stack;

/* MAIN FUNCTIONS: DO NOT EDIT */
treeNode createNode(int x);
Stack initStack(); // returns a linked list implementation of a stack
void push(Stack *S, treeNode t); // pushes a tree node to a stack
treeNode pop(Stack *S); // pops the top of the stack and returns it
/* ----------- */

void traversal1(Tree t);
void traversal2(Tree t);
void traversal3(Tree t);

int main() {
    treeNode a = createNode(1);
    treeNode b = createNode(2);
    treeNode c = createNode(3);
    treeNode d = createNode(4);
    treeNode e = createNode(5);
    treeNode f = createNode(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;

    printf("\nTRAVERSAL 1: \n");
    traversal1(a);

    // printf("\nTRAVERSAL 2: \n");
    // traversal2(a);

    // printf("\nTRAVERSAL 3: \n");
    // traversal3(a);
}

treeNode createNode(int x) {
    treeNode t = (treeNode)malloc(sizeof(treeNode));
    if (t != NULL) {
        t->val = x;
        t->left = NULL;
        t->right = NULL;
    }

    return t;
}

Stack initStack() {
    Stack S = (Stack)malloc(sizeof(struct node2));
    S = NULL;
    return S;
}

void push(Stack *S, treeNode t) {
    Stack temp = malloc(sizeof(struct node2));
    if (temp != NULL) {
        temp->data = t;
        temp->next = *S;
        *S = temp;
    }
}

treeNode pop(Stack *S) {
    treeNode t = (*S)->data;
    if (*S != NULL) {
        Stack temp = *S;
        *S = temp->next;
        free(temp);
    }

    return t;
}

void traversal1(Tree t) {
    Stack S = initStack();
    treeNode curr = t;

    while (curr != NULL || S != NULL) {

        while (curr != NULL) {
            push(&S, curr);
            curr = curr->left;
        }

        curr = pop(&S);
        printf("%d ", curr->val);

        curr = curr->right;
    }

    printf("\n");
}


// void traversal2(Tree t) {
//     //TODO
//     Stack S = initStack();
//     treeNode curr = t;
//     treeNode lastVisit = NULL;

//     while(curr != NULL || S != NULL) {
//         while(curr != NULL) {
//             push(&S, curr);
//             curr = curr->left;
//         }

//         treeNode peek = S->data;

//         if(peek->right != NULL && lastVisit != peek->right) {
//             curr = peek->right;
//         } else {
//             printf("%d ", peek->val);
//             lastVisit = pop(&S);
//         }
//     } 
//     printf("\n");
// }

// void traversal3(Tree t) {
//     //TODO
//     printf("\n");
// }

