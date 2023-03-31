#include "Data_Game.h"
#include "Control_Functions.h"
#include "Model_Functions.h"
#include "View_Functions.h"

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
		draw_BOARD(4, 2, 12, "NGUYEN LAN ");
		draw_POINTS(4, 2, a);
		display_TURN(62, 3, 'X');
		display_SCORE_X(61,9,1);
		display_SCORE_O(80, 9,2);
	}
	while(1){}
	return 0;
}