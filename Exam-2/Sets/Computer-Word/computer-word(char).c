#include <stdio.h>
#include <stdbool.h>

typedef char Set;

void displayBit(Set);
void initSet(Set *);
void displaySet(Set);
void insert(int, Set *);
void removeB(int, Set *);
bool isMember(int, Set);

Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
    Set s;
    initSet(&s);
    displayBit(s); //0000 0000

    insert(0, &s);
    displayBit(s); //0000 0001

    insert(4, &s);
    displaySet(s);
    displayBit(s); //0001 0001

    removeB(4, &s);
    displaySet(s);
    displayBit(s); // 0000 0001

    printf("%s\n", isMember(0, s) ? "true" : "false"); //true
    printf("%s\n", isMember(4, s) ? "true" : "false"); //false
}

void initSet(Set *S) {
    *S = '\0';
}

void displayBit(Set S) {
    int mask = sizeof(S) * 8 - 1;

    for(; mask >= 0; mask--) {
        if(mask == 3) printf(" ");

        printf("%d", S >> mask & 1);
    }
    printf("\n");
}

void displaySet(Set S) {
    int mask = sizeof(S) * 8 - 1;

    for(; mask >= 0; mask--) {
        if(S >> mask & 1) printf("%d ", mask);
    }
    printf("\n");
}

void insert(int off, Set *S) {
    *S |= 1 << off; //1 << off is the position. ex. 0000 0000 *S |= 1 << 6 = 0100 0000
}

void removeB(int off, Set *S) {
    *S &= ~(1 << off); //the operation flips the value of 1 to 0 but not 0 to 1
}

bool isMember(int idx, Set S) {
    return S >> idx & 1;
}

Set Union(Set A, Set B) {
    Set C;
    initSet(&C);

    C = A | B;
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    initSet(&C);

    C = A & B;
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    initSet(&C);

    C = A & ~(B);
    return C;
}