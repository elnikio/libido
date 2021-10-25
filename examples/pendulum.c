#include <libido/plot.h>
#include <libido/vector.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main() {
	
	double time = 0;
	char running = 1;

	int offsetD = rand() % 10;
	int offsetE = rand() % 10;
	int offsetF = rand() % 10;
	int offsetG = rand() % 10;
	int offsetH = rand() % 10;
	int offsetI = rand() % 10;

	canvas* screen = canvas_new (FILL, FILL, 1.0, CLEAR, XTERM);
	while(running) {
		canvas* can = canvas_new (screen -> sizeX, screen ->sizeY - 2, 4.0, CLEAR, XTERM);

		can -> unit = 1.0;
		plot_axes (can, can -> sizeX/2, screen -> sizeY/2);

		double B[2] = {0, 4};
		double C[2] = {8 * cos(time / 2), 4 * cos(time)};
		double D[2] = {8 * cos((time + offsetD) / 2), 4 * cos(time + offsetD)};
		double E[2] = {8 * cos((time + offsetE) / 2), 4 * cos(time + offsetE)};
		double F[2] = {8 * cos((time + offsetF) / 2), 4 * cos(time + offsetF)};
		double G[2] = {8 * cos((time + offsetG) / 2), 4 * cos(time + offsetG)};
		double H[2] = {8 * cos((time + offsetH) / 2), 4 * cos(time + offsetH)};
		double I[2] = {8 * cos((time + offsetI) / 2), 4 * cos(time + offsetI)};
		vec vecB = vec_from_arr (B, 2);
		vec vecC = vec_from_arr (C, 2);
		vec vecD = vec_from_arr (D, 2);
		vec vecE = vec_from_arr (E, 2);
		vec vecF = vec_from_arr (F, 2);
		vec vecG = vec_from_arr (G, 2);
		vec vecH = vec_from_arr (H, 2);
		vec vecI = vec_from_arr (I, 2);

		plot_line (can, vecB, vecC, GREEN);
		plot_line (can, vecB, vecD, BLUE);
		plot_line (can, vecB, vecE, RED);
		plot_line (can, vecB, vecF, PINK);
		plot_line (can, vecB, vecG, CYAN);
		plot_line (can, vecB, vecH, WHITE);
		plot_line (can, vecB, vecI, GRAY);

		display (can);
		fflush (stdout);
		wait (0.02);
		time += 0.1;
		free (can);
	}

	free (screen);
}
