#include <libido/plot.h>
#include <libido/vector.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

/*
question:
 when a plot funciton overwrites another plot funciton, is the overwritten pixel string freed from memory?
*/

point p_from_v (canvas* can, vec vector) {
	
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


int main() {
	
	canvas* can = canvas_new (FILL, FILL, 4.0, DONT_CLEAR, XTERM);

	can -> unit = 1.0;
	plot_axes (can, can -> sizeX/2, can -> sizeY/2);

	double A[2] = {0, 2};

	for (float i = 0.4; i < 8; i += 0.04) {
		A[0] = i;
		vec temp = vec_from_arr (A, 2);
		int* tempP = p_from_v (can, temp);
		vec_print (temp);
		printf ("point = (%d, %d)\n\n", tempP[0], tempP[1]);
		plot_vec (can, temp, GREEN);
		display (can);
		fflush (stdout);
		wait (0.1);
	}

	free (can);
}
