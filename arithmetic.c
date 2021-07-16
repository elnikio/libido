#include "arithmetic.h"

// add :
double scalar_add (double n, double m) {
	return n + m;
}

// subtract :
double scalar_sub (double n, double m) {
	return n - m;
}

// multiply:
double scalar_mul (double n, double m) {
	return n * m;
}

// divide:
double scalar_div (double n, double m) {
	return n / m;
}

// double :
double scalar_double (double n) {
	return 2 * n;
}

// tripple :
double scalar_tripple (double n) {
	return 3 * n;
}

// quadruple :
double scalar_quadruple (double n) {
	return 4 * n;
}

// half :
double scalar_half (double n) {
	return n / 2;
}

// third :
double scalar_third (double n) {
	return n / 3;
}

// forth :
double scalar_forth (double n) {
	return n / 4;
}

// tenth :
double scalar_tenth (double n) {
	return n / 10;
}

// powers :
double scalar_pow (double num, int pow) {
	double acc = 1;
	for (int i = 0; i < pow; i ++)
	acc *= num;
	return acc;
}

// powers of two :
double scalar_two_pow (double n) {
	return scalar_pow (2, n);
}
double scalar_two_pow_neg (double n) {
	return 1 / scalar_pow (2, n);
}

// powers of ten :
double scalar_ten_pow (double n) {
	return scalar_pow (10, n);
}
double scalar_ten_pow_neg (double n) {
	return 1 / scalar_pow (10, n);
}
