#include "vector.h"

// constructors:
vec vec_from_arr (double arr[], int size) {
	vec vec;
	vec.val = arr;
	vec.size = size;
	return vec;
}

vec vec_from_const (double cons, int size) {
	vec vec;
	vec.val = malloc (sizeof (double) * size);
	vec.size = size;
	for (int i = 0; i < size; i ++)
		vec.val [i] = cons;
	return vec;
}

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
	return vec;
}

// modifiers:
vec vec_fill (vec vec, double val) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] = val;
	return vec;
}

vec vec_clear (vec vec) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] = 0;
	return vec;
}

vec vec_mul_const (vec vec, double mul) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] *= mul;
	return vec;
}

vec vec_div_const (vec vec, double div) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] /= div;
	return vec;
}

vec vec_add_const (vec vec, double add) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] += add;
	return vec;
}

vec vec_sub_const (vec vec, double sub) {
	for (int i = 0; i < vec.size; i ++)
		vec.val [i] -= sub;
	return vec;
}

vec vec_unit (vec vec) {
	vec = vec_div_const (vec, vec_mag (vec));
	return vec;
}

vec vec_add (vec vec0, vec vec1) {
	vec vec2 = vec_from_const (0, 2);
	for (int i = 0; i < vec0.size; i ++) {
		vec2.val [i] = vec1.val [i] + vec0.val[i];
	}
	return vec2;
}

vec vec_sub (vec vec0, vec vec1) {
	vec vec2 = vec_from_const (0, 2);
	for (int i = 0; i < vec0.size; i ++) {
		vec2.val [i] = vec0.val [i] - vec1.val [i];
	}
	return vec2;
}

vec vec_hada (vec vec0, vec vec1) {
	for (int i = 0; i < vec0.size; i ++) {
		vec0.val [i] *= vec1.val [i];
	}
	return vec0;
}

double vec_mag (vec vec) {
	double mag = 0;
	for (int i = 0; i < vec.size; i ++) {
		mag += (vec.val [i] * vec.val [i]);
	}
	return sqrt (mag);
}

double dot_prod (vec vec0, vec vec1) {
	double prod = 0;
	for (int i = 0; i < vec0.size; i ++) {
		prod += vec0.val [i] * vec1.val [i];
	}
	return prod;
}

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

// printers:
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

void vec_print_fancy (vec vec, char *label, int padding, const char* color) {
	printf ("%s%s = (%s", color, label, "\033[0;0m");
	for (int i = 0; i < vec.size; i ++) {
		(i < vec.size - 1) ?
		printf ("%*g, ", padding, vec.val [i]) :
		printf ("%*g", padding, vec.val [i]);
	}
	printf ("%s)%s", color, "\033[0;0m");
	printf ("\n");
}
void good_dog (int dog) {
	printf ("dog = %d\n", dog);
}
/*
int main () {
	double A[2] = {3,1},
		   B[2] = {7,-2};
	vec vecA = vec_from_arr (A, 2);
	vec vecB = vec_from_arr (B, 2);

	vec vecC = vec_add (vecA, vecB);
	vec vecD = vec_sub (vecA, vecB);
	vec_print_fancy (vecA, "A", 4, "\033[0;31m");
	vec_print_fancy (vecB, "B", 4, "\033[0;31m");
	vec_print_fancy (vecC, "A + B", 4, "\033[0;31m");
	vec_print_fancy (vecD, "A - B", 4, "\033[0;31m");
}
*/
