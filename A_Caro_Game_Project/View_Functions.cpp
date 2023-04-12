#include "View_Functions.h"
#include "_draw_SHAPE.h"

using namespace std;

// _draw functions are made with tool
// and this tool was created by myself xD

void _draw_Screen_Border() {
	draw_BORDER_2line(0, 0, 93, 30);
}

SHORT getRandomColor() {
	SHORT hold = (rand() % 8);
	if (hold == COLOR_BG) hold = getRandomColor();
	return hold;
}

void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void removeScrollBar()
{
	SetConsoleTitle(L"Serial Key");

	try {
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(console, &csbi);
		COORD scrollbar = {
			csbi.srWindow.Right - csbi.srWindow.Left + 1,
			csbi.srWindow.Bottom - csbi.srWindow.Top + 1
		};

		if (console == 0) {
			throw 0;
		}
		else {
			SetConsoleScreenBufferSize(console, scrollbar);
		}
	}
	catch (...) {
		std::cerr << "Error removing scrollbar" << std::endl;
	}
}
void changeFont(int x)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = x;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void returnColor() {
	SetColor(COLOR_BG, COLOR_TXT);
}
void draw_BORDER_1line(SHORT posX, SHORT posY, int width, int height, int COLOR) {
	GoTo(posX, posY);
	SetColor(COLOR_BG, COLOR);
	cout << LINE1_LEFT_TOP;
	for (int i = 2; i < width; i++) cout << LINE1_H;
	cout << LINE1_RIGHT_TOP;
	for (int i = 1; i < height - 1; i++) {
		GoTo(posX, posY + i);
		cout << LINE1_V;
		GoTo(posX + width - 1, posY + i);
		cout << LINE1_V;
	}
	GoTo(posX, posY + height - 1);
	cout << LINE1_LEFT_BOT;
	for (int i = 2; i < width; i++) cout << LINE1_H;
	cout << LINE1_RIGHT_BOT;
	returnColor();

}
void draw_BORDER_2line(SHORT posX, SHORT posY, int width, int height, int COLOR) {
	GoTo(posX, posY);
	SetColor(COLOR_BG, COLOR);
	cout << LINE2_LEFT_TOP;
	for (int i = 2; i < width; i++) cout << LINE2_H;
	cout << LINE2_RIGHT_TOP;
	for (int i = 1; i < height - 1; i++) {
		GoTo(posX, posY + i);
		cout << LINE2_V;
		GoTo(posX + width - 1, posY + i);
		cout << LINE2_V;
	}
	GoTo(posX, posY + height - 1);
	cout << LINE2_LEFT_BOT;
	for (int i = 2; i < width; i++) cout << LINE2_H;
	cout << LINE2_RIGHT_BOT;
	returnColor();
}
void draw_RETANGLE_SPACE(SHORT posX, SHORT posY, int width, int height, int COLOR, bool SHADOW) {
	SetColor(COLOR, COLOR);
	for (int i = 0; i < height; i++) {
		GoTo(posX, posY + i);
		for (int j = 0; j < width; j++) {
			cout << ' ';
		}
	}
	SetColor(COLOR_BG, COLOR_GRAY);
	if (SHADOW) {
		for (int i = 0; i < height; i++) {
			GoTo(posX - 2, posY + i);
			cout << BLUR2 << BLUR3;
			GoTo(posX + width, posY + i);
			cout << BLUR3 << BLUR2;
		}

	}
	returnColor();
}
void draw_BOX(SHORT posX, SHORT posY, int width, int height, char type, int COLOR_bg, int COLOR_txt) {
	if (type == '-') {
		draw_BORDER_1line(posX, posY, width, height, COLOR_txt);
		draw_RETANGLE_SPACE(posX + 1, posY + 1, width - 2, height - 2, COLOR_bg);
	}
	else if (type == '=') {
		draw_BORDER_2line(posX, posY, width, height, COLOR_txt);
		draw_RETANGLE_SPACE(posX + 1, posY + 1, width - 2, height - 2, COLOR_bg);
	}
}
void draw_BOARD(SHORT posX, SHORT posY, int sizeBoard, string nameBoard) {
	GoTo(posX, posY);
	cout << LINE2_LEFT_TOP;
	for (int i = 0; i < sizeBoard - 1; i++) {
		cout << LINE2_H << LINE2_H << LINE2_H << LINE2_H_TOP;
	}
	cout << LINE2_H << LINE2_H << LINE2_H << LINE2_RIGHT_TOP;
	for (int i = 1; i < sizeBoard * 2 - 2; i += 2) {
		GoTo(posX, posY + i);
		cout << LINE2_V;
		for (int j = 0; j < sizeBoard; j++) {
			cout << "   " << LINE2_V;
		}
		GoTo(posX, posY + i + 1);
		cout << LINE2_V_LEFT;
		for (int j = 0; j < sizeBoard - 1; j++) {
			cout << LINE2_H << LINE2_H << LINE2_H << LINE2_MIDDLE;
		}
		cout << LINE2_H << LINE2_H << LINE2_H << LINE2_V_RIGHT;
	}
	GoTo(posX, posY + sizeBoard * 2 - 1);
	cout << LINE2_V;
	for (int j = 0; j < sizeBoard; j++) {
		cout << "   " << LINE2_V;
	}
	GoTo(posX, posY + sizeBoard * 2);
	cout << LINE2_LEFT_BOT;
	for (int i = 0; i < sizeBoard - 1; i++) {
		cout << LINE2_H << LINE2_H << LINE2_H << LINE2_H_BOT;
	}
	cout << LINE2_H << LINE2_H << LINE2_H << LINE2_RIGHT_BOT;
	GoTo(posX, posY - 1);
	SetColor(COLOR_BLACK, COLOR_BG);
	cout << BLUR3 << BLUR2 << BLUR1 << " BOARD NAME: ";
	returnColor(); cout << ' ';
	if (nameBoard.size() > 25) {
		nameBoard.resize(25); nameBoard += "...  ";
	}
	cout << nameBoard;
	GoTo(posX + 63, posY + 25);
	SetColor(COLOR_GRAY, COLOR_BG);
	cout << BLUR3 << BLUR2 << BLUR1 << " Caro game ver " << VERSION << " ";
	returnColor();
}
void draw_POINT(const _POINT& point) {
	switch (point.c) {
	case 'X':
		SetColor(COLOR_BG, COLOR_RED);
		cout << " X ";
		returnColor();
		break;
	case 'O':
		SetColor(COLOR_BG, COLOR_BLUE);
		cout << " O ";
		returnColor();
		break;
	default:
		cout << "   ";
		break;
	}
}
void draw_POINTS(SHORT posX, SHORT posY, const BOARD& matrix) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			GoTo(posX + X_OFFSET + j * POINT_DIST_X, posY + Y_OFFSET + i * POINT_DIST_Y);
			draw_POINT(matrix.points[i][j]);
		}
	}

}

