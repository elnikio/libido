#ifndef GEOMETRY_ENUMS
enum _shape {
	RECTANGLE,
	SQUARE,
	ELLIPSE,
	CIRCLE
};

enum _coord_type {
	CARTESIAN,
	POLAR
};
#endif

// coordinates :
typedef struct _coord_2d {
	int type;
	coord_car_2d car;
	coord_pol_2d pol;
} coord_2d;

// cartesian coordinates :
typedef struct _coord_car_2d {
	double X;
	double Y;
} coord_car_2d;
typedef struct _coord_car_3d {
	double X;
	double Y;
	double Z;
} coord_car_3d;

// polar coordinates :
typedef struct _coord_pol_2d {
	double R;
	double A;
} coord_pol_2d;
typedef struct _coord_pol_3d {
	double R;
	double A;
	double B;
} coord_pol_3d;

// points :
typedef struct _point_2d {
	double X;
	double Y;
} point_2d;
typedef struct _point {
	double X;
	double Y;
	double Z;
} point;

// figures :
typedef struct _rectangle {
	point A;
	point B;
	point C;
	point D;
} rectangle;
typedef struct _rectangle_3d {
	point_3d A;
	point_3d B;
	point_3d C;
	point_3d D;
} rectangle_3d;

// color :
typedef struct _color {
	int R;
	int G;
	int B;
} color;

#define GEOMETRY_ENUMS
