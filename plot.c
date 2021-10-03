// camera = (width, height, distance)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define PIXSIZE 32
#define FILL 0
	
char* c0 = "\033[0;0m";
const char* c2 = "\033[0;2m";
const char* c4 = "\033[0;4m";
const char* c7 = "\033[0;7m";
const char* c8 = "\033[0;8m";
const char* c9 = "\033[0;9m";
const char* c30 = "\033[0;30m";
const char* c31 = "\033[0;31m";
const char* c32 = "\033[0;32m";
const char* c33 = "\033[0;33m";
const char* c34 = "\033[0;34m";
const char* c35 = "\033[0;35m";
const char* c36 = "\033[0;36m";
const char* c37 = "\033[0;37m";
const char* c40 = "\033[0;40m";
const char* c41 = "\033[0;41m";
const char* c42 = "\033[0;42m";
const char* c43 = "\033[0;43m";
const char* c44 = "\033[0;44m";
const char* c45 = "\033[0;45m";
const char* c46 = "\033[0;46m";
const char* c47 = "\033[0;47m";
const char* c90 = "\033[0;90m";
const char* c91 = "\033[0;91m";
const char* c92 = "\033[0;92m";
const char* c93 = "\033[0;93m";
const char* c94 = "\033[0;94m";
const char* c95 = "\033[0;95m";
const char* c96 = "\033[0;96m";
const char* c97 = "\033[0;97m";
const char* c100 = "\033[0;100m";
const char* c101 = "\033[0;101m";
const char* c102 = "\033[0;102m";
const char* c103 = "\033[0;103m";
const char* c104 = "\033[0;104m";
const char* c105 = "\033[0;105m";
const char* c106 = "\033[0;106m";
const char* c107 = "\033[0;107m";
const char* c109 = "\033[0;109m";

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

int point_visible(canvas* can, int X, int Y) {
	if (
		X >= can->minX &&
		X <= can->maxX &&
		Y >= can->minY &&
		Y <= can->maxY
	) return 1;
	else
		return 0;
}

struct winsize window_size() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w;
}

canvas *new_canvas(int sizeX, int sizeY) {
	struct winsize ws = window_size();
	if (sizeX == FILL) {
		sizeX = ws.ws_col;
	}
	if (sizeY == FILL) {
		sizeY = ws.ws_row - 1;
	}

	buffer buf = malloc(sizeY * sizeof(pixel*));

	for (int Y = 0; Y < sizeY; Y ++) {

		pixel* row = malloc(sizeof(pixel) * sizeX);
		for (int X = 0; X < sizeX; X ++) {
			row[X] = malloc(PIXSIZE);
			row[X] = "\033[0;30m█\033[0;0m";

			if (X==0&&Y==0)
				row[X] = "\033[0;31m╔\033[0;0m";
			else if (X==sizeX-1&&Y==sizeY-1)
				row[X] = "\033[0;31m╝\033[0;0m";
			else if (X==0&&Y==sizeY-1)
				row[X] = "\033[0;31m╚\033[0;0m";
			else if (X==sizeX-1&&Y==0)
				row[X] = "\033[0;31m╗\033[0;0m";
			else if (X==0||X==sizeX-1)
				row[X] = "\033[0;31m║\033[0;0m";
			else if (Y==0||Y==sizeY-1)
				row[X] = "\033[0;31m═\033[0;0m";

		}

		buf[Y] = row;
	}
	canvas *can = malloc(sizeof (canvas));
	can -> buf = buf;
	can -> sizeX = sizeX;
	can -> sizeY = sizeY;
	can -> minX = 0;
	can -> minY = 0;
	can -> maxX = sizeX - 1;
	can -> maxY = sizeY - 1;
	can -> originX = 0;
	can -> originY = 0;
	can -> unit = 1.0;
	return can;
}

void display(canvas* can) {
	fflush(stdout);
	system("clear");

	/*
	for (int Y = 0; Y < can -> sizeY; Y ++) {
		for (int X = 0; X < can -> sizeX; X ++)
			printf("%s", can -> buf[Y][X]);
		printf("\033[0;0m\n");
	}
	*/
}

