#include "plot.h"

void canvas_new (canvas *canvas, int window_width, int window_height, int X_min, int X_max, int Y_min, int Y_max, char options) {
	canvas -> window_width = window_width;
	canvas -> window_height = window_height;
	canvas -> X_min = X_min;
	canvas -> X_max = X_max;
	canvas -> Y_min = Y_min;
	canvas -> Y_max = Y_max;
	canvas -> options = options;
}

char plot_options (char axes, char lines, char lines_dashed, char points, char filling) {
	char options;
	if (axes) options |= AXES;
	if (lines) options |= LINES;
	if (lines_dashed) options |= LINES_DASHED;
	if (points) options |= POINTS;
	if (filling) options |= FILLING;
	return options;
}

void vec_plot_2d (vec pointsX, vec pointsY, canvas *canvas) {
	putchar ('g');
	printf ("initializing glut...\n");
	//glutInit (&argc, argv);
	printf ("glut initialized.\n");
	GLenum type = 0;
	type |= (GLUT_RGBA | GLUT_DOUBLE);
	printf ("initializing glut...\n");
	glutInitDisplayMode (type);
	printf ("glutInitDisplayMode: [success]\n");
	glutInitWindowSize (canvas -> window_width, canvas -> window_height);
	printf ("glutInitWindowSize: [success]\n");
	glutCreateWindow ("libido plot");
	printf ("glutCreateWindow: [success]\n");
}

// void vec_plot_points (vec **points, canvas canvas);
