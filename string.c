#include "string.h"

// print:
void string_print (string str) {
	for (int i = 0; str [i] != '\0'; i ++)
		printf ("%c", str [i]);
		printf ("\n");
}

// logical:
bool string_greater_than (string string1, string string2) {
	for (int i = 0; string1 [i] != '\0' || string2 [i] != '\0'; i ++) {
		if (
			(string1 [i] > string2 [i]) ||
			(string1 [i] != '\0' && string2 [i] == '\0')
		) return FALSE;
		if (
			(string1 [i] < string2 [i]) ||
			(string1 [i] == '\0' && string2 [i] != '\0')
		) return TRUE;
	}
	return FALSE;
}
bool string_less_than (string string1, string string2) {
	for (int i = 0; string1 [i] != '\0' || string2 [i] != '\0'; i ++) {
		if (
			(string1 [i] > string2 [i]) ||
			(string1 [i] != '\0' && string2 [i] == '\0')
		) return TRUE;
		if (
			(string1 [i] < string2 [i]) ||
			(string1 [i] == '\0' && string2 [i] != '\0')
		) return FALSE;
	}
	return FALSE;
}
bool string_equal (string string1, string string2) {
	for (int i = 0; string1 [i] != '\0' || string2 [i] != '\0'; i ++) {
		if (
			(string1 [i] > string2 [i]) ||
			(string1 [i] != '\0' && string2 [i] == '\0')
		) return FALSE;
		if (
			(string1 [i] < string2 [i]) ||
			(string1 [i] == '\0' && string2 [i] != '\0')
		) return FALSE;
	}
	return TRUE;
}
bool string_unequal (string string1, string string2) {
	for (int i = 0; string1 [i] != '\0' || string2 [i] != '\0'; i ++) {
		if (
			(string1 [i] > string2 [i]) ||
			(string1 [i] != '\0' && string2 [i] == '\0')
		) return TRUE;
		if (
			(string1 [i] < string2 [i]) ||
			(string1 [i] == '\0' && string2 [i] != '\0')
		) return TRUE;
	}
	return FALSE;
}

// item:
int string_greatest (string *strings, int size) {
	int max;
	int greatest_index = -1;
	for (int i = 0; ; i ++) {
		max = strings [0][i];
		for (int j = 0; j < size; j++) {
			if (strings [j][i] > max) {
				max = strings [j][i];
				greatest_index = j;
			}
		}
		if (greatest_index != -1)
			return greatest_index;
	}
	return 0;
}
int string_find_char_first (string string1, char char1) {
	for (int i = 0; string1 [i] != '\0'; i ++) {
		if (string1 [i] == char1)
			return i;
	}
	return -1;
}
int string_find_char_last (string string1, char char1) {
	int pos = -1;
	for (int i = 0; string1 [i] != '\0'; i ++) {
		if (string1 [i] == char1)
			pos = i;
	}
	return pos;
}

// copy:
void string_copy_by_value (string string1, string string2) {
	int i;
	for (i = 0; string1 [i] != '\0'; i ++)
		string2 [i] = string1 [i];
	string2 [i + 1] = '\0';
}
void string_copy_by_ref (string string1, string string2) {
	string2 = string1;
}
