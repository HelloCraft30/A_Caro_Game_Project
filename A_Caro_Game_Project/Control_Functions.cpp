#include "Control_Functions.h"
#include "View_Functions.h"
#include "_draw_SHAPE.h"

using namespace std;

SHORT _do_CMD_MAINMENU(SHORT cmd);

SHORT _do_CMD_SUBMENU(BOARD& board, DATA& data, SHORT cmd);

SHORT _do_CMD_SETTINGS(DATA& data);

void resetMatch(BOARD& a) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			a.points[i][j].c = 'N';
		}
	}
	a.listOfMoves.resize(0);
}

void get_BOARD_NAME(DATA& gameDat, BOARD& result, string Name) {
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
	waveOutSetVolume(NULL, 1615 * 11);
}

void Display(DATA& data) {
	int display_id = 0;
	string insSTR;
	PlaySound(L"GAME_MUSICS\\music_BG.wav", NULL, SND_ASYNC | SND_LOOP);
	while (true) {
		system("cls");
		switch (display_id) {
		case 0:
			_TRANSITION();
			display_id = display_SCREEN_MAINMENU(data);
			break;
		case 1:
			display_id = display_SCREEN_GAME(data);
			break;
		case 2:
			display_id = display_SCREEN_CGAME(data, insSTR);
			break;
		case 3:
			display_id = display_SCREEN_HTP(data);
			break;
		case 4:
			display_id = display_SCREEN_ABOUT();
			break;
		case 5:
			display_id = display_SCREEN_SETTINGS(data);
			break;
		case 6:
			display_id = display_SCREEN_GAME_BOT(data);
			break;
		case 9:
			display_id = display_SCREEN_GAME(data, false, insSTR);
			break;
		case 10:
			display_id = display_SCREEN_GAME_BOT(data, false, insSTR);
			break;
		}
	}
}

SHORT display_SCREEN_MAINMENU(DATA& gameData) {
	SHORT cmd = 1;
	bool ct_check = gameData.SAVEnames.size();
	int _size = 7;
	int _color = 1;
	_draw_NAME_CARO(4, 2, _color);
	_draw_XO_SHAPE(58, 5);
	show_SCREEN_MAINMENU(0, cmd, ct_check, 0, 0);
	while (true) {
		while (_kbhit()) {
			switch (toupper(_getch())) {
			case 72: case 'W':
				selectSound1();
				if (cmd == 3 && !ct_check) {
					cmd = 1;
				}
				else if (cmd == 1) {
					cmd = 5;
				}
				else cmd--; break;
			case 80: case 'S':
				selectSound1();
				if (cmd == 1 && !ct_check) {
					cmd = 3;
				}
				else if (cmd == 5) {
					cmd = 1;
				}
				else cmd++; break;
			case ENTER:
				selectSound2();
				_TRANSITION();
				return _do_CMD_MAINMENU(cmd);
				break;
			case ESC:
				selectSound3();
				system("cls");
				exit(0);
				break;
			}
			show_SCREEN_MAINMENU(0, cmd, ct_check, 0, 0);
			break;
		}
		//_color = (_color + 1) % _size;
		////if (_color == 0) _color = 1;
		//_draw_NAME_CARO(4, 2, _color);
		//Sleep(70);
		//_draw_XO_SHAPE(58,5, _color%2);
		//Sleep(30);
	}
	return 0;
}

bool is_DRAW(const BOARD& a) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (a.points[i][j].c == 'N') return false;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			show_BOARD_CURSOR(i, j, a.points[i][j].c);
		}
	}

	return true;
}

SHORT display_SCREEN_GAME(DATA& gameDat, bool newGame, const string& gameName) {

	if (newGame) {
		if (!display_get_GAMEPLAY()) {
			system("cls");
			_TRANSITION();
			return 6;
		}
		system("cls");
		_TRANSITION();
	}
	//maaybe transition
	BOARD a;
	SHORT cur_X = 0, cur_Y = 0;
	a.gamePlay = 0;

	if (newGame) {
		if (new_GAME_BOARD(gameDat, a) == 0) return 0;
		else _TRANSITION();
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
				selectSound3();
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
				selectSound3();
				game_UNDO(a, cur_X, cur_Y);
				draw_POINTS(4, 2, a);
				show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
				show_LASTMOVE(61, 15, a);
				break;
			case ESC:
				selectSound3();
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
			if (checkResult(a, cur_X, cur_Y)) {
				show_TURN(61, 4, a.Turn); break;
			}
		}

	}

	return 0;
}

