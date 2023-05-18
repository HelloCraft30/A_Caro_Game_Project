#pragma once
#include "Data_Game.h"
#include "Model_Functions.h"
#include "_computer_play.h"
#include <string>

#define ENTER 13
#define ESC 27
#define BACKSPACE 8

void getFormedWindow();

void resetMatch(BOARD& a);

void Display(DATA& data);

SHORT display_Screen_MainMenu(DATA& gameData);

SHORT display_Screen_Game_pvp(DATA &gameData,bool newGame = 1,const std::string& nameGame = "");

SHORT display_Screen_Game_pvc(DATA& gameData, bool newGame = 1, const std::string& nameGame = "");

SHORT display_Screen_SubMenu(BOARD& board, DATA & data, bool& newGame);

SHORT display_Screen_Continue_Game(DATA& gameData, std::string& output);

SHORT display_Screen_Setting(DATA& gameData);

SHORT display_Screen_About();

SHORT display_Screen_HTP(DATA& gameData);

BOOL display_Ask_Delete();

BOOL display_Ask_Gameplay();

BOOL display_Ask_Save();

INT display_Ask_Difficult();

SHORT build_New_Game(DATA& gameDat, BOARD& a);

std::string get_String(SHORT x, SHORT y, int len);

SHORT isWin(const BOARD& a, SHORT x, SHORT y);

bool isDraw(const BOARD& a);

void sys_Undo(BOARD& a, SHORT &curX, SHORT &curY);

bool display_Screen_Result(BOARD& a, SHORT &curX, SHORT &curY);