// camera = (width, height, distance)
#include "plot.h"

static const char* c1 = "\033[0;1m";
static const char* c2 = "\033[0;2m";
static const char* c3 = "\033[0;3m";
static const char* c4 = "\033[0;4m";
static const char* c7 = "\033[0;7m";
static const char* c8 = "\033[0;8m";
static const char* c9 = "\033[0;9m";
static const char* c30 = "\033[0;30m";
static const char* c31 = "\033[0;31m";
static const char* c32 = "\033[0;32m";
static const char* c33 = "\033[0;33m";
static const char* c34 = "\033[0;34m";
static const char* c35 = "\033[0;35m";
static const char* c36 = "\033[0;36m";
static const char* c37 = "\033[0;37m";
static const char* c40 = "\033[0;40m";
static const char* c41 = "\033[0;41m";
static const char* c42 = "\033[0;42m";
static const char* c43 = "\033[0;43m";
static const char* c44 = "\033[0;44m";
static const char* c45 = "\033[0;45m";
static const char* c46 = "\033[0;46m";
static const char* c47 = "\033[0;47m";
static const char* c90 = "\033[0;90m";
static const char* c91 = "\033[0;91m";
static const char* c92 = "\033[0;92m";
static const char* c93 = "\033[0;93m";
static const char* c94 = "\033[0;94m";
static const char* c95 = "\033[0;95m";
static const char* c96 = "\033[0;96m";
static const char* c97 = "\033[0;97m";
static const char* c100 = "\033[0;100m";
static const char* c101 = "\033[0;101m";
static const char* c102 = "\033[0;102m";
static const char* c103 = "\033[0;103m";
static const char* c104 = "\033[0;104m";
static const char* c105 = "\033[0;105m";
static const char* c106 = "\033[0;106m";
static const char* c107 = "\033[0;107m";
static const char* c109 = "\033[0;109m";
static const char* cran = "R";

typedef struct _size {
	int X;
	int Y;
} size;

size screen_size () {
	struct winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	ws = window_size();

	size scr_sz;
	scr_sz.X = ws.ws_col;
	scr_sz.Y = ws.ws_row;
	return scr_sz;
}

/*
todo:
 - add overlap parameter to all plotting functions:
    - overlap = FRONT to overwrite buffer
	- overlap = BACK to write below buffer, i.e. do not overwrite
	- do it with an optional parameter, implemented using #define macros
*/

int running = 1;
static const char* cCLEAR = "\033[0;0m";
static const char* cAXES = "\033[0;96m";

char rand_c () {
	int num = rand() % 8 + 1;
	char c = 0;

	switch (num) {
		case 1:
			c = RED;
			break;
		case 2:
			c = GREEN;
			break;
		case 3:
			c = YELLOW;
			break;
		case 4:
			c = BLUE;
			break;
		case 5:
			c = PINK;
			break;
		case 6:
			c = CYAN;
			break;
		case 7:
			c = WHITE;
			break;
		case 8:
			c = GRAY;
			break;
	}

	return c;
}

