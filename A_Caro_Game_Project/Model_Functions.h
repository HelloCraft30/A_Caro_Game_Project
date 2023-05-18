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

void create_Point(_POINT& point,int _x, int _y, char _c);

void create_Point(_POINT& point, char _c);

void init_Board(BOARD& matrix);

bool load_Data(DATA& data);

void load_Board_from_Data(BOARD& des,const std::string& fileName);

bool save_Board_to_Data(DATA& data,const BOARD& src);

void save_Board_to_File(BOARD& board);

void save_Data_to_File(DATA& data);

void delete_Board_from_Data(DATA& data,const std::string& name);

void delete_Board_from_File(const std::string& name);

void delete_Board_from_Game(DATA& data, const std::string& name);