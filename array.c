#include "array.h"
// array print functions, get element functions, copy functions, slice functions, size functions, etc.
/*
C(w) = cardinality of word - number of possible values a variable word can take.
C(w) = size of P(w) - size of power set of variable word.
word size = log(C) - number of bits needed to represent the value of a word.

*/

// capped arrays :
typedef struct _carr_capd {
	char *arr;
	int size;
} carr_capd;
typedef struct _iarr_capd {
	double *arr;
	int size;
} iarr_capd;
typedef struct _sarr_capd {
	char **arr;
	int size;
} sarr_capd;
typedef struct _farr_capd {
	double *arr;
	int size;
} farr_capd;

// THIS SHIT ISN'T DONE : I JUST COPIED IT FROM LIST.C
void carr_print (char *list, int format) {
	if (format == LIST) {
		int index = 0;
		while (TRUE) {
			if (list == 0)
				break;
			printf ("[%d] %c\n", index, list -> val);
			list = list -> next;
			index ++;
		}
	}
	else {
		while (TRUE) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %c ] --> ", list -> val) : printf ("[ %c ]", list -> val);
			list = list -> next;
		}
	}
	printf ("\n");
}