char shade_from_colorID (char colorID) {
	if (
		colorID == RED90 ||
		colorID == GREEN90 ||
		colorID == YELLOW90 ||
		colorID == BLUE90 ||
		colorID == PINK90 ||
		colorID == CYAN90 ||
		colorID == WHITE90 ||
		colorID == GRAY90
	) return L90;	
	if (
		colorID == RED80 ||
		colorID == GREEN80 ||
		colorID == YELLOW80 ||
		colorID == BLUE80 ||
		colorID == PINK80 ||
		colorID == CYAN80 ||
		colorID == WHITE80 ||
		colorID == GRAY80
	) return L80;	
	if (
		colorID == RED70 ||
		colorID == GREEN70 ||
		colorID == YELLOW70 ||
		colorID == BLUE70 ||
		colorID == PINK70 ||
		colorID == CYAN70 ||
		colorID == WHITE70 ||
		colorID == GRAY70
	) return L70;	
	if (
		colorID == RED60 ||
		colorID == GREEN60 ||
		colorID == YELLOW60 ||
		colorID == BLUE60 ||
		colorID == PINK60 ||
		colorID == CYAN60 ||
		colorID == WHITE60 ||
		colorID == GRAY60
	) return L60;
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

char get_colorID(canvas* can, char* color) {
	char colorTemp[16];
	strcpy (colorTemp, color);

	int i = 0;
	for (i; color[i] != 'm'; i ++);
	colorTemp[i + 1] = '\0';

	if (!strcmp(colorTemp, can->pal->red90))
		return RED90;
	if (!strcmp(colorTemp, can->pal->red80))
		return RED80;
	if (!strcmp(colorTemp, can->pal->red70))
		return RED70;
	if (!strcmp(colorTemp, can->pal->red60))
		return RED60;
	if (!strcmp(colorTemp, can->pal->green90))
		return GREEN90;
	if (!strcmp(colorTemp, can->pal->green80))
		return GREEN80;
	if (!strcmp(colorTemp, can->pal->green70))
		return GREEN70;
	if (!strcmp(colorTemp, can->pal->green60))
		return GREEN60;
	if (!strcmp(colorTemp, can->pal->yellow90))
		return YELLOW90;
	if (!strcmp(colorTemp, can->pal->yellow80))
		return YELLOW80;
	if (!strcmp(colorTemp, can->pal->yellow70))
		return YELLOW70;
	if (!strcmp(colorTemp, can->pal->yellow60))
		return YELLOW60;
	if (!strcmp(colorTemp, can->pal->blue90))
		return BLUE90;
	if (!strcmp(colorTemp, can->pal->blue80))
		return BLUE80;
	if (!strcmp(colorTemp, can->pal->blue70))
		return BLUE70;
	if (!strcmp(colorTemp, can->pal->blue60))
		return BLUE60;
	if (!strcmp(colorTemp, can->pal->pink90))
		return PINK90;
	if (!strcmp(colorTemp, can->pal->pink80))
		return PINK80;
	if (!strcmp(colorTemp, can->pal->pink70))
		return PINK70;
	if (!strcmp(colorTemp, can->pal->pink60))
		return PINK60;
	if (!strcmp(colorTemp, can->pal->cyan90))
		return CYAN90;
	if (!strcmp(colorTemp, can->pal->cyan80))
		return CYAN80;
	if (!strcmp(colorTemp, can->pal->cyan70))
		return CYAN70;
	if (!strcmp(colorTemp, can->pal->cyan60))
		return CYAN60;
	if (!strcmp(colorTemp, can->pal->white90))
		return WHITE90;
	if (!strcmp(colorTemp, can->pal->white80))
		return WHITE80;
	if (!strcmp(colorTemp, can->pal->white70))
		return WHITE70;
	if (!strcmp(colorTemp, can->pal->white60))
		return WHITE60;
	if (!strcmp(colorTemp, can->pal->gray90))
		return GRAY90;
	if (!strcmp(colorTemp, can->pal->gray80))
		return GRAY80;
	if (!strcmp(colorTemp, can->pal->gray70))
		return GRAY70;
	if (!strcmp(colorTemp, can->pal->gray60))
		return GRAY60;
	else
		return CYAN90;
}

char* parse_colorID(canvas* can, char colorID) {
	switch (colorID) {
		case RED90: return can->pal->red90;
		case RED80: return can->pal->red80;
		case RED70: return can->pal->red70;
		case RED60: return can->pal->red60;
		case GREEN90: return can->pal->green90;
		case GREEN80: return can->pal->green80;
		case GREEN70: return can->pal->green70;
		case GREEN60: return can->pal->green60;
		case YELLOW90: return can->pal->yellow90;
		case YELLOW80: return can->pal->yellow80;
		case YELLOW70: return can->pal->yellow70;
		case YELLOW60: return can->pal->yellow60;
		case BLUE90: return can->pal->blue90;
		case BLUE80: return can->pal->blue80;
		case BLUE70: return can->pal->blue70;
		case BLUE60: return can->pal->blue60;
		case PINK90: return can->pal->pink90;
		case PINK80: return can->pal->pink80;
		case PINK70: return can->pal->pink70;
		case PINK60: return can->pal->pink60;
		case CYAN90: return can->pal->cyan90;
		case CYAN80: return can->pal->cyan80;
		case CYAN70: return can->pal->cyan70;
		case CYAN60: return can->pal->cyan60;
		case WHITE90: return can->pal->white90;
		case WHITE80: return can->pal->white80;
		case WHITE70: return can->pal->white70;
		case WHITE60: return can->pal->white60;
		case GRAY90: return can->pal->gray90;
		case GRAY80: return can->pal->gray80;
		case GRAY70: return can->pal->gray70;
		case GRAY60: return can->pal->gray60;
		default: return can->pal->white90;
	}
}

void swap_strings (char* str1, char* str2) {
	char temp[10];
	strcpy (temp, str1);
	strcpy (str1, str2);
	strcpy (str2, temp);
}

buffer buf_copy(buffer buf, int sizeX, int sizeY) {
	buffer bufNew = malloc(sizeY * sizeof(pixel*));

	for (int Y = 0; Y < sizeY; Y ++) {

		pixel* row = malloc(sizeof(pixel) * sizeX);
		for (int X = 0; X < sizeX; X ++) {
			row[X] = malloc(PIXSIZE);
			strcpy(row[X], buf[Y][X]);
		}
		bufNew[Y] = row;
	}
}

canvas *canvas_new(int sizeX, int sizeY, double unit, int clear, char PALETTE) {

	struct winsize ws = window_size();
	if (sizeX == FILL) {
		sizeX = ws.ws_col;
	}
	if (sizeY == FILL) {
		sizeY = ws.ws_row - 2;
	}

	buffer buf = malloc(sizeY * sizeof(pixel*));

	for (int Y = 0; Y < sizeY; Y ++) {

		pixel* row = malloc(sizeof(pixel) * sizeX);
		for (int X = 0; X < sizeX; X ++) {
			row[X] = malloc(PIXSIZE);
			strcpy(row[X], "\033[0;96m \033[0;0m");

			if (X==0&&Y==0)
				strcpy(row[X], "\033[0;31m╚\033[0;0m");
			else if (X==sizeX-1&&Y==sizeY-1)
				strcpy(row[X], "\033[0;31m╗\033[0;0m");
			else if (X==0&&Y==sizeY-1)
				strcpy(row[X], "\033[0;31m╔\033[0;0m");
			else if (X==sizeX-1&&Y==0)
				strcpy(row[X], "\033[0;31m╝\033[0;0m");
			else if (X==0||X==sizeX-1)
				strcpy(row[X], "\033[0;31m║\033[0;0m");
			else if (Y==0||Y==sizeY-1)
				strcpy(row[X], "\033[0;31m═\033[0;0m");

		}

		buf[Y] = row;
	}

	if (PALETTE < XTERM || PALETTE > SLRZD) {
		printf ("error: incorrect palette name fed to canvas constructor. returning NULL.\n");
		return NULL;
	}

	palette *pal = malloc(sizeof(palette));

	pal -> gray60 = "\033[2;49;30m";
	pal -> gray70 = "\033[4;49;30m";
	pal -> gray80 = "\033[2;49;90m";
	pal -> gray90 = "\033[4;49;90m";
	pal -> red60 = "\033[2;49;31m";
	pal -> red70 = "\033[2;49;91m";
	pal -> red80 = "\033[4;49;31m";
	pal -> red90 = "\033[4;49;91m";
	pal -> green90 =  "\033[2;49;32m";
	pal -> green80 = "\033[2;49;92m";
	pal -> green70 = "\033[4;49;32m";
	pal -> green60 = "\033[4;49;92m";
	pal -> yellow90 = "\033[2;49;33m";
	pal -> yellow80 = "\033[2;49;93m";
	pal -> yellow70 = "\033[4;49;33m";
	pal -> yellow60 = "\033[4;49;93m";
	pal -> blue90 = "\033[2;49;34m";
	pal -> blue80 = "\033[4;49;34m";
	pal -> blue70 = "\033[2;49;94m";
	pal -> blue60 = "\033[4;49;94m";
	pal -> pink90 = "\033[2;49;35m";
	pal -> pink80 = "\033[2;49;95m";
	pal -> pink70 = "\033[4;49;35m";
	pal -> pink60 = "\033[4;49;95m";
	pal -> cyan90 = "\033[2;49;36m";
	pal -> cyan80 = "\033[2;49;96m";
	pal -> cyan70 = "\033[4;49;36m";
	pal -> cyan60 = "\033[4;49;96m";
	pal -> white90 = "\033[2;49;37m";
	pal -> white80 = "\033[2;49;97m";
	pal -> white70 = "\033[4;49;37m";
	pal -> white60 = "\033[4;49;97m";

	switch (PALETTE) {

		case XTERM:
			break;

		case GNOME:
			swap_strings (pal -> red70, pal -> red80);
			break;

		case LINUX:
			swap_strings (pal -> pink70, pal -> pink80);
			swap_strings (pal -> yellow70, pal -> yellow80);
			swap_strings (pal -> green70, pal -> green80);
			swap_strings (pal -> red70, pal -> red80);
			break;

		case RXVT:
			swap_strings (pal -> blue70, pal -> red80);
			break;

		case SLRZD:
			strcpy (pal -> cyan70, pal -> cyan60);
			strcpy (pal -> cyan90, pal -> cyan80);
			strcpy (pal -> pink70, pal -> pink60);
			strcpy (pal -> pink90, pal -> pink80);
			strcpy (pal -> blue70, pal -> blue60);
			strcpy (pal -> blue90, pal -> blue80);
			strcpy (pal -> yellow70, pal -> yellow60);
			strcpy (pal -> yellow90, pal -> yellow80);
			strcpy (pal -> green70, pal -> green60);
			strcpy (pal -> green90, pal -> green80);
			strcpy (pal -> red70, pal -> red60);
			strcpy (pal -> red90, pal -> red80);
			swap_strings (pal -> gray60, pal -> gray80);
			swap_strings (pal -> gray70, pal -> gray90);
			break;
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
	can -> clear = clear;
	can -> buf_stack = NULL;
	can -> buf_pointer = 0;
	can -> pal = pal;
	return can;
}

void buffer_delete (buffer buf, int sizeX, int sizeY) {

	for (int Y = 0; Y < sizeY; Y ++) {
		for (int X = 0; X < sizeX; X ++) {
			free (buf[Y][X]);
		}
		free (buf[Y]);
	}
	free (buf);
}

void canvas_delete (canvas* can) {

	for (int Y = 0; Y < can -> sizeY; Y ++) {
		for (int X = 0; X < can -> sizeX; X ++) {
			free (can -> buf[Y][X]);
		}
		free (can -> buf[Y]);
	}
	free (can -> buf);
	free (can -> pal);
	free (can);

	for (int i = 0; i < can -> buf_pointer; i ++)
		buffer_delete (can->buf_stack[-- (can->buf_pointer)], can->sizeX, can->sizeY);
}

canvas *canvas_empty(int sizeX, int sizeY, int clear) {
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
	can -> clear = clear;
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
	//fflush(stdout);
	if (can->clear == 1)
		system("clear");
	
	for (int Y = can -> sizeY - 1; Y >= 0; Y --) {
		for (int X = 0; X < can -> sizeX; X ++)
			printf("%s", can -> buf[Y][X]);
		printf("\033[0;0m\n");
	}
}

char* get_point_color (canvas *can, int X, int Y) {

	if (
		X <= can -> minX ||
		X >= can -> maxX ||
		Y <= can -> minY ||
		Y >= can -> maxY
	) return NULL;
	return can -> buf[Y+can->originY][X+can->originX];
}

int plot_point (canvas *can, int X, int Y, char colorID) {
	if (colorID == RAND) {
		colorID = rand_c ();
	}

	char* color = parse_colorID (can, colorID);

	if (
		X <= can -> minX ||
		X >= can -> maxX ||
		Y <= can -> minY ||
		Y >= can -> maxY
	) return 1;

	if (point_visible(can, X, Y)) {
		sprintf(can -> buf[Y+can->originY][X+can->originX], "%s█%s", color, cCLEAR);
	}

	return 0;
}

int plot_image(canvas* can, int X, int Y, char* img_path) {

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

			case 'o':
				plot_point(can, posX, posY, GRAY60);
				break;

			case 'd':
				plot_point(can, posX, posY, GRAY90);
				break;
			case 'D':
				plot_point(can, posX, posY, GRAY80);
				break;

			case 'r':
				plot_point(can, posX, posY, RED90);
				break;
			case 'R':
				plot_point(can, posX, posY, RED80);
				break;

			case 'g':
				plot_point(can, posX, posY, GREEN90);
				break;
			case 'G':
				plot_point(can, posX, posY, GREEN80);
				break;

			case 'y':
				plot_point(can, posX, posY, YELLOW90);
				break;
			case 'Y':
				plot_point(can, posX, posY, YELLOW80);
				break;

			case 'b':
				plot_point(can, posX, posY, BLUE90);
				break;
			case 'B':
				plot_point(can, posX, posY, BLUE80);
				break;

			case 'p':
				plot_point(can, posX, posY, PINK90);
				break;
			case 'P':
				plot_point(can, posX, posY, PINK80);
				break;

			case 'c':
				plot_point(can, posX, posY, CYAN90);
				break;
			case 'C':
				plot_point(can, posX, posY, CYAN80);
				break;

			case 'w':
				plot_point(can, posX, posY, WHITE90);
				break;
			case 'W':
				plot_point(can, posX, posY, WHITE80);
				break;
		}

		if (c == '\n') {
			posX = X;
			posY ++;
		}
		else
			posX ++;
	}
	canvas_flip_vertical(can);
	fclose(img);

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
		sprintf(can -> buf[Y+can->originY][X+can->originX], "%s%c%s", color, text, cCLEAR);
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
		sprintf(can -> buf[Y+can->originY][X+can->originX], "%s%s%s", color, text, cCLEAR);
	}

	return 0;
}