int plot_point(canvas *can, int X, int Y, const char* color) {
	if (
		X <= can -> minX ||
		X >= can -> maxX ||
		Y <= can -> minY ||
		Y >= can -> maxY
	) return 1;

	if (point_visible(can, X, Y)) {
		can -> buf[Y+can->originY][X+can->originX] = malloc(PIXSIZE);
		sprintf(can -> buf[Y+can->originY][X+can->originX], "%s█%s", color, c0);
	}

	return 0;
}

int plot_char(canvas *can, int X, int Y, const char* color, char text) {
	if (
		X <= can -> minX ||
		X >= can -> maxX ||
		Y <= can -> minY ||
		Y >= can -> maxY
	) return 1;

	if (point_visible(can, X, Y)) {
		can -> buf[Y+can->originY][X+can->originX] = malloc(PIXSIZE);
		sprintf(can -> buf[Y+can->originY][X+can->originX], "%s%c%s", color, text, c0);
	}

	return 0;
}

int plot_uni(canvas *can, int X, int Y, const char* color, char* text) {
	if (
		X <= can -> minX ||
		X >= can -> maxX ||
		Y <= can -> minY ||
		Y >= can -> maxY
	) return 1;

	if (point_visible(can, X, Y)) {
		can -> buf[Y+can->originY][X+can->originX] = malloc(PIXSIZE);
		sprintf(can -> buf[Y+can->originY][X+can->originX], "%s%s%s", color, text, c0);
	}

	return 0;
}

int plot_axis(canvas *can, int originX, int originY) {

	can -> originX = originX;
	can -> originY = originY;

	can -> maxX = can -> maxX - originX;
	can -> minX = can -> minX - originX;
	can -> maxY = can -> maxY - originY;
	can -> minY = can -> minY - originY;

	for (int X = can->minX; X <= can->maxX; X ++) {
		plot_uni(can, X, 0, c96, "━");
		if (X % 8 == 0) {
			if (originY >= (int)(can -> sizeY / 2)) {
				plot_uni(can, X, 0, c96, "┯");
				plot_uni(can, X, 1, c96, "1");
			}
			if (originY < (int)(can -> sizeY / 2))
				plot_uni(can, X, 0, c96, "┷");
		}
	}
	for (int Y = can->minY; Y <= can->maxY; Y ++) {
		plot_uni(can, 0, Y, c96, "┃");
		if (Y % 4 == 0) {
			if (originX < (int)(can -> sizeX / 2))
				plot_uni(can, 0, Y, c96, "┠");
			if (originX >= (int)(can -> sizeX / 2))
				plot_uni(can, 0, Y, c96, "┨");
		}
	}
	plot_uni(can, 0, 0, c96, "╋");

}

int main () {
	canvas* can = new_canvas(FILL, FILL);
	
	plot_point(can, 4, 12, c30);
	plot_point(can, 6, 12, c31);
	plot_point(can, 8, 12, c32);
	plot_point(can, 10, 12, c33);
	plot_point(can, 12, 12, c34);
	plot_point(can, 14, 12, c35);
	plot_point(can, 16, 12, c36);
	plot_point(can, 18, 12, c37);	
	
	plot_point(can, 4, 14, c90);
	plot_point(can, 6, 14, c91);
	plot_point(can, 8, 14, c92);
	plot_point(can, 10, 14, c93);
	plot_point(can, 12, 14, c94);
	plot_point(can, 14, 14, c95);
	plot_point(can, 16, 14, c96);
	plot_point(can, 18, 14, c97);

	char *text = "next gen graphics by libido/plot HEWL YEAH!\0";
	for (int i = 0; text[i] != '\0'; i ++)
		plot_char(can, 4 + i, 10, c0, text[i]);

	plot_char(can, 4, 16, c33, 'k');
	plot_axis(can, 2, 2);
	plot_uni(can, 2, 2, c33, "∫");

	display(can);
}
