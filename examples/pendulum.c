#include <libido/plot.h>
#include <libido/vector.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

const char* c31 = "\033[0;31m";
const char* c32 = "\033[0;32m";

void wait(double secs) {
	usleep(1000000 * secs);
}

int main() {
	
	double time = 0;
	char running = 1;

	canvas* screen = canvas_new (FILL, FILL, 1.0, CLEAR, XTERM);
	while(running) {
		canvas* can = canvas_new (screen -> sizeX, screen ->sizeY - 2, 4.0, CLEAR, XTERM);

		can -> unit = 1.0;
		plot_axes (can, can -> sizeX/2, screen -> sizeY/2);

		double B[2] = {0, 4};
		double C[2] = {8 * cos(time / 2), 4 * cos(time)};
		vec vecB = vec_from_arr (B, 2);
		vec vecC = vec_from_arr (C, 2);

		plot_line (can, vecB, vecC, c31);
		plot_vec (can, vecC, c32);

		display (can);
		fflush (stdout);
		wait (0.1);
		time += 0.1;

		free (can);
	}

	free (screen);
}