void draw_Grid_XO() {
	SHORT _x = 6, _y = 1;
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 10; j++) {
			GoTo(_x + i * 6, _y + j * 3); if ((i + j) % 2) {
				cout << 'X';
			}
			else cout << 'O';
		}
	}
}

void draw_TXT(SHORT posX, SHORT posY, const string& str) {
	GoTo(posX, posY);
	cout << "-- " << str;
}

void show_ASK_DEL(SHORT x, SHORT y,BOOL check) {
	draw_BOX(62, 21, 24, 5, '-');
	GoTo(67,22); cout << "Are you sure?";
	GoTo(66, 23); for (int i = 0; i < 16; i++) cout << LINE1_H;
	if (check) SetColor(COLOR_BLACK, COLOR_BG);
	GoTo(66, 24); cout << " YES ";
	returnColor();
	if (!check) SetColor(COLOR_BLACK, COLOR_BG);
	GoTo(77, 24); cout << " NO ";
	returnColor();
}

void draw_STR_limit(SHORT x, SHORT y, string str, int len) {
	GoTo(x, y);
	if (str.size() > len) {
		string temp = str;
		temp.resize(len - 2);
		cout << temp << "..";
	}
	else cout << str;
}

void show_TURN(SHORT posX, SHORT posY, char turn) {

	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, (turn == 'X' ? COLOR_RED : COLOR_BLUE), true);
	SetColor((turn == 'X' ? COLOR_RED : COLOR_BLUE), COLOR_BG);
	GoTo(posX, posY); cout << "CURRENT";
	GoTo(posX + 1, posY + 1); cout << "TURN:";

	int _posX = posX + 17, _posY = posY - 4;

	if (turn == 'X') {
		draw_RETANGLE_SPACE(_posX - 1, _posY + 2, 13, 6);
		SetColor(COLOR_BG, 12);
		_draw_X_shape(_posX, _posY + 2);
	}
	else {
		draw_RETANGLE_SPACE(_posX - 1, _posY + 2, 13, 6);
		SetColor(COLOR_BG, 9);
		_draw_O_shape(_posX + 1, _posY + 2);
	}
	draw_BORDER_2line(_posX - 2, _posY + 2, 13, 6);
	returnColor();
}
void show_SCORE_X(SHORT posX, SHORT posY, int score) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, COLOR_RED, true);
	SetColor(COLOR_RED, COLOR_BG);
	GoTo(posX - 2, posY); cout << "X player's";
	GoTo(posX + 1, posY + 1); cout << "SCORE: ";
	returnColor();
	GoTo(posX + 2, posY + 3); cout << score;
	draw_BORDER_1line(posX - 4, posY + 2, 14, 3);
}
void show_SCORE_O(SHORT posX, SHORT posY, int score) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, COLOR_BLUE, true);
	SetColor(COLOR_BLUE, COLOR_BG);
	GoTo(posX - 2, posY); cout << "O player's";
	GoTo(posX + 1, posY + 1); cout << "SCORE: ";
	returnColor();
	GoTo(posX + 2, posY + 3); cout << score;
	draw_BORDER_1line(posX - 4, posY + 2, 14, 3);
}
void show_LASTMOVE(SHORT posX, SHORT posY, const BOARD& board) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 1, COLOR_AQUA, TRUE);
	int n = board.listOfMoves.size();
	if (n) {
		SetColor(COLOR_AQUA, COLOR_BG);
		GoTo(posX - 2, posY); cout << "Last move: ";
		returnColor();
		GoTo(posX + 14, posY); cout << "                  ";
		GoTo(posX + 14, posY); cout << board.listOfMoves[n - 1].c;
		cout << ": [" << board.listOfMoves[n - 1].x << "] - [";
		cout << board.listOfMoves[n - 1].y << "]";
	}
	else {
		SetColor(COLOR_AQUA, COLOR_BG);
		GoTo(posX - 2, posY); cout << "Last move: "; returnColor();
		GoTo(posX + 14, posY); cout << "                  ";
		GoTo(posX + 14, posY); cout << "nothing here";
	}

}
void show_GAME_HELP(SHORT posX, SHORT posY) {
	draw_BORDER_2line(posX, posY, 33, 10);
	GoTo(posX + 3, posY + 2);
	cout << "1. WASD or " << (char)273 << ' ' << (char)286 << ' ' << (char)287 << ' ' << (char)272 << " to move.";
	GoTo(posX + 3, posY + 3);
	cout << "2. [ENTER] to tick your TURN.";
	GoTo(posX + 3, posY + 4);
	cout << "3. [ESCAPE] to open menu.";
	GoTo(posX + 3, posY + 5);
	SetColor(COLOR_BG, COLOR_GRAY);
	cout << "   (Quit, Save, Load Game)";
	returnColor();
	GoTo(posX + 3, posY + 6);
	cout << "4. [BACKSPACE] to undo.";
	GoTo(posX + 11, posY + 8);
	cout << "--Enjoy!--";
}
void show_SCREEN_MAINMENU(SHORT color, SHORT cmd, bool continue_check, SHORT _x, SHORT _y) {

	SetColor(COLOR_BG, color);
	_draw_NAME_CARO(4, 2);
	SetColor(COLOR_BG, COLOR_TXT);

	draw_TXT(29, 28, "Press ESC to QUIT the game --");
	//draw options
	SHORT op_x = 52, op_y = 16;
	int a[6]{};
	int b[6]{ 15,15,15,15,15,15 };
	a[cmd] = COLOR_YELLOW;
	b[cmd] = 15;
	if (!continue_check) a[2] = COLOR_GRAY;
	//option 1: NEW GAME
	draw_RETANGLE_SPACE(op_x, op_y, 17, 1, a[1], true);
	SetColor(a[1], b[1]);
	GoTo(op_x + 5, op_y); cout << "NEW GAME";
	//option 2: CONTINUE GAME
	draw_RETANGLE_SPACE(op_x, op_y + 2, 17, 1, a[2], true);
	SetColor(a[2], b[2]);
	GoTo(op_x + 2, op_y + 2); cout << "CONTINUE GAME";
	//option 3: HOW TO PLAY
	draw_RETANGLE_SPACE(op_x, op_y + 4, 17, 1, a[3], true);
	SetColor(a[3], b[3]);
	GoTo(op_x + 3, op_y + 4); cout << "HOW TO PLAY";
	//option 4: ABOUT
	draw_RETANGLE_SPACE(op_x, op_y + 6, 17, 1, a[4], true);
	SetColor(a[4], b[4]);
	GoTo(op_x + 6, op_y + 6); cout << "ABOUT";
	//option 6: QUIT
	draw_RETANGLE_SPACE(op_x, op_y + 8, 17, 1, a[5], true);
	SetColor(a[5], b[5]);
	GoTo(op_x + 5, op_y + 8); cout << "SETTINGS";
	returnColor();

	_draw_MY_BOY(5, 13);
	draw_BORDER_2line(5, 1, 83, 12);
	_draw_XO_SHAPE(58, 5);
}