void plot_axes(canvas *can, int originX, int originY) {

	can -> originX = originX;
	can -> originY = originY;

	can -> maxX = can -> maxX - originX;
	can -> minX = can -> minX - originX;
	can -> maxY = can -> maxY - originY;
	can -> minY = can -> minY - originY;

	for (int X = can->minX; X <= can->maxX; X ++) {
		plot_uni(can, X, 0, cAXES, "━");
		if (X % 8 == 0 && X != 0) {
			if (originY >= (int)(can -> sizeY / 2)) {
				plot_uni(can, X, 0, cAXES, "┯");
				char val[8];
			   	sprintf(val, "%f", X/8 * can->unit);
				val[6] = '\0';
				plot_string(can, X, -1, cAXES, val);

			}
			if (originY < (int)(can -> sizeY / 2)) {
				plot_uni(can, X, 0, cAXES, "┷");
				char val[8];
			   	sprintf(val, "%f", X/8 * can->unit);
				val[6] = '\0';
				plot_string(can, X, 1, cAXES, val);
			}
		}
	}
	for (int Y = can->minY; Y <= can->maxY; Y ++) {
		plot_uni(can, 0, Y, cAXES, "┃");
		if (Y % 4 == 0 && Y != 0) {
			if (originX < (int)(can -> sizeX / 2)) {
				plot_uni(can, 0, Y, cAXES, "┠");
				char val[8];
			   	sprintf(val, "%f", Y/4 * can->unit);
				val[6] = '\0';
				plot_string(can, 2, Y, cAXES, val);
			}
			if (originX >= (int)(can -> sizeX / 2)) {
				plot_uni(can, 0, Y, cAXES, "┨");
				char val[8];
			   	sprintf(val, "%f", Y/4 * can->unit);
				val[6] = '\0';
				plot_string(can, -7, Y, cAXES, val);
			}
		}
	}
	plot_uni(can, 0, 0, cAXES, "╋");

}

