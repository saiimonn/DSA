#include <stdio.h>
#include <stdlib.h>

#define VHSIZE 50

typedef struct {
    int data;
} Element;

typedef struct {
    Element elem;
    int next;
} Node;

typedef struct {
    Node VHNode[VHSIZE];
    int avail;
} VHeap;

typedef int Stack;  // index of top element


/*************************************/
/*           YOUR TASKS              */
/*************************************/
// --- CB functions --- //
void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void freeSpace(VHeap *VH, int idx);

// --- Stack functions ---
void initStack(Stack *S);
void insertSorted(VHeap *VH, Stack *S, int data);
void printStack(VHeap VH, Stack S);

// --- Main program ---
int main() {
    VHeap VH;
    Stack S;
    int N, val;

    initVHeap(&VH);
    initStack(&S);

    printf("Enter size: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertSorted(&VH, &S, val);
    }

    printStack(VH, S);

    return 0;
}

void initVHeap(VHeap *VH) {
    //implement here.....
	VH->avail = 0;
	int i;
	for(i = 0; i < VHSIZE - 1; i++) {
		VH->VHNode[i].next = i + 1;
	}
    VH->VHNode[i].next = -1;
}

int allocSpace(VHeap *VH) {
    //implement here.....
	int idx = VH->avail;
	if(idx != -1) {
		VH->avail = VH->VHNode[idx].next; 
	}
	return idx;
}

void freeSpace(VHeap *VH, int idx) {
    //implement here.....
	if(idx >= 0 && idx < VHSIZE) {
		VH->VHNode[idx].next = VH->avail;
		VH->avail = idx;
	}
}

// --- Stack functions ---
void initStack(Stack *S) {
    //implement here.....
	*S = -1;
}

void insertSorted(VHeap *VH, Stack *S, int data) {
    //implement here.....
	Stack temp;
	initStack(&temp);

	while(*S != -1 && VH->VHNode[*S].elem.data < data) {
		int idx = allocSpace(VH);
		if(idx != -1) {
			VH->VHNode[idx].elem = VH->VHNode[*S].elem;
			VH->VHNode[idx].next = temp;
			temp = idx;

			int tempTop = *S;
			*S = VH->VHNode[*S].next;
			freeSpace(VH, tempTop);
		}
	}

	int newIdx = allocSpace(VH);
	if(newIdx != -1) {
		VH->VHNode[newIdx].elem.data = data;
		VH->VHNode[newIdx].next = *S;
		*S = newIdx;
	}

	while(temp != -1) {
		int idx = allocSpace(VH);
		if(idx != -1) {
			VH->VHNode[idx].elem = VH->VHNode[temp].elem;
			VH->VHNode[idx].next = *S;
			*S = idx;

			int tempTop = temp;
			temp = VH->VHNode[temp].next;
			freeSpace(VH, tempTop);
		}
	}
}

void printStack(VHeap VH, Stack S) {
    //implement here.....
	if(S != -1) {
		printf("Sorted Stack: ");
		while(S != -1) {
			printf("%d ", VH.VHNode[S].elem.data);
			int temp = S;
			S = VH.VHNode[S].next;
			freeSpace(&VH, temp);
		}
	}
}
