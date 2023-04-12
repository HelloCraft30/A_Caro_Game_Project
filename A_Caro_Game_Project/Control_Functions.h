#pragma once
#include "Data_Game.h"
#include "Model_Functions.h"
#include <string>

#define ENTER 13
#define ESC 27
#define BACKSPACE 8

void getFormedWindow();

void resetMatch(BOARD& a);

void Display(DATA& data);

SHORT display_SCREEN_MAINMENU(DATA& gameData);

SHORT display_SCREEN_GAME(DATA &gameData,bool newGame = 1,const std::string& nameGame = "");

SHORT display_SCREEN_SUBMENU(BOARD& board, DATA & data);

SHORT display_SCREEN_CGAME(DATA& gameData, std::string& output);

SHORT display_SCREEN_SETTINGS(DATA& gameData);

SHORT display_SCREEN_ABOUT();

SHORT display_SCREEN_HTP(DATA& gameData);

BOOL display_ASK_DEL();

SHORT new_GAME_BOARD(DATA& gameDat, BOARD& a);

std::string get_STRING(SHORT x, SHORT y, int len);

SHORT is_WIN(const BOARD& a, SHORT x, SHORT y);

bool is_DRAW(const BOARD& a);

void game_UNDO(BOARD& a, SHORT &curX, SHORT &curY);