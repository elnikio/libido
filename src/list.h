#include "generic.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
// generic list :
typedef struct _list list;
struct _list {
	void *val;
	list *next;
};

// generic bi-directional list :
typedef struct _bi_list bi_list;
struct _bi_list {
	void *val;
	bi_list *next;
	bi_list *prev;
};

// int list :
typedef struct _ilist ilist;
struct _ilist {
	long int val;
	ilist *next;
};

// bi-directional int list :
typedef struct _bi_ilist bi_ilist;
struct _bi_ilist {
	long int val;
	bi_ilist *next;
	bi_ilist *prev;
};

// list float :
typedef struct _flist flist;
struct _flist {
	double val;
	flist *next;
};

// bi-directional float list :
typedef struct _bi_flist bi_flist;
struct _bi_flist {
	double val;
	bi_flist *next;
	bi_flist *prev;
};

// list char :
typedef struct _clist clist;
struct _clist {
	char val;
	clist *next;
};

// bi-directional char list :
typedef struct _bi_clist bi_clist;
struct _bi_clist {
	char val;
	bi_clist *next;
	bi_clist *prev;
};

// list string :
typedef struct _slist slist;
struct _slist {
	char *val;
	slist *next;
};

// list string :
typedef struct _bi_slist bi_slist;
struct _bi_slist {
	char *val;
	bi_slist *next;
	bi_slist *prev;
};

#ifndef LIST_ENUMS
enum _print_format {
	LIST,
	DIAGRAM
};
#endif

// list element accessors :
clist *clist_el (clist *list, int index);
ilist *ilist_el (ilist *list, int index);
flist *flist_el (flist *list, int index);
slist *slist_el (slist *list, int index);

// bi-directional list element accessors :
bi_clist *bi_clist_el (bi_clist *list, int index);
bi_ilist *bi_ilist_el (bi_ilist *list, int index);
bi_flist *bi_flist_el (bi_flist *list, int index);
bi_slist *bi_slist_el (bi_slist *list, int index);

// fill list :
clist clist_fill (char *array);
ilist ilist_fill (int *array);
flist flist_fill (float *array);
slist slist_fill (char *array []);

// fill bi-list :
bi_clist bi_clist_fill (char *array);
bi_ilist bi_ilist_fill (int *array);
bi_flist bi_flist_fill (float *array);
bi_slist bi_slist_fill (char *array []);

// print list :
void list_print_string (list *list, int format);
void slist_print (slist *list, int format);
void clist_print (clist *list, int format);
void ilist_print (ilist *list, int format);
void flist_print (flist *list, int format);

// bounce print for bi-directional lists :
void clist_print_bounce (bi_clist *list, int format);

#define LIST_ENUMS 0