bool checkResult(BOARD& a, SHORT& cur_X, SHORT& cur_Y) {
	bool exit = false;
	switch (is_WIN(a, cur_X, cur_Y)) {
		//temp notice
	case 1:
		exit = true;
		Sleep(1000);
		system("cls");
		_draw_animation_win(-3, 10, _draw_XWIN_shape);
		resetMatch(a);
		a.X_wins++;
		system("cls");
		show_SCREEN_GAME(a);
		cur_X = 5;
		cur_Y = 5;
		show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
		break;
	case 2:
		exit = true;
		Sleep(1000);
		system("cls");
		_draw_animation_win(-3, 10, _draw_OWIN_shape);
		resetMatch(a);
		a.O_wins++;
		system("cls");
		show_SCREEN_GAME(a);
		cur_X = 5;
		cur_Y = 5;
		show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
		break;
	}
	if (is_DRAW(a)) {
		exit = true;
		Sleep(1000);
		system("cls");
		SetColor(COLOR_BG, COLOR_GREEN);
		_draw_animation_win(28, 8, _draw_DRAW_shape);
		returnColor();
		resetMatch(a);
		system("cls");
		show_SCREEN_GAME(a);
		cur_X = 5;
		cur_Y = 5;
	}
	return exit;
}

SHORT display_SCREEN_GAME_BOT(DATA& gameDat, bool newGame, const string& gameName) {
	BOARD a;
	SHORT cur_X = 5, cur_Y = 5;
	SHORT _x = 0, _y = 0;
	_POINT bot; setVal_POINT(bot, 0, 0, 'N');
	if (newGame) {
		if (new_GAME_BOARD(gameDat, a) == 0) return 0;
		else _TRANSITION();
	}
	else {
		get_BOARD_NAME(gameDat, a, gameName);
	}
	system("cls");
	a.gamePlay = 1;
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
				if (a.Turn == 'O') break;
				selectSound3();
				a.points[cur_Y][cur_X].c = 'X';
				a.listOfMoves.push_back({ cur_X,cur_Y,a.Turn });
				a.Turn = 'O';
				show_LASTMOVE(61, 15, a);
				break;
			case BACKSPACE:
				selectSound3();
				game_UNDO(a, cur_X, cur_Y);
				game_UNDO(a, cur_X, cur_Y);
				draw_POINTS(4, 2, a);
				show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
				show_LASTMOVE(61, 15, a);
				break;
			case ESC:
				selectSound3();
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
			show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
			if (checkResult(a, cur_X, cur_Y)) {
				show_LASTMOVE(61, 15, a); break;
			}
			if (a.Turn == 'O') {
				bot = computer_Turn(a);
				_x = bot.x; _y = bot.y;
				a.points[bot.y][bot.x].c = 'O';
				a.listOfMoves.push_back({ _x,_y,a.Turn });
				a.Turn = 'X';
				draw_RETANGLE_SPACE(78, 3, 8, 4);
				SetColor(COLOR_BG, COLOR_BLUE);
				_draw_BOT_face(75, 2);
				draw_POINTS(4, 2, a);
				show_BOARD_CURSOR(_x, _y, 'O');
				Sleep(300);
				draw_POINTS(4, 2, a);
				returnColor();
			}


			show_BOARD_CURSOR(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
			if (checkResult(a, _x, _y)) {
				cur_X = 5;
				cur_Y = 5;
				show_LASTMOVE(61, 15, a);
				break;
			}
			show_TURN(61, 4, a.Turn);
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
				selectSound1();
				if (cmd == 0) cmd = 2;
				else cmd--; break;
			case 80: case 'S':
				selectSound1();
				if (cmd == 2) cmd = 0;
				else cmd++; break;
			case ESC:
				selectSound1();
				return 0;
			case ENTER:
				selectSound2();
				return _do_CMD_SUBMENU(board, data, cmd);
				break;
			}
			show_SCREEN_SUBMENU(0, 0, cmd);
		}

	}
}

