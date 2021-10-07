#include "string.h"
#include "generic.h"

#ifndef CALENDAR_ENUMS
enum _month {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

enum _format {
	MM_DD_YY,
	DD_MM_YY,
	YY_MM_DD,
};
#endif

// date class :
typedef struct _date_methods date_methods;

typedef struct _date_class {
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;
	date_methods *methods;
} date_class;

struct _date_methods {
	int (*set_time)(date_class *, int, int, int);
	int (*set_day)(date_class *, int);
	int (*set_month)(date_class *, int);
	int (*set_year)(date_class *, int);
};
//

// date class methods :
int set_time (date_class *date, int hour, int minute, int second);
int set_day (date_class *date, int day);
int set_month (date_class *date, int month);
int set_year (date_class *date, int year);
int move_time (date_class *date, int hour_move, int minute_move, int second_move);
int move_day (date_class *date, int day_move);
int move_month (date_class *date, int month_move);
int move_year (date_class *date, int year_move);
//

// date class static methods :
string date_format (date_class *date, int format);
//

#define CALENDAR_ENUMS 0
