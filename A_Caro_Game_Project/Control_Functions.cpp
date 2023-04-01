#include "Control_Functions.h"
#include "View_Functions.h"

using namespace std;

void getFormedWindow() {
	fixConsoleWindow();
	string str = "color XY";
	str[6] = (COLOR_BG > 10 ? 'F' : '0' + COLOR_BG);
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

SHORT display_SCREEN_MAINMENU() {
	SHORT cmd = 1;
	show_SCREEN_MAINMENU(0, cmd);
	while (true) {
		while (_kbhit()) {
			switch (_getch()) {
			case 'W':
			case 'w':
			case key_Up:
				if (cmd == 1) {
					cmd = 5;
				}
				else cmd--; break;
			case 'S':
			case 's':
			case key_Down:
				if (cmd == 5) {
					cmd = 1;
				}
				else cmd++; break;
			case ENTER:
				break;
			}
			show_SCREEN_MAINMENU(0, cmd);
		}
	}
	return 0;
}

SHORT display_SCREEN_GAME() {
	BOARD a;
	init_BOARD(a);
	draw_BOARD(4, 2, 12, "NGUYEN LAN ");
	draw_POINTS(4, 2, a);
	show_TURN(61, 4, 'X');
	show_SCORE_X(61, 9, 1);
	show_SCORE_O(80, 9, 2);
	show_LASTMOVE(61, 15, { 1,2 ,'X' });
	show_GAME_HELP(57, 17);
	return 0;
}