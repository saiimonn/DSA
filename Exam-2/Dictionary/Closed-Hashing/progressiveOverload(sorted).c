#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
#define MAXMAX 20

typedef enum { EMPTY = -10, DELETED = -20, FULL = -30 } DicStatus;

typedef struct {
    int data;
    int link;
} nodeType;

typedef struct {
    nodeType nodes[MAXMAX];
    int avail;
} Dictionary;



int main() {

}