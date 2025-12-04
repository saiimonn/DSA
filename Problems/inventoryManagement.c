#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_AISLES 10

typedef struct Product {
    char name[30];
    int quantity;
    struct Product *next;
} Product;

typedef struct {
    Product *aisles[NUM_AISLES];
} Inventory;

void init_inventory(Inventory *inv) {
    for (int i = 0; i < NUM_AISLES; i++) {
        inv->aisles[i] = NULL;
    }
}

int aisle_assignment(const char *name) {
    unsigned int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % NUM_AISLES;
}

void restock_product(Inventory *inv, char *name, int count) {
    // Implementation here...
    int aisle_num = aisle_assignment(name);
    Product *find;

    for(find = inv->aisles[aisle_num]; find != NULL && strcmp(find->name, name) != 0; find = find->next) {}

    if(find == NULL) {
        Product *new = (Product*)malloc(sizeof(struct Product));
        if(new != NULL) {
            strcpy(new->name, name);
            new->quantity = count;
            new->next = inv->aisles[aisle_num];
            inv->aisles[aisle_num] = new;
        }
    } else {
        find->quantity += count;
    }
}

void discontinue_product(Inventory *inv, char *name) {
    // Implementation here...
    int aisle_num = aisle_assignment(name);
    Product **find;

    for(find = &inv->aisles[aisle_num]; *find != NULL && strcmp((*find)->name, name) != 0; find = &(*find)->next) {}

    if(find != NULL) {
        Product *temp = *find;
        *find = (*find)->next;
        free(temp);
    }
}

void print_inventory(Inventory *inv) {
    printf("\n--- Current Inventory Levels ---\n");
    for (int i = 0; i < NUM_AISLES; i++) {
        printf("Aisle [%d]: ", i);
        Product *curr = inv->aisles[i];
        if (!curr) {
            printf("(Empty)\n");
            continue;
        }
        while (curr) {
            printf("[%s: %d units] -> ", curr->name, curr->quantity);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Inventory supermarket;
    init_inventory(&supermarket);

    printf("1. Receiving Delivery Truck...\n");

    restock_product(&supermarket, "Milk", 50);
    restock_product(&supermarket, "Bread", 20);
    restock_product(&supermarket, "Eggs", 100);
    restock_product(&supermarket, "Apples", 30);
    restock_product(&supermarket, "Biscuits", 150);
  restock_product(&supermarket, "Sugar", 40);
  restock_product(&supermarket, "Salt", 25);
    restock_product(&supermarket, "Meats", 30);
  restock_product(&supermarket, "Ketchup", 40);
  
    print_inventory(&supermarket);

    printf("\n2. Receiving Late Delivery Trucks...\n");

     restock_product(&supermarket, "Milk", 25);
    restock_product(&supermarket, "Eggs", 250);
    restock_product(&supermarket, "Meats", 90);
    restock_product(&supermarket, "Biscuits", 30);
    restock_product(&supermarket, "Salt", 90);
    restock_product(&supermarket, "Sandwich Spread", 40);

    print_inventory(&supermarket);

    printf("\n3. Discontinuing Products...\n");
    discontinue_product(&supermarket, "Bread");
    discontinue_product(&supermarket, "Salt");

    print_inventory(&supermarket);

    return 0;
}