point point_from_vec (canvas* can, vec vector) {
	
	if (vector.size < 2) {
		printf ("error: point_from_vec received a vector of dimension lower than 2.\n");
		return 0;
	}

	vec temp = vec_from_const (0, 2);
	temp.val[0] = vector.val[0] * 8 / can -> unit;
	temp.val[1] = vector.val[1] * 4 / can -> unit;
	point p = malloc(sizeof(int) * 2);

	if (vector.val[0] >= 0) {
		double frac = vector.val[0] - (int)vector.val[0];
		temp.val[0] = (int)temp.val[0];
		if (frac >= 0.5)
			temp.val[0] += 1;
	}

	if (vector.val[1] < 0) {
		double frac = vector.val[1] - (int)vector.val[1];
		temp.val[1] = (int)temp.val[1];
		if (frac < -0.5)
			temp.val[1] -= 1;
	}

	p[0] = temp.val[0];
	p[1] = temp.val[1];

	return p;
}

vec vec_from_point (canvas* can, point p) {
	p[0] /= 8;
	p[1] /= 4;
	p[0] *= can -> unit;
	p[1] *= can -> unit;
	double arr[2] = {p[0], p[1]};
	vec vec = vec_from_arr (arr, 2);
	return vec;
}

double point_vec_dist (canvas* can, vec vector) {
	vec real = vec_from_const (0, 2);
	real.val[0] = vector.val[0] * 8 / can -> unit;
	real.val[1] = vector.val[1] * 4 / can -> unit;

	point p = point_from_vec (can, vector);
	double arr[2] = {(double)p[0], (double)p[1]};
	vec integer = vec_from_arr (arr, 2);

	double dist = sqrt (pow (integer.val[1] - real.val[1], 2) + pow (integer.val[0] - real.val[0], 2));

	return dist;
}

