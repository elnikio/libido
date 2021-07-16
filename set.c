#include "set.h"

// 11 : 10 go to the subway
double *set_define (double *source, int size, int (*function)(int)) {
	double *set = malloc (sizeof (source));
	int i = 0;
	int j = 0;
	while (i < size || size == 0) {
		if (source [i] == '\0' || i == size)
			break;
		if (function ((int) source [i ++]))
			set [j ++] = source [i];
	}
	set [j] = '\0';
	return set;
}
