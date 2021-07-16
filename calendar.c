#include "calendar.h"

// date class methods :
int set_time (date_class *date, int hour, int minute, int second) {
	if (
	hour < 0 || hour > 24 ||
	minute < 0 || minute > 60 ||
	second < 0 || second > 60
	) return FAILURE;
	date -> second = second;
	date -> minute = minute;
	date -> hour = hour;
	return SUCCESS;
}
int set_day (date_class *date, int day) {
	if (day < 0 || day > 31) return FAILURE;
	date -> day = day;
	return SUCCESS;
}
int set_month (date_class *date, int month) {
	if (month < 0 || month > 12) return FAILURE;
	date -> month = month;
	return SUCCESS;
}
int set_year (date_class *date, int year) {
	date -> year = year;
	return SUCCESS;
}
int move_time (date_class *date, int hour_move, int minute_move, int second_move) {
	int hour = date -> hour + hour_move;
	int minute = date -> minute + minute_move;
	int second = date -> second + second_move;
	minute += second / 60;
	second = second % 60;
	hour += minute / 60;
	minute = minute % 60;
	return SUCCESS;
}
int move_day (date_class *date, int day_move) {
	day = day_move + date -> day;
	month = date -> month;
	year = date -> year;
	int month_len = compute_month_len (date -> month, date -> year);
	if (day > month_len) {
		for (day, day > month_len, month_len = compute_month_len (month, year)) {
			day -= month_len;
			month ++;
			if (month > 12) {
				year ++;
				month = 1;
			}
		}
	}
	else if (day < compute_month_len (month - 1, year)) {
		month_len = compute_month_len (month, year);
		for (day, day < 0, month_len = compute_month_len (month - 1, year)) {
			day += month_len;
			month --;
			if (month < 1) {
				year --;
				month = 12;
			}
		}
	}
	else {
		date -> day = day;
	}
	return SUCCESS;
}
int move_month (date_class *date, int month_move) {
	return SUCCESS;
}
int move_year (date_class *date, int year_move) {
	return SUCCESS;
}
//

// date functions :
int compute_month_len (int month, int year) {
	switch (month) {
		case JANUARY:
			return 31;
		case FEBRUARY:
			if (year % 4)
				return 28;
			else
				return 29;
		case MARCH:
			return 31;
		case APRIL:
			return 30;
		case MAY:
			return 31;
		case JUNE:
			return 30;
		case JULY:
			return 31;
		case AUGUST:
			return 31;
		case SEPTEMBER:
			return 30;
		case OCTOBER:
			return 31;
		case NOVEMBER:
			return 30;
		case DECEMBER:
			return 31;
		case 0:
			return 31;
		default:
			return FAILURE;
	}
}
//
