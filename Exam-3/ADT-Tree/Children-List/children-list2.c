#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int node;
    struct node *link;
} *List;

typedef struct {
    List Header[MAX];
    int root;
} Tree;

