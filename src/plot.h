#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "vector.h"

#define PIXSIZE 32
#define FILL 0
#define CLEAR 1
#define DONT_CLEAR 0

//const char* c31 = "\033[0;31m";

#ifndef PLOT
typedef int* point;
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
	int clear;
	double unit;
	buffer *buf_stack;
	int buf_pointer;
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
	double unit,
	int clear
);

canvas *canvas_empty (
	int sizeX,
	int sizeY,
	int clear
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

void display_i (
	canvas* can
);

int canvas_ctl (
	canvas *can,
	char* input
);

int plot_uni (
	canvas* can,
	int X,
	int Y,
	const char* color,
	char* text
);

void plot_axes (
	canvas *can,
	int originX,
	int originY
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

point point_from_vec (
	vec vector
);

int plot_string (
	canvas *can,
	int X,
	int Y,
	const char* color,
	char* text
);

void plot_vec (
	canvas *can,
	vec vector,
	const char* color
);

void plot_line (
	canvas *can,
	vec A,
	vec B,
	const char* color
);

vec* vecs_from_func (
	double min,
	double max,
	double inc,
	double (*function)(double)
);

void plot_vecs (
	canvas* can,
	vec* vectors,
	const char* color
);

int plot_uni (
	canvas *can,
	int X,
	int Y,
	const char* color,
	char* text
);

void plot_axes (
	canvas *can,
	int originX,
	int originY
);

// End
#define PLOT
