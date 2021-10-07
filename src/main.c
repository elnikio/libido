#include <stdio.h>
#include "vector.h"
#include "set.h"

int main(int argc, char **argv) {
	vec a = vec_gen (1, 4, 1, NULL);
	vec b = vec_gen (1, 4, 1, *scalar_third);
	vec_print_labeled (a, "A", 4);
	vec_print_labeled (b, "B", 4);
	vec aUb = set_union (a, b);
	vec_print_labeled (aUb, "union (A, B)", 4);
	vec aXb = set_intersection (a, b);
	vec_print_labeled (aXb, "intersection (A, B)", 4);
	vec aDb= set_difference (a, b);
	vec_print_labeled (aDb, "difference (A, B)", 4);
	vec empty = set_empty (10);
	vec_print_labeled (empty, "empty", 4);
}
