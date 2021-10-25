#include <libido/plot.h>
#include <libido/vector.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

const char* c31 = "\033[0;31m";
const char* c32 = "\033[0;32m";

/*
void wait(double secs) {
	usleep(1000000 * secs);
}
*/

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
		*/
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

		plot_line (can, vecB, vecC, GREEN);
		plot_vec (can, vecC, GREEN);

		display (can);
		fflush (stdout);
		wait (0.1);
		time += 0.1;

		free (can);
	}

	free (screen);
}
