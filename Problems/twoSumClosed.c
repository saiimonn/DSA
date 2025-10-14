#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef enum { EMPTY = -10, DELETED = -20, NOTEXIST = -30 } status;

typedef int Dictionary[MAX];

void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

int hash(int x) {
    return abs(x) % MAX;
}

void insert(Dictionary D, int x) {
    int hashVal = hash(x);

    int i, deleteIdx = -9999;
    for(i = 0; i < MAX && D[hashVal] != EMPTY;hashVal = (hashVal + 1) % MAX, i++) {
        if(deleteIdx == -9999 && D[hashVal] == DELETED) {
            deleteIdx = i;
        }
    }

    if(i != MAX) {
        D[hashVal] = x;
    } else if (deleteIdx != -9999) {
        D[deleteIdx] = x;
    } else {
        printf("Insert failed\n");
    }
}

void display(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        if(D[i] == EMPTY){
             printf("[%d] - EMPTY\n", i);
        } else if(D[i] == DELETED) {
            printf("[%d] - DELETED\n", i);
        } else {
            printf("[%d] - %d\n", i, D[i]);
        }
    }
}

// O(n^2) bushet
int *twoSum(Dictionary D, int x) {
    int i;
    for(i = 0; i < MAX; i++) {
        if(D[i] != EMPTY && D[i] != DELETED) {
            int first = D[i];
            int j;
            for(j = (i + 1) % MAX; j != i; j = (j + 1) % MAX) {
                if(D[j] != EMPTY && D[j] != DELETED) {
                    if(D[first] + D[j] == x) {
                        int *result = (int*)malloc(sizeof(int) * 2);
                        result[0] = first;
                        result[1] = D[j];
                        return result;
                    }
                }
            }
        }
    }
    return NULL;
}

int main() {
    Dictionary D;
    initDict(D);

    insert(D, 2);
    insert(D, 7);
    insert(D, 11);
    insert(D, 5);

    display(D);

    int *result = twoSum(D, 13);
    if(result != NULL) {
        for(int i = 0; i < 2; i++) {
            printf("%d ", result[i]);
        }
    } else {
        printf("NONE\n");
    }

}