SHORT display_SCREEN_SETTINGS(DATA& gameData) {
	bool cmd = 0;
	bool a[2]{ 0 };
	a[cmd] = true;
	show_SPEAKER(gameData.mute);
	draw_BORDER_2line(5, 1, 83, 28);
	draw_TXT(31, 26, "Press ESC to go back --");
	show_SCREEN_SETTINGS(cmd, gameData);
	a[0] = a[1] = 0;
	while (true) {
		while (_kbhit()) {
			switch (toupper(_getch())) {
			case 72: case 'W':
			case 80: case 'S':
				cmd = !cmd;
				break;
			case 75: case 'A':
				if (cmd) {
					if (!gameData.mute && gameData.Vol == 1) gameData.mute = !gameData.mute;
					if (gameData.Vol == 0) {
						show_SPEAKER(gameData.mute); break;
					}
					else if (gameData.Vol == 1) {
						show_SPEAKER(true);
						gameData.Vol--;
					}
					else {
						gameData.Vol--; break;
					}
				}break;
			case 77: case 'D':
				if (cmd) {
					if (gameData.mute) {
						gameData.mute = !gameData.mute;
						show_SPEAKER(gameData.mute);
					}
					if (gameData.Vol == 22) break;
					else gameData.Vol++; break;
				}break;
			case ESC: selectSound2(); return 0;
			case ENTER:
				selectSound2();
				if (!cmd) {
					gameData.mute = !gameData.mute;
					show_SPEAKER(gameData.mute);
					if (gameData.mute) gameData.Vol = 0;
					else gameData.Vol = 1;
				}
				break;
			}
			a[cmd] = true;
			show_SETTINGS_MUTE(gameData.mute, a[0]);
			show_SETTINGS_VOLUME(gameData.Vol, a[1]);
			a[0] = a[1] = 0;
			_do_CMD_SETTINGS(gameData);
		}
	}
	system("pause");
	return 0;
}

SHORT display_SCREEN_ABOUT() {
	show_SCREEN_ABOUT(0, 0);
	while (true) {
		switch (_getch()) {
		case ESC:
			return 0;
		}
	}
}


SHORT _do_CMD_SETTINGS(DATA& data) {
	waveOutSetVolume(NULL, 1615 * data.Vol);
	return 0;
}

