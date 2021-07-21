#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include <math.h>
#include <plot.h>

#ifndef VECTOR
// vector class :
typedef struct _vec {
	double *val;
	int size;
} vec;

enum _plot_options {
	POINTS = 0b1,
	LINE = 0b10,
};

#endif

// Only the double version of everything works.

// initialize vector from double array :
vec vec_init (double *arr, int size); // <---

// print vec :
void vec_print (vec vec);
void vec_print_padded (vec vec, int padding);

// genereate vec iteratively :
vec vec_gen (double min, double max, double inc, double (*function)(double));

// lossy compression functions that retain some meaningful information about the vectors :

// component-wise arithmetic :
vec vec_add (vec vec0, vec vec1);
vec vec_sub (vec vec0, vec vec1);
vec hada_prod (vec vec0, vec vec1);

// vector magnitude :
double vec_mag (vec vec);

// dor product :
double dot_prod (vec vec0, vec vec1);

// cross product :
vec cross_prod (vec vec0, vec vec1); // <---
double cross_prod_mag (vec vec0, vec vec1);

#define VECTOR 0
