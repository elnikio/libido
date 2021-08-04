// Vector
#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include <math.h>
#include <plot.h>

// Types
#ifndef VECTOR
	typedef struct _vec {
		double *val; // vector contents.
		int size; // vector size.
	} vec; // This is the vector struct. All functions in vector.h operate on `vec`. It is identical to the struct `set` from `<libido/set.h>`.
#endif

// Constructors
vec vec_from_arr (double arr[], int size); // Initialize a vector from a double array.
vec vec_from_const (double cons, int size); // Initialize a vector with identical values.
vec vec_gen (double min, double max, double inc, double (*function)(double)); // Vector generating function meant for iteratively populating a vector.

// Methods
vec vec_fill (vec vec, double val); // Fill a vector with identical values.
vec vec_clear (vec vec); // Nullify a vector.
vec vec_mul_const (vec vec, double mul); // Multiply a vector by a constant.
vec vec_div_const (vec vec, double div); // Divide a vector by a constant.
vec vec_add_const (vec vec, double add); // Add a constant to each component of a vector.
vec vec_sub_const (vec vec, double sub); // Subtract a constant from each component of a vector.
vec vec_unit (vec vec); // Compute the unit vector of a select vector.
vec vec_add (vec vec0, vec vec1); // Add two vectors.
vec vec_sub (vec vec0, vec vec1); // Subtract two vectors.
vec vec_hada (vec vec0, vec vec1); // Compute the Hadamard product of two vectors.
double vec_mag (vec vec); // Compute the magnitude of a vector.
double dot_prod (vec vec0, vec vec1); // Compute the dot product of two vectors.
double cross_prod_mag (vec vec0, vec vec1); // Compute the cross product magnitude of two vectors.

// Printers
void vec_print (vec vec); // Print a vector in vector notation.
void vec_print_padded (vec vec, int padding); // Print a vector in vector notation with padding.
void vec_print_labeled (vec vec, char *label, int padding); // Print a vector in vector notation with padding and a label.
void good_dog (int dog); // Print the index of a good dog (not to be confused with bad_dog()).

#define VECTOR 0
