// path - countof # of nodes - 1
/*
    depth = nodes unique path from the root 
    height = nodes longest path to aleaf

    order of nodes
    siblings should be ordered from left to right
    if order of nodes is disregarded its an unordered tree


    preorder- root,left sub, right sub
    inorder- left sub, root, right sub
    postorder - left sub, right sub, root

    ADT TREE


    BST
    no children,1 child,2 children
    left or rightchild
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
    int book_id;
    String book_name;
} Book;

typedef struct node {
    Book book;
    struct node *left;
    struct node *right;
} *BST;

int main() {

}

void insertNode(BST *root, Book newBook) {
    if(*root == NULL) {
        BST newnode = (BST)malloc(sizeof(struct node));
        newnode->book = newBook;
        newnode->left = NULL;
        newnode->right = NULL;
    } else if(newBook.book_id > (*root)->book.book_id) {
        insertNode(&(*root)->right, newBook);
    } else if(newBook.book_id < (*root)->book.book_id) {
        insertNode(&(*root)->left, newBook);
    }
}

void insertNode(BST *root, Book newBook) {
    BST *trav;
    for(trav = root; *trav != NULL && (*trav)->book.book_id != newBook.book_id;) {
        trav = (newBook.book_id > (*trav)->book.book_id) ? &(*trav)->right : &(*trav)->left;
    }

    BST newnode = (BST)malloc(sizeof(struct node));
    if(newnode != NULL) {
        newnode->book = newBook;
        newnode->left = NULL;
        newnode->right = NULL;
        *trav = newnode;
    }
}