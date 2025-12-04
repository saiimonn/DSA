// Write your boilerplate code here...#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 50
#define MAX_HEAP 200

typedef struct Node {
    char name[MAX_STR];
    int load;
    int isRealService; // 1 for real services, 0 for a virtual cluster
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node* arr[MAX_HEAP];
    int size;
} MinHeap;


Node* createNode(char *name, int load, int isReal);

void initHeap(MinHeap *h);
void insertMinHeap(MinHeap *h, Node *node);
Node* extractMin(MinHeap *h);

Node* buildLoadTree(MinHeap *h);

void printTree(Node *root, int depth);


Node* createNode(char *name, int load, int isReal) {
    Node *n = (Node*)malloc(sizeof(Node));
    strcpy(n->name, name);
    n->load = load;
    n->isRealService = isReal;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void initHeap(MinHeap *h) {
    h->size = 0;
}

void insertMinHeap(MinHeap *h, Node *node) {
    if (h->size >= MAX_HEAP) return;
    int i = h->size++;
    h->arr[i] = node;

    while (i != 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent]->load <= h->arr[i]->load)
            break;

        Node *tmp = h->arr[parent];
        h->arr[parent] = h->arr[i];
        h->arr[i] = tmp;
        i = parent;
    }
}

Node* extractMin(MinHeap *h) {
    if (h->size == 0)
        return NULL;

    Node *min = h->arr[0];
    h->size--;

    h->arr[0] = h->arr[h->size];

    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < h->size && h->arr[left]->load < h->arr[smallest]->load)
            smallest = left;

        if (right < h->size && h->arr[right]->load < h->arr[smallest]->load)
            smallest = right;

        if (smallest == i)
            break;

        Node *tmp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = tmp;

        i = smallest;
    }

    return min;
}

Node* buildLoadTree(MinHeap *h) {
    
    while(h->size > 1) {
        Node *a = extractMin(h);
        Node *b = extractMin(h);

        char name[MAX_STR] = "cluster";
        int combined = a->load + b->load;

        Node *cluster = createNode(name, combined, 0);

        cluster->left = a;
        cluster->right = b;

        insertMinHeap(h, cluster);
    }
    return extractMin(h);
}


void printTree(Node *root, int depth) {
    if (root == NULL) return;

    for (int i = 0; i < depth; i++) printf("    ");

    if (root->isRealService)
        printf("%s (%d)\n", root->name, root->load);
    else
        printf("(%d)\n", root->load);

    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}


// ============================== MAIN ==============================

int main() {
    MinHeap heap;
    initHeap(&heap);

    int heapSize;
    char serviceName[MAX_STR];
    int load;

    printf("How many services?: ");
    scanf("%d", &heapSize);

    for (int i = 0; i < heapSize; i++) {
        printf("--- SERVICE %i ---\n", i + 1);
        printf("Service Name: ");
        scanf("%s", serviceName);
        printf("Load: ");
        scanf("%d", &load);

        insertMinHeap(&heap, createNode(serviceName,     load, 1));
    }

    Node *root = buildLoadTree(&heap);

    printf("\n=== LOAD AGGREGATION TREE ===\n");
    printTree(root, 0);

    return 0;
}
