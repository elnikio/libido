#include "generic.h"

// return ordinal number of character c in ASCII character set
int char_ordinal (char c) {
	return (int) c;
}

// return i-th character of ASCII character set
char char_ordinal_to_char (int i) {
	return (char) i;
}

// return the digit, represented by char c
int char_to_digit_ordinal (char c) {
	return (int)(c - '0');
}

// return the character, representing the digit i
char digit_ordinal_to_char (int i) {
	return (char)(i + '0');
}
