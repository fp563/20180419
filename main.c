#include <stdio.h>
#include "matrix.h"


int main() {

	matrix a, b;

	if (mat_alloc(&a, 6, 2)) {
		printf("allocation error\n");
		exit(-1);
	}
	if (mat_alloc(&b, 4, 1)) {
		printf("allocation error\n");
		exit(-1);
	}

#ifndef FROM0
	mat_elem(a, 1, 1) = 1;
	mat_elem(a, 1, 2) = 3;
	mat_elem(a, 1, 3) = 4;
	mat_elem(a, 2, 1) = 2;
	mat_elem(a, 2, 2) = 6;
	mat_elem(a, 2, 3) = 1;
	mat_elem(a, 3, 1) = 3;
	mat_elem(a, 3, 2) = 2;
	mat_elem(a, 3, 3) = 1;

	mat_elem(b, 1, 1) = 1;
	mat_elem(b, 2, 1) = 9;
	mat_elem(b, 3, 1) = 7;
#else
	mat_elem(a, 0, 0) = 0;
	mat_elem(a, 0, 1) = 0;
	mat_elem(a, 1, 0) = 2;
	mat_elem(a, 1, 1) = -5.1;
	mat_elem(a, 2, 0) = 4;
	mat_elem(a, 2, 1) = -9.5;
	mat_elem(a, 3, 0) = 6;
	mat_elem(a, 3, 1) = -6.9;
	mat_elem(a, 4, 0) = 8;
	mat_elem(a, 4, 1) = 7;
	mat_elem(a, 5, 0) = 10;
	mat_elem(a, 5, 1) = 38;
#endif

	mat_least_square(&b, a, 3);
	mat_print(b);


	mat_free(&a);	mat_free(&b);

	return 0;
}

