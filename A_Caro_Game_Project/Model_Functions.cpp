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

void save_BOARD_DATA(DATA& data, const BOARD& src) {
	//linear search
	bool existed = 0;
	for(auto x: data.SAVEnames) 
		if (x == src.name) {
			existed = 1;
			break;
		}
	if (!existed) {
		data.SAVEnames.push_back(src.name);
		data.SAVEdatas.push_back(src);
	}
	else {
		for (auto x : data.SAVEdatas) {
			if (x.name == src.name) {
				x = src;
				break;
			}
		}
	}
}

void save_BOARD_FILE(BOARD& board) {
	string link = SAVESFOLDER;
	link += '\\';
	link += board.name;
	link += ".txt";
	fstream fileOpen(link, ios::out | ios::trunc);
	fileOpen << "score: X/O" << endl;
	fileOpen << board.X_wins << " " << board.O_wins << endl;
	fileOpen << "turn:" << endl;
	fileOpen << board.Turn << endl;
	fileOpen << "data:" << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			fileOpen << board.points[i][j].c << " ";
		}
		fileOpen << endl;
	}
	fileOpen.close();
}

void save_DATA_FILE(DATA& data) {
	fstream fileLIST(LISTSAVES, ios::out | ios::trunc);
	for (auto x : data.SAVEnames) {
		fileLIST << x << endl;
	}
	fileLIST.close();
	for (auto x : data.SAVEdatas) {
		save_BOARD_FILE(x);
	}
}