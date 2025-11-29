/*
    NOTES

    finite set of vertices and edges

    directed - ordered pair of vertices (naay arrowhead)
    undirected - unorderedpair of vertices (walay arrowhead)

    complete graph - all vertices directly connected to one another

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct node {
    char label;
    struct node *link;
}*VERTEX;

typedef VERTEX List[MAX];

void display(List);

int main() {
    int matrix[MAX][MAX] = {
    //   A  B  C  D  E  F  G  H
        {0, 1, 0, 0, 0, 0, 0, 1}, //A
        {0, 0, 0, 0, 0, 1, 0, 0}, //B
        {1, 0, 0, 0, 0, 0, 0, 0}, //C
        {0, 0, 0, 0, 1, 0, 0, 1}, //D
        {0, 1, 0, 0, 0, 0, 0, 1}, //E
        {0, 0, 1, 0, 0, 0, 0, 0}, //F
        {1, 0, 1, 0, 0, 1, 0, 0}, //G
        {0, 0, 0, 0, 0, 0, 0, 0}, //H
    };

    List L;
    for(int i =0; i < MAX; i++) {
        L[i] = NULL;
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) {
            if(matrix[i][j] == 1) {
                VERTEX new = (VERTEX)malloc(sizeof(struct node));
                if(new != NULL) {
                    new->label = 65 + j;
                    new->link = L[i];
                    L[i] = new;
                }
            }
        }
    }

    display(L);
}

void display(List L){
    for(int i = 0; i < MAX; i++) {
        printf("NODE %c: ", i + 65);
        for(VERTEX trav = L[i];trav != NULL; trav = trav->link) {
            printf("%c %s ", trav->label, trav->link != NULL ? "->" : "");
        }
        printf("\n");
    }
}