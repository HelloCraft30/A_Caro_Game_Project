#pragma once
#include "Data_Game.h"
#include <vector>
#include <string>

#define SAVESFOLDER "GAME_SAVES"
#define LISTSAVES "GAME_SAVES\\List_SAVES.txt"

struct DATA {
	std::vector<std::string> SAVEnames;
	std::vector<BOARD> SAVEdatas;
	SHORT Vol;
	bool mute;
};

void setVal_POINT(_POINT& point,int _x, int _y, char _c);

void setVal_POINT(_POINT& point, char _c);

void init_BOARD(BOARD& matrix);

bool get_STUFFS(DATA& data);

void get_BOARD_DATA(BOARD& des,const std::string& fileName);

bool save_BOARD_DATA(DATA& data,const BOARD& src);

void save_BOARD_FILE(BOARD& board);

void save_DATA_FILE(DATA& data);

void delete_BOARD_DATA(DATA& data,const std::string& name);

void delete_BOARD_FILE(const std::string& name);

void delete_BOARD(DATA& data, const std::string& name);