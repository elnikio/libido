#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "vector.h"

#ifndef PLOT
typedef char*** buffer;
typedef char* pixel;
typedef struct _canvas {
	buffer buf;
	int sizeX;
	int sizeY;
	int minX;
	int minY;
	int maxX;
	int maxY;
	int originX;
	int originY;
	double unit;
} canvas;
#endif

int point_visible (
	canvas* can,
	int X,
	int Y
);

struct winsize window_size (
);

canvas *canvas_new (
	int sizeX,
	int sizeY,
	double unit
);

canvas *canvas_empty (
	int sizeX,
	int sizeY
);

buffer buffer_new (
	int sizeX,
	int sizeY
);

void canvas_merge (
	canvas* can0,
	canvas* can1
);

void canvas_flip_vertical (
	canvas *can
);

void display (
	canvas* can
);

int plot_point (
	canvas *can,
	int X,
	int Y,
	const char* color
);

int plot_image (
	canvas* can,
	int X,
	int Y,
	char* img_path
);

int plot_char (
	canvas *can,
	int X,
	int Y,
	const char* color,
	char text
);

int plot_string (
	canvas *can,
	int X,
	int Y,
	const char* color,
	char* text
);

int plot_uni (
	canvas *can,
	int X,
	int Y,
	const char* color,
	char* text
);

int plot_axis (
	canvas *can,
	int originX,
	int originY
);

// End
#define PLOT
