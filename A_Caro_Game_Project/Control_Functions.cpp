#include "Control_Functions.h"
#include "View_Functions.h"
#include "_draw_SHAPE.h"

using namespace std;

SHORT _do_CMD_MAINMENU(SHORT cmd);

SHORT _do_CMD_SUBMENU(BOARD& board, DATA& data, SHORT cmd, bool& newGame);

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
			_draw_transition();
			display_id = display_Screen_MainMenu(data);
			break;
		case 1:
			display_id = display_Screen_Game_pvp(data);
			break;
		case 2:
			display_id = display_Screen_Continue_Game(data, insSTR);
			break;
		case 3:
			display_id = display_Screen_HTP(data);
			break;
		case 4:
			display_id = display_Screen_About();
			break;
		case 5:
			display_id = display_Screen_Setting(data);
			break;
		case 6:
			display_id = display_Screen_Game_pvc(data);
			break;
		case 9:
			display_id = display_Screen_Game_pvp(data, false, insSTR);
			break;
		case 10:
			display_id = display_Screen_Game_pvc(data, false, insSTR);
			break;
		}
	}
}

SHORT display_Screen_MainMenu(DATA& gameData) {
	SHORT cmd = 1;
	bool ct_check = gameData.SAVEnames.size();
	int _size = 7;
	int _color = 1;
	_draw_shape_caro(4, 2, _color);
	_draw_shape_x_o(58, 5);
	show_Screen_MainMenu(0, cmd, ct_check, 0, 0);
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
				_draw_transition();
				return _do_CMD_MAINMENU(cmd);
				break;
			case ESC:
				selectSound3();
				system("cls");
				exit(0);
				break;
			}
			show_Screen_MainMenu(0, cmd, ct_check, 0, 0);
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

bool isDraw(const BOARD& a) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (a.points[i][j].c == 'N') return false;
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			show_Board_Cursor(i, j, a.points[i][j].c);
		}
	}

	return true;
}

SHORT display_Screen_Game_pvp(DATA& gameDat, bool newGame, const string& gameName) {

	if (newGame) {
		if (!display_Ask_Gameplay()) {
			system("cls");
			_draw_transition();
			return 6;
		}
		system("cls");
		_draw_transition();
	}
	//maaybe transition
	BOARD a;
	SHORT cur_X = 0, cur_Y = 0;
	a.gamePlay = 0;

	if (newGame) {
		if (build_New_Game(gameDat, a) == 0) return 0;
		else _draw_transition();
	}
	else {
		get_BOARD_NAME(gameDat, a, gameName);
	}
	system("cls");

	//CONTROL THE GAME
	show_Screen_Game(a);
	show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
	show_Game_LastMove(61, 15, a);
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
				show_Game_LastMove(61, 15, a);
				break;
			case BACKSPACE:
				selectSound3();
				sys_Undo(a, cur_X, cur_Y);
				draw_GridPoint(4, 2, a);
				show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
				show_Game_LastMove(61, 15, a);
				break;
			case ESC:
				selectSound3();
				if (display_Screen_SubMenu(a, gameDat,newGame)) {
					system("cls");
					return 0;
				}
				else {
					show_Screen_Game(a);
					show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
					show_Game_LastMove(61, 15, a);
				}
				break;
			default:
				break;
			}
			draw_GridPoint(4, 2, a);
			show_Game_Turn(61, 4, a.Turn);
			show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
			if (display_Screen_Result(a, cur_X, cur_Y)) {
				show_Game_Turn(61, 4, a.Turn); break;
			}
		}

	}

	return 0;
}

