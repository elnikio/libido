#include "plot_templates.h"
#include "colors.h"

static const char* c1 = "\033[0;1m";
static const char* c2 = "\033[0;2m";
static const char* c3 = "\033[0;3m";
static const char* c4 = "\033[0;4m";
static const char* c7 = "\033[0;7m";
static const char* c8 = "\033[0;8m";
static const char* c9 = "\033[0;9m";
static const char* c30 = "\033[0;30m";
static const char* c31 = "\033[0;31m";
static const char* c32 = "\033[0;32m";
static const char* c33 = "\033[0;33m";
static const char* c34 = "\033[0;34m";
static const char* c35 = "\033[0;35m";
static const char* c36 = "\033[0;36m";
static const char* c37 = "\033[0;37m";
static const char* c40 = "\033[0;40m";
static const char* c41 = "\033[0;41m";
static const char* c42 = "\033[0;42m";
static const char* c43 = "\033[0;43m";
static const char* c44 = "\033[0;44m";
static const char* c45 = "\033[0;45m";
static const char* c46 = "\033[0;46m";
static const char* c47 = "\033[0;47m";
static const char* c90 = "\033[0;90m";
static const char* c91 = "\033[0;91m";
static const char* c92 = "\033[0;92m";
static const char* c93 = "\033[0;93m";
static const char* c94 = "\033[0;94m";
static const char* c95 = "\033[0;95m";
static const char* c96 = "\033[0;96m";
static const char* c97 = "\033[0;97m";
static const char* c100 = "\033[0;100m";
static const char* c101 = "\033[0;101m";
static const char* c102 = "\033[0;102m";
static const char* c103 = "\033[0;103m";
static const char* c104 = "\033[0;104m";
static const char* c105 = "\033[0;105m";
static const char* c106 = "\033[0;106m";
static const char* c107 = "\033[0;107m";
static const char* c109 = "\033[0;109m";
static const char* cran = "R";

