#include "list.h"

int clist_size (clist *list);
char *clist_to_carr (clist *list);
/*
T = {a, b, c}
P(T) = {{}, {a}, {b}, {c}, {a,b}, {a,c}, {b,c}, {a,b,c}}
T - alphabet of P(T) - set of all elements, composing the elements of P(T)
P(T) - language of T - set of all sets, comprised of elements of T
B(P(T)) = {a, b, c}
/*
T = {a, b, c}
P(T) = {{}, {a}, {b}, {c}, {a,b}, {a,c}, {b,c}, {a,b,c}}
T - alphabet of P(T) - set of all elements, composing the elements of P(T)
P(T) - language of T - set of all sets, comprised of elements of T
B(P(T)) = {a, b, c}

base type set = alphabet
power set = language

People think that the economy is some magic horn of plenty - that it just spits out products and you don't have to do anything. That's incredibly ignorant. If you don't make stuff, there is no stuff. If you don't make something that an AI can't, there won't be anything that an AI can't make. Here's something else - the difference between children and adults is - children consume, adults create. School is the training ground for you to learn how to create. Not only that, but also to train your societal-contribution radar, aka learning to make shit that's valuable. And the awesome thing about being an adult is that you very quickly realize when something you're doing is not valuable. At least that's how it works in real capitalism. Whatever that means.
*/

// test program :
int main () {
	char stringo[] = "legit engineer.";
	clist chars = clist_fill (stringo);
	clist_print (&chars, DIAGRAM);
	printf ("size = %d\n", clist_size (&chars));
	printf ("el 14 = %c\n", clist_el (&chars, 14) -> val);
}
// list element accessors :
clist *clist_el (clist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	return list;
}
ilist *ilist_el (ilist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	return list;
}
flist *flist_el (flist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	return list;
}
slist *slist_el (slist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	return list;
}
// bi-directional list element accessors :
bi_clist *bi_clist_el (bi_clist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	for (int i = 0; i > index && list -> prev != 0; i --) {
		list = list -> prev;
	}
	return list;
}
bi_ilist *bi_ilist_el (bi_ilist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	for (int i = 0; i > index && list -> prev != 0; i --) {
		list = list -> prev;
	}
	return list;
}
bi_flist *bi_flist_el (bi_flist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	for (int i = 0; i > index && list -> prev != 0; i --) {
		list = list -> prev;
	}
	return list;
}
bi_slist *bi_slist_el (bi_slist *list, int index) {
	for (int i = 0; i < index && list -> next != 0; i ++) {
		list = list -> next;
	}
	for (int i = 0; i > index && list -> prev != 0; i --) {
		list = list -> prev;
	}
	return list;
}

// fill list :
clist clist_fill (char *array) {
	clist *first = malloc (sizeof (clist));
	clist *list = malloc (sizeof (clist));
	first -> next = list;
	for (int i = 0; array [i] != '\0'; i ++) {
		list -> val = array [i];
		if (array [i + 1] != '\0')
			list -> next = malloc (sizeof (clist));
		list = list -> next;
	}
	return * (first -> next);
}
ilist ilist_fill (int *array) {
	ilist *first = malloc (sizeof (ilist));
	ilist *list = malloc (sizeof (ilist));
	first -> next = list;
	for (int i = 0; array [i] != '\0'; i ++) {
		list -> val = array [i];
		if (array [i + 1] != '\0')
			list -> next = malloc (sizeof (ilist));
		list = list -> next;
	}
	return * (first -> next);
}
flist flist_fill (float *array) {
	flist *first = malloc (sizeof (flist));
	flist *list = malloc (sizeof (flist));
	first -> next = list;
	for (int i = 0; array [i] != '\0'; i ++) {
		list -> val = array [i];
		if (array [i + 1] != '\0')
			list -> next = malloc (sizeof (flist));
		list = list -> next;
	}
	return * (first -> next);
}
slist slist_fill (char *array []) {
	slist *first = malloc (sizeof (slist));
	slist *list = malloc (sizeof (slist));
	first -> next = list;
	for (int i = 0; array [i] != NULL; i ++) {
		list -> val = array [i];
		if (array [i + 1] != NULL)
			list -> next = malloc (sizeof (slist));
		list = list -> next;
	}
	return * (first -> next);
}