bool display_Screen_Result(BOARD& a, SHORT& cur_X, SHORT& cur_Y) {
	bool exit = false;
	switch (isWin(a, cur_X, cur_Y)) {
		//temp notice
	case 1:
		exit = true;
		Sleep(1000);
		system("cls");
		_draw_animation_win(-3, 10, _draw_shape_x_win);
		resetMatch(a);
		a.X_wins++;
		system("cls");
		show_Screen_Game(a);
		cur_X = 5;
		cur_Y = 5;
		show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
		break;
	case 2:
		exit = true;
		Sleep(1000);
		system("cls");
		_draw_animation_win(-3, 10, _draw_shape_o_win);
		resetMatch(a);
		a.O_wins++;
		system("cls");
		show_Screen_Game(a);
		cur_X = 5;
		cur_Y = 5;
		show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
		break;
	}
	if (isDraw(a)) {
		exit = true;
		Sleep(1000);
		system("cls");
		SetColor(COLOR_BG, COLOR_GREEN);
		_draw_animation_win(28, 8, _draw_shape_isdraw);
		reset_Color();
		resetMatch(a);
		system("cls");
		show_Screen_Game(a);
		cur_X = BOARD_SIZE/2;
		cur_Y = BOARD_SIZE / 2;
	}
	return exit;
}

SHORT display_Screen_Game_pvc(DATA& gameDat, bool newGame, const string& gameName) {
	BOARD a;
	SHORT cur_X = 5, cur_Y = 5;
	SHORT _x = 0, _y = 0;
	_POINT bot; create_Point(bot, 0, 0, 'N');
	if (newGame) {
		if (build_New_Game(gameDat, a) == 0) return 0;
		else _draw_transition();
	}
	else {
		get_BOARD_NAME(gameDat, a, gameName);
	}
	system("cls");
	a.gamePlay = 1;
	//CONTROL THE GAME
	show_Screen_Game(a);
	show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
	show_Game_LastMove(61, 15, a);
	SetColor(COLOR_BLUE, COLOR_BG); GoTo(80 - 2, 9); cout << "Computer's"; reset_Color();
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
				show_Game_LastMove(61, 15, a);
				break;
			case BACKSPACE:
				selectSound3();
				sys_Undo(a, cur_X, cur_Y);
				sys_Undo(a, cur_X, cur_Y);
				draw_GridPoint(4, 2, a);
				show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
				show_Game_LastMove(61, 15, a);
				break;
			case ESC:
				selectSound3();
				if (display_Screen_SubMenu(a, gameDat,newGame)) {
					system("cls");
					return 0;
				}
				else {
					show_Screen_Game(a);
					show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
					show_Game_LastMove(61, 15, a);
				}
				break;
			default:
				break;
			}
			draw_GridPoint(4, 2, a);
			show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
			if (display_Screen_Result(a, cur_X, cur_Y)) {
				show_Game_LastMove(61, 15, a); break;
			}
			if (a.Turn == 'O') {
				bot = computer_Turn(a);
				_x = bot.x; _y = bot.y;
				a.points[bot.y][bot.x].c = 'O';
				a.listOfMoves.push_back({ _x,_y,a.Turn });
				a.Turn = 'X';
				draw_RetangleSpace(78, 3, 8, 4);
				SetColor(COLOR_BG, COLOR_BLUE);
				_draw_shape_bot_face(75, 2);
				draw_GridPoint(4, 2, a);
				show_Board_Cursor(_x, _y, 'O');
				Sleep(300);
				draw_GridPoint(4, 2, a);
				reset_Color();
			}


			show_Board_Cursor(cur_X, cur_Y, a.points[cur_Y][cur_X].c);
			if (display_Screen_Result(a, _x, _y)) {
				cur_X = 5;
				cur_Y = 5;
				show_Game_LastMove(61, 15, a);
				break;
			}
			show_Game_Turn(61, 4, a.Turn);
		}


	}

	return 0;
}

SHORT display_Screen_SubMenu(BOARD& board, DATA& data, bool& newGame) {
	int cmd = 0;
	show_Screen_SubMenu(0, 0, cmd);
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
				return _do_CMD_SUBMENU(board, data, cmd, newGame);
				break;
			}
			show_Screen_SubMenu(0, 0, cmd);
		}

	}
}