void show_GET_NAME() {
	draw_Grid_XO();
	draw_BOX(16, 4, 58, 14, '=');
	draw_BOX(25, 13, 40, 3, '=');
	GoTo(25 + 2, 13 + 1); cout << "NAME THE BOARD: ";
	_draw_NEWBOARDGAME(19, 5);
}

void show_SCREEN_GAME(BOARD& board) {
	system("cls");
	draw_BOARD(4, 2, 12, board.name);
	draw_POINTS(4, 2, board);
	show_TURN(61, 4, board.Turn);
	show_SCORE_X(61, 9, board.X_wins);
	show_SCORE_O(80, 9, board.O_wins);
	show_GAME_HELP(57, 17);
}

void show_SCREEN_HTP(SHORT _x, SHORT _y) {
	draw_BOX(6, 1, 81, 27, '=');
	_draw_HTP_SHAPE(15, 2);
	GoTo(9, 7); cout << "1. Set up the game board by drawing a grid of 12x12 squares.";
	GoTo(9, 8); cout << "2. Decide who goes first, and each player takes turns placing their game";
	GoTo(12, 9); cout << "piece (e.g., \"X\" or \"O\") on an empty square on the board.";
	GoTo(9, 10); cout << "3. Use \"WASD\" keys to move the cursor on the board and select an empty";
	GoTo(12, 11); cout << "square to place your game piece.";
	GoTo(9, 12); cout << "4. The objective is to be the first player to form a horizontal, vertical,";
	GoTo(12, 13); cout << "or diagonal line of five game pieces in a row.";
	GoTo(9, 14); cout << "5. Players take turns placing their game pieces strategically to block";
	GoTo(12, 15); cout << "their opponent from forming a line while also attempting to create their";
	GoTo(12, 16); cout << "own line of five.";
	GoTo(9, 17); cout << "6. The game continues until one player achieves a line of five game pieces";
	GoTo(12, 18); cout << "in a row or until the board is completely filled, resulting in a draw.";
	GoTo(9, 19); cout << "7. The player who forms a line of five game pieces first wins the game!";
	GoTo(37, 22); cout << "GOODLUCK PLAYERS.";
	draw_TXT(8, 26, "Press ESC to go back");
	_draw_CONSOLE_SHAPE(58, 20);
}

