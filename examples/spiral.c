#include <libido/plot.h>
#include <stdlib.h>
#include <libido/vector.h>

int main () {
	// Create root canvas where all the plotting will happen:
	canvas* can = canvas_new(FILL, FILL, 4.0, DONT_CLEAR, XTERM);
	// make canvas_new accept negative values as size parameters, and parse them as FILL - x, as you would. no ambiguity.
	
	// Set the size of the vector plane units:
	can->unit = 1.0;
	// note to self: create an example for drawing with pixels and an example for drawing with vectors.

	// Plot the vector plane axes, repositioning the vector plane origin (previously at {0, 0}) to the center of the screen:
	plot_axes(can, can->sizeX/2, can->sizeY/2);
	
	double x1 = 0;
	double y1 = 0;
	double point1[2] = {x1, y1};
	vec A = vec_from_arr (point1, 2);

	
	for (double t = 0; t < 25; t += 0.05) {

		double x2 = t/4 * sin(t);
		double y2 = t/4 * cos(t);
		double point2[2] = {x2, y2};
		vec B = vec_from_arr (point2, 2);
		plot_line (can, A, B, GREEN);
		//plot_lineDDA (can, A, B, GREEN);
		system("clear");
		display (can);
		vec_print_fancy(A, "A", 4, RAND);
		fflush(stdout);
		usleep(25000);
		//A.val = B.val;
	}
}
