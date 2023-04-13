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
	if (get_STUFFS(gameDat)) {
		Display(gameDat);
	}
	
	_TRANSITION();

	//while (1) {
	//	
	//	moveCur(x, y);
	//	system("cls");
	//	show_SCREEN_CGAME(gameDat.SAVEdatas[0], gameDat, 0, 0, 0);
	//	//show_ASK_DEL(x,y,1);

	//}

	return 0;
}