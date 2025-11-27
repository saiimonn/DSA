#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct node {
    int weight;
    struct node *link;
} *VERTEX;

typedef VERTEX List[MAX];


void initialize(List);
void insert(List, int[]);
void displayList(List);

int main() {

}