#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

typedef struct _canvas {
	int window_width;
	int window_height;
	int X_min;
	int X_max;
	int Y_min;
	int Y_max;
	char options;
} canvas;

#ifndef PLOT
enum _options {
	AXES = 1,
	LINES = 2,
	LINES_DASHED = 4,
	POINTS = 8,
	FILLING = 16,
};
#endif

void canvas_new (canvas *canvas, int window_width, int window_height, int X_min, int X_max, int Y_min, int Y_max, char options);
char plot_options (char axes, char lines, char lines_dashed, char points, char filling);
//void vec_plot_2d (vec pointsX, vec pointsY, canvas canvas, int *argcp, char **argv);
void vec_plot_2d (vec pointsX, vec pointsY, canvas *canvas, int *argcp, char **argv);

// void vec_plot_points (vec **points, canvas canvas);

#define PLOT 0
