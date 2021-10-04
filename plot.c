// camera = (width, height, distance)
#include "plot.h"

/*
todo:
 - add overlap parameter to all plotting functions:
    - overlap = FRONT to overwrite buffer
	- overlap = BACK to write below buffer, i.e. do not overwrite
*/

#define PIXSIZE 32
#define FILL 0

typedef int* point;
	
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
const char* cran = "R";

char* rand_c () {
	int num = rand() % 6 + 1;
	char *c = NULL;

	switch (num) {
		case 1:
			c = "\033[0;31m";
			break;
		case 2:
			c = "\033[0;32m";
			break;
		case 3:
			c = "\033[0;33m";
			break;
		case 4:
			c = "\033[0;34m";
			break;
		case 5:
			c = "\033[0;35m";
			break;
		case 6:
			c = "\033[0;36m";
			break;
	}

	return c;
}

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

canvas *canvas_new(int sizeX, int sizeY, double unit) {
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
				row[X] = "\033[0;31m╚\033[0;0m";
			else if (X==sizeX-1&&Y==sizeY-1)
				row[X] = "\033[0;31m╗\033[0;0m";
			else if (X==0&&Y==sizeY-1)
				row[X] = "\033[0;31m╔\033[0;0m";
			else if (X==sizeX-1&&Y==0)
				row[X] = "\033[0;31m╝\033[0;0m";
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
	can -> unit = unit;
	return can;
}

canvas *canvas_empty(int sizeX, int sizeY) {
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

buffer buffer_new(int sizeX, int sizeY) {
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
				row[X] = "\033[0;31m╚\033[0;0m";
			else if (X==sizeX-1&&Y==sizeY-1)
				row[X] = "\033[0;31m╗\033[0;0m";
			else if (X==0&&Y==sizeY-1)
				row[X] = "\033[0;31m╔\033[0;0m";
			else if (X==sizeX-1&&Y==0)
				row[X] = "\033[0;31m╝\033[0;0m";
			else if (X==0||X==sizeX-1)
				row[X] = "\033[0;31m║\033[0;0m";
			else if (Y==0||Y==sizeY-1)
				row[X] = "\033[0;31m═\033[0;0m";

		}

		buf[Y] = row;
	}
	return buf;
}

void canvas_merge(canvas* can0, canvas* can1) {
	char* glass = "\033[0;30m█\033[0;0m";
	if (can0->sizeX < can1->sizeX || can0->sizeY < can1->sizeY) {
		printf("error: attempting to merge two canvas of differing sizes. second argument to canvas_merge() must be the smaller of the two canvases.");
	}

	for (int Y = 0; Y < can1 -> sizeY; Y ++) {
		for (int X = 0; X < can1 -> sizeX; X ++) {
			if (strcmp(can1->buf[Y][X], glass))
				can0->buf[Y][X] = can1->buf[Y][X];
		}
	}

}

void canvas_flip_vertical(canvas *can) {
	buffer bufNew = malloc(can->sizeY * sizeof(pixel*));

	for (int Y = 0; Y < can -> sizeY; Y ++) {
		pixel* row = malloc(PIXSIZE * can -> sizeX);
		for (int X = 0; X < can -> sizeX; X ++) {
			row[X] = can->buf[can->sizeY -1 - Y][X];
		}

		bufNew[Y] = row;
	}
	can->buf = bufNew;
}

void display(canvas* can) {
	fflush(stdout);
	//system("clear");
	
	for (int Y = can -> sizeY - 1; Y >= 0; Y --) {
		for (int X = 0; X < can -> sizeX; X ++)
			printf("%s", can -> buf[Y][X]);
		printf("\033[0;0m\n");
	}
}