void show_SCREEN_ABOUT(SHORT _x, SHORT _y) {
	draw_BOX(6, 1, 81, 27, '=');
	_draw_ABOUT_SHAPE(31, 2);
	GoTo(16, 8); cout << "Our group of students came together for a seminar project to create";
	GoTo(9, 9); cout << "a unique twist on the classic board game called Caro. With our collective";
	GoTo(9, 10); cout << "passion for gaming and programming skills, we designed a digital version";
	GoTo(9, 11); cout << "of Caro that features modern elements, including the use of \"WASD\" keys";
	GoTo(9, 12); cout << "or cursor movement. As avid gamers ourselves, we aimed to create an engaging";
	GoTo(9, 13); cout << "and challenging experience for players, offering them a new way to enjoy";
	GoTo(9, 14); cout << "this timeless game. Our project was a culmination of our teamwork,";
	GoTo(9, 15); cout << "creativity, and dedication to delivering a fun and enjoyable gaming";
	GoTo(9, 16); cout << "experience for players of all levels.";

	GoTo(20, 19); cout << "22120183 - Nguyen Dang Minh Lan .";
	GoTo(20, 20); cout << "22120186 - Huynh Tan Loc .";
	GoTo(20, 21); cout << "22120188 - Dinh Viet Loi .";
	GoTo(20, 22); cout << "22120198 - Trinh Nguyen Luong .";
	GoTo(20, 23); cout << "22120199 - Tran Luong .";

	_draw_FACE_SHAPE(64, 20);

	draw_TXT(8, 26, "Press ESC to go back");
}

