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

void DRAW_BORDER_1line(SHORT posX, SHORT posY, int width, int height, int COLOR) {
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
void DRAW_BORDER_2line(SHORT posX, SHORT posY, int width, int height, int COLOR) {
	GoTo(posX, posY);
	SetColor(COLOR_BG, COLOR);
	cout << LINE2_LEFT_TOP;
	for (int i = 2; i < width; i++) cout << LINE2_H;
	cout << LINE2_RIGHT_TOP;
	for (int i = 1; i < height - 1; i++) {
		GoTo(posX, posY + i);
		cout << LINE2_V;
		for (int j = 2; j < width; j++) cout << ' ';
		cout << LINE2_V;
	}
	GoTo(posX, posY + height - 1);
	cout << LINE2_LEFT_BOT;
	for (int i = 2; i < width; i++) cout << LINE2_H;
	cout << LINE2_RIGHT_BOT;
	returnColor();
}

void DRAW_RETANGLE_SPACE(SHORT posX, SHORT posY, int width, int height, int COLOR) {
	SetColor(COLOR, COLOR);
	for (int i = 0; i < height; i++) {
		GoTo(posX, posY + i);
		for (int j = 0; j < width; j++) {
			cout << ' ';
		}
	}
	returnColor();
}

void DRAW_BOX(SHORT posX, SHORT posY, int width, int height, char type, int COLOR_bg, int COLOR_txt) {
	if (type == '-') {
		DRAW_BORDER_1line(posX, posY, width, height, COLOR_txt);
		DRAW_RETANGLE_SPACE(posX + 1, posY + 1, width - 2, height - 2, COLOR_bg);
	}
	else if (type == '=') {
		DRAW_BORDER_2line(posX, posY, width, height, COLOR_txt);
		DRAW_RETANGLE_SPACE(posX + 1, posY + 1, width - 2, height - 2, COLOR_bg);
	}
}
