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
	
	int x1 = 0;
	int y1 = 0;
	int p1[2] = {x1, y1};

	
	for (double t = 0; t < 25; t += 0.05) {
		int x2 = (int)(t/4 * sin(t) * 8);
		int y2 = (int)(t/4 * cos(t) * 4);
		int p2[2] = {x2, y2};
		plot_lineDDA (can, p1, p2, GREEN);
		system("clear");
		display (can);
		fflush(stdout);
		usleep(25000);
		//A.val = B.val;
	}
}
