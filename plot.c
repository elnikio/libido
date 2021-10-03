// camera = (width, height, distance)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define PIXSIZE 32
#define FILL 0

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
} canvas;

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
			row[X] = malloc(16);
			row[X] = "\033[0;30m█\033[0;0m";
			if (X==0||Y==0||X==sizeX-1||Y==sizeY-1)
				row[X] = "\033[0;31m█\033[0;0m";
		}

		buf[Y] = row;
	}
	canvas *can = malloc(sizeof (canvas));
	can -> buf = buf;
	can -> sizeX = sizeX;
	can -> sizeY = sizeY;
	can -> minX = 1;
	can -> minY = 1;
	can -> maxX = sizeX - 2;
	can -> maxY = sizeY - 2;
	return can;
}

void display(canvas* can) {
	fflush(stdout);
	system("clear");
	for (int Y = 0; Y < can -> sizeY; Y ++) {
		for (int X = 0; X < can -> sizeX; X ++)
			printf("%s", can -> buf[Y][X]);
		printf("\033[0;0m\n");
	}
}

int plot_point(canvas *can, int X, int Y) {
	if (
		X < can -> minX ||
		X > can -> maxX ||
		Y < can -> minY ||
		Y > can -> maxY
	) return 1;

	strcpy(can -> buf[X][Y], "\033[0;31m█\033[0;0m");

	return 0;
}

int main () {
	canvas* can = new_canvas(FILL, FILL);
	//plot_point(can, 3, 4);
	display(can);
}
