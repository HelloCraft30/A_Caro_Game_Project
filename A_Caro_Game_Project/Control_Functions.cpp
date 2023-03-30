#include "Control_Functions.h"

using namespace std;

void getFormedWindow() {
	fixConsoleWindow();
	string str = "color XY";
	str[6] = '0' + COLOR_BG;
	str[7] = '0' + COLOR_TXT;
	system(str.c_str());
	resizeConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
	DisableSelection();
	removeScrollBar();
	Nocursortype();
	changeFont(FONT_SIZE);
}

void Display() {
	int display_id = 0;
}