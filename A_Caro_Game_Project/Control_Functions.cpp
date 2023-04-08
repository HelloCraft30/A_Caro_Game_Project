#include "Control_Functions.h"
#include "View_Functions.h"
#include "_draw_SHAPE.h"

using namespace std;

SHORT _do_CMD_MAINMENU(SHORT cmd);

SHORT _do_CMD_SUBMENU(BOARD& board,DATA& data,SHORT cmd);

void resetMatch(BOARD& a) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			a.points[i][j].c = 'N';
		}
	}
	a.listOfMoves.resize(0);
}

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
	//DisableSelection();
	removeScrollBar();
	Nocursortype();
	changeFont(FONT_SIZE);
}

void Display(DATA& data) {
	int display_id = 0;
	string insSTR;
	while (true) {
		system("cls");
		switch (display_id) {
		case 0:
			display_id = display_SCREEN_MAINMENU();
			break;
		case 1:
			display_id = display_SCREEN_GAME(data);
			break;
		case 2:
			display_id = display_SCREEN_CGAME(data, insSTR);
			break;
		case 9:
			display_id = display_SCREEN_GAME(data, false, insSTR);
		}
	}
}

SHORT display_SCREEN_MAINMENU() {
	SHORT cmd = 1;
	show_SCREEN_MAINMENU(0, cmd);
	while (true) {
		while (_kbhit()) {
			switch (toupper(_getch())) {
			case 72: case 'W':
				if (cmd == 1) {
					cmd = 5;
				}
				else cmd--; break;
			case 80: case 'S':
				if (cmd == 5) {
					cmd = 1;
				}
				else cmd++; break;
			case ENTER:
				return _do_CMD_MAINMENU(cmd);
				break;
			case ESC:
				system("cls");
				exit(0);
				break;
			}
			show_SCREEN_MAINMENU(0, cmd);
		}
	}
	return 0;
}

SHORT display_SCREEN_GAME(DATA &gameDat,bool newGame,string gameName) {
	//maaybe transition
	BOARD a;
	SHORT cur_X = 0, cur_Y = 0;

	if (newGame) {
		system("cls");
		if(new_GAME_BOARD(gameDat, a)==0) return 0;
	}
	else {
		get_BOARD_NAME(gameDat, a, gameName);
	}
	system("cls");

	//CONTROL THE GAME
	show_SCREEN_GAME(a);
	show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
	show_LASTMOVE(61, 15, a);
	while (true) {
		while (_kbhit()) {
			char key = toupper(_getch());
			switch (key) {
			case 72: case 'W':
				if (cur_Y == 0) cur_Y = BOARD_SIZE - 1;
				else cur_Y--;
				break;
			case 80: case 'S':
				if (cur_Y == BOARD_SIZE - 1) cur_Y = 0;
				else cur_Y++;
				break;
			case 75: case 'A':
				if (cur_X == 0) cur_X = BOARD_SIZE - 1;
				else cur_X--;
				break;
			case 77: case 'D':
				if (cur_X == BOARD_SIZE - 1) cur_X = 0;
				else cur_X++;
				break;
			case ENTER:
				if (a.points[cur_Y][cur_X].c == 'X' || a.points[cur_Y][cur_X].c == 'O') break;
				{
					a.points[cur_Y][cur_X].c = a.Turn;
					a.listOfMoves.push_back({ cur_X,cur_Y,a.Turn });
				}
				if (a.Turn == 'X') a.Turn = 'O';
				else a.Turn = 'X';
				show_LASTMOVE(61, 15, a);
				break;
			case BACKSPACE:
				game_UNDO(a, cur_X, cur_Y);
				draw_POINTS(4, 2, a);
				show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
				show_LASTMOVE(61, 15, a);
				break;
			case ESC:
				if (display_SCREEN_SUBMENU(a, gameDat)) {
					system("cls");
					return 0;
				}
				else {
					show_SCREEN_GAME(a);
					show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
					show_LASTMOVE(61, 15, a);
				}
				break;
			default:
				break;
			}
			draw_POINTS(4, 2, a);
			show_TURN(61, 4, a.Turn);
			show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
			switch (is_WIN(a, cur_X, cur_Y)) {
				//temp notice
			case 1:
				Sleep(1000);
				system("cls");
				_draw_animation_win(9, 7, _draw_XWIN_shape);
				resetMatch(a);
				a.X_wins++;
				system("cls");
				show_SCREEN_GAME(a);
				cur_X = 0;
				cur_Y = 0;
				show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
				break;
			case 2:
				Sleep(1000);
				system("cls");
				_draw_animation_win(9, 7, _draw_OWIN_shape);
				resetMatch(a);
				a.O_wins++;
				system("cls");
				show_SCREEN_GAME(a);
				cur_X = 0;
				cur_Y = 0;
				break;
			}

		}
		
	}

	return 0;
}

