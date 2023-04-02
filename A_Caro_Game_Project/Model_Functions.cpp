#include "Model_Functions.h"
#include <direct.h>

using namespace std;

void get_STUFFS(DATA &data) {
	data.SAVEdatas.resize(0);
	data.SAVEnames.resize(0);
	int status = _mkdir("GAME_SAVES");
	if (status != -1) {
		fstream createFILE(LISTSAVES, ios::out);
		createFILE.close();
	}
	else {
		fstream readFILE(LISTSAVES, ios::in);
		string temp;
		while (getline(readFILE, temp)) {
			data.SAVEnames.push_back(temp);
		}
		readFILE.close();
		//get BOARDS
		
		for (int i = 0; i < data.SAVEnames.size(); i++) {
			BOARD _board; init_BOARD(_board);
			get_BOARD_DATA(_board, data.SAVEnames[i]);
			data.SAVEdatas.push_back(_board);
		}
	}
}

void setVal_POINT(_POINT& point, int _x, int _y, char _c) {
	point.x = _x;
	point.y = _y;
	point.c = _c;
}

void setVal_POINT(_POINT& point, char _c) {
	point.c = _c;
}

void init_BOARD(BOARD& matrix) {
	matrix.points = new _POINT * [BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) matrix.points[i] = new _POINT[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			setVal_POINT(matrix.points[i][j], j, i, 'N');
		}
	}
	matrix.O_wins = 0;
	matrix.X_wins = 0;
	matrix.Turn = 'X';
}

void get_BOARD_DATA(BOARD& des, string fileName) {
	des.name = fileName;
	string dir = SAVESFOLDER;
	dir+= '\\' + fileName + ".txt";
	fstream fileOPEN(dir, ios::in);
	string temp;
	getline(fileOPEN, temp);
	fileOPEN >> des.X_wins >> des.O_wins;
	fileOPEN.ignore();
	getline(fileOPEN, temp);
	fileOPEN >> des.Turn;
	fileOPEN.ignore();
	getline(fileOPEN, temp);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			fileOPEN >> des.points[j][i].c;
		}
	}
	fileOPEN.close();
}

void save_BOARD_DATA(const BOARD& src) {
	
}