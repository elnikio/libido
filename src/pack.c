//#include "pack.h"
#include "string.h"
#include <math.h>

typedef struct _pack {
	char *type;

	char width;
	int height;
	int size;

	char *char_pack;
	short *short_pack;
	int *int_pack;
	long *long_pack;
} pack;

pack *packer (char *intype, char *outtype, char width, int count, void *input);

int main (){
	printf ("dick\n");
	char words[] = "michelangelo was a furry.";
	pack *pack_0 = packer ("char", "long", 5, 13, &words);
	printf ("pack_0 type = %s\n", pack_0 -> type);
	printf ("pack_0 size in bytes = %d\n", pack_0 -> size);
}
// only works for long input & long output
pack *packer (char *intype, char *outtype, char width, int height, void *input) {
	pack *output = malloc (sizeof (struct _pack));
	int pos_w, pos_h;

	pos_w = 0;
	pos_h = 0;

	if (string_equal (outtype, "long")) {
		output -> long_pack = malloc (
			height / ((sizeof (long) * 8) / width)
		);
		long mask = ~(-1 << width);
		// output -> long_pack = malloc ((count * width) / 8 + sizeof (long)));
		for (int i = 0; i < height; i ++) {
			if (pos_w + width > sizeof (long) * 8) {
				pos_h ++;
				pos_w = 0;
			}
			if (string_equal (intype, "char"))
				output -> long_pack [pos_h] += (((char*) input) [i] & mask) << pos_w;
			pos_w += width;
		}
		output -> width = width;
		output -> height = height;
		output -> type = outtype;
		output -> size = (pos_h + 1) * sizeof (long);
	}
	return output;
}
/*
T [a..d]
packed T [b..c]
a <= b <= c <= d
d-a >= c-b














*/