SHORT display_Screen_Setting(DATA& gameData) {
	bool cmd = 0;
	bool a[2]{ 0 };
	a[cmd] = true;
	show_Speaker(gameData.mute);
	draw_Border_2line(5, 1, 83, 28);
	draw_Str(31, 26, "Press ESC to go back --");
	show_Screen_Setting(cmd, gameData);
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
						show_Speaker(gameData.mute); break;
					}
					else if (gameData.Vol == 1) {
						show_Speaker(true);
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
						show_Speaker(gameData.mute);
					}
					if (gameData.Vol == 22) break;
					else gameData.Vol++; break;
				}break;
			case ESC: selectSound2(); return 0;
			case ENTER:
				selectSound2();
				if (!cmd) {
					gameData.mute = !gameData.mute;
					show_Speaker(gameData.mute);
					if (gameData.mute) gameData.Vol = 0;
					else gameData.Vol = 1;
				}
				break;
			}
			a[cmd] = true;
			show_Setting_Mute(gameData.mute, a[0]);
			show_Setting_Volume(gameData.Vol, a[1]);
			a[0] = a[1] = 0;
			_do_CMD_SETTINGS(gameData);
		}
	}
	system("pause");
	return 0;
}

SHORT display_Screen_About() {
	show_Screen_About(0, 0);
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

SHORT build_New_Game(DATA& gameDat, BOARD& a) {
	init_Board(a);
	show_Get_Name();
	draw_Box(28, 24, 32, 3, '-');
	draw_Str(31, 25, "Press ESC to go back --");
	bool success = false;
	bool next = false;
	do {
		a.name = get_String(43, 14, 17);
		if (a.name == "########################################") return 0;
		//linear search :|
		for (int i = 0; i < gameDat.SAVEnames.size(); i++) {
			if (gameDat.SAVEnames[i] == a.name) {
				SetColor(COLOR_BG, COLOR_RED);
				GoTo(43, 14); cout << "EXISTED NAME!"; Sleep(1000);
				reset_Color();
				next = true; break;
			}
		}

		if (a.name.size() > 25) {
			SetColor(COLOR_BG, COLOR_RED);
			GoTo(43, 14); cout << "TOO LONG (< 25)! "; Sleep(1000);
			reset_Color();
			continue;
		}

		if (next) {
			next = false; continue;
		}
		success = true;
	} while (!success || a.name.size() == 0);
}

SHORT display_Screen_HTP(DATA& gameData) {
	show_Screen_HTP(0, 0);
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

std::string get_String(SHORT x, SHORT y, int len) {
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

SHORT isWin(const BOARD& a, SHORT x, SHORT y) {
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
			show_Board_Cursor(_x.first, _x.second, a.points[y][x].c);
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
			show_Board_Cursor(_x.first, _x.second, a.points[y][x].c);
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
			show_Board_Cursor(_x.first, _x.second, a.points[y][x].c);
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
			show_Board_Cursor(_x.first, _x.second, a.points[y][x].c);
		}
		return winTYPE;
	}
	return 0;
}

SHORT _do_CMD_SUBMENU(BOARD& board, DATA& data, SHORT cmd, bool& newGame) {
	switch (cmd) {
	case 0:
		//save game
		if (!save_Board_to_Data(data, board)) {
			SetColor(COLOR_RED, COLOR_BG);
			GoTo(65, 21); cout << " SAVEs LIMITED! ";
			reset_Color();
			Sleep(1000);
			return 0;
		};
		save_Board_to_File(board);
		save_Data_to_File(data);
		SetColor(COLOR_GREEN, COLOR_BG);
		GoTo(67, 21); cout << "   SAVED!   ";
		reset_Color();
		newGame = false;
		Sleep(1000);
		return 0;
	case 1:
		//settings
		system("cls");
		display_Screen_Setting(data);
		return 0;
	case 2:
		//quit
		if (newGame) {
			if (display_Ask_Save()) {
				if (!save_Board_to_Data(data, board)) {
					SetColor(COLOR_RED, COLOR_BG);
					GoTo(65, 21); cout << " SAVEs LIMITED! ";
					reset_Color();
					Sleep(500);
					return 0;
				};
				save_Board_to_File(board);
				save_Data_to_File(data);
			}
		}
		else {
			if (!save_Board_to_Data(data, board)) {
				SetColor(COLOR_RED, COLOR_BG);
				GoTo(65, 21); cout << " SAVEs LIMITED! ";
				reset_Color();
				Sleep(500);
				return 0;
			};
			save_Board_to_File(board);
			save_Data_to_File(data);
		}
		return 1;
	}
}

bool checkHeadStr(string a, string b) {
	if (a.size()>b.size()) return false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

SHORT display_Screen_Continue_Game(DATA& gameData, string& output) {
	system("cls");
	load_Data(gameData);
	int curBoard = 0;
	DATA showBoard = gameData;
	vector<BOARD> tmpB;
	vector<string> tmpN;
	string nameTyped;
	bool joinSearch = false;
	GoTo(65, 9); cout << " Search: ";
	bool color_search = false;
	show_Screen_ContinueGame(gameData.SAVEdatas[curBoard], gameData, curBoard, 0, 0);
	while (true) {
		int n = showBoard.SAVEdatas.size();
		if (nameTyped == "") showBoard = gameData;
		while (joinSearch) {
			bool do_sth = false;
			while (_kbhit()) {
				do_sth = true;
				char _chr = _getch();
				switch (_chr) {
				case ENTER: case ESC:
					GoTo(65, 9); cout << " Search:";
					joinSearch = false;
					break;
				case BACKSPACE:
					if(nameTyped.size()!=0) nameTyped.pop_back();
					GoTo(74, 9); cout << nameTyped;
					cout << (char)219; cout << ' ';
					break;
				default:
					nameTyped.push_back(_chr);
					break;
				}
				if (showBoard.SAVEnames.size() != 0) show_Screen_ContinueGame(showBoard.SAVEdatas[curBoard], showBoard, curBoard, 0, 0);
				else {
					draw_RetangleSpace(65, 13, 18, 9);
				}
			}
			if (do_sth) {
				GoTo(74, 9); cout << nameTyped;
				cout << (char)219;
				if (nameTyped == "") showBoard = gameData;
				else {
					for (int i = 0; i < gameData.SAVEnames.size(); i++) {
						GoTo(0, 0); cout << i;
						if (checkHeadStr(nameTyped, gameData.SAVEnames[i])) {

							bool _okay = true;
							for (auto x : tmpN) {
								if (x == gameData.SAVEnames[i]) {
									_okay = false;
								}
							}
							if (_okay) {
								tmpB.push_back(gameData.SAVEdatas[i]);
								tmpN.push_back(gameData.SAVEnames[i]);
							}
						}
					}
					showBoard.SAVEdatas = tmpB;
					showBoard.SAVEnames = tmpN;
					tmpB.clear();
					tmpN.clear();
				}
				if (showBoard.SAVEnames.size() != 0) show_Screen_ContinueGame(showBoard.SAVEdatas[curBoard], showBoard, curBoard, 0, 0);
				else {
					draw_RetangleSpace(65, 13, 18, 9);
				}
			}
		}
		GoTo(74, 9); cout << nameTyped << " ";
		while (_kbhit()) {
			switch (toupper(_getch())) {
			case 'A': case 75:
				if (showBoard.SAVEnames.size() == 0) continue;
				selectSound1();
				curBoard = (curBoard - 7 + n) % n;
				break;
			case 'W': case 72:
				if (showBoard.SAVEnames.size() == 0) continue;
				selectSound1();
				if (curBoard == 0) curBoard = n - 1;
				else curBoard--; break;
			case 'D': case 77:
				if (showBoard.SAVEnames.size() == 0) continue;
				selectSound1();
				curBoard = (curBoard + 7 + n) % n;
				break;
			case 'S': case 80:
				if (showBoard.SAVEnames.size() == 0) continue;
				selectSound1();
				if (curBoard == n - 1) curBoard = 0;
				else curBoard++; break;
			case ESC:
				selectSound2();
				return 0;
			case ENTER:
				if (showBoard.SAVEnames.size() == 0) continue;
				selectSound2();
				output = showBoard.SAVEdatas[curBoard].name;
				if (showBoard.SAVEdatas[curBoard].gamePlay == 0) return 9;
				if (showBoard.SAVEdatas[curBoard].gamePlay == 1) return 10;
			case BACKSPACE:
				if (showBoard.SAVEnames.size() == 0) continue;
				if (display_Ask_Delete()) {
					delete_Board_from_Game(gameData, showBoard.SAVEnames[curBoard]);
					delete_Board_from_Data(showBoard, showBoard.SAVEnames[curBoard]);
					if (!(gameData.SAVEdatas.size())) return 0;
					if (curBoard != 0) curBoard--;
				}
				system("cls");
				show_Screen_ContinueGame(showBoard.SAVEdatas[curBoard], showBoard, curBoard, 0, 0);
				GoTo(65, 9); cout << " Search:";
				break;
			case 'F':
				curBoard = 0;
				GoTo(74, 9); cout << nameTyped << (char)219;
				SetColor(COLOR_BG, COLOR_GREEN);
				GoTo(65, 9); cout << " Search:";
				reset_Color();
				joinSearch = true;
				continue;
			default:
				break;
			}
			show_Screen_ContinueGame(showBoard.SAVEdatas[curBoard], showBoard, curBoard, 0, 0);
		}
	}
	return 0;
}

BOOL display_Ask_Delete() {
	bool cmd = 0;
	show_Ask_Delete(0, 0, 0);
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
		show_Ask_Delete(0, 0, cmd);
	}
}

BOOL display_Ask_Gameplay() {
	bool cmd = 1;
	draw_Box(6, 1, 81, 27, '=');
	_draw_shape_vs(35, 15);
	show_Ask_Gameplay(32, 3, cmd);
	if (cmd) {
		SetColor(COLOR_BG, COLOR_BG);
		_draw_shape_robot(52, 10);
		SetColor(COLOR_BG, COLOR_RED);
		_draw_shape_human(11, 10);
		SetColor(COLOR_BG, COLOR_BLUE);
		_draw_shape_human(52, 10);
		reset_Color();
	}
	else {
		SetColor(COLOR_BG, COLOR_RED);
		_draw_shape_human(11, 10);
		SetColor(COLOR_BG, COLOR_BG);
		_draw_shape_human(52, 10);
		SetColor(COLOR_BG, COLOR_BLUE);
		_draw_shape_robot(52, 10);
		reset_Color();
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
			if (!cmd) display_Ask_Difficult();
			return cmd;
		}
		if (cmd) {
			SetColor(COLOR_BG, COLOR_BG);
			_draw_shape_robot(52, 10);
			SetColor(COLOR_BG, COLOR_RED);
			_draw_shape_human(11, 10);
			SetColor(COLOR_BG, COLOR_BLUE);
			_draw_shape_human(52, 10);
			reset_Color();
		}
		else {
			SetColor(COLOR_BG, COLOR_RED);
			_draw_shape_human(11, 10);
			SetColor(COLOR_BG, COLOR_BG);
			_draw_shape_human(52, 10);
			SetColor(COLOR_BG, COLOR_BLUE);
			_draw_shape_robot(52, 10);
			reset_Color();
		}
		show_Ask_Gameplay(32, 3, cmd);
	}
}

