#include "../Abstraction/ADT-CB.h"

int main() {
	CursorList CL;
	initialize(&CL);

	insertFirst(&CL, 43);
	insertLast(&CL, 50);
	insertSorted(&CL, 45);
	read(CL);

	deleteElem(&CL, 45);
	read(CL);

	makeNull(&CL);
	printf("\nIs empty?: %d\n", isEmpty(CL));
}
