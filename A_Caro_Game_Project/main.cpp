#include "Data_Game.h"
#include "Control_Functions.h"
#include "Model_Functions.h"
#include "View_Functions.h"
#include "_draw_SHAPE.h"
#pragma comment( lib, "Winmm.lib" )

using namespace std;

void moveCur(int& x, int& y) {
	switch (_getch()) {
	case 'A':
		x--;
		break;
	case 'S':
		y++;
		break;
	case 'W':
		y--;
		break;
	case 'D':
		x++;
		break;
	case 13:
		cout << "x: " << x << " y: " << y;
	}
}

int main() {

	int x = 0; int y = 0;
	DATA gameDat;
	resizeConsole(700, 70);
	system("color F0");
	GoTo(0, 0); cout << "THIS WORKS BEST ON WINDOW CONSOLE HOST - press any key";
	system("pause");

	SetConsoleTitleA("CARO GAME");
	getFormedWindow();
	get_STUFFS(gameDat);
	display_SCREEN_GAME_BOT(gameDat, 0, gameDat.SAVEnames[0]);
	if (get_STUFFS(gameDat)) {
		Display(gameDat);
	}
	
	_TRANSITION();

	return 0;
}