SHORT display_SCREEN_SUBMENU(BOARD& board, DATA& data) {
	int cmd = 0;
	show_SCREEN_SUBMENU(0, 0, cmd);
	char key = ' ';
	while (true) {
		while (_kbhit()) {
			switch (toupper(_getch())) {
			case 72: case 'W':
				if (cmd == 0) cmd = 2;
				else cmd--; break;
			case 80: case 'S':
				if (cmd == 2) cmd = 0;
				else cmd++; break;
			case ESC:
				return 0;
			case ENTER:
				return _do_CMD_SUBMENU(board, data, cmd);
				break;
			}
			show_SCREEN_SUBMENU(0, 0, cmd);
		}
		
	}
}

SHORT new_GAME_BOARD(DATA &gameDat,BOARD& a) {
	init_BOARD(a);
	show_GET_NAME();
	draw_TXT(3, 28, "Press ESC to go back!");
	bool success = false;
	bool next = false;
	do {
		a.name = get_STRING(43, 14, 17);
		if (a.name == "########################################") return 0;
		//linear search :|
		for (int i = 0; i < gameDat.SAVEnames.size(); i++) {
			if (gameDat.SAVEnames[i] == a.name ) {
				SetColor(COLOR_BG, COLOR_RED);
				GoTo(43, 14); cout << "EXISTED NAME!"; Sleep(500);
				returnColor();
				next = true; break;
			}
		}

		if (a.name.size() > 25) {
			SetColor(COLOR_BG, COLOR_RED);
			GoTo(43, 14); cout << "TOO LONG (< 25)! "; Sleep(500);
			returnColor();
			continue;
		}

		if (next) {
			next = false; continue;
		}
		success = true;
	} while (!success || a.name.size()==0);
}

SHORT _do_CMD_MAINMENU(SHORT cmd) {
	switch (cmd) {
	case 1:
		return 1;
	case 2:
		return 2;
	}
	return 0;
}

