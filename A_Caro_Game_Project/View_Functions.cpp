#include "View_Functions.h"

using namespace std;

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
	SetColor(COLOR_BG, COLOR);
	if (SHADOW) {
		for (int i = 0; i < height; i++) {
			GoTo(posX - 3, posY + i);
			cout << BLUR1 << BLUR2 << BLUR3;
			GoTo(posX + width, posY + i);
			cout << BLUR3 << BLUR2 << BLUR1;
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
	SetColor(COLOR_TXT, COLOR_BG);
	cout << BLUR3 << BLUR2 << BLUR1<< " NAME BOARD: ";
	returnColor(); cout << ' ';
	if (nameBoard.size() > 25) {
		nameBoard.resize(25); nameBoard += "...  ";
	}
	cout << nameBoard;
	GoTo(posX + 27, posY + 25);
	SetColor(COLOR_TXT, COLOR_BG);
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

void _draw_X_shape(int _x, int _y) {
	GoTo(_x + 1, _y + 1); cout << (char)223;
	GoTo(_x + 1, _y + 4); cout << (char)223;
	GoTo(_x + 2, _y + 1); cout << (char)220;
	GoTo(_x + 2, _y + 3); cout << (char)220;
	GoTo(_x + 3, _y + 2); cout << (char)223;
	GoTo(_x + 3, _y + 3); cout << (char)223;
	GoTo(_x + 4, _y + 2); cout << (char)220;
	GoTo(_x + 5, _y + 2); cout << (char)223;
	GoTo(_x + 5, _y + 3); cout << (char)223;
	GoTo(_x + 6, _y + 1); cout << (char)220;
	GoTo(_x + 6, _y + 3); cout << (char)220;
	GoTo(_x + 7, _y + 1); cout << (char)223;
	GoTo(_x + 7, _y + 4); cout << (char)223;
}
void _draw_O_shape(int _x, int _y) {
	GoTo(_x + 1, _y + 2); cout << (char)219;
	GoTo(_x + 1, _y + 3); cout << (char)219;
	GoTo(_x + 2, _y + 1); cout << (char)220;
	GoTo(_x + 2, _y + 4); cout << (char)223;
	GoTo(_x + 3, _y + 1); cout << (char)220;
	GoTo(_x + 3, _y + 4); cout << (char)223;
	GoTo(_x + 4, _y + 1); cout << (char)220;
	GoTo(_x + 4, _y + 4); cout << (char)223;
	GoTo(_x + 5, _y + 2); cout << (char)219;
	GoTo(_x + 5, _y + 3); cout << (char)219;

}

void display_TURN(SHORT posX, SHORT posY, char turn) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, 0, true);
	SetColor(COLOR_TXT, COLOR_BG);
	GoTo(posX, posY); cout << "CURRENT";
	GoTo(posX + 1, posY + 1); cout << "TURN:";

	int _posX = posX + 17, _posY = posY - 4;
	
	if (turn == 'X') {
		draw_RETANGLE_SPACE(_posX - 2, _posY + 2, 13, 6);
		SetColor(COLOR_BG, 12);
		_draw_X_shape(_posX - 1, _posY + 2);
	}
	else {
		draw_RETANGLE_SPACE(_posX - 2, _posY + 2, 13, 6);
		SetColor(COLOR_BG, 9);
		_draw_O_shape(_posX, _posY + 2);
	}
	draw_BORDER_2line(_posX - 3, _posY + 2, 13, 6);
	returnColor();
}

void display_SCORE_X(SHORT posX, SHORT posY, int score) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, 0, true);
	SetColor(COLOR_TXT, COLOR_BG);
	GoTo(posX-2, posY); cout << "X player's";
	GoTo(posX + 1, posY + 1); cout << "SCORE: ";

	draw_BORDER_1line(posX-4, posY + 2, 14, 3);
}

void display_SCORE_O(SHORT posX, SHORT posY, int score) {
	draw_RETANGLE_SPACE(posX - 3, posY, 12, 2, 0, true);
	SetColor(COLOR_TXT, COLOR_BG);
	GoTo(posX - 2, posY); cout << "O player's";
	GoTo(posX + 1, posY + 1); cout << "SCORE: ";

	draw_BORDER_1line(posX - 4, posY + 2, 14, 3);
}