void plot_palette (canvas* can, int x, int y) {

		char* label = "palette:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, GRAY60); // 60
		plot_point(can, x, y + 6, GRAY70); // 70
		plot_point(can, x, y + 7, GRAY60); // 80
		plot_point(can, x, y + 8, GRAY90); // 90
		char* r24930 = "GRAY60\0"; // 60
		char* r44930 = "GRAY70\0"; // 85
		char* r24990 = "GRAY80\0"; // 65
		char* r44990 = "GRAY90\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24930);
		plot_string(can, x + 1, y + 6, c2, r44930);
		plot_string(can, x + 1, y + 7, c2, r24990);
		plot_string(can, x + 1, y + 8, c2, r44990);

		//RED
		plot_point(can, x, y, RED60);
		plot_point(can, x, y + 1, RED70);
		plot_point(can, x, y + 2, RED80);
		plot_point(can, x, y + 3, RED90);
		char* r24931 = "RED60\0"; // 30
		char* r24991 = "RED70\0"; // 35
		char* r44931 = "RED80\0"; // 45
		char* r44991 = "RED90\0"; // 50
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r24991);
		plot_string(can, x + 1, y + 2, c2, r44931);
		plot_string(can, x + 1, y + 3, c2, r44991);

		//GREEN
		plot_point(can, x, y + 10, GREEN60);
		plot_point(can, x, y + 11, GREEN70);
		plot_point(can, x, y + 12, GREEN80);
		plot_point(can, x, y + 13, GREEN90);
		char* r24932 = "GREEN60\0"; // 40
		char* r24992 = "GREEN70\0"; // 55
		char* r44932 = "GREEN80\0"; // 60
		char* r44992 = "GREEN90\0"; // 80
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r24992);
		plot_string(can, x + 1, y + 12, c2, r44932);
		plot_string(can, x + 1, y + 13, c2, r44992);

		//YELLOW
		plot_point(can, x, y + 15, YELLOW60);
		plot_point(can, x, y + 16, YELLOW70);
		plot_point(can, x, y + 17, YELLOW80);
		plot_point(can, x, y + 18, YELLOW90);
		char* r24933 = "YELLOW60\0"; // 45
		char* r24993 = "YELLOW70\0"; // 65
		char* r44933 = "YELLOW80\0"; // 70
		char* r44993 = "YELLOW90\0"; // 90
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r24993);
		plot_string(can, x + 1, y + 17, c2, r44933);
		plot_string(can, x + 1, y + 18, c2, r44993);

		//BLUE
		plot_point(can, x, y + 20, BLUE60);
		plot_point(can, x, y + 21, BLUE70);
		plot_point(can, x, y + 22, BLUE80);
		plot_point(can, x, y + 23, BLUE90);
		char* r24934 = "BLUE60\0"; // 25
		char* r44934 = "BLUE70\0"; // 40
		char* r24994 = "BLUE80\0"; // 40
		char* r44994 = "BLUE90\0"; // 60
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r44934);
		plot_string(can, x + 1, y + 22, c2, r24994);
		plot_string(can, x + 1, y + 23, c2, r44994);

		//PINK
		plot_point(can, x, y + 25, PINK60);
		plot_point(can, x, y + 26, PINK70);
		plot_point(can, x, y + 27, PINK80);
		plot_point(can, x, y + 28, PINK90);
		char* r24935 = "PINK60\0"; // 25
		char* r24995 = "PINK70\0"; // 40
		char* r44935 = "PINK80\0"; // 40
		char* r44995 = "PINK90\0"; // 60
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r24995);
		plot_string(can, x + 1, y + 27, c2, r44935);
		plot_string(can, x + 1, y + 28, c2, r44995);

		//CYAN
		plot_point(can, x, y + 30, CYAN60);
		plot_point(can, x, y + 31, CYAN70);
		plot_point(can, x, y + 32, CYAN80);
		plot_point(can, x, y + 33, CYAN90);
		char* r24936 = "CYAN60\0"; // 40
		char* r24996 = "CYAN70\0"; // 60
		char* r44936 = "CYAN80\0"; // 60
		char* r44996 = "CYAN90\0"; // 80
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24996);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44996);

		//WHITE
		plot_point(can, x, y + 35, WHITE60);
		plot_point(can, x, y + 36, WHITE70);
		plot_point(can, x, y + 37, WHITE80);
		plot_point(can, x, y + 38, WHITE90);
		char* r24937 = "WHITE60\0"; // 60
		char* r24997 = "WHITE70\0"; // 65
		char* r44937 = "WHITE80\0"; // 85
		char* r44997 = "WHITE90\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}

