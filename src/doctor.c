// Generate documentation from header files.
#include <stdio.h>
#include <string.h>
#include "string.h"
#include "list.h"

void generate (FILE *doc, char *filename);
int stage_next (FILE *fp);
char read_char (FILE *fp);
void skip_blank (FILE *fp);
char read_back_char (FILE *fp);
void unread_char (FILE *fp);
char *read_till (FILE *fp, char till, char *read);
int read_till_or (FILE *fp, char *till, char count, char *read);
void read_through (FILE *fp, char *through);
int read_through_or (FILE *fp, char *through[], char count);

enum _generate_stage {
	DONE,
	SEEK,
	TITLE,
	STRUCT,
	UNSIGNED,
	SIGNED,
	CHAR,
	INT,
	SHORT,
	LONG,
	FLOAT,
	DOUBLE,
	MACROS,
	FUNCTIONS
};

FILE *doc;
int modules;
char pointer;
int funcs;
int stage = TITLE;

int main (int argc, char **argv) {
	//FILE *fp;

	funcs = 0;
	modules = 0;
	// header:
	doc = fopen("./DOC.md.md", "w");
	fputs ("# **Libido - \\<libido/\\>**\nA C math library.\n\n1. [Installation](#installation)  \n2. [Documentation](#documentation)  \n	2.1. [Vector](#vector)\n---\n# **1. Installation**\n1. Run install.sh, which copies the files to your include directory.\n2. Compile using ./compile.sh.\n---\n# **2. Documentation**\n", doc);
	fclose (doc);

	// vector:
	doc = fopen ("./DOC.md.md", "a");
	char *vector = "vector.h";
	generate (doc, vector);

	// close file:
	fclose (doc);
}

int i;
int seeking;

void generate (FILE *doc, char *filename) {
	modules ++;
	FILE *fp;

	char dir[32];
	char temp[100];

	strcpy (dir, "./");
	strcat (dir, filename);
	printf ("Generating documentation for %s\n", dir);
	fp = fopen  (dir, "r");
	char head;
	fseek (fp, 0L, SEEK_END);
	int len = ftell (fp);
	rewind (fp);
	printf ("[\"\n");
	for (i = 0; i < len || i == -1; i ++, head = fgetc (fp)) {
		pointer = head;
		if (stage != 0)
			putchar (head);
		switch (stage) {
			case SEEK:
				if (head == '/' && read_char (fp) == '/') {
					stage = stage_next (fp);
				}
				break;
			case TITLE:
				if (head == '/' && read_char (fp) == '/') {
					printf ("\n\"]\n");
					while (read_char (fp) == ' ');
					unread_char(fp);
					//char *title = malloc (100);
					char title[100];
					read_till (fp, '\n', title);
					printf ("TITLE: %s\n", title);
					fputs ("---\n", doc);
					fprintf (doc, "## 2.%d. **%s** - <libido/%s>\n", modules, title, filename);
					printf ("[\"\n");
					stage = SEEK;
				}
				break;
			case STRUCT:
				unread_char (fp);
				printf ("[\"\n");
				//read_through (fp, "struct _\0");
				while (read_char (fp) == ' ');
				unread_char (fp);

				// table header:
				fputs ("| Variable Type: | Members: | Description: |\n", doc);
				fputs ("| - | - | - |\n", doc);

				// struct name:
				char name [100];
				read_till (fp, '{', name);
				printf ("NAME = %s\n", name);
				read_till (fp, '\n', temp);
				fprintf (doc, "| %s |", name);

				// struct args:
				do {
					char arg [100];
					skip_blank (fp);
					if (read_char (fp) == '}') // check for struct end.
						break;
					unread_char (fp);
					read_till (fp, ';', arg);
					printf ("ARG = %s\n", arg);
					fprintf (doc, " `%s` -", arg);
					char desc [100];
					read_through (fp, "//");
					skip_blank (fp);
					read_till (fp, '\n', desc);
					printf ("DESCRIPTION = %s\n", desc);
					fprintf (doc, " %s <br>", desc);
				} while (1);

				// struct description:
				char type_desc [100];
				read_through (fp, name);
				read_through (fp, "//");
				skip_blank (fp);
				read_till (fp, '\n', type_desc);
				printf ("TYPE DESCRIPTION = %s\n", type_desc);
				fprintf (doc, "| %s |\n\n", type_desc);
				stage = 0;
				stage = SEEK;
				break;
			case MACROS:
				break;
			case FUNCTIONS:
				unread_char(fp);
				int more_func = 1;
				char function[100];
				fputs ("| Function: | Arguments: | Description: |\n", doc);
				fputs ("| - | - | - |\n", doc);
				do {
					// function name:
					read_till(fp, '(', function);
					fprintf (doc, "| `%s`", function);
					int more_args = 1;

					// function arguments:
					char arg[100];
					char arg_desc[100];
					read_till (fp, '\n', temp);
					fputs ("|", doc);
					do {
						printf ("SCANNING FUCTION ARGUMENTS\n");
						skip_blank (fp);
						if (read_char (fp) != ')') {
							// argument:
							unread_char (fp);
							read_till(fp, '/', arg);
							char *arg_format = string_remove (arg, ',');
							printf ("ARG = %s\n", arg_format);

							// argument description:
							read_char(fp);
							skip_blank (fp);
							read_till(fp, '\n', arg_desc);
							printf ("DESCRIPTION = %s\n", arg_desc);
							fprintf (doc, " `%s` - ", arg_format);
							fprintf (doc, "%s<br>", arg_desc);
						}
						else {
							fputs (" |", doc);
							more_args = 0;
						}
					}
					while (more_args);

					// function description:
					char func_desc[100];
					read_through (fp, "//");
					skip_blank (fp);
					read_till (fp, '\n', func_desc);
					printf ("FUNCTION DESCRIPTION = %s\n", func_desc);
					fprintf (doc, " %s |\n", func_desc);
					// is last function?
					//more_func = read_till_or (fp, "/(", 2, NULL);
					skip_blank (fp);
					if (read_char(fp) == '/')
						more_func = 0;
					unread_char (fp);
				} while (more_func);
				stage = SEEK;
				//if (funcs == 2)
				//	stage = 0;
				//funcs ++;
				seeking = 51;
				break;
			case 0:
				i = len;
		}
	}
}

