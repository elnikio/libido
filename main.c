#include <stdio.h>
#include <libido/vector.h>
#include <libido/arithmetic.h>
//#include "vector.h"
//#include "arithmetic.h"

int main() {
	printf ("This is awesome! Yolo!\n");
	vec vec0 = vec_gen (1, 3, 1, &scalar_two_pow_neg);
	vec vec1;
	double val1[] = {6.0, 1.0, 4.0};
	vec1.val = val1;
	vec1.size = 3;
	printf ("vec0 = ");
	vec_print_padded (vec0, 6);
	printf ("vec1 = ");
	vec_print_padded (vec1, 6);
	printf ("|| vec0 x vec1 || = %lf\n", cross_prod_mag (vec0, vec1));;
}
// cartinality of word - number of possible values
// wordsize - number of bits
// storage size = address-space * wordsize