SHORT new_GAME_BOARD(DATA& gameDat, BOARD& a) {
	init_BOARD(a);
	show_GET_NAME();
	draw_BOX(28, 24, 32, 3, '-');
	draw_TXT(31, 25, "Press ESC to go back --");
	bool success = false;
	bool next = false;
	do {
		a.name = get_STRING(43, 14, 17);
		if (a.name == "########################################") return 0;
		//linear search :|
		for (int i = 0; i < gameDat.SAVEnames.size(); i++) {
			if (gameDat.SAVEnames[i] == a.name) {
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
	} while (!success || a.name.size() == 0);
}

SHORT display_SCREEN_HTP(DATA& gameData) {
	show_SCREEN_HTP(0, 0);
	while (true) {
		switch (_getch()) {
		case ESC:
			return 0;
		}
	}
}

SHORT _do_CMD_MAINMENU(SHORT cmd) {
	switch (cmd) {
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
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
				selectSound2();
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
				selectSound2();
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

SHORT is_WIN(const BOARD& a, SHORT x, SHORT y) {
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
	for (int _x = x + 1, _y = y + 1; _x < BOARD_SIZE && _y < BOARD_SIZE; _x++, _y++) {
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
	for (int _x = x - 1, _y = y + 1; _x >= 0 && _y < BOARD_SIZE; _x--, _y++) {
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

SHORT _do_CMD_SUBMENU(BOARD& board, DATA& data, SHORT cmd) {
	switch (cmd) {
	case 0:
		//save game
		save_BOARD_DATA(data, board);
		save_BOARD_FILE(board);
		save_DATA_FILE(data);
		SetColor(COLOR_GREEN, COLOR_BG);
		GoTo(67, 21); cout << "   SAVED!   ";
		returnColor();
		Sleep(300);
		return 0;
	case 1:
		//settings
		system("cls");
		display_SCREEN_SETTINGS(data);
		return 0;
	case 2:
		//quit
		return 1;
	}
}

SHORT display_SCREEN_CGAME(DATA& gameData, string& output) {
	system("cls");
	get_STUFFS(gameData);
	int n = gameData.SAVEdatas.size();
	int curBoard = 0;
	show_SCREEN_CGAME(gameData.SAVEdatas[curBoard], gameData, curBoard, 0, 0);
	while (true) {
		while (_kbhit()) {
			switch (toupper(_getch())) {
			case 'A': case 75:
			case 'W': case 72:
				selectSound1();
				if (curBoard == 0) curBoard = n - 1;
				else curBoard--; break;
			case 'D': case 77:
			case 'S': case 80:
				selectSound1();
				if (curBoard == n - 1) curBoard = 0;
				else curBoard++; break;
			case ESC:
				selectSound2();
				return 0;
			case ENTER:
				selectSound2();
				output = gameData.SAVEdatas[curBoard].name;
				if (gameData.SAVEdatas[curBoard].gamePlay == 0) return 9;
				if (gameData.SAVEdatas[curBoard].gamePlay == 1) return 10;
			case BACKSPACE:
				if (display_ASK_DEL()) {
					delete_BOARD(gameData, gameData.SAVEdatas[curBoard].name);
					if (!(gameData.SAVEdatas.size())) return 0;
					curBoard--;
				}
				system("cls");
			default:
				break;
			}
			show_SCREEN_CGAME(gameData.SAVEdatas[curBoard], gameData, curBoard, 0, 0);
		}
	}
	return 0;
}

BOOL display_ASK_DEL() {
	bool cmd = 0;
	show_ASK_DEL(0, 0, 0);
	while (true) {
		switch (toupper(_getch())) {
		case 75: case 'A':
			if (!cmd) cmd = 1;
			break;
		case 77: case 'D':
			if (cmd) cmd = 0;
			break;
		case ENTER:
			return cmd;
		}
		show_ASK_DEL(0, 0, cmd);
	}
}

BOOL display_get_GAMEPLAY() {
	bool cmd = 1;
	draw_BOX(6, 1, 81, 27, '=');
	show_ASK_GAMEPLAY(32, 3, cmd);
	if (cmd) {
		SetColor(COLOR_BG, COLOR_BG);
		_draw_ROBOT(46, 11);
		SetColor(COLOR_BG, COLOR_RED);
		_draw_HUMAN(11, 10);
		SetColor(COLOR_BG, COLOR_BLUE);
		_draw_HUMAN(46, 10);
		returnColor();
	}
	else {
		SetColor(COLOR_BG, COLOR_RED);
		_draw_HUMAN(11, 10);
		SetColor(COLOR_BG, COLOR_BG);
		_draw_HUMAN(46, 10);
		SetColor(COLOR_BG, COLOR_BLUE);
		_draw_ROBOT(46, 11);
		returnColor();
	}
	while (true) {
		switch (toupper(_getch())) {
		case 75: case 'A':
			if (!cmd) cmd = 1;
			break;
		case 77: case 'D':
			if (cmd) cmd = 0;
			break;
		case ENTER:
			return cmd;
		}
		if (cmd) {
			SetColor(COLOR_BG, COLOR_BG);
			_draw_ROBOT(46, 11);
			SetColor(COLOR_BG, COLOR_RED);
			_draw_HUMAN(11, 10);
			SetColor(COLOR_BG, COLOR_BLUE);
			_draw_HUMAN(46, 10);
			returnColor();
		}
		else {
			SetColor(COLOR_BG, COLOR_RED);
			_draw_HUMAN(11, 10);
			SetColor(COLOR_BG, COLOR_BG);
			_draw_HUMAN(46, 10);
			SetColor(COLOR_BG, COLOR_BLUE);
			_draw_ROBOT(46, 11);
			returnColor();
		}
		show_ASK_GAMEPLAY(32, 3, cmd);
	}
}

void game_UNDO(BOARD& a, SHORT& curX, SHORT& curY) {
	if (a.listOfMoves.size() == 0) return;
	curX = a.listOfMoves[a.listOfMoves.size() - 1].x;
	curY = a.listOfMoves[a.listOfMoves.size() - 1].y;
	a.points[a.listOfMoves[a.listOfMoves.size() - 1].y][a.listOfMoves[a.listOfMoves.size() - 1].x].c = 'N';
	a.listOfMoves.pop_back();
	if (a.Turn == 'X') a.Turn = 'O';
	else a.Turn = 'X';

}