void plot_vec (canvas* can, vec vector, char colorID) {
	point p = point_from_vec (can, vector);
		if (
			colorID == RED ||
			colorID == GREEN ||
			colorID == YELLOW ||
			colorID == BLUE ||
			colorID == PINK ||
			colorID == CYAN ||
			colorID == WHITE
		) {
			char shade;
			double dist = point_vec_dist (can, vector);
			point p = point_from_vec (can, vector);
			if (dist >= 0.000 && dist < 0.175) shade = L90;
			if (dist >= 0.175 && dist < 0.350) shade = L80;
			if (dist >= 0.350 && dist < 0.525) shade = L70;
			if (dist >= 0.525 && dist < 0.700) shade = L60;
			char presentShade = shade_from_colorID (colorID);
			switch (colorID) {
				case RED:
					switch (shade) {
						case L90:
							colorID = RED90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = RED80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = RED70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = RED60;
							break;
					}
					break;
				case GREEN:
					switch (shade) {
						case L90:
							colorID = GREEN90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = GREEN80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = GREEN70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = GREEN60;
							break;
					}
					break;
				case YELLOW:
					switch (shade) {
						case L90:
							colorID = YELLOW90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = YELLOW80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = YELLOW70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = YELLOW60;
							break;
					}
					break;
				case BLUE:
					switch (shade) {
						case L90:
							colorID = BLUE90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = BLUE80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = BLUE70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = BLUE60;
							break;
					}
					break;
				case PINK:
					switch (shade) {
						case L90:
							colorID = PINK90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = PINK80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = PINK70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = PINK60;
							break;
					}
					break;
				case CYAN:
					switch (shade) {
						case L90:
							colorID = CYAN90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = CYAN80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = CYAN70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = CYAN60;
							break;
					}
					break;
				case WHITE:
					switch (shade) {
						case L90:
							colorID = WHITE90;
							break;
						case L80:
							if (presentShade != L90)
								colorID = WHITE80;
							break;
						case L70:
							if (presentShade != L90 && presentShade != L80)
								colorID = WHITE70;
							break;
						case L60:
							if (presentShade != L90 && presentShade != L80 && presentShade != L70)
								colorID = WHITE60;
							break;
					}
					break;
			}
		}

	plot_point(can, p[0], p[1], colorID);
	free (p);
}