int stage_next (FILE *fp) {
	printf ("\n\"]\n");
	while (read_char (fp) == ' ');
	unread_char(fp);
	char macro[100];
	read_till (fp, '\n', macro);
	printf ("STAGE: %s\n", macro);

	if (string_equal (macro, "End"))
		stage = 0;
	// Types:
	else if (string_equal (macro, "Types")) {
		//fputs ("---\n", doc);
		fprintf (doc, "### %s:\n", macro);
		char *type[9];
		type[0] = "struct _\0";
		type[1] = "unsigned\0";
		type[2] = "signed\0";
		type[3] = "char\0";
		type[4] = "int\0";
		type[5] = "short\0";
		type[6] = "long\0";
		type[7] = "float\0";
		type[8] = "double\0";
		int type_type = read_through_or (fp, type, 9);
		switch (type_type) {
			case 0:
				return STRUCT;
			case 1:
				return UNSIGNED;
			case 2:
				return SIGNED;
			case 3:
				return CHAR;
			case 4:
				return INT;
			case 5:
				return SHORT;
			case 6:
				return LONG;
			case 7:
				return FLOAT;
			case 8:
				return DOUBLE;
		}
		return DONE;
	}
	// Functions:
	else {
		//fputs ("---\n", doc);
		fprintf (doc, "\n### %s:\n", macro);
		return FUNCTIONS;
	}
	return DONE;
}

char read_char (FILE *fp) {
	char read = fgetc (fp);
	if (read == EOF)
		stage = 0;
	pointer = read;
	//putchar (read);
	i ++;
	return read;
}

void skip_blank (FILE *fp) {
	char c;
	do {
		c = read_char (fp);
	} while (c == ' ' || c == '\t' || c == '\n');
	unread_char (fp);
}

char read_back_char (FILE *fp) {
	char read = fgetc (fp);
	pointer = read;
	//putchar (read);
	fseek (fp, -2, SEEK_CUR);
	i --;
	return read;
}

void unread_char (FILE *fp) {
	i --;
	fseek (fp, -1, SEEK_CUR);
}

// read till you find a specified char.
char *read_till (FILE *fp, char till, char *read) {
	char c;
	int j = 0;
	while ((c = read_char (fp)) != till) {
		read[j] = c;
		j ++;
	}
	read[j] = '\0';
	return read;
}

// read till you find one of the chars in specified array.
int read_till_or (FILE *fp, char *till, char count, char *read) {
	// count = number of characters in till (chars to look for).
	//char read[100];
	int searching = 1;
	char c;
	int j = 0;
	int i;
	do {
		c = read_char (fp);
		(read != NULL) ? read[j ++] = c : 0;
		for (i = 0; i < count; i ++)
			if (c == till[i]) {
				searching = 0;
				break;
			}
	} while (searching);
	(read != NULL) ? read[j] = '\0' : 0;
	return i;
}

char *rev_till (FILE *fp, char till, char *read) {
	char c;
	int j = 0;
	while ((c = read_back_char (fp)) != till) {
		read[j ++] = c;
	}
	read[j] = '\0';
	return read;
}

void read_through (FILE *fp, char *through) {
	for (int j = 0; through[j] != '\0'; ) {
		if (read_char (fp) == through[j])
			j ++;
	}
}

// read till you find one of the specified strings. return its index. if none is found, return -1.
int read_through_or (FILE *fp, char *through[], char count) {
	int searching = 1;
	int index[16];
	int k;
	char c;
	for (int j = 0; j < 16; j ++)
		index[j] = 0;
	while (searching) {
		c = read_char (fp);
		for (k = 0; k < count; k ++) {
			if (through[k][index[k]] == '\0') {
				searching = 0;
				break;
			}
			if (c == through[k][index[k]])
				index[k] ++;
			else
				index[k] = 0;
		}
	}
	unread_char(fp);
	return k;
}