std::string get_STRING(SHORT x, SHORT y, int len) {
	string str;
	while (true) {
		while (_kbhit()) {
			char key = _getch();
			switch (key) {
			case BACKSPACE:
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
			case ESC:
				return "########################################";
			default:
				str.push_back(key);
				break;
			}

		}
		if (str.size() <= len) {
			GoTo(x, y);
			cout << str << (char)219;
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

SHORT is_WIN(BOARD a, SHORT x, SHORT y) {
	vector<pair<int, int>> list;
	SHORT winTYPE = (a.points[y][x].c == 'X' ? 1 : 2);
	if (a.points[y][x].c != 'X' && a.points[y][x].c != 'O') return 0;
	int count = 0; //5: win, i dunt check if it was blocked
	//Horizon
	for (int i = x; i >= 0; i--) {
		if (a.points[y][i].c == a.points[y][x].c) {
			count++;
			list.push_back({ i, y });
		}
		else break;
	}
	for (int i = x + 1; i < BOARD_SIZE; i++) {
		if (a.points[y][i].c == a.points[y][x].c) {
			count++;
			list.push_back({ i, y });
		}
		else break;
	}
	if (count >= 5) {
		for (auto _x : list) {
			show_BOARD_CURSOR(_x.first, _x.second, a.points[y][x].c);
		}
		return winTYPE;
	}
	else {
		count = 0;
		list.resize(0);
	}
	//Vertical
	for (int i = x; i >= 0; i--) {
		if (a.points[i][x].c == a.points[y][x].c) {
			count++;
			list.push_back({ x,i });
		}
		else break;
	}
	for (int i = x + 1; i < BOARD_SIZE; i++) {
		if (a.points[i][x].c == a.points[y][x].c) {
			count++;
			list.push_back({ x,i });
		}
		else break;
	}
	if (count >= 5) {
		for (auto _x : list) {
			show_BOARD_CURSOR(_x.first, _x.second, a.points[y][x].c);
		}
		return winTYPE;
	}
	else {
		count = 0; list.resize(0);
	}
	//diagonal
	for (int _x = x, _y = y; _x >= 0 && _y >= 0; _x--, _y--) {
		if (a.points[_y][_x].c == a.points[y][x].c) {
			count++;
			list.push_back({ _x,_y });
		}
		else break;
	}
	for (int _x = x+1, _y = y+1; _x <BOARD_SIZE && _y < BOARD_SIZE; _x++, _y++) {
		if (a.points[_y][_x].c == a.points[y][x].c) {
			count++;
			list.push_back({ _x,_y });
		}
		else break;
	}
	if (count >= 5) {
		for (auto _x : list) {
			show_BOARD_CURSOR(_x.first, _x.second, a.points[y][x].c);
		}
		return winTYPE;
	}
	else {
		count = 0;
		list.resize(0);
	}
	//oposite diagonal
	for (int _x = x, _y = y; _x < BOARD_SIZE && _y >= 0; _x++, _y--) {
		if (a.points[_y][_x].c == a.points[y][x].c) {
			list.push_back({ _x,_y });
			count++;
		}
		else break;
	}
	for (int _x = x - 1, _y = y + 1; _x >=0 && _y < BOARD_SIZE; _x--, _y++) {
		if (a.points[_y][_x].c == a.points[y][x].c) {
			list.push_back({ _x,_y });
			count++;
		}
		else break;
	}
	if (count >= 5) {
		for (auto _x : list) {
			show_BOARD_CURSOR(_x.first, _x.second, a.points[y][x].c);
		}
		return winTYPE;
	}
	return 0;
}

SHORT _do_CMD_SUBMENU(BOARD& board,DATA& data,SHORT cmd) {
	switch (cmd) {
	case 0:
		//save game
		save_BOARD_DATA(data, board);
		save_BOARD_FILE(board);
		save_DATA_FILE(data);
		SetColor(COLOR_GREEN, COLOR_BG);
		GoTo(67, 21); cout << "   SAVED!   ";
		returnColor();
		Sleep(1000);
		return 0;
	case 1:
		//settings
	case 2:
		//quit
		return 1;
	}
}

SHORT display_SCREEN_CGAME(DATA& gameData, string& output) {
	system("cls");
	get_STUFFS(gameData);
	if (gameData.SAVEnames.size() == 0) {
		GoTo(1, 1); cout << "ERROR: NO DATA"; _getch(); return 0;
	}
	int n = gameData.SAVEdatas.size();
	int curBoard = 0;
	show_SCREEN_CGAME(gameData.SAVEdatas[curBoard]);
	while (true) {
		while (_kbhit()) {
			char key = _getch();
			if (isalpha(key)) key = toupper(key);
			switch (key) {
			case 'A':
				if (curBoard == 0) curBoard = n - 1;
				else curBoard--; break;
			case 'D':
				if (curBoard == n - 1) curBoard = 0;
				else curBoard++; break;
			case ESC:
				return 0;
			case ENTER:
				output = gameData.SAVEdatas[curBoard].name;
				return 9;
			default:
				break;
			}
			show_SCREEN_CGAME(gameData.SAVEdatas[curBoard]);
		}
	}
	return 0;
}

void game_UNDO(BOARD& a, SHORT &curX, SHORT &curY) {
	if (a.listOfMoves.size() == 0 ) return;
	curX = a.listOfMoves[a.listOfMoves.size() - 1].x;
	curY = a.listOfMoves[a.listOfMoves.size() - 1].y;
	a.points[a.listOfMoves[a.listOfMoves.size() - 1].y][a.listOfMoves[a.listOfMoves.size() - 1].x].c = 'N';
	a.listOfMoves.pop_back();
	if (a.Turn == 'X') a.Turn = 'O';
	else a.Turn = 'X';

}