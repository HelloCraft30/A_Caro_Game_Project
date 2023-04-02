#include "Control_Functions.h"
#include "View_Functions.h"

using namespace std;

SHORT _do_CMD_MAINMENU(SHORT cmd);

void get_BOARD_NAME(DATA& gameDat,BOARD& result, string Name) {
	for (int i = 0; i < gameDat.SAVEdatas.size(); i++) {
		if (Name == gameDat.SAVEdatas[i].name) {
			result = gameDat.SAVEdatas[i];
			return;
		}
	}
}

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
				return _do_CMD_MAINMENU(cmd);
				break;
			}
			show_SCREEN_MAINMENU(0, cmd);
		}
	}
	return 0;
}

SHORT display_SCREEN_GAME(DATA &gameDat,bool newGame,string gameName) {
	//maaybe transition
	system("cls");
	BOARD a;
	if (newGame) {
		new_GAME_BOARD(gameDat, a);
	}
	else {
		get_BOARD_NAME(gameDat, a, gameName);
	}
	system("cls");
	draw_BOARD(4, 2, 12, a.name);
	draw_POINTS(4, 2, a);
	show_TURN(61, 4, a.Turn);
	show_SCORE_X(61, 9, 1);
	show_SCORE_O(80, 9, 2);
	show_LASTMOVE(61, 15, { 1,2 ,'X' });
	show_GAME_HELP(57, 17);
	return 0;
}

void new_GAME_BOARD(DATA &gameDat,BOARD& a) {
	init_BOARD(a);
	show_GET_NAME();
	bool success = false;
	bool next = false;
	do {
		a.name = get_STRING(43, 12, 17);
		//linear search :|
		for (int i = 0; i < gameDat.SAVEnames.size(); i++) {
			if (gameDat.SAVEnames[i] == a.name) {
				SetColor(COLOR_BG, COLOR_RED);
				GoTo(43, 12); cout << "EXISTED NAME!"; Sleep(500);
				returnColor();
				next = true; break;
			}
		}
		if (next) {
			next = false; continue;
		}
		success = true;
	} while (!success);
}

SHORT _do_CMD_MAINMENU(SHORT cmd) {
	switch (cmd) {
	case 1:
		break;
	}
	return 0;
}

std::string get_STRING(SHORT x, SHORT y, int len) {
	string str;
	while (true) {
		while (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 127:
				if (str.size() != 0) str.pop_back();
				break;
			case 13:
				if (str.size() <= len) {
					GoTo(x, y);
					cout << str;
					for (int i = len - str.size(); i >= 0; i--) cout << " ";
				}
				else {
					GoTo(x, y);
					cout << "..";
					int n = str.size();
					for (int i = n - (len - 2); i <= n - 1; i++) {
						cout << str[i];
					}
				}
				return str;
				break;
			default:
				str.push_back(key);
				break;
			}

		}
		if (str.size() <= len) {
			GoTo(x, y);
			cout << str;
			for (int i = len - str.size(); i >= 0; i--) cout << " ";
		}
		else {
			GoTo(x, y);
			cout << "..";
			int n = str.size();
			for (int i = n - (len - 2); i <= n - 1; i++) {
				cout << str[i];
			}
		}
	}
	return str;
}