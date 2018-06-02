
#include <stdio.h>
#include <stdlib.h>

using namespace std;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)


#define FROM0
#define MAT_EPS 1.0e-8
#define mat_elem(mat,i,j)  ((mat).element[(i)*((mat).col)+(j)])


typedef struct {
	int row;
	int col;
	double *element;
} matrix;

int mat_alloc(matrix *mat1, int row, int col) {
	
	mat1->element = (double*)calloc(row*col, sizeof(double));
	if (mat1->element == NULL) {
		printf("配列用の領域が確保できませんでした。\n");
		exit(-1);
	}
	mat1->row = row;
	mat1->col = col;
	return 0;
}

void mat_free(matrix *mat1) {
	free(mat1->element);
}

void mat_print(matrix mat1) {
	REP(i, mat1.row) {
		REP(j, mat1.col) {
			printf("%4.2f  ", mat_elem(mat1, i, j));
		}
		printf("\n");
	}
}

int mat_copy(matrix *mat1, matrix mat2) {
	if ((mat1->row != mat2.row) || (mat1->col != mat2.col)) {
		return (-1);
	}
	REP(i, mat1->row) {
		REP(j, mat1->col) {
			mat_elem(*mat1, i, j) = mat_elem(mat2, i, j);
		}
	}
	return 0;
}

int mat_add(matrix *mat1, matrix mat2, matrix mat3)
{
	if ((mat1->row != mat2.row) || (mat1->col != mat2.col)) {
		return (-1);
	}
	if ((mat1->row != mat3.row) || (mat1->col != mat3.col)) {
		return (-1);
	}
	REP(i,mat2.row){
		REP(j,mat2.col) {
			mat_elem(*mat1, i, j) = mat_elem(mat2, i, j) + mat_elem(mat3, i, j);
		}
	}
	return 0;
}

int mat_sub(matrix *mat1, matrix mat2, matrix mat3)
{
	if ((mat1->row != mat2.row) || (mat1->col != mat2.col)) {
		return (-1);
	}
	if ((mat1->row != mat3.row) || (mat1->col != mat3.col)) {
		return (-1);
	}
	REP(i, mat2.row) {
		REP(j, mat2.col) {
			mat_elem(*mat1, i, j) = mat_elem(mat2, i, j) - mat_elem(mat3, i, j);
		}
	}
	return 0;
}

int mat_mul(matrix *mat1, matrix mat2, matrix mat3)
{
	if ((mat1->row != mat2.row) || (mat1->col != mat2.col)) {
		return (-1);
	}
	if ((mat1->row != mat3.row) || (mat1->col != mat3.col)) {
		return (-1);
	}
	if (mat2.col != mat3.row) {
		return (-1);
	}

	matrix matt;
	mat_alloc(&matt, mat1->row, mat1->col);
	REP(i, mat2.row) {
		REP(j, mat3.col) {
			
			double temp = 0;
			REP(k, mat3.row) {
				temp+= mat_elem(mat2, i, k) * mat_elem(mat3, k, j);
			}
			mat_elem(matt, i, j) = temp;
		}
	}
	mat_copy(mat1, matt);
	mat_free(&matt);
	
	return 0;
}

int mat_muls(matrix *mat1, matrix mat2, double c) {
	if ((mat1->row != mat2.row) || (mat1->col != mat2.col)) {
		return (-1);
	}
	REP(i, mat2.row) {
		REP(j, mat2.col) {
			mat_elem(*mat1, i, j) = mat_elem(mat2, i, j) * c;
		}
	}
	return 0;
}

int mat_trans(matrix *mat1, matrix mat2) {
	if ((mat1->row != mat2.col) || (mat1->col != mat2.row)) {
		return (-1);
	}
	matrix matt;
	mat_alloc(&matt, mat1->row, mat1->col);
	REP(i, mat2.row) {
		REP(j, mat2.col) {
			mat_elem(matt, i, j) = mat_elem(mat2, j, i);
		}
	}
	mat_copy(mat1, matt);
	mat_free(&matt);
	return 0;
}

int mat_unit(matrix *mat1) {
	if ((mat1->row  != mat1->col)) {
		return (-1);
	}
	REP(i, mat1->row) {
		REP(j, mat1->col) {
			if (i == j) {
				mat_elem(*mat1, i, j) = 1;
			}
			else {
				mat_elem(*mat1, i, j) = 0;
			}
		}
	}
	return 0;
}

int mat_compare(matrix mat1, matrix mat2) {
	if ((mat1.row != mat2.row) || (mat1.col != mat2.col)) {
		return (-1);
	}
	int flag = 1;
	REP(i, mat1.row) {
		REP(j, mat1.col) {
			if (mat_elem(mat1, i, j) != mat_elem(mat2, i, j)) {
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	matrix a, b, c;

	if (mat_alloc(&a, 4, 4)) printf("allocation error\n");
	if (mat_alloc(&b, 4, 4)) printf("allocation error\n");
	if (mat_alloc(&c, 4, 4)) printf("allocation error\n");

	printf("行列aの行数は，%dです．\n", a.row);
	printf("行列cの列数は，%dです．\n", c.col);

#ifndef FROM0
	mat_elem(a, 1, 1) = 3;
	mat_elem(a, 1, 2) = 5;
	mat_elem(a, 1, 3) = 2;
	mat_elem(a, 2, 2) = 0.5;
	mat_elem(a, 2, 4) = -3.5;
	mat_elem(a, 3, 3) = 1.5;
	mat_elem(a, 4, 2) = 2.5;
	mat_elem(b, 1, 1) = 4;
	mat_elem(b, 1, 2) = 4;
	mat_elem(b, 1, 3) = 1;
	mat_elem(b, 2, 2) = 1.5;
	mat_elem(b, 2, 4) = -2.5;
	mat_elem(b, 3, 3) = 0.5;
	mat_elem(b, 4, 2) = 1.5;
#else
	mat_elem(a, 0, 0) = 3;
	mat_elem(a, 0, 1) = 5;
	mat_elem(a, 0, 2) = 2;
	mat_elem(a, 1, 1) = 0.5;
	mat_elem(a, 1, 3) = -3.5;
	mat_elem(a, 2, 2) = 1.5;
	mat_elem(a, 3, 1) = 2.5;
	mat_elem(b, 0, 0) = 4;
	mat_elem(b, 0, 1) = 4;
	mat_elem(b, 0, 2) = 1;
	mat_elem(b, 1, 1) = 1.5;
	mat_elem(b, 1, 3) = -2.5;
	mat_elem(b, 2, 2) = 0.5;
	mat_elem(b, 3, 1) = 1.5;
#endif

	printf("matrix a = \n");
	mat_print(a);

	printf("matrix b = \n");
	mat_print(b);

	mat_add(&c, a, b);
	printf("matrix a+b = \n");
	mat_print(c);

	mat_sub(&c, a, b);
	printf("matrix a-b = \n");
	mat_print(c);

	mat_free(&a);
	mat_free(&b);
	mat_free(&c);

	return 0;
}