void plot_line (canvas *can, vec A, vec B, char colorID) {

	if (colorID == RAND)
		colorID = rand_c ();
	double len = sqrt(pow(B.val[0] - A.val[0], 2) + pow(B.val[1] - A.val[1], 2));
	for (double i = 0; i < 1; i += 1.0/(len / (can->unit)*8)) {
		vec BsubA = vec_sub(B, A);
		vec AaddBsubA = vec_add (A, vec_mul_const(BsubA, i));
		plot_vec (can, AaddBsubA, colorID);
		free(AaddBsubA.val);
		free(BsubA.val);
	}
	plot_vec (can, A, colorID);
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

void plot_vecs (canvas *can, vec* vectors, const char colorID) {
	for (int i = 0; vectors[i].val != NULL; i ++)
		plot_vec (can, vectors[i], colorID);
}

//double squared (double x) {
//	return x * x;
//}

int canvas_ctl (canvas *can, char* input) {
/*
	if (command exists) {
		execute command;
		return 0;
	}
	else
		return 1;
*/
	return 0;
}

void display_i (canvas* can) {
	char* input= malloc(32);
	char* input_exit = malloc(5);
	char* exit = malloc(5);

	strncpy(exit, "exit\0", 5);
	display(can);

	do {
		fgets(input, 32, stdin);
		display(can);
		strncpy(input_exit, input, 4);
		input_exit[4] = '\0';
		if (string_equal_till(exit, input_exit, 4))
			break;
		else if (!canvas_ctl(can, input));
		else
			printf("[command not recognized. type `help` for list of commands.]\n");
	} while(1);
}

void buf_push (canvas *can) {
	if (can->buf_stack == NULL)
		can->buf_stack = malloc (sizeof(buffer*));
	else
		can->buf_stack = realloc (can->buf_stack, sizeof(buffer*) * (can->buf_pointer + 1));
	
	can->buf_stack[can->buf_pointer ++] = buf_copy (can->buf, can->sizeX, can->sizeY);
}

int buf_pop (canvas *can) {
	if (can->buf_pointer == 1) {
		printf ("error: attempted to push from empty buffer stack. nothing popped.");
		return 1;
	}
	else {
		can->buf = buf_copy (can->buf_stack[--(can -> buf_pointer)], can->sizeX, can->sizeY);
	}
}

void* ctl_loop (void* arg) {
	char key;
	while(running) {
		timeout(1000);
		key = getch();
		if (key == 1)
			running = 0;
	}
	return 0;
}

void wait(double secs) {
	usleep(1000000 * secs);
}

/*
int main () {
	solution to the keyboard loop problem:
	1.	use a keyboard library, which directly parses the keyboard signals, this way I won't have to press Enter.
	2.	use system("stty");
	3.	learn to live with the fact that commands will not be displayed to the user as they type them.
	4.	have one thread loop getch(), filling stdin, and a second thread parsing stdin with FILE functions.

  	freeing memory:
	1.	char* string = malloc(10);
		free(string);
		string = "doctor"; <-- create automatic string and set pointer to point it
	2.	char* string = malloc(10);
		sprintf(string, "doctor"); <-- copied string into allocated memory
		free(string);
	3.	char* string = malloc(10);
		strcpy(string, "doctor"); <-- copied string into allocated memory
		free(string);

	thick-line algorithm:
	0.	define line radius R.
	1.	iterate through all pixels.
	2.	compute disstance from pixel to line.
	3.	shading range = [R - (UNIT * 8)/2, R + (UNIT * 8)/2].
	4.	color pixel.
	this is too slow...
	//system("/bin/stty raw");
	

	//plot_logo (can, 32, 8);

	todo:
	 - parse inputs while updating the plot
	 - update the canvas if inputs are received
	char chars[10];
	int charp = 0;
	double time = 0;

	//pthread_t ctl_thread;
	//pthread_create(&ctl_thread, NULL, ctl_loop, NULL);

	// 3 threads - one handles the input, another does the plotting, and a third updates the canvas.

	while(running && time < 100) {
		canvas* can = canvas_new(FILL, FILL, 4.0, DONT_CLEAR, XTERM);
		//printf(" [[[%c, %s]]] ", can->colordict[0]->colorID, can->colordict[0]->color);
	
		can->unit = 1.0;
		plot_axes(can, can->sizeX/2, can->sizeY/2);

		//double A[2] = {0 + 4 * sin(time), 0 + cos(time)};
		//vec vecA = vec_from_arr (A, 2);
		vec *square_points = vecs_from_func (-6, 6, 0.02, squared);
		plot_vecs (can, square_points, RED90);
	
		vec *sin_points = vecs_from_func (-6, 6, 0.02, sin);
		plot_vecs (can, sin_points, BLUE);

		vec *log_points = vecs_from_func (-6, 6, 0.02, log);
		plot_vecs (can, log_points, PINK);
	
		vec *sqrt_points = vecs_from_func (-6, 6, 0.02, sqrt);
		plot_vecs (can, sqrt_points, GREEN);



		double D[2] = {-5,-5}, E[2] = {5, 5};
		vec vecD = vec_from_arr (D, 2);
		vec vecE = vec_from_arr (E, 2);
		plot_line (can, vecD, vecE, RAND);
		//plot_line (can, vecD, vecE, YELLOW);
		vecD.val[0] += 1;
		vecE.val[0] += 1;
		plot_line (can, vecD, vecE, RAND);
		//plot_line (can, vecD, vecE, GREEN);
		vecD.val[0] += 1;
		vecE.val[0] += 1;
		plot_line (can, vecD, vecE, RAND);
		//plot_line (can, vecD, vecE, PINK);
		vecD.val[0] += 1;
		vecE.val[0] += 1;
		plot_line (can, vecD, vecE, CYAN);
		vecD.val[0] += 1;
		vecE.val[0] += 1;
		plot_line (can, vecD, vecE, WHITE);
		vecD.val[0] += 1;
		vecE.val[0] += 1;
		plot_line (can, vecD, vecE, RED);
		//plot_point (can, -7, -7, BLUE90);
		//
		//double A[2] = {-2, 2};
		//vec vecA = vec_from_arr (A, 2);
		//plot_vec(can, vecA, RED90);
		//point pA = point_from_vec (vecA);
		//plot_point(can, pA[0], pA[1], RED60);
		// make point and vec constructors, which take canvas* can as parameter and store the points and canvases
		// in arrays inside struct _canvas so they can then be easily freed inside canvas_delete(), instead of manually.
		double B[2] = {0,4}, C[2] = {8 * cos(time / 2), 4 * cos(time)};
		vec vecB = vec_from_arr (B, 2), vecC = vec_from_arr (C, 2);
		//plot_line (can, vecB, vecC, CYAN90);
		plot_line (can, vecB, vecC, BLUE);
		plot_vec(can, vecC, RED90);
		plot_palette (can, 2, -19);
		plot_point(can, 16, 8, GREEN90);
		
		char col168 = get_colorID(can, get_point_color (can, 16, 8));
		plot_point(can, 17, 8, col168);
		//get_point_color (can, 16, 8);

		display (can);
		//fflush(stdout);
		wait(0.05);
		time += 0.2;

		canvas_delete (can);
	}

	//void* return_from_thread;

	//pthread_join(ctl_thread, &return_from_thread);
	//int retval;
	for (double t = 0; t < 25; t += 0.05) {
		double x = t/4 * sin(t);
		double y = t/4 * cos(t);
		double point[2] = {x, y};
		vec A = vec_from_arr (point, 2);
		//plot_vecs (can, log_points, c93);
		plot_vec (can, A, cran);
		system("clear");
		//canvas_update (getch());
		display (can);
		vec_print_fancy(A, "A", 4, c32);
		//fflush(stdout);
		usleep(25000);
	}
	//system("/bin/stty cooked");
	//
	return 0;
}
*/

void plot_palette (canvas* can, int x, int y) {

		char* label = "palette:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, GRAY60); // 60
		plot_point(can, x, y + 6, GRAY70); // 70
		plot_point(can, x, y + 7, GRAY60); // 80
		plot_point(can, x, y + 8, GRAY90); // 90
		char* r24930 = "GRAY60\0"; // 60
		char* r44930 = "GRAY70\0"; // 85
		char* r24990 = "GRAY80\0"; // 65
		char* r44990 = "GRAY90\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24930);
		plot_string(can, x + 1, y + 6, c2, r44930);
		plot_string(can, x + 1, y + 7, c2, r24990);
		plot_string(can, x + 1, y + 8, c2, r44990);

		//RED
		plot_point(can, x, y, RED60);
		plot_point(can, x, y + 1, RED70);
		plot_point(can, x, y + 2, RED80);
		plot_point(can, x, y + 3, RED90);
		char* r24931 = "RED60\0"; // 30
		char* r24991 = "RED70\0"; // 35
		char* r44931 = "RED80\0"; // 45
		char* r44991 = "RED90\0"; // 50
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r24991);
		plot_string(can, x + 1, y + 2, c2, r44931);
		plot_string(can, x + 1, y + 3, c2, r44991);

		//GREEN
		plot_point(can, x, y + 10, GREEN60);
		plot_point(can, x, y + 11, GREEN70);
		plot_point(can, x, y + 12, GREEN80);
		plot_point(can, x, y + 13, GREEN90);
		char* r24932 = "GREEN60\0"; // 40
		char* r24992 = "GREEN70\0"; // 55
		char* r44932 = "GREEN80\0"; // 60
		char* r44992 = "GREEN90\0"; // 80
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r24992);
		plot_string(can, x + 1, y + 12, c2, r44932);
		plot_string(can, x + 1, y + 13, c2, r44992);

		//YELLOW
		plot_point(can, x, y + 15, YELLOW60);
		plot_point(can, x, y + 16, YELLOW70);
		plot_point(can, x, y + 17, YELLOW80);
		plot_point(can, x, y + 18, YELLOW90);
		char* r24933 = "YELLOW60\0"; // 45
		char* r24993 = "YELLOW70\0"; // 65
		char* r44933 = "YELLOW80\0"; // 70
		char* r44993 = "YELLOW90\0"; // 90
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r24993);
		plot_string(can, x + 1, y + 17, c2, r44933);
		plot_string(can, x + 1, y + 18, c2, r44993);

		//BLUE
		plot_point(can, x, y + 20, BLUE60);
		plot_point(can, x, y + 21, BLUE70);
		plot_point(can, x, y + 22, BLUE80);
		plot_point(can, x, y + 23, BLUE90);
		char* r24934 = "BLUE60\0"; // 25
		char* r44934 = "BLUE70\0"; // 40
		char* r24994 = "BLUE80\0"; // 40
		char* r44994 = "BLUE90\0"; // 60
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r44934);
		plot_string(can, x + 1, y + 22, c2, r24994);
		plot_string(can, x + 1, y + 23, c2, r44994);

		//PINK
		plot_point(can, x, y + 25, PINK60);
		plot_point(can, x, y + 26, PINK70);
		plot_point(can, x, y + 27, PINK80);
		plot_point(can, x, y + 28, PINK90);
		char* r24935 = "PINK60\0"; // 25
		char* r24995 = "PINK70\0"; // 40
		char* r44935 = "PINK80\0"; // 40
		char* r44995 = "PINK90\0"; // 60
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r24995);
		plot_string(can, x + 1, y + 27, c2, r44935);
		plot_string(can, x + 1, y + 28, c2, r44995);

		//CYAN
		plot_point(can, x, y + 30, CYAN60);
		plot_point(can, x, y + 31, CYAN70);
		plot_point(can, x, y + 32, CYAN80);
		plot_point(can, x, y + 33, CYAN90);
		char* r24936 = "CYAN60\0"; // 40
		char* r24996 = "CYAN70\0"; // 60
		char* r44936 = "CYAN80\0"; // 60
		char* r44996 = "CYAN90\0"; // 80
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24996);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44996);

		//WHITE
		plot_point(can, x, y + 35, WHITE60);
		plot_point(can, x, y + 36, WHITE70);
		plot_point(can, x, y + 37, WHITE80);
		plot_point(can, x, y + 38, WHITE90);
		char* r24937 = "WHITE60\0"; // 60
		char* r24997 = "WHITE70\0"; // 65
		char* r44937 = "WHITE80\0"; // 85
		char* r44997 = "WHITE90\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}

