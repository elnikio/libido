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
void read_through (FILE *fp, char *through);

enum generate_stage {
	SEEK = 1,
	TITLE,
	STRUCT,
	MACROS,
	FUNCTIONS
};

int main (int argc, char **argv) {
	FILE *fp;

	// header:
	fp = fopen("./DOC.md", "w");
	fputs ("# Libido - \\<libido/\\>\nA C math library.\n\n[Installation](#installation)\n[Documentation](#documentation)\n\n# Installation:\n1. Run install.sh, which copies the files to your include directory.\n2. Compile using ./compile.sh.\n\n# Documentation:\n", fp);
	fclose (fp);

	// vector:
	fp = fopen ("./DOC.md", "a");
	char *vector = "vector.h";
	generate (fp, vector);

	// close file:
	fclose (fp);
}

int i;

void generate (FILE *doc, char *filename) {
	FILE *fp;

	char dir[32];
	char temp[100];
	int stage = TITLE;

	strcpy (dir, "./");
	strcat (dir, filename);
	printf ("Generating documentation for %s\n", dir);
	fp = fopen  (dir, "r");
	char head;
	fseek (fp, 0L, SEEK_END);
	int len = ftell (fp);
	rewind (fp);
	printf ("[\"\n");
	for (i = 0; i < len; i ++, head = fgetc (fp)) {
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
					fputs ("## ", doc);
					fputs (title, doc);
					fputs (" - <libido/vector.h>\n", doc);
					printf ("[\"\n");
					stage = SEEK;
				}
				break;
			case STRUCT:
				printf ("[\"\n");
				read_through (fp, "struct _\0");
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

				fprintf (doc, "| %s |\n", type_desc);
				stage = 0;
				fputs ("| - | - | - |\n", doc);
				break;
			case MACROS:
				break;
			case FUNCTIONS:
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
	//char *macro = malloc (100);
	char macro[100];
	read_till (fp, '\n', macro);
	printf ("STAGE: %s\n", macro);
	if (string_equal (macro, "Types")) {
		char type[9][10];
		strcpy (type[0], "struct");
		strcpy (type[1], "unsigned");
		strcpy (type[2], "signed");
		strcpy (type[3], "char");
		strcpy (type[4], "int");
		strcpy (type[5], "short");
		strcpy (type[6], "long");
		strcpy (type[7], "foat");
		strcpy (type[8], "double");
		return STRUCT;
	}
	else return 0;
}

char read_char (FILE *fp) {
	char read = fgetc (fp);
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
char *read_till_or (FILE *fp, char *till, char count, char *read) {
	// count = number of characters in till (chars to look for).
	//char read[100];
	char c;
	int j = 0;
	do {
		c = read_char (fp);
		read[j ++] = c;
		for (int i = 0; i < count; i ++)
			if (c == till[i]) break;
	} while (1);
	read[j] = '\0';
	return read;
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
int read_through_or (FILE *fp, char **through, char count) {
	int index[16];
	for (int j = 0; ; ) {
		for (int i = 0; i < count; i ++) {
			if (through[i][j] == '\0')
				break;
			if (read_char (fp) == through[i][j])
				index[i] ++;
		}
	}
}
