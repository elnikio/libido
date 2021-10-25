#include <libido/plot.h>
#include <libido/vector.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	
		canvas* can = canvas_new (FILL, FILL, 1.0, CLEAR, XTERM);

		plot_axes (can, can -> sizeX/2, can -> sizeY/2);

		plot_palette (can, 0, 0);

		display (can);
		fflush (stdout);
		free (can);
}
