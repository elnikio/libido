#include "matrix.h"

/*
// test program :
int main() {
	printf ("This is awesome! Yolo!\n");
	fmat mat = mat_gen (1, 3, 1, 2, 8, 2, &scalar_mul);
	mat_print_padded (mat, 4);
}
*/

// print matrix :
void mat_print (fmat mat) {
	printf ("[");
	for (int iy = 0; iy < mat.size_y; iy ++) {
		(iy > 0) ? printf (" ") : printf ("");
		for (int ix = 0; ix < mat.size_x; ix ++)
			(ix < mat.size_x - 1) ? printf ("%g, ", mat.val [iy][ix]) : printf ("%g", mat.val [iy][ix]);
		(iy < mat.size_y - 1) ? printf ("\n") : printf ("");
	}
	printf ("]");
}
void mat_print_padded (fmat mat, int padding) {
	printf ("[");
	for (int iy = 0; iy < mat.size_y; iy ++) {
		(iy > 0) ? printf (" ") : printf ("");
		for (int ix = 0; ix < mat.size_x; ix ++)
			(ix < mat.size_x - 1) ? printf ("%*g, ", padding, mat.val [iy][ix]) : printf ("%*g", padding, mat.val [iy][ix]);
		(iy < mat.size_y - 1) ? printf ("\n") : printf ("");
	}
	printf ("]");
}

// generate matrix iteratively :
fmat mat_gen (
		double min_x, double max_x, double inc_x,
		double min_y, double max_y, double inc_y,
		double (*function)(double, double)
	) {
	fmat mat;
	double ix, iy;
	int jx, jy;
	int cells_y = (max_y - min_y) / inc_y + 1;
	int cells_x = (max_x - min_x) / inc_x + 1;
	double **val = malloc ((cells_y + 1) * sizeof (double *));
	for (int k = 0; k < cells_y; k++)
		val [k] = malloc ((cells_x + 1) * sizeof (double));
	for (iy = min_y, jy = 0; iy <= max_y; iy += inc_y, jy ++) {
		for (ix = min_x, jx = 0; ix <= max_x; ix += inc_x, jx ++) {
			if (function)
				val [jy][jx] = function (ix, iy);
			else
				val [jy][jx] = ix * iy;
		}
		val [jy][jx + 1] = '\0';
	}
	val [jy + 1] = NULL;
	mat.val = val;
	mat.size_x = jx;
	mat.size_y = jy;
	return mat;
}
