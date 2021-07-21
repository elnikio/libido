#ifndef NULL
#define NULL 0
#endif

#ifndef GENERIC
enum _object {
	CONSTANT = 1,
	TYPE,
	VARIABLE,
	PROCEDURE,
	FUNCTION
};

enum _bool {
	FALSE,
	TRUE
};

enum _return {
	SUCCESS,
	FAILURE
};
#endif

typedef char bool;

// return ordinal number of character c in ASCII character set
int char_ordinal (char c);

// return i-th character of ASCII character set
char char_ordinal_to_char (int i);

// return the digit, represented by char c
int char_to_digit_ordinal (char c);

// return the character, representing the digit i
char digit_ordinal_to_char (int i);

#define GENERIC 0
