#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

typedef struct node {
    int val;
    struct node *LC;
    struct node *RC;
} Treenode;

bool isMirror(Treenode *r1, Treenode *r2) {
    if(r1->LC == NULL && r2->RC == NULL) return true;
    if(r1->LC == NULL || r2->RC == NULL) return false;
    return (r1->val == r2->val) && isMirror(r1->LC, r2->RC) && isMirror(r1->RC, r2->LC);
}

bool isSymmetric(Treenode *root) {
    if(root == NULL) return true;
    return isMirror(root->LC, root->RC);
}

int main(){
    
}