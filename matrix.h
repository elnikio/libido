#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
// matrix class :
typedef struct _mat {
	int **val;
	int size_x;
	int size_y;
} mat;
typedef struct _lmat {
	long **val;
	long size_x;
	long size_y;
} lmat;
typedef struct _dmat {
	double **val;
	int size_x;
	int size_y;
} dmat;
typedef struct _fmat {
	double **val;
	int size_x;
	int size_y;
} fmat;

// print :
void mat_print (fmat mat);
void mat_print_padded (fmat mat, int padding);

// generate matrix iteratively :
fmat mat_gen (
		double min_x, double max_x, double inc_x,
		double min_y, double max_y, double inc_y,
		double (*function)(double, double)
	);

#define MATRIX_ENUMS 0
