#include "Data_Game.h"
#include "Control_Functions.h"
#include "Model_Functions.h"
#include "View_Functions.h"
#include "_draw_SHAPE.h"

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
	getFormedWindow();
	BOARD a;
	init_BOARD(a);
	a.points[0][0].c = 'X';
	a.points[11][11].c = 'O';
	
	while (true) {
		moveCur(x, y);
		system("cls");
		system("color F0");
		display_SCREEN_GAME();
		while(1){}
	}
	while(1){}
	return 0;
}