#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
=================================================
            STRUCT DEFINITION
=================================================
*/

typedef struct animal {
    int tagID;
    char name[40];
    char species[40];
    float weight;
    int age;

    struct animal* LC;
    struct animal* RC;
} AnimalNode, *BST;

/*
=================================================
            FUNCTION PROTOTYPES
=================================================
*/

// BST Operations (TO BE IMPLEMENTED BY YOU)
void insertAnimal(BST* root, AnimalNode data);
void deleteAnimal(BST* root, int tagID);
AnimalNode* searchAnimal(BST root, int tagID);
AnimalNode* findMinAnimal(BST root);   // returns node with smallest tagID
AnimalNode* findMaxAnimal(BST root);   // returns node with largest tagID
void inOrderList(BST root);

// Helper (already implemented below)
AnimalNode createAnimal(int tagID, const char* name, const char* species, float weight, int age);

/*
=================================================
            MAIN PROGRAM (COMPLETE)
=================================================
*/

int main() {
    BST S = NULL;

    // Preload animals (INSERTION TASKS)
    insertAnimal(&S, createAnimal(104, "Koda", "Bear", 220.5, 12));
    insertAnimal(&S, createAnimal(52, "Willow", "Fox", 8.2, 3));
    insertAnimal(&S, createAnimal(335, "Orion", "Wolf", 42.7, 5));
    insertAnimal(&S, createAnimal(77, "Maple", "Deer", 60.1, 7));
    insertAnimal(&S, createAnimal(250, "Storm", "Eagle", 5.9, 4));
    insertAnimal(&S, createAnimal(400, "Glacier", "Moose", 320.0, 15));

    printf("=====================================\n");
    printf(" INITIAL TREE (IN-ORDER TRAVERSAL)\n");
    printf("=====================================\n");
    inOrderList(S);

    // Search for Maple (tag 77)
    printf("\n\nSearching for Tag 77...\n");
    AnimalNode* result = searchAnimal(S, 77);
    if (result) {
        printf("Found %s (%s), Age %d\n", result->name, result->species, result->age);
    } else {
        printf("Not found.\n");
    }

    // Delete Storm (tag 250)
    printf("\nDeleting Tag 250...\n");
    deleteAnimal(&S, 250);

    // Insert a new animal (Sprig)
    printf("Inserting Tag 90 (Sprig)...\n");
    insertAnimal(&S, createAnimal(90, "Sprig", "Hare", 1.4, 1));

    // Check Tag 500
    printf("\nChecking Tag 500...\n");
    result = searchAnimal(S, 500);
    printf("%s\n", result ? "Found!" : "Not found.");

    // Minimum Tag
    AnimalNode* min = findMinAnimal(S);
    printf("\nLightest Tag: %d (%s, %s)\n",
           min->tagID, min->name, min->species);

    // Maximum Tag
    AnimalNode* max = findMaxAnimal(S);
    printf("Heaviest Tag: %d (%s, %s)\n",
           max->tagID, max->name, max->species);

    // Final list
    printf("\n=====================================\n");
    printf(" FINAL TREE (IN-ORDER TRAVERSAL)\n");
    printf("=====================================\n");
    inOrderList(S);

    printf("\n");
    return 0;
}

/*
=================================================
            HELPER — ALREADY DONE
=================================================
*/

AnimalNode createAnimal(int tagID, const char* name, const char* species, float weight, int age) {
    AnimalNode A;
    A.tagID   = tagID;
    strcpy(A.name, name);
    strcpy(A.species, species);
    A.weight  = weight;
    A.age     = age;
    A.LC = NULL;
    A.RC = NULL;
    return A;
}

/*
=================================================
            FUNCTIONS TO IMPLEMENT
=================================================
*/

// Insert based on tagID
void insertAnimal(BST* root, AnimalNode data) {
    // TODO: Implement BST insertion using tagID as key
    BST *trav;
    for(trav = root; *trav != NULL && data.tagID != (*trav)->tagID;) {
        trav = (data.tagID > (*trav)->tagID) ? &(*trav)->RC : &(*trav)->LC;
    }

    AnimalNode *newAnimal = (AnimalNode*)malloc(sizeof(AnimalNode));
    if(newAnimal != NULL) {
        *newAnimal = createAnimal(data.tagID, data.name, data.species, data.weight, data.age);
        *trav = newAnimal;
    }
}


// Delete using immediate successor
void deleteAnimal(BST* root, int tagID) {
    // TODO: Implement delete logic (3 cases)
    BST *trav;
    for(trav = root; *trav != NULL && (*trav)->tagID != tagID;) {
        trav = (tagID > (*trav)->tagID) ? &(*trav)->RC : &(*trav)->LC;
    }

    if(*trav != NULL) {
        BST target = *trav;

        if(target->LC != NULL && target->RC != NULL) {
            BST *succ;
            for(succ = &target->RC; *succ != NULL && (*succ)->LC != NULL; succ = &(*succ)->LC) {}

            target->age = (*succ)->age;
            target->tagID = (*succ)->tagID;
            target->weight = (*succ)->weight;
            strcpy(target->name, (*succ)->name);
            strcpy(target->species, (*succ)->species);

            target = *succ;
            *succ = target->RC;
        } else {
            *trav = (target->RC != NULL) ? target->RC : target->LC;
        }
        free(target);
    }
}

// Search by tagID
AnimalNode* searchAnimal(BST root, int tagID) {
    // TODO: Return pointer to node or NULL
   for(; root != NULL && root->tagID != tagID;) {
    root = (tagID > root->tagID) ? root->RC : root->LC;
   }

   return (root != NULL) ? root : NULL;
}

// Minimum tagID node
AnimalNode* findMinAnimal(BST root) {
    // TODO: Return pointer to leftmost node
    if(root != NULL) {
        for(; root->LC != NULL; root = root->LC) {}
        return root;
    }
    return NULL;
}

// Maximum tagID node
AnimalNode* findMaxAnimal(BST root) {
    // TODO: Return pointer to rightmost node
    if(root != NULL) {
        for(; root->RC != NULL; root = root->RC) {}
        return root;
    }
    return NULL;
}

// Print all animals in sorted order
void inOrderList(BST root) {
    if (root != NULL) {
        inOrderList(root->LC);

        printf("[Tag %d] Name: %s, Species: %s, Weight: %.1fkg, Age: %d\n",
               root->tagID,
               root->name,
               root->species,
               root->weight,
               root->age);

        inOrderList(root->RC);
    }
}