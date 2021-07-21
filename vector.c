#include "vector.h"

/*
int main () {
	printf ("kiddo eat ganda.\n");
	vec vec0 = vec_gen (2, 10, 1, NULL);
	vec_print_padded (vec0, 6);
	double array[] = {1.0, 4.2, 2.1, 6.3, 8.4};
	vec vec1 = vec_init (array, 5);
	vec_print_padded (vec1, 6);
}
*/

// initialize vector from double array :
vec vec_init (double *arr, int size) {
	vec vec;
	vec.val = arr;
	vec.size = size;
	return vec;
}

// print vector :
void vec_print (vec vec) {
	printf ("(");
	for (int i = 0; i < vec.size; i ++)
		(i < vec.size - 1) ? printf ("%g, ", vec.val [i]) : printf ("%g", vec.val [i]);
	printf (")");
	printf ("\n");
	printf ("vec.size = %d\n", vec.size);
}

void vec_print_padded (vec vec, int padding) {
	printf ("(");
	for (int i = 0; i < vec.size; i ++) {
		(i < vec.size - 1) ?
		printf ("%*g, ", padding, vec.val [i]) :
		printf ("%*g", padding, vec.val [i]);
	}
	printf (")");
	printf ("\n");
}

// genereate vector iteratively :
vec vec_gen (double min, double max, double inc, double (*function)(double)) {
	vec vec;
	double i;
	int j;
	double *val = malloc (((int)((max - min) / inc) + 2) * sizeof (double));
	for (i = min, j = 0; i <= max; i += inc, j ++) {
		if (function)
			val [j] = function (i);
		else
			val [j] = i;
	}
	vec.val = val;
	vec.size = j;
	printf ("generated vec size = %d\n", vec.size);
	return vec;
}

// fill vector with identical values:
vec vec_fill (vec vec, double val) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] = val;
	return vec;
}

// plot vector data :
void vec_plot (vec vec, char options) {

	printf ("plotting\n");
}

// component-wise arithmetic :
vec vec_add (vec vec0, vec vec1) {
	for (int i = 0; i < vec0.size; i ++) {
		vec0.val [i] += vec1.val [i];
	}
	return vec0;
}
vec vec_sub (vec vec0, vec vec1) {
	for (int i = 0; i < vec0.size; i ++) {
		vec0.val [i] -= vec1.val [i];
	}
	return vec0;
}
vec hada_prod (vec vec0, vec vec1) {
	for (int i = 0; i < vec0.size; i ++) {
		vec0.val [i] *= vec1.val [i];
	}
	return vec0;
}

// vector magnitude :
double vec_mag (vec vec) {
	double mag = 0;
	for (int i = 0; i < vec.size; i ++) {
		mag += (vec.val [i] * vec.val [i]);
	}
	return sqrt (mag);
}

// dot product :
double dot_prod (vec vec0, vec vec1) {
	double prod = 0;
	for (int i = 0; i < vec0.size; i ++) {
		prod += vec0.val [i] * vec1.val [i];
	}
	return prod;
}

// cross product :
double cross_prod_mag (vec vec0, vec vec1) {
	if (vec0.size != 3 || vec1.size != 3) {
		printf ("error: attempting to compute cross-product of non-3-dimensional vectors.");
		return 0;
	}
	double v0_mag = vec_mag (vec0);
	double v1_mag = vec_mag (vec1);
	double diff_mag = vec_mag (vec_sub (vec0, vec1));
	double cos = (v0_mag*v0_mag + v1_mag*v1_mag - diff_mag*diff_mag) / (2*(v0_mag*v1_mag));
	double sin = sqrt (1 - cos*cos);
	return sin * v0_mag * v1_mag;
}
