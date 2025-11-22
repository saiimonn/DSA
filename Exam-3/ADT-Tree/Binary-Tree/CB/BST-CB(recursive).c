#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int left;
    int right;
} nodeType;

typedef int Root;

typedef struct {
    nodeType nodes[MAX];
    int avail;
} Tree;

void initialize(Tree *);
int allocSpace(Tree *);
void deallocSpace(Tree *, Root);
void insert(Tree *, Root *, int);
void delete(Tree *, Root *, int);
int member(Tree, Root, int);
int min(Tree, Root);
int max(Tree, Root);
void preorder(Tree, Root);
void inorder(Tree, Root);
void postorder(Tree, Root);

int main() {
    Tree T;
    Root root = -1;
    initialize(&T);

    insert(&T, &root, 10);
    insert(&T, &root, 5);
    insert(&T, &root, 20);
    insert(&T, &root, 15);
    insert(&T, &root, 30);

    printf("%d\n", min(T, root));
    printf("%d\n", max(T, root));
}

void initialize(Tree *T) {
    T->avail = 0;
    
    int i;
    for(i = 0; i < MAX - 1; i++) {
        T->nodes[i].left = i + 1;
        T->nodes[i].right = -1;
    }
    T->nodes[i].left = -1;
}

int allocSpace(Tree *T) {
    int idx = T->avail;

    if(idx != -1) {
        T->avail = T->nodes[idx].left;
        T->nodes[idx].left = -1;
        T->nodes[idx].right = -1;
    }
    return idx;
}

void insert(Tree *T, Root *R, int x) {
    if(*R == -1) {
        *R = allocSpace(T);
        T->nodes[*R].data = x;
    } else if(x > T->nodes[*R].data) {
        insert(T, &(T->nodes[*R].right), x);
    } else if(x < T->nodes[*R].data) {
        insert(T, &(T->nodes[*R].left), x);
    }
}

void deallocSpace(Tree *T, Root idx) {
    if(idx >= 0 && idx < MAX) {
        T->nodes[idx].left = T->avail;
        T->nodes[idx].right = -1;
        T->avail = idx;
    }
}

void delete(Tree *T, Root *R, int x) {

}

int member(Tree T, Root R, int x) {
    if(x == T.nodes[R].data) {
        return 1;
    } else if(x > T.nodes[R].data) {
        return member(T, T.nodes[R].right, x);
    } else if(x < T.nodes[R].data) {
        return member(T, T.nodes[R].left, x);
    } else {
        return 0;
    }
}

int min(Tree T, Root R) {
    return (T.nodes[R].left == -1) ? T.nodes[R].data : min(T, T.nodes[R].left);
}

int max(Tree T, Root R) {
    return (T.nodes[R].right == -1) ? T.nodes[R].data : min(T, T.nodes[R].right);
}

void preorder(Tree T, Root R) {
    if(R != -1) {
        printf("%d ", T.nodes[R].data);
        preorder(T, T.nodes[R].left);
        preorder(T, T.nodes[R].right);
    }
}

void inorder(Tree T, Root R) {
    if(R != -1) {
        inorder(T, T.nodes[R].left);
        printf("%d ", T.nodes[R].data);
        inorder(T, T.nodes[R].right);
    }
}

void postorder(Tree T, Root R) {
    if(R != -1) {
        postorder(T, T.nodes[R].left);
        postorder(T, T.nodes[R].right);
        printf("%d ", T.nodes[R].data);
    }
}