int plot_point(canvas *can, int X, int Y, const char* color) {
	if (color[0] == 'R')
		color = rand_c ();
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

int plot_image(canvas* can, int X, int Y, char* img_path) {

	buffer img_buf = buffer_new(FILL, FILL);

	FILE *img = NULL;
	if ((img = fopen(img_path, "r")) == NULL) {
		fprintf(stderr, "error opening %s\n", img_path);
		return 1;
	}

	int posX = X;
	int posY = Y;
	char c;

	while((c = fgetc(img)) != EOF) {
		switch (c) {

			// black
			case 'o':
				plot_point(can, posX, posY, c31);
				break;

			// dark
			case 'd':
				plot_point(can, posX, posY, c30);
				break;
			case 'D':
				plot_point(can, posX, posY, c90);
				break;

			// red
			case 'r':
				plot_point(can, posX, posY, c31);
				break;
			case 'R':
				plot_point(can, posX, posY, c91);
				break;

			// green
			case 'g':
				plot_point(can, posX, posY, c32);
				break;
			case 'G':
				plot_point(can, posX, posY, c92);
				break;

			// yellow
			case 'y':
				plot_point(can, posX, posY, c33);
				break;
			case 'Y':
				plot_point(can, posX, posY, c93);
				break;

			// blue
			case 'b':
				plot_point(can, posX, posY, c34);
				break;
			case 'B':
				plot_point(can, posX, posY, c94);
				break;

			// purple
			case 'p':
				plot_point(can, posX, posY, c35);
				break;
			case 'P':
				plot_point(can, posX, posY, c95);
				break;

			// cyan
			case 'c':
				plot_point(can, posX, posY, c36);
				break;
			case 'C':
				plot_point(can, posX, posY, c96);
				break;

			// white
			case 'w':
				plot_point(can, posX, posY, c37);
				break;
			case 'W':
				plot_point(can, posX, posY, c97);
				break;

		}

		if (c == '\n') {
			posX = X;
			posY ++;
		}
		else
			posX ++;
	}
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

int plot_string(canvas *can, int X, int Y, const char* color, char* text) {
	for (int i = 0; text[i] != '\0'; i ++)
		plot_char(can, X + i, Y, color, text[i]);
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
		if (X % 8 == 0 && X != 0) {
			if (originY >= (int)(can -> sizeY / 2)) {
				plot_uni(can, X, 0, c96, "┯");
				char val[8];
			   	sprintf(val, "%f", X/8 * can->unit);
				val[6] = '\0';
				plot_string(can, X, -1, c96, val);

			}
			if (originY < (int)(can -> sizeY / 2)) {
				plot_uni(can, X, 0, c96, "┷");
				char val[8];
			   	sprintf(val, "%f", X/8 * can->unit);
				val[6] = '\0';
				plot_string(can, X, 1, c96, val);
			}
		}
	}
	for (int Y = can->minY; Y <= can->maxY; Y ++) {
		plot_uni(can, 0, Y, c96, "┃");
		if (Y % 4 == 0 && Y != 0) {
			if (originX < (int)(can -> sizeX / 2)) {
				plot_uni(can, 0, Y, c96, "┠");
				char val[8];
			   	sprintf(val, "%f", Y/4 * can->unit);
				val[6] = '\0';
				plot_string(can, 2, Y, c96, val);
			}
			if (originX >= (int)(can -> sizeX / 2)) {
				plot_uni(can, 0, Y, c96, "┨");
				char val[8];
			   	sprintf(val, "%f", Y/4 * can->unit);
				val[6] = '\0';
				plot_string(can, -7, Y, c96, val);
			}
		}
	}
	plot_uni(can, 0, 0, c96, "╋");

}
/*
 2.5 to  3.5 =  3
 1.5 to  2.5 =  2
 0.5 to  1.5 =  1
-0.5 to -0.5 =  0
-0.5 to -1.5 = -1
-1.5 to -2.5 = -2
-2.5 to -3.5 = -3
*/
point point_from_vec (vec vector) {
	point p = malloc(sizeof(int) * 2);

	if (vector.size < 2) {
		printf ("error: point_from_vec received a vector of dimension lower than 2.\n");
		return 0;
	}

	if (vector.val[0] >= 0) {
		double frac = vector.val[0] - (int)vector.val[0];
		vector.val[0] = (int)vector.val[0];
		if (frac >= 0.5)
			vector.val[0] += 1;
	}

	if (vector.val[1] < 0) {
		double frac = vector.val[1] - (int)vector.val[1];
		vector.val[1] = (int)vector.val[1];
		if (frac < -0.5)
			vector.val[1] -= 1;
	}

	p[0] = vector.val[0];
	p[1] = vector.val[1];

	return p;
}



void plot_vec (canvas *can, vec vector, const char* color) {
	vector.val[0] *= 8 / can -> unit;
	vector.val[1] *= 4 / can -> unit;
	point p = point_from_vec (vector);
	plot_point(can, p[0], p[1], color);
	free (p);
}

vec* vecs_from_func (double min, double max, double inc, double (*function)(double)) {
	int count = (max - min) / inc;
	vec *vectors = malloc(sizeof (vec) * count + 1);

	int j = 0;
	for (double i = min; i <= max; i += inc, j ++) {
		double *vector = malloc(sizeof(double)*2);
		vector[0] = i;
		vector[1] = function(i);
		vectors[j].val = vector;
		vectors[j].size = 2;
	}
	vectors[j].val = NULL;
	return vectors;
}
void plot_vecs (canvas *can, vec* vectors, const char* color) {
	for (int i = 0; vectors[i].val != NULL; i ++)
		plot_vec (can, vectors[i], color);
}

double squared (double x) {
	return x * x;
}

int main () {
	canvas* can = canvas_new(FILL, 32, 1.0);
	
	char *text = "C math lib w/ rad console plots\0";
	for (int i = 0; text[i] != '\0'; i ++)
		plot_char(can, 18 + i, 5, c31, text[i]);
	
	can->unit = 0.5;
	plot_axis(can, can->sizeX/2, can->sizeY/4);

	canvas* can_logo = canvas_empty(FILL, 32);
	plot_image(can_logo, 32, 6, "text.txt");
	canvas_flip_vertical(can_logo);

	vec vector;
	double v[2] = {2.3, 4.7};
	vector.val = v;
	vector.size = 2;
	canvas_merge(can, can_logo);
	
	vec *square_points = vecs_from_func (-6, 6, 0.05, squared);
	plot_vecs (can, square_points, c92);
	
	vec *sin_points = vecs_from_func (-6, 6, 0.05, sin);
	plot_vecs (can, sin_points, c91);

	vec *log_points = vecs_from_func (-6, 6, 0.05, log);
	plot_vecs (can, log_points, c93);
	
	vec *sqrt_points = vecs_from_func (-6, 6, 0.05, sqrt);
	plot_vecs (can, sqrt_points, c94);

	display(can);
}
