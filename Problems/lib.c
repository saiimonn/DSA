#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    int ISBN;
    char title[50];
    char author[50];
    float price;
    int copies;
    struct book* LC;
    struct book* RC;
} BookNode, *BST;

/* Function prototypes */
void insertBook(BST* root, BookNode data);
void deleteBook(BST* root, int ISBN);
BookNode* searchBook(BST root, int ISBN);
BookNode* findMinBook(BST root);
BookNode* findMaxBook(BST root);
void inOrderBooks(BST root);
void printBooksUnderPrice(BST root, float maxPrice);

int main() {
    BST library = NULL;

    insertBook(&library, (BookNode){101, "C Programming", "Dennis Ritchie", 45.0, 5});
    insertBook(&library, (BookNode){102, "Data Structures", "Mark Allen", 60.0, 2});
    insertBook(&library, (BookNode){103, "Algorithms", "Cormen", 75.0, 3});

    printf("All books in-order:\n");
    inOrderBooks(library);

    printf("\nBooks under $60:\n");
    printBooksUnderPrice(library, 60.0);

    return 0;
}

void insertBook(BST* root, BookNode data) {

}

void deleteBook(BST* root, int ISBN) {

}

BookNode* searchBook(BST root, int ISBN) {

}

BookNode* findMinBook(BST root) {

}

BookNode* findMaxBook(BST root) {

}

void inOrderBooks(BST root) {

}

void printBooksUnderPrice(BST root, float maxPrice) {

}