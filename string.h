#include "generic.h"
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include <stdio.h>

// string type :
typedef char* string;

// string comparison :
bool string_greater_than (string string1, string string2);
bool string_less_than (string string1, string string2);
bool string_equal (string string1, string string2);
bool string_unequal (string string1, string string2);
int string_greatest (string *strings, int size);
int string_find_char_first (string string1, char char1);
int string_find_char_last (string string1, char char1);
void string_copy_by_value (string string1, string string2);	// buggy
void string_copy_by_ref (string string1, string string2);	// buggy

#define STRING_ENUMS 0
