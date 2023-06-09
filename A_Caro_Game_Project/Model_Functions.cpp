#include "Model_Functions.h"
#include <direct.h>

using namespace std;

bool load_Data(DATA &data) {
	data.SAVEdatas.resize(0);
	data.SAVEnames.resize(0);
	data.mute = false;
	data.Vol = 11;
	int status = _mkdir("GAME_SAVES");
	if (status != -1) {
		fstream createFILE(LISTSAVES, ios::out);
		createFILE.close();
	}
	else {
		fstream readFILE(LISTSAVES, ios::in);
		if (!readFILE) return 0;
		string temp;
		while (getline(readFILE, temp)) {
			data.SAVEnames.push_back(temp);
		}
		readFILE.close();
		//get BOARDS
		
		for (int i = 0; i < data.SAVEnames.size(); i++) {
			BOARD _board; init_Board(_board);
			load_Board_from_Data(_board, data.SAVEnames[i]);
			data.SAVEdatas.push_back(_board);
		}
	}
	return true;
}

void create_Point(_POINT& point, int _x, int _y, char _c) {
	point.x = _x;
	point.y = _y;
	point.c = _c;
}

void create_Point(_POINT& point, char _c) {
	point.c = _c;
}

void init_Board(BOARD& matrix) {
	matrix.gamePlay = 0;
	matrix.points = new _POINT * [BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) matrix.points[i] = new _POINT[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			create_Point(matrix.points[i][j], j, i, 'N');
		}
	}
	matrix.O_wins = 0;
	matrix.X_wins = 0;
	matrix.Turn = 'X';
	matrix.listOfMoves.resize(0);
}

void load_Board_from_Data(BOARD& des,const string& fileName) {
	des.name = fileName;
	string dir = SAVESFOLDER;
	dir+= '\\' + fileName + ".txt";
	fstream fileOPEN(dir, ios::in);
	string temp;
	getline(fileOPEN, temp);
	fileOPEN >> des.gamePlay;
	fileOPEN.ignore();
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
	fileOPEN.ignore();
	fileOPEN.ignore();
	getline(fileOPEN, temp);
	while (!fileOPEN.eof()) {
		int _x = 0, _y = 0;
		char _ch = 'N';
		fileOPEN >> _x >> _y >> _ch;
		if (_ch == 'N') break;
		des.listOfMoves.push_back({ _x,_y,_ch });
	}
	fileOPEN.close();
}

bool save_Board_to_Data(DATA& data, const BOARD& src) {
	//linear search
	if (data.SAVEnames.size() >= SAVES_LIMIT) return false;
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
		for (auto &x : data.SAVEdatas) {
			if (x.name == src.name) {
				x = src;
				break;
			}
		}
	}
	return true;
}

void save_Board_to_File(BOARD& board) {
	string link = SAVESFOLDER;
	link += '\\';
	link += board.name;
	link += ".txt";
	fstream fileOpen(link, ios::out | ios::trunc);
	fileOpen << "player/computer: " << endl;
	fileOpen << board.gamePlay << endl;
	fileOpen << "score: X/O" << endl;
	fileOpen << board.X_wins << " " << board.O_wins << endl;
	fileOpen << "turn:" << endl;
	fileOpen << board.Turn << endl;
	fileOpen << "data:" << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			fileOpen << board.points[j][i].c << " ";
		}
		fileOpen << endl;
	}
	fileOpen << "history:" << endl;
	for (const _POINT& x : board.listOfMoves) {
		fileOpen << x.x << " " << x.y << " " << x.c << endl;
	}
	fileOpen.close();
}

void save_Data_to_File(DATA& data) {
	fstream fileLIST(LISTSAVES, ios::out | ios::trunc);
	for (auto x : data.SAVEnames) {
		fileLIST << x << endl;
	}
	fileLIST.close();
	for (auto x : data.SAVEdatas) {
		save_Board_to_File(x);
	}
}

void delete_Board_from_Data(DATA& data,const std::string& name) {
	for (int i = 0; i < data.SAVEnames.size(); i++) {
		if (data.SAVEnames[i] == name) {
			data.SAVEnames.erase(data.SAVEnames.begin()+i);
			break;
		}
	}

	for (int i = 0; i < data.SAVEdatas.size(); i++) {
		if (data.SAVEdatas[i].name == name) {
			data.SAVEdatas.erase(data.SAVEdatas.begin() + i);
			break;
		}
	}
}

void delete_Board_from_File(const std::string& name) {
	string dir = SAVESFOLDER;
	dir += '\\';
	dir += name;
	dir += ".txt";
	remove(dir.c_str());
}

void delete_Board_from_Game(DATA& data, const std::string& name) {
	delete_Board_from_File(name);
	delete_Board_from_Data(data, name);
	save_Data_to_File(data);
}