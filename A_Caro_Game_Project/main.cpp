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
	DATA gameDat;
	

	getFormedWindow();
	get_STUFFS(gameDat);
	
	Display(gameDat);

	//show_SCREEN_MAINMENU(0, 0);

	while(1){
		
		moveCur(x, y);
		system("cls");
	}
	return 0;
}