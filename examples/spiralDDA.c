#include <libido/plot.h>
#include <stdlib.h>
#include <math.h>
#include <signal.h>
#include <libido/vector.h>
#include <fenv.h>

void spammer () {
	printf ("[FE_INEXACT]");
}

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
	int point1[2] = {(int) x1, (int) y1};

	
	for (double t = 0.05; t < 25; t += 0.05) {

		feclearexcept(FE_ALL_EXCEPT);
		double x2 = round(t * sin(t));
		double y2 = round(t * cos(t));
		printf ("x2 = %lf, y2 = %lf\n", x2, y2);
		int point2[2] = {round(x2), round(y2)};
		printf ("ix2 = %d, iy2 = %d\n", point2[0], point2[1]);
		printf("point1 = [%d, %d], point2 = [%d, %d].\n", point1[0], point1[1], point2[0], point2[1]);

		// ignore FE_INEXACT SIGFPE
		if (fetestexcept(FE_INEXACT)) {
			signal(SIGFPE, spammer);
			signal(SIGFPE, SIG_IGN);
			printf ("FPX: FE_INEXACT\n");
		}
		else
			signal(SIGFPE, SIG_DFL);

		fflush(stdout);
		plot_lineDDA (can, point1, point2, GREEN);
		system("clear");
		display (can);
		fflush(stdout);
		usleep(25000);
	}
}
