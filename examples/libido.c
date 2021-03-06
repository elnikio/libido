#include <libido/plot.h>
#include <string.h>
#include <libido/vector.h>
//#include "colors.h"
//#include <ncurses.h>
//#include <unistd.h>
#include <math.h>

//const char* c31 = "\033[0;31m";

double squared (double x) {
	return x * x;
}
/*
void plot_logo (canvas* can, int X, int Y) {
	// Create a new canvas object for the image:
	canvas* can_logo = canvas_empty(can->sizeX, can->sizeY, DONT_CLEAR);

	// Plot image onto canvas:
	plot_image(can_logo, X, Y, "text.txt");

	// Flip canvas (images are plotted downward up):
	canvas_flip_vertical(can_logo);
	// note to self: insert canvas_flip_vertical() inside plot_image to avoid the need to manually call it every time.

	// Merge the image canvas with the root canvas:
	canvas_merge(can, can_logo);
}
*/

int main () {
	// Create root canvas where all the plotting will happen:
	canvas* can = canvas_new(FILL, FILL, 4.0, DONT_CLEAR, XTERM);
	// make canvas_new accept negative values as size parameters, and parse them as FILL - x, as you would. no ambiguity.
	
	// Set the size of the vector plane units:
	can->unit = 1.0;
	// note to self: create an example for drawing with pixels and an example for drawing with vectors.

	// Plot the vector plane axes, repositioning the vector plane origin (previously at {0, 0}) to the center of the screen:
	plot_axes(can, can->sizeX/2, can->sizeY/2);

	for (double t = 0; t < 25; t += 0.05) {
		double x = t/4 * sin(t);
		double y = t/4 * cos(t);
		double point[2] = {x, y};
		vec A = vec_from_arr (point, 2);
		//plot_vecs (can, log_points, c93);
		plot_vec (can, A, RAND);
		system("clear");
		//canvas_update (getch());
		display (can);
		vec_print_fancy(A, "A", 4, RAND);
		fflush(stdout);
		usleep(25000);
	}
}
