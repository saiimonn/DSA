#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/**
 * @brief Deletes a node with the given key from the BST.
 * @param root The current root of the BST.
 * @param key_data The string key to delete.
 * @return BST The new root of the BST after deletion.
 */
BST deleteNode(BST root, const char *key_data) {
    BST *trav;
    for(trav = &root; *trav != NULL && strcmp(key_data, (*trav)->key) != 0;) {
        trav = (strcmp(key_data, (*trav)->key) > 0) ? &(*trav)->RC : &(*trav)->LC;
    }

    if(*trav != NULL) {
        BST target = *trav;

        if(target->LC != NULL && target->RC != NULL) {
            BST *succ = &target->RC;
            for(; (*succ)->LC != NULL; succ = &(*succ)->LC) {}

            strcpy(target->key, (*succ)->key);
            target = *succ;
            *succ = target->RC;
        } else {
            *trav = (target->RC != NULL) ? target->RC : target->LC;
        }
        free(target);
    }
    return root;
}

void inorderTraversal(BST tree) {
    if(tree != NULL) {
        inorderTraversal(tree->LC);
        printf("\"%s\" ", tree->key);
        inorderTraversal(tree->RC);
    }
}

void destroyTree(BST tree) {
    if (tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);

        if (tree->key != NULL) {
            free(tree->key);
        }

        free(tree);
    }
}

void insert(BST *tree, const char *key_data) {
    BST *trav;
    for(trav = tree; *trav != NULL && (strcmp(key_data, (*trav)->key) != 0);) {
        trav = (strcmp(key_data, (*trav)->key) > 0) ? &(*trav)->RC : &(*trav)->LC;
    }

    if(*trav == NULL) {
        BST new = (BST)malloc(sizeof(Node));
        if(new != NULL) {
            new->key = (char*)malloc(strlen(key_data) + 1);
            strcpy(new->key, key_data);
            new->LC = NULL;
            new->RC = NULL;
            *trav = new;
            printf("Inserted key: \"%s\"\n", key_data);
        }
    } else {
        printf("Key \"%s\" already exists. Ignoring.\n", key_data);
    }

}

int main() {
    // 1. Create and initialize the tree
    BST myTree = NULL;

    printf("--- Building BST for Deletion Test ---\n");
    // Keys: Apple, Banana, Grape, Kiwi, Mango(ROOT), Orange, Pineapple
    insert(&myTree, "Mango");      // Root
    insert(&myTree, "Apple");      // Left of Mango
    insert(&myTree, "Pineapple");  // Right of Mango
    insert(&myTree, "Banana");     // Right of Apple
    insert(&myTree, "Grape");      // Left of Pineapple
    insert(&myTree, "Orange");     // Right of Grape
    insert(&myTree, "Kiwi");       // Left of Orange

    printf("\nInitial In-Order Traversal:\n   ");
    inorderTraversal(myTree);
    printf("\n");

    // --- Deletion Tests ---

    printf("\n--- Test 1: Delete Leaf Node (Kiwi) ---\n");
    // Kiwi is a leaf node (0 children)
    myTree = deleteNode(myTree, "Kiwi");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 2: Delete Node with 1 Child (Apple) ---\n");
    // Apple has 1 child (Banana)
    myTree = deleteNode(myTree, "Apple");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 3: Delete Node with 2 Children (Mango - the Root) ---\n");
    // Mango is replaced by its successor (Orange)
    myTree = deleteNode(myTree, "Mango");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 4: Delete Non-Existent Key (Zebra) ---\n");
    myTree = deleteNode(myTree, "Zebra");
    printf("No change expected: ");
    inorderTraversal(myTree);
    printf("\n");

    // 2. Clean up memory
    destroyTree(myTree);
    printf("\nTree destroyed and memory freed.\n");

    return 0;
}