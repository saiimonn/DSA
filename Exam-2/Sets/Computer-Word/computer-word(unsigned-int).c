#include <stdio.h>
#define MAX (sizeof(unsigned int) * 8 - 1)

typedef unsigned int Set;
typedef enum {TRUE, FALSE} boolean;

void insert(Set *, int);
void delete(Set *, int);
void display(Set);
boolean isMember(Set, int);

int main() {
    Set S = 0;

    display(S);

    insert(&S, 31);
    insert(&S, 4);
    insert(&S, 16);

    display(S);

    delete(&S, 4);

    display(S);
}

void insert(Set *S, int pos) {
    *S |= 1 << pos;
}

void delete(Set *S, int pos) {
    *S &= ~(1 << pos);
}

void display(Set S) {
    int mask = MAX;

    while(mask >= 0) {
        printf("%d", S >> mask & 1);
        if(mask % 4 == 0) printf(" ");
        mask--;
    }
    printf("\n");
}

boolean isMember(Set S, int pos) {
    return (S >> pos & 1) ? TRUE : FALSE;
}