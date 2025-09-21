#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int Set[MAX];

void populateSet(Set);
void printSet(Set);
bool isMember(Set, int);
Set *Union(Set, Set);
Set *Intersection(Set, Set);
Set *Difference(Set, Set);

int main() {
    Set A = {0};  // initialize all to 0
    Set B = {0};

    printf("Populate Set A:\n");
    populateSet(A);

    printf("\nPopulate Set B:\n");
    populateSet(B);

    printf("\nSet A: ");
    printSet(A);
    printf("\nSet B: ");
    printSet(B);

    Set *U = Union(A, B);
    Set *I = Intersection(A, B);
    Set *D = Difference(A, B);

    printf("\n\nUnion: ");
    printSet(*U);

    printf("\nIntersection: ");
    printSet(*I);

    printf("\nDifference (A - B): ");
    printSet(*D);

    printf("\n");

    // free allocated memory
    free(U);
    free(I);
    free(D);

    return 0;
}


void populateSet(Set S) {
	for(int i = 0; i < MAX; i++) {
		int inp;
		printf("Element %d: ", i);
		scanf("%d", &inp);

		if(inp < MAX && inp > 0) {
			S[inp] = 1;
		}
	}
}

void printSet(Set S) {
	printf("{ ");
	for(int i = 0; i < MAX; i++) {
		if(S[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("}");
}

bool isMember(Set S, int x) {
	return S[x] == 1;
}

Set *Union(Set A, Set B) {
	Set *S = (Set*)calloc(1, sizeof(Set));

	if(S != NULL) {
		for(int i = 0; i < MAX; i++) {
			(*S)[i] = A[i] | B[i];
		}
	}
	return S;
}

Set *Intersection(Set A, Set B) {
	Set *S = (Set*)calloc(1, sizeof(Set));

	if(S != NULL) {
		for(int i = 0; i < MAX; i++) {
			(*S)[i] = A[i] & B[i];
		}
	}
	return S;
}

Set *Difference(Set A, Set B) {
	Set *S = (Set*)calloc(1, sizeof(Set));

	if(S != NULL) {
		for(int i = 0; i < MAX; i++) {
			(*S)[i] = A[i] & (~B[i]);
		}
	}
	return S;
}