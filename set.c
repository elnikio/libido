#include "set.h"

set set_random (int size) {
	set set;
	double val[size];
	set.val = val;
	set.size = size;
}

set set_empty (int size) {
	set set;
	double *val = malloc (size * sizeof(double));
	set.val = val;
	set.size = size;
}

set set_define (double *source, int size, bool (*function)(double)) {
	double *val = malloc (sizeof (source));
	int i = 0;
	int j = 0;
	while (i < size || size == 0) {
		if (source [i] == '\0' || i == size)
			break;
		if (function ((int) source [i ++]))
			val [j ++] = source [i];
	}
	val [j] = '\0';
	set set;
	set.val = val;
	set.size = j;
	return set;
}

bool set_contains (set set, double target) {
	for (int i = 0; i < set.size; i ++) {
		if (set.val[i] == target)
			return TRUE;
	}
	return FALSE;
}

set set_union (set set0, set set1) {
	int i = 0;
	set out = set_empty (set0.size + set1.size);
	for (int j = 0; j < set0.size; j ++) {
		if (set_contains(out, set0.val[j]))
			out.val [i ++] = set0.val[j];
	}
	for (int j = 0; j < set1.size; j ++) {
		if (set_contains(out, set1.val[j]))
			out.val [i ++] = set1.val[j];
	}
	return out;
}
