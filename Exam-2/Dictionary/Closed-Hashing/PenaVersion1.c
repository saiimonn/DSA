#include <stdio.h>
#define MAX 20
#define PDA 10

typedef struct {
    int arr[MAX];
    int last;
} Dictionary;

typedef enum { EMPTY, DELETED } status;

void initialize(Dictionary);
int hash(int);

int main() {

}

void initialize(Dictionary D) {
    for(int i = 0; i < PDA; i++) {
        D.arr[i] = EMPTY;
    }
    
    D.last = PDA - 1;
}

int hash(int x) {
    return x % 10;
}