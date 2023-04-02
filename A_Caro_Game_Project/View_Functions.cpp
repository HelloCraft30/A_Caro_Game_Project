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
			cout  << BLUR2 << BLUR3;
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
	cout << BLUR3 << BLUR2 << BLUR1<< " BOARD NAME: ";
	returnColor(); cout << ' ';
	if (nameBoard.size() > 25) {
		nameBoard.resize(25); nameBoard += "...  ";
	}
	cout << nameBoard;
	GoTo(posX + 63, posY + 25);
	SetColor(COLOR_GRAY, COLOR_BG);
	cout << BLUR3 << BLUR2 << BLUR1 << " Caro game ver 0.1 ";
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
void show_TURN(SHORT posX, SHORT posY, char turn) {
	
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, (turn=='X'?COLOR_RED:COLOR_BLUE), true);
	SetColor((turn == 'X' ? COLOR_RED : COLOR_BLUE), COLOR_BG);
	GoTo(posX, posY); cout << "CURRENT";
	GoTo(posX + 1, posY + 1); cout << "TURN:";

	int _posX = posX + 17, _posY = posY - 4;
	
	if (turn == 'X') {
		draw_RETANGLE_SPACE(_posX - 1, _posY + 2, 13, 6);
		SetColor(COLOR_BG, 12);
		_draw_X_shape(_posX , _posY + 2);
	}
	else {
		draw_RETANGLE_SPACE(_posX - 1, _posY + 2, 13, 6);
		SetColor(COLOR_BG, 9);
		_draw_O_shape(_posX+1, _posY + 2);
	}
	draw_BORDER_2line(_posX - 2, _posY + 2, 13, 6);
	returnColor();
}
void show_SCORE_X(SHORT posX, SHORT posY, int score) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, COLOR_RED, true);
	SetColor(COLOR_RED, COLOR_BG);
	GoTo(posX-2, posY); cout << "X player's";
	GoTo(posX + 1, posY + 1); cout << "SCORE: ";
	returnColor();
	GoTo(posX +2, posY + 3); cout << score;
	draw_BORDER_1line(posX-4, posY + 2, 14, 3);
}
void show_SCORE_O(SHORT posX, SHORT posY, int score) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, COLOR_BLUE, true);
	SetColor(COLOR_BLUE, COLOR_BG);
	GoTo(posX - 2, posY); cout << "O player's";
	GoTo(posX + 1, posY + 1); cout << "SCORE: ";
	returnColor();
	GoTo(posX +2, posY + 3); cout << score;
	draw_BORDER_1line(posX - 4, posY + 2, 14, 3);
}
void show_LASTMOVE(SHORT posX, SHORT posY, _POINT point) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 1, COLOR_GRAY,TRUE);
	SetColor(COLOR_GRAY, COLOR_BG);
	GoTo(posX - 2, posY); cout << "Last move: ";
	returnColor();
	GoTo(posX + 14, posY); cout << "                  ";
	GoTo(posX + 14, posY); cout << point.c << ": [" << point.x << "] - [" << point.y<<"]";
}
void show_GAME_HELP(SHORT posX, SHORT posY) {
	draw_BORDER_2line(posX, posY, 33, 10);
	GoTo(posX + 3, posY + 2);
	cout << "1. WASD or " << (char)273<<' ' << (char)286 << ' ' << (char)287 << ' ' << (char)272 << " to move.";
	GoTo(posX + 3, posY + 3);
	cout << "2. [ENTER] to tick your TURN.";
	GoTo(posX + 3, posY + 4);
	cout << "3. [ESCAPE] to open menu.";
	GoTo(posX + 3, posY + 5);
	cout << "    (Quit, Save, Load Game)";
	GoTo(posX + 11, posY + 7);
	cout << "--Enjoy!--";
}
void show_SCREEN_MAINMENU(SHORT color,SHORT cmd) {
	SetColor(COLOR_BG, color);
	_draw_NAME_CARO(12, 3);
	SetColor(COLOR_BG, COLOR_TXT);
	//draw options
	SHORT op_x = 26, op_y = 15;
	int a[6]{};
	int b[6]{ 15,15,15,15,15,15 };
	a[cmd] = COLOR_GREEN;
	b[cmd] = 15;
	//option 1: NEW GAME
	draw_RETANGLE_SPACE(op_x, op_y, 17, 1, a[1], true);
	SetColor(a[1], b[1]);
	GoTo(op_x + 5, op_y); cout << "NEW GAME";
	//option 2: CONTINUE GAME
	draw_RETANGLE_SPACE(op_x, op_y+2, 17, 1, a[2], true);
	SetColor(a[2], b[2]);
	GoTo(op_x + 2, op_y+2); cout << "CONTINUE GAME";
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
	_draw_MY_BOY(60, 3);
	_draw_XO_SHAPE(62, 17);
}

void show_GET_NAME() {
	draw_BOX(25, 11, 40, 3, '=');
	GoTo(25 + 2, 11 + 1); cout << "NAME THE BOARD: ";
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