/*

void plot_palette_xterm(canvas* can, int x, int y) {

		char* label = "xterm:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, "\033[m"); // 60
		plot_point(can, x, y + 6, "\033[0m"); // 70
		plot_point(can, x, y + 7, "\033[0m"); // 80
		plot_point(can, x, y + 8, "\033[0m"); // 90
		char* r24930 = "\0"; // 60
		char* r44930 = "0\0"; // 85
		char* r24990 = "0\0"; // 65
		char* r44990 = "0\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24930);
		plot_string(can, x + 1, y + 6, c2, r44930);
		plot_string(can, x + 1, y + 7, c2, r24990);
		plot_string(can, x + 1, y + 8, c2, r44990);

		//RED
		plot_point(can, x, y, "\033[0m");
		plot_point(can, x, y + 1, "\033[0m");
		plot_point(can, x, y + 2, "\033[0m");
		plot_point(can, x, y + 3, "\033[0m");
		char* r24931 = "0\0"; // 30
		char* r24991 = "0\0"; // 35
		char* r44931 = "0\0"; // 45
		char* r44991 = "0\0"; // 50
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r24991);
		plot_string(can, x + 1, y + 2, c2, r44931);
		plot_string(can, x + 1, y + 3, c2, r44991);

		//GREEN
		plot_point(can, x, y + 10, "\033[0m");
		plot_point(can, x, y + 11, "\033[0m");
		plot_point(can, x, y + 12, "\033[0m");
		plot_point(can, x, y + 13, "\033[0m");
		char* r24932 = "0\0"; // 40
		char* r24992 = "0\0"; // 55
		char* r44932 = "0\0"; // 60
		char* r44992 = "0\0"; // 80
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r24992);
		plot_string(can, x + 1, y + 12, c2, r44932);
		plot_string(can, x + 1, y + 13, c2, r44992);

		//YELLOW
		plot_point(can, x, y + 15, "\033[0m");
		plot_point(can, x, y + 16, "\033[0m");
		plot_point(can, x, y + 17, "\033[0m");
		plot_point(can, x, y + 18, "\033[0m");
		char* r24933 = "0\0"; // 45
		char* r24993 = "0\0"; // 65
		char* r44933 = "0\0"; // 70
		char* r44993 = "0\0"; // 90
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r24993);
		plot_string(can, x + 1, y + 17, c2, r44933);
		plot_string(can, x + 1, y + 18, c2, r44993);

		//BLUE
		plot_point(can, x, y + 20, "\033[0m");
		plot_point(can, x, y + 21, "\033[0m");
		plot_point(can, x, y + 22, "\033[0m");
		plot_point(can, x, y + 23, "\033[0m");
		char* r24934 = "0\0"; // 25
		char* r44934 = "0\0"; // 40
		char* r24994 = "0\0"; // 40
		char* r44994 = "0\0"; // 60
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r44934);
		plot_string(can, x + 1, y + 22, c2, r24994);
		plot_string(can, x + 1, y + 23, c2, r44994);

		//PINK
		plot_point(can, x, y + 25, "\033[0m");
		plot_point(can, x, y + 26, "\033[0m");
		plot_point(can, x, y + 27, "\033[0m");
		plot_point(can, x, y + 28, "\033[0m");
		char* r24935 = "0\0"; // 25
		char* r24995 = "0\0"; // 40
		char* r44935 = "0\0"; // 40
		char* r44995 = "0\0"; // 60
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r24995);
		plot_string(can, x + 1, y + 27, c2, r44935);
		plot_string(can, x + 1, y + 28, c2, r44995);

		//CYAN
		plot_point(can, x, y + 30, "\033[0m");
		plot_point(can, x, y + 31, "\033[0m");
		plot_point(can, x, y + 32, "\033[0m");
		plot_point(can, x, y + 33, "\033[0m");
		char* r24936 = "0\0"; // 40
		char* r24996 = "0\0"; // 60
		char* r44936 = "0\0"; // 60
		char* r44996 = "0\0"; // 80
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24996);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44996);

		//WHITE
		plot_point(can, x, y + 35, "\033[0m");
		plot_point(can, x, y + 36, "\033[0m");
		plot_point(can, x, y + 37, "\033[0m");
		plot_point(can, x, y + 38, "\033[0m");
		char* r24937 = "0\0"; // 60
		char* r24997 = "0\0"; // 65
		char* r44937 = "0\0"; // 85
		char* r44997 = "0\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}

void plot_palette_gnome(canvas* can, int x, int y) {

		char* label = "gnome:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, "\033[m");
		plot_point(can, x, y + 6, "\033[0m");
		plot_point(can, x, y + 7, "\033[0m");
		plot_point(can, x, y + 8, "\033[0m");
		char* r24930 = "\0"; // 60
		char* r44930 = "0\0"; // 85
		char* r24990 = "0\0"; // 65
		char* r44990 = "0\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24930);
		plot_string(can, x + 1, y + 6, c2, r44930);
		plot_string(can, x + 1, y + 7, c2, r24990);
		plot_string(can, x + 1, y + 8, c2, r44990);

		//RED
		plot_point(can, x, y, "\033[0m");
		plot_point(can, x, y + 1, "\033[0m");
		plot_point(can, x, y + 2, "\033[0m");
		plot_point(can, x, y + 3, "\033[0m");
		char* r24931 = "0\0"; // 30
		char* r44931 = "0\0"; // 45
		char* r24991 = "0\0"; // 35
		char* r44991 = "0\0"; // 50
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r44931);
		plot_string(can, x + 1, y + 2, c2, r24991);
		plot_string(can, x + 1, y + 3, c2, r44991);

		//GREEN
		plot_point(can, x, y + 10, "\033[0m");
		plot_point(can, x, y + 11, "\033[0m");
		plot_point(can, x, y + 12, "\033[0m");
		plot_point(can, x, y + 13, "\033[0m");
		char* r24932 = "0\0"; // 40
		char* r24992 = "0\0"; // 55
		char* r44932 = "0\0"; // 60
		char* r44992 = "0\0"; // 80
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r24992);
		plot_string(can, x + 1, y + 12, c2, r44932);
		plot_string(can, x + 1, y + 13, c2, r44992);

		//YELLOW
		plot_point(can, x, y + 15, "\033[0m");
		plot_point(can, x, y + 16, "\033[0m");
		plot_point(can, x, y + 17, "\033[0m");
		plot_point(can, x, y + 18, "\033[0m");
		char* r24933 = "0\0"; // 45
		char* r24993 = "0\0"; // 65
		char* r44933 = "0\0"; // 70
		char* r44993 = "0\0"; // 90
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r24993);
		plot_string(can, x + 1, y + 17, c2, r44933);
		plot_string(can, x + 1, y + 18, c2, r44993);

		//BLUE
		plot_point(can, x, y + 20, "\033[0m");
		plot_point(can, x, y + 21, "\033[0m");
		plot_point(can, x, y + 22, "\033[0m");
		plot_point(can, x, y + 23, "\033[0m");
		char* r24934 = "0\0"; // 25
		char* r44934 = "0\0"; // 40
		char* r24994 = "0\0"; // 40
		char* r44994 = "0\0"; // 60
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r44934);
		plot_string(can, x + 1, y + 22, c2, r24994);
		plot_string(can, x + 1, y + 23, c2, r44994);

		//PINK
		plot_point(can, x, y + 25, "\033[0m");
		plot_point(can, x, y + 26, "\033[0m");
		plot_point(can, x, y + 27, "\033[0m");
		plot_point(can, x, y + 28, "\033[0m");
		char* r24935 = "0\0"; // 25
		char* r24995 = "0\0"; // 40
		char* r44935 = "0\0"; // 40
		char* r44995 = "0\0"; // 60
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r24995);
		plot_string(can, x + 1, y + 27, c2, r44935);
		plot_string(can, x + 1, y + 28, c2, r44995);

		//CYAN
		plot_point(can, x, y + 30, "\033[0m");
		plot_point(can, x, y + 31, "\033[0m");
		plot_point(can, x, y + 32, "\033[0m");
		plot_point(can, x, y + 33, "\033[0m");
		char* r24936 = "0\0"; // 40
		char* r24996 = "0\0"; // 60
		char* r44936 = "0\0"; // 60
		char* r44996 = "0\0"; // 80
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24996);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44996);

		//WHITE
		plot_point(can, x, y + 35, "\033[0m");
		plot_point(can, x, y + 36, "\033[0m");
		plot_point(can, x, y + 37, "\033[0m");
		plot_point(can, x, y + 38, "\033[0m");
		char* r24937 = "0\0"; // 60
		char* r24997 = "0\0"; // 65
		char* r44937 = "0\0"; // 85
		char* r44997 = "0\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}

void plot_palette_linux(canvas* can, int x, int y) {

		char* label = "linux:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, "\033[m");
		plot_point(can, x, y + 6, "\033[0m");
		plot_point(can, x, y + 7, "\033[0m");
		plot_point(can, x, y + 8, "\033[0m");
		char* r24930 = "\0"; // 60
		char* r44930 = "0\0"; // 85
		char* r24990 = "0\0"; // 65
		char* r44990 = "0\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24930);
		plot_string(can, x + 1, y + 6, c2, r44930);
		plot_string(can, x + 1, y + 7, c2, r24990);
		plot_string(can, x + 1, y + 8, c2, r44990);

		//RED
		plot_point(can, x, y, "\033[0m");
		plot_point(can, x, y + 1, "\033[0m");
		plot_point(can, x, y + 2, "\033[0m");
		plot_point(can, x, y + 3, "\033[0m");
		char* r24931 = "0\0"; // 30
		char* r44931 = "0\0"; // 45
		char* r24991 = "0\0"; // 35
		char* r44991 = "0\0"; // 50
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r44931);
		plot_string(can, x + 1, y + 2, c2, r24991);
		plot_string(can, x + 1, y + 3, c2, r44991);

		//GREEN
		plot_point(can, x, y + 10, "\033[0m");
		plot_point(can, x, y + 11, "\033[0m");
		plot_point(can, x, y + 12, "\033[0m");
		plot_point(can, x, y + 13, "\033[0m");
		char* r24932 = "0\0"; // 40
		char* r44932 = "0\0"; // 60
		char* r24992 = "0\0"; // 55
		char* r44992 = "0\0"; // 80
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r44932);
		plot_string(can, x + 1, y + 12, c2, r24992);
		plot_string(can, x + 1, y + 13, c2, r44992);

		//YELLOW
		plot_point(can, x, y + 15, "\033[0m");
		plot_point(can, x, y + 16, "\033[0m");
		plot_point(can, x, y + 17, "\033[0m");
		plot_point(can, x, y + 18, "\033[0m");
		char* r24933 = "0\0"; // 45
		char* r44933 = "0\0"; // 70
		char* r24993 = "0\0"; // 65
		char* r44993 = "0\0"; // 90
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r44933);
		plot_string(can, x + 1, y + 17, c2, r24993);
		plot_string(can, x + 1, y + 18, c2, r44993);

		//BLUE
		plot_point(can, x, y + 20, "\033[0m");
		plot_point(can, x, y + 21, "\033[0m");
		plot_point(can, x, y + 22, "\033[0m");
		plot_point(can, x, y + 23, "\033[0m");
		char* r24934 = "0\0"; // 25
		char* r44934 = "0\0"; // 40
		char* r24994 = "0\0"; // 40
		char* r44994 = "0\0"; // 60
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r44934);
		plot_string(can, x + 1, y + 22, c2, r24994);
		plot_string(can, x + 1, y + 23, c2, r44994);

		//PINK
		plot_point(can, x, y + 25, "\033[0m");
		plot_point(can, x, y + 26, "\033[0m");
		plot_point(can, x, y + 27, "\033[0m");
		plot_point(can, x, y + 28, "\033[0m");
		char* r24935 = "0\0"; // 25
		char* r44935 = "0\0"; // 40
		char* r24995 = "0\0"; // 40
		char* r44995 = "0\0"; // 60
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r44935);
		plot_string(can, x + 1, y + 27, c2, r24995);
		plot_string(can, x + 1, y + 28, c2, r44995);

		//CYAN
		plot_point(can, x, y + 30, "\033[0m");
		plot_point(can, x, y + 31, "\033[0m");
		plot_point(can, x, y + 32, "\033[0m");
		plot_point(can, x, y + 33, "\033[0m");
		char* r24936 = "0\0"; // 40
		char* r24996 = "0\0"; // 60
		char* r44936 = "0\0"; // 60
		char* r44996 = "0\0"; // 80
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24996);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44996);

		//WHITE
		plot_point(can, x, y + 35, "\033[0m");
		plot_point(can, x, y + 36, "\033[0m");
		plot_point(can, x, y + 37, "\033[0m");
		plot_point(can, x, y + 38, "\033[0m");
		char* r24937 = "0\0"; // 60
		char* r24997 = "0\0"; // 65
		char* r44937 = "0\0"; // 85
		char* r44997 = "0\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}

void plot_palette_rxvt (canvas* can, int x, int y) {

		char* label = "rxvt:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, "\033[m");
		plot_point(can, x, y + 6, "\033[0m");
		plot_point(can, x, y + 7, "\033[0m");
		plot_point(can, x, y + 8, "\033[0m");
		char* r24930 = "\0"; // 60
		char* r44930 = "0\0"; // 85
		char* r24990 = "0\0"; // 65
		char* r44990 = "0\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24930);
		plot_string(can, x + 1, y + 6, c2, r44930);
		plot_string(can, x + 1, y + 7, c2, r24990);
		plot_string(can, x + 1, y + 8, c2, r44990);

		//RED
		plot_point(can, x, y, "\033[0m");
		plot_point(can, x, y + 1, "\033[0m");
		plot_point(can, x, y + 2, "\033[0m");
		plot_point(can, x, y + 3, "\033[0m");
		char* r24931 = "0\0"; // 30
		char* r24991 = "0\0"; // 35
		char* r44931 = "0\0"; // 45
		char* r44991 = "0\0"; // 50
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r24991);
		plot_string(can, x + 1, y + 2, c2, r44931);
		plot_string(can, x + 1, y + 3, c2, r44991);

		//GREEN
		plot_point(can, x, y + 10, "\033[0m");
		plot_point(can, x, y + 11, "\033[0m");
		plot_point(can, x, y + 12, "\033[0m");
		plot_point(can, x, y + 13, "\033[0m");
		char* r24932 = "0\0"; // 40
		char* r24992 = "0\0"; // 55
		char* r44932 = "0\0"; // 60
		char* r44992 = "0\0"; // 80
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r24992);
		plot_string(can, x + 1, y + 12, c2, r44932);
		plot_string(can, x + 1, y + 13, c2, r44992);

		//YELLOW
		plot_point(can, x, y + 15, "\033[0m");
		plot_point(can, x, y + 16, "\033[0m");
		plot_point(can, x, y + 17, "\033[0m");
		plot_point(can, x, y + 18, "\033[0m");
		char* r24933 = "0\0"; // 45
		char* r24993 = "0\0"; // 65
		char* r44933 = "0\0"; // 70
		char* r44993 = "0\0"; // 90
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r24993);
		plot_string(can, x + 1, y + 17, c2, r44933);
		plot_string(can, x + 1, y + 18, c2, r44993);

		//BLUE
		plot_point(can, x, y + 20, "\033[0m");
		plot_point(can, x, y + 21, "\033[0m");
		plot_point(can, x, y + 22, "\033[0m");
		plot_point(can, x, y + 23, "\033[0m");
		char* r24934 = "0\0"; // 25
		char* r24994 = "0\0"; // 40
		char* r44934 = "0\0"; // 40
		char* r44994 = "0\0"; // 60
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r24994);
		plot_string(can, x + 1, y + 22, c2, r44934);
		plot_string(can, x + 1, y + 23, c2, r44994);

		//PINK
		plot_point(can, x, y + 25, "\033[0m");
		plot_point(can, x, y + 26, "\033[0m");
		plot_point(can, x, y + 27, "\033[0m");
		plot_point(can, x, y + 28, "\033[0m");
		char* r24935 = "0\0"; // 25
		char* r24995 = "0\0"; // 40
		char* r44935 = "0\0"; // 40
		char* r44995 = "0\0"; // 60
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r24995);
		plot_string(can, x + 1, y + 27, c2, r44935);
		plot_string(can, x + 1, y + 28, c2, r44995);

		//CYAN
		plot_point(can, x, y + 30, "\033[0m");
		plot_point(can, x, y + 31, "\033[0m");
		plot_point(can, x, y + 32, "\033[0m");
		plot_point(can, x, y + 33, "\033[0m");
		char* r24936 = "0\0"; // 40
		char* r24996 = "0\0"; // 60
		char* r44936 = "0\0"; // 60
		char* r44996 = "0\0"; // 80
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24996);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44996);

		//WHITE
		plot_point(can, x, y + 35, "\033[0m");
		plot_point(can, x, y + 36, "\033[0m");
		plot_point(can, x, y + 37, "\033[0m");
		plot_point(can, x, y + 38, "\033[0m");
		char* r24937 = "0\0"; // 60
		char* r24997 = "0\0"; // 65
		char* r44937 = "0\0"; // 85
		char* r44997 = "0\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}

void plot_palette_slrzd (canvas* can, int x, int y) {

		char* label = "slrzd:\0";
		plot_string(can, x, y + 40, c4, label);

		//GRAY
		plot_point(can, x, y + 5, "\033[0m");
		plot_point(can, x, y + 6, "\033[m");
		plot_point(can, x, y + 7, "\033[0m");
		plot_point(can, x, y + 8, "\033[0m");
		char* r24930 = "\0"; // 60
		char* r44930 = "0\0"; // 85
		char* r24990 = "0\0"; // 65
		char* r44990 = "0\0"; // 95
		plot_string(can, x + 1, y + 5, c2, r24990);
		plot_string(can, x + 1, y + 6, c2, r24930);
		plot_string(can, x + 1, y + 7, c2, r44990);
		plot_string(can, x + 1, y + 8, c2, r44930);

		//RED
		plot_point(can, x, y, "\033[0m");
		plot_point(can, x, y + 1, "\033[0m");
		plot_point(can, x, y + 2, "\033[0m");
		plot_point(can, x, y + 3, "\033[0m");
		char* r24931 = "0\0"; // 30
		char* r44931 = "0\0"; // 45
		plot_string(can, x + 1, y, c2, r24931);
		plot_string(can, x + 1, y + 1, c2, r24931);
		plot_string(can, x + 1, y + 2, c2, r44931);
		plot_string(can, x + 1, y + 3, c2, r44931);

		//GREEN
		plot_point(can, x, y + 10, "\033[0m");
		plot_point(can, x, y + 11, "\033[0m");
		plot_point(can, x, y + 12, "\033[0m");
		plot_point(can, x, y + 13, "\033[0m");
		char* r24932 = "0\0"; // 40
		char* r44932 = "0\0"; // 60
		plot_string(can, x + 1, y + 10, c2, r24932);
		plot_string(can, x + 1, y + 11, c2, r24932);
		plot_string(can, x + 1, y + 12, c2, r44932);
		plot_string(can, x + 1, y + 13, c2, r44932);

		//YELLOW
		plot_point(can, x, y + 15, "\033[0m");
		plot_point(can, x, y + 16, "\033[0m");
		plot_point(can, x, y + 17, "\033[0m");
		plot_point(can, x, y + 18, "\033[0m");
		char* r24933 = "0\0"; // 45
		char* r44933 = "0\0"; // 70
		plot_string(can, x + 1, y + 15, c2, r24933);
		plot_string(can, x + 1, y + 16, c2, r24933);
		plot_string(can, x + 1, y + 17, c2, r44933);
		plot_string(can, x + 1, y + 18, c2, r44933);

		//BLUE
		plot_point(can, x, y + 20, "\033[0m");
		plot_point(can, x, y + 21, "\033[0m");
		plot_point(can, x, y + 22, "\033[0m");
		plot_point(can, x, y + 23, "\033[0m");
		char* r24934 = "0\0"; // 25
		char* r44934 = "0\0"; // 40
		plot_string(can, x + 1, y + 20, c2, r24934);
		plot_string(can, x + 1, y + 21, c2, r24934);
		plot_string(can, x + 1, y + 22, c2, r44934);
		plot_string(can, x + 1, y + 23, c2, r44934);

		//PINK
		plot_point(can, x, y + 25, "\033[0m");
		plot_point(can, x, y + 26, "\033[0m");
		plot_point(can, x, y + 27, "\033[0m");
		plot_point(can, x, y + 28, "\033[0m");
		char* r24935 = "0\0"; // 25
		char* r44935 = "0\0"; // 40
		plot_string(can, x + 1, y + 25, c2, r24935);
		plot_string(can, x + 1, y + 26, c2, r24935);
		plot_string(can, x + 1, y + 27, c2, r44935);
		plot_string(can, x + 1, y + 28, c2, r44935);

		//CYAN
		plot_point(can, x, y + 30, "\033[0m");
		plot_point(can, x, y + 31, "\033[0m");
		plot_point(can, x, y + 32, "\033[0m");
		plot_point(can, x, y + 33, "\033[0m");
		char* r24936 = "0\0"; // 40
		char* r44936 = "0\0"; // 60
		plot_string(can, x + 1, y + 30, c2, r24936);
		plot_string(can, x + 1, y + 31, c2, r24936);
		plot_string(can, x + 1, y + 32, c2, r44936);
		plot_string(can, x + 1, y + 33, c2, r44936);

		//WHITE
		plot_point(can, x, y + 35, "\033[0m");
		plot_point(can, x, y + 36, "\033[0m");
		plot_point(can, x, y + 37, "\033[0m");
		plot_point(can, x, y + 38, "\033[0m");
		char* r24937 = "0\0"; // 60
		char* r24997 = "0\0"; // 65
		char* r44937 = "0\0"; // 85
		char* r44997 = "0\0"; // 95
		plot_string(can, x + 1, y + 35, c2, r24937);
		plot_string(can, x + 1, y + 36, c2, r24997);
		plot_string(can, x + 1, y + 37, c2, r44937);
		plot_string(can, x + 1, y + 38, c2, r44997);
}
*/
