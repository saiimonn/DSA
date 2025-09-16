#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef int Set[MAX]; //Just 1's and 0's

void populateSet(Set); //Enter REAL numbers here not binary.
void read(Set); //Prints the numbers in the set with a value of 1

Set* Union(Set, Set);
Set* Intersection(Set, Set);
Set* Difference(Set, Set);

int main() {
	Set A = {0};
	Set B = {0};

	populateSet(A);
	populateSet(B);

	printf("Set A: ");
	read(A);

	printf("Set B: ");
	read(B);

	Set *U = Union(A, B);
	printf("Union: ");
	read(*U);

	Set *I = Intersection(A, B);
	printf("Intersection: ");
	read(*I);


	Set *D = Difference(A, B);
	printf("Difference: ");
	read(*D);
}

void populateSet(Set S) {
	printf("---------- Populating Set ----------\n");
	int i;
	for(i = 0; i < MAX; i++) {
		int data;
		printf("Element %d: ", i);
		scanf("%d", &data);

		if(data >= 0 && data < MAX) {
			S[data] = 1;
		}
	}
	printf("\n");
}

void read(Set S) {
	int i;
	for(i = 0; i < MAX; i++) {
		if(S[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

Set *Union(Set A, Set B) {
	Set *z = (Set*)malloc(sizeof(Set));
	if(z != NULL) {
		int i;
		for(i = 0; i < MAX; i++) {
			(*z)[i] = A[i] | B[i];
		}
	}
	return z;
}

Set *Intersection(Set A, Set B) {
	Set *z = (Set*)malloc(sizeof(Set));
	if(z != NULL) {
		int i;
		for(i = 0; i < MAX; i++) {
			(*z)[i] = A[i] & B[i];
		}
	}
	return z;
}

Set *Difference(Set A, Set B) {
	Set *z = (Set*)malloc(sizeof(Set));
	if(z != NULL) {
		int i;
		for(i = 0; i < MAX; i++) {
			(*z)[i] = A[i] & (~B[i]);
		}
	}
	return z;
}
