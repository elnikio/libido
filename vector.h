#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include <math.h>
#include <plot.h>

// vector class:
#ifndef VECTOR
	typedef struct _vec {
		double *val;
		int size;
	} vec;
#endif

// constructors:
vec vec_from_arr (double arr[], int size); // <-- throws a multiple definition error.
vec vec_from_const (double cons, int size);
vec vec_gen (double min, double max, double inc, double (*function)(double));

// methods:
vec vec_fill (vec vec, double val);
vec vec_clear (vec vec);
vec vec_mul_const (vec vec, double mul);
vec vec_div_const (vec vec, double div);
vec vec_add_const (vec vec, double add);
vec vec_sub_const (vec vec, double sub);
vec vec_unit (vec vec);
vec vec_add (vec vec0, vec vec1);
vec vec_sub (vec vec0, vec vec1);
vec vec_hada (vec vec0, vec vec1);
double vec_mag (vec vec);
double dot_prod (vec vec0, vec vec1);
double cross_prod_mag (vec vec0, vec vec1);

// printers:
void vec_print (vec vec);
void vec_print_padded (vec vec, int padding);

#define VECTOR 0
