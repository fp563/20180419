
#include <math.h>
#include "matrix.h"

int least_square(matrix *a, matrix points, int order);

int least_square(matrix *a, matrix points, int order) {
	matrix G, F;
	if (mat_alloc(&G, order + 1, order + 1)) return (-1);
	if (mat_alloc(&F, order + 1, 1)) return (-1);

	REP(i, order+1 ) {
		mat_elem(F, i, 0) = 0;
		REP(j, order+1 ) {
			mat_elem(G, i, j) = 0;
			REP(k, points.row) {
				mat_elem(G, i, j) += pow(mat_elem(points, k,0), i)*pow(mat_elem(points, k,0), j);
			}	
		}
	}

	REP(i, order + 1) {
		REP(j, points.row) {
			mat_elem(F, i, 0) += pow(mat_elem(points, j, 0), i)*mat_elem(points, j, 1);
		}
	}

	
	mat_solve_pivot(a, G, F);

	mat_free(&G);
	mat_free(&F);

	return 0;
}
