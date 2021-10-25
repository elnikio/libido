#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include <sys/ioctl.h>
#include <pthread.h>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include "vector.h"
#include "colors.h"

#define PIXSIZE 32
#define FILL 0
#define CLEAR 1
#define DONT_CLEAR 0

//const char* c31 = "\033[0;31m";

#ifndef PLOT
typedef int* point;
typedef char*** buffer;
typedef char* pixel;

void wait(double secs);

enum _palettes {
	XTERM,
	GNOME,
	LINUX,
	RXVT,
	SLRZD
};

typedef struct palette {
	char* red90;
	char* red80;
	char* red70;
	char* red60;	
	char* green90;
	char* green80;
	char* green70;
	char* green60;	
	char* yellow90;
	char* yellow80;
	char* yellow70;
	char* yellow60;	
	char* blue90;
	char* blue80;
	char* blue70;
	char* blue60;	
	char* pink90;
	char* pink80;
	char* pink70;
	char* pink60;	
	char* cyan90;
	char* cyan80;
	char* cyan70;
	char* cyan60;	
	char* white90;
	char* white80;
	char* white70;
	char* white60;	
	char* gray90;
	char* gray80;
	char* gray70;
	char* gray60;
} palette;

#define COLORNUM 32

typedef struct _colormap {
	char* color;
	char colorID;
} colormap;

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
	buffer* buf_stack;
	int buf_pointer;
	palette* pal;
	colormap** colordict;
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
	int clear,
	char PALETTE
);

void canvas_delete (
	canvas* can
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
	const char colorID
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
	canvas* can,
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
	char colorID
);

void plot_line (
	canvas *can,
	vec A,
	vec B,
	const char colorID
);

void plot_lineDDA (
	canvas *can,
	point A,
	point B,
	char colorID
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
	const char colorID
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

void plot_palette (canvas* can, int x, int y);

// End
#define PLOT