INT display_Ask_Difficult() {
	int cmd = 1;
	show_Ask_Difficult(29, 9, cmd);
	while (true) {
		switch (toupper(_getch())) {
		case 75: case 'A':
			if (cmd == 0) cmd = 2;
			else cmd--;
			break;
		case 77: case 'D':
			if (cmd == 2) cmd = 0;
			else cmd++;
			break;
		case ENTER:
			return cmd;
		}
		show_Ask_Difficult(29, 9, cmd);
	}
}

BOOL display_Ask_Save() {
	bool cmd = 0;
	show_Ask_Save(27, 12, cmd);
	while (true) {
		switch (toupper(_getch())) {
		case 'A': case 75:
		case 'D': case 77:
			cmd = !cmd;
			break;
		case ENTER:
			return cmd;
		case ESC:
			return 0;
		}
		show_Ask_Save(27, 12, cmd);
	}
}

void sys_Undo(BOARD& a, SHORT& curX, SHORT& curY) {
	if (a.listOfMoves.size() == 0) return;
	curX = a.listOfMoves[a.listOfMoves.size() - 1].x;
	curY = a.listOfMoves[a.listOfMoves.size() - 1].y;
	a.points[a.listOfMoves[a.listOfMoves.size() - 1].y][a.listOfMoves[a.listOfMoves.size() - 1].x].c = 'N';
	a.listOfMoves.pop_back();
	if (a.Turn == 'X') a.Turn = 'O';
	else a.Turn = 'X';

}