void show_BOARD_CURSOR(SHORT _x, SHORT _y, char type) {
	GoTo(4 + X_OFFSET + _x * POINT_DIST_X, 2 + Y_OFFSET + _y * POINT_DIST_Y);
	switch (type) {
	case 'X':
		SetColor(COLOR_RED, COLOR_BG);
		cout << " X ";
		break;
	case 'O':
		SetColor(COLOR_BLUE, COLOR_BG);
		cout << " O ";
		break;
	default:
		cout << ' ' << (char)260;
		break;
	}
	returnColor();
}

void show_SCREEN_SUBMENU(SHORT _x, SHORT _y, SHORT cmd) {
	int x = 28, y = 9;
	draw_BOX(x + 30, y + 9, 31, 10, '=');
	GoTo(x + 40, y + 10); cout << "---MENU---";
	GoTo(x + 30, y + 11); cout << LINE2_V_LEFT;
	for (int i = 0; i < 29; i++) cout << LINE2_H;
	GoTo(x + 60, y + 11); cout << LINE2_V_RIGHT;

	//draw options
	SHORT x_op = 67, y_op = 21;
	bool a[3]{ 0 };
	a[cmd] = true;
	if (a[0]) SetColor(COLOR_BLACK, COLOR_BG);
	else SetColor(COLOR_WHITE, COLOR_BLACK);
	GoTo(x_op, y_op);
	cout << "    SAVE    ";
	returnColor();
	if (a[1]) SetColor(COLOR_BLACK, COLOR_BG);
	else SetColor(COLOR_WHITE, COLOR_BLACK);
	GoTo(x_op, y_op + 2);
	cout << "  SETTINGS  ";
	returnColor();
	if (a[2]) SetColor(COLOR_BLACK, COLOR_BG);
	else SetColor(COLOR_WHITE, COLOR_BLACK);
	GoTo(x_op, y_op + 4);
	cout << "    QUIT    ";
	returnColor();
}

