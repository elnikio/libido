#include "generic.h"
#include <stdlib.h>
#include "vector.h"

#ifndef SET
/*
typedef struct _set {
	double *val;
	int size;
} set;
*/
typedef vec set;
#endif

set set_random (int size);
set set_empty (int size);
set set_define (double *source, int size, bool (*function)(double));
bool set_contains (set set, double target);
set set_union (set set0, set set1);
set set_intersection (set set0, set set1);
set set_difference (set set0, set set1);

#define SET 0
