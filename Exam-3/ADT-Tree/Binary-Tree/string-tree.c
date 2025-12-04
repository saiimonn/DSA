#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX 100

typedef struct node {
    char word[STR_MAX];
    struct node *LC;
    struct node *RC;
} *BST;

void insert(BST *B, char *word) {
    BST *trav;
    for(trav = B; *trav != NULL;) {
        trav = (strcmp(word, (*trav)->word) > 0) ? &(*trav)->RC : &(*trav)->LC;
    }

    BST new = (BST)malloc(sizeof(struct node));
    if(new != NULL) {
        strcpy(new->word, word);
        new->LC = NULL;
        new->RC = NULL;
        *trav = new;
    }
}

void inorder(BST B) {
    if(B != NULL) {
        inorder(B->LC);
        printf("%5s ", B->word);
        inorder(B->RC);
    }
    printf("\n");
}

void postorder(BST B) {
    if(B != NULL) {
        postorder(B->LC);
        postorder(B->RC);
        printf("%5s ", B->word);
    }
    printf("\n");
}

void preorder(BST B) {
    if(B != NULL) {
        printf("%5s ", B->word);
        preorder(B->LC);
        preorder(B->RC);
    }
    printf("\n");
}

int main() {
    BST B = NULL;

    insert(&B, "serendipity");
    insert(&B, "petrichor");
    insert(&B, "supine");
    insert(&B, "solitude");
    insert(&B, "aurora");
    insert(&B, "idyllic");
    insert(&B, "clinomania");
    insert(&B, "pluviophile");
    insert(&B, "euphoria");
    insert(&B, "sequoia");
    insert(&B, "sumptuous");
    insert(&B, "angst");
    insert(&B, "nadir");
    insert(&B, "lassir");
    insert(&B, "mellifluous");
    insert(&B, "languor");

    inorder(B);
    preorder(B);
    postorder(B);
}

