#include <stdio.h>
#define MAX 10

typedef struct {
    int set[MAX];
    int count;
} Set;

void populate(Set *);
void insert(Set *, int);
void delete(Set *, int);
void read(Set);

Set Union(Set, Set);
Set Intersection(Set, Set);
Set Difference(Set, Set);

int main() {
	Set A = {{}, 0};
	Set B = {{}, 0};

	populate(&A);
	populate(&B);

	Set U = Union(A, B); //Elements in A and B
	read(U);

	Set I = Intersection(A, B); // Elements in A that are also in B
	read(I);

	Set D = Difference(A, B); // A - B (The elements in A that are not in B)
	read(D);
}

void populate(Set *S) {
	int size;
	printf("Enter number of elements: ");
	scanf("%d", &size);

	for(int i = 0; i < size; i++) {
		int inp;
		printf("Enter element: ");
		scanf("%d", &inp);

		insert(S, inp);
	}
}

void insert(Set *S, int x) {
	if(S->count < MAX) {
		int i;
		for(i = 0; i < S->count && S->set[i] != x; i++) {}

		if(i == S->count) {
			S->set[S->count++] = x;
		}
	}
}

void read(Set S) {
	if(S.count != 0) {
		int i;
		printf("{ ");
		for(i = 0; i < S.count; i++) printf("%d ", S.set[i]);
		printf("}\n");
	}
}

Set Union(Set A, Set B) {
	Set C = A;

	int i;
	for(i = 0; i < B.count; i++) {
		int j;
		for(j = 0; j < C.count && B.set[i] != C.set[j]; j++) {}

		if(j == C.count) {
			C.set[C.count++] = B.set[i];
		}
	}
	return C;
}

Set Intersection(Set A, Set B) {
	Set C = {{}, 0};

	int i;
	for(i = 0; i < A.count; i++) {
		int j;
		for(j = 0; j < B.count && B.set[j] != A.set[i]; j++) {}

		if(j != B.count) {
			C.set[C.count++] = A.set[i];
		}
	}

	return C;
}

Set Difference(Set A, Set B) {
	Set C = {{}, 0};

	int i;
	for(i = 0; i < A.count; i++) {
		int j;
		for(j = 0; j < B.count && B.set[j] != A.set[i]; j++) {}

		if(j == B.count) {
			C.set[C.count++] = A.set[i];
		}
	}

	return C;
}
