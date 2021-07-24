#include <stdio.h>
#include <libido/generic.h>
#include <libido/vector.h>
#include <libido/arithmetic.h>
#include <libido/plot.h>
#include <libido/string.h>
#include <GL/glut.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char options = plot_options (TRUE, TRUE, TRUE, TRUE, TRUE);
	printf ("options = %x\n", options);
	canvas can;
	canvas *canp = &can;
	canvas_new (canp, 1920, 1080, -4, 4, -2, 2, options);
	vec val_x = vec_gen (1, 10, 1, NULL);
	vec val_y = vec_gen (2, 20, 2, NULL);
	printf ("window has been created.\n");
	/*
	printf ("argc = %d\n", argc);
	printf ("argv = ");
	string_print (argv [0]);
	printf ("\n");
	*/
	glutInit (&argc, argv);
	vec_print_padded (val_x, 4);
	vec_print_padded (val_y, 4);
	vec_plot_2d (val_x, val_y, canp);
	while (TRUE);
}
