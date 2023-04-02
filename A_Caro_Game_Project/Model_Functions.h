#pragma once
#include "Data_Game.h"
#include <vector>
#include <string>

#define SAVESFOLDER "GAME_SAVES"
#define LISTSAVES "GAME_SAVES\\List_SAVES.txt"

struct DATA {
	std::vector<std::string> SAVEnames;
	std::vector<BOARD> SAVEdatas;
};

void setVal_POINT(_POINT& point,int _x, int _y, char _c);

void setVal_POINT(_POINT& point, char _c);

void init_BOARD(BOARD& matrix);

void get_STUFFS(DATA& data);

void get_BOARD_DATA(BOARD& des, std::string fileName);

void save_BOARD_DATA(const BOARD& src);