// fill bi-list :
bi_clist bi_clist_fill (char *array) {
	bi_clist *first = malloc (sizeof (bi_clist));
	bi_clist *list = malloc (sizeof (bi_clist));
	first -> next = list;
	list -> prev = first; //
	for (int i = 0; array [i] != '\0'; i ++) {
		list -> val = array [i];
		if (array [i + 1] != '\0') {
			list -> next = malloc (sizeof (bi_clist));
			list -> next -> prev = list; //
		}
		list = list -> next;
	}
	first -> next -> prev = 0;
	return * (first -> next);
}
bi_ilist bi_ilist_fill (int *array) {
	bi_ilist *first = malloc (sizeof (bi_ilist));
	bi_ilist *list = malloc (sizeof (bi_ilist));
	first -> next = list;
	list -> prev = first;
	for (int i = 0; array [i] != '\0'; i ++) {
		list -> val = array [i];
		if (array [i + 1] != '\0') {
			list -> next = malloc (sizeof (bi_ilist));
			list -> next -> prev = list;
		}
		list = list -> next;
	}
	return * (first -> next);
}
bi_flist bi_flist_fill (float *array) {
	bi_flist *first = malloc (sizeof (bi_flist));
	bi_flist *list = malloc (sizeof (bi_flist));
	first -> next = list;
	list -> prev = first;
	for (int i = 0; array [i] != '\0'; i ++) {
		list -> val = array [i];
		if (array [i + 1] != '\0') {
			list -> next = malloc (sizeof (bi_flist));
			list -> next -> prev = list;
		}
		list = list -> next;
	}
	return * (first -> next);
}
bi_slist bi_slist_fill (char *array []) {
	bi_slist *first = malloc (sizeof (bi_slist));
	bi_slist *list = malloc (sizeof (bi_slist));
	first -> next = list;
	list -> prev = first;
	for (int i = 0; array [i] != NULL; i ++) {
		list -> val = array [i];
		if (array [i + 1] != NULL) {
			list -> next = malloc (sizeof (bi_slist));
			list -> next -> prev = list;
		}
		list = list -> next;
	}
	return * (first -> next);
}

// print list :
void list_print_string (list *list, int format) {
	if (format == LIST) {
		int index = 0;
		while (TRUE) {
			if (list == 0)
				break;
			printf ("[%d] %s\n", index, (char *)(list -> val));
			list = list -> next;
			index ++;
		}
	}
	else {
		while (TRUE) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %s ] --> ", (char *)(list -> val)) : printf ("[ %s ]", (char *)(list -> val));
			list = list -> next;
		}
	}
}
void slist_print (slist *list, int format) {
	if (format == LIST) {
		int index = 0;
		while (TRUE) {
			if (list == 0)
				break;
			printf ("[%d] %s\n", index, (char *)(list -> val));
			list = list -> next;
			index ++;
		}
	}
	else {
		while (TRUE) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %s ] --> ", (char *)(list -> val)) : printf ("[ %s ]", (char *)(list -> val));
			list = list -> next;
		}
	}
	printf ("\n");
}
/*
char **slist_to_sarr (slist *list) {
	if (format == LIST) {
		int index = 0;
		while (TRUE) {
			if (list == 0)
				break;
			printf ("[%d] %s\n", index, (char *)(list -> val));
			list = list -> next;
			index ++;
		}
	}
}
*/
int clist_size (clist *list) {
	int size = 0;
	while (list != 0) {
		list = list -> next;
		size ++;
	}
	return size;
}
char *clist_to_carr (clist *list) {
	char *arr = malloc (clist_size (list));
	for (int i = 0; list != 0; i ++) {
		arr [i] = list -> val;
		list = list -> next;
	}
	return arr;
}
void clist_print (clist *list, int format) {
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
void ilist_print (ilist *list, int format) {
	if (format == LIST) {
		int index = 0;
		while (TRUE) {
			if (list == 0)
				break;
			printf ("[%d] %ld\n", index, list -> val);
			list = list -> next;
			index ++;
		}
	}
	else {
		while (TRUE) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %ld ] --> ", list -> val) : printf ("[ %ld ]", list -> val);
			list = list -> next;
		}
	}
	printf ("\n");
}
void flist_print (flist *list, int format) {
	if (format == LIST) {
		int index = 0;
		while (TRUE) {
			if (list == 0)
				break;
			printf ("[%d] %lf\n", index, list -> val);
			list = list -> next;
			index ++;
		}
	}
	else {
		while (TRUE) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %lf ] --> ", list -> val) : printf ("[ %lf ]", list -> val);
			list = list -> next;
		}
	}
	printf ("\n");
}

// bounce print for bi-directional lists :
void clist_print_bounce (bi_clist *list, int format) {
	if (format == LIST) {
		int index = 0;
		while (list -> next != 0) {
			printf ("[%d] %c\n", index, list -> val);
			list = list -> next;
			index ++;
		}
		while (list -> prev != 0) {
			printf ("[%d] %c\n", index, list -> val);
			list = list -> prev;
			index --;
		}
	}
	else {
		while (list -> next != 0) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %c ] --> ", list -> val) : printf ("[ %c ]", list -> val);
			list = list -> next;
		}
		while (list -> prev != 0) {
			if (list == 0)
				break;
			(list -> next != 0) ? printf ("[ %c ] --> ", list -> val) : printf ("[ %c ]", list -> val);
			list = list -> prev;
		}
	}
	printf ("\n");
}