void show_SCREEN_CGAME(const BOARD& a, const DATA& data, SHORT index, SHORT _x, SHORT _y) {
	draw_BORDER_2line(13, 9, 42, 17);
	GoTo(2, 1);
	draw_BORDER_2line(3, 1, 87, 28);
	draw_BORDER_1line(15, 11, 27, 14);
	//draw_RETANGLE_SPACE(_x-1, _y, 48, 5, COLOR_BLACK);
	//SetColor(COLOR_BLACK, COLOR_BG);
	_draw_CONTINUE_SHAPE(22, 2);
	//returnColor();
	//
	string _name = a.name;
	GoTo(15, 10); cout << "Name: " << "                            ";
	if (_name.size() > 25) {
		_name.resize(25);  _name += "...";
	}
	GoTo(15, 10); cout << "Name: " << _name;
	
	draw_RETANGLE_SPACE(44, 13, 8, 4);

	int x_mat = 15, y_mat = 12;
	GoTo(x_mat + 1, y_mat);
	for (int i = 0; i < BOARD_SIZE; i++) {
		GoTo(x_mat + 1, y_mat + i);
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << (a.points[i][j].c != 'N' ? a.points[i][j].c : ' ') << " ";
		}
	}

	draw_TXT(33, 27, "Press ESC to go back --");

	if (a.Turn == 'X') {
		_draw_X_shape(43, 12);
	}
	else _draw_O_shape(44, 12);
	GoTo(44, 18);
	cout << "[X]: " << "   ";
	GoTo(44, 20);
	cout << "[O]: " << "   ";
	GoTo(44, 18);
	cout << "[X]: " << a.X_wins;
	GoTo(44, 20);
	cout << "[O]: " << a.O_wins;

	_draw_LEFTARROW_SHAPE(4, 13);
	_draw_RIGHTARROW_SHAPE(54, 14);

	draw_BOX(64, 10, 20, 13, '=');

	draw_RETANGLE_SPACE(55, 24, 20, 1, COLOR_BLACK);
	draw_RETANGLE_SPACE(73, 23, 2, 1, COLOR_BLACK);

	GoTo(73, 22); SetColor(COLOR_BLACK, COLOR_BG); cout << LINE2_H << LINE2_H; returnColor();

	GoTo(22, 7); cout << "Press ENTER to play, BACKSPACE to delete save";

	GoTo(67, 11); cout << "LIST OF SAVES:";

	bool _3dots = data.SAVEnames.size() - index + 1 > 7;
	SHORT _posX = 67, _posY = 13;

	int dist = (index % 7);
	SHORT last = index - dist + 7;
	for (int i = index-dist; i < last && i < data.SAVEnames.size(); i++) {
		if (i == index) SetColor(COLOR_BG, COLOR_BLACK);
		else SetColor(COLOR_BG, COLOR_GRAY);
		draw_STR_limit(_posX, _posY + i- (index - dist), data.SAVEnames[i], 14);
	}
}

void show_SCREEN_SETTINGS(SHORT cmd, DATA& dat) {
	_draw_SETTINGS_SHAPE(27, 3);
	bool a[2]{ 0 };
	a[cmd] = true;

	show_SETTINGS_MUTE(dat.mute, a[0]);
	show_SETTINGS_VOLUME(dat.Vol, a[1]);

}

void show_SETTINGS_VOLUME(SHORT lenVolume, BOOL HL) {
	if (HL) SetColor(COLOR_BLACK, COLOR_BG);
	GoTo(13, 12); cout << " VOLUME: ";
	returnColor();
	draw_BOX(25, 11, 48, 3, '-');
	//draw volume line
	draw_RETANGLE_SPACE(27, 12, 2 * lenVolume, 1, 0);
	//44 is max
	//0 is min
}

void show_SETTINGS_MUTE(BOOL check, BOOL HL) {
	if (HL) SetColor(COLOR_BLACK, COLOR_BG);
	GoTo(13, 9); cout << " MUTE: ";
	returnColor();
	draw_BOX(27, 8, 5, 3, '=');
	GoTo(29, 9); if (check) cout << "X";
	else cout << " ";

}

void show_SPEAKER(bool check) {
	if (check) {
		draw_RETANGLE_SPACE(29, 13, 40, 11);
		SetColor(COLOR_BG, COLOR_RED);
		_draw_SILINE_SHAPE(29, 13);
		returnColor();
	}
	else {
		draw_RETANGLE_SPACE(29, 13, 40, 11);
		_draw_VOLUME_SHAPE(29, 13);
	}
}

void selectSound1() {
	mciSendString(L"play music_select1.wav", NULL, 0, NULL);
	Sleep(1);
}

void selectSound2() {
	mciSendString(L"play music_select2.wav", NULL, 0, NULL);
	Sleep(1);
}

void selectSound3() {
	mciSendString(L"play music_select3.wav", NULL, 0, NULL);

}