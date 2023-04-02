#pragma once
#include "Data_Game.h"
#include "Model_Functions.h"
#include <string>

#define key_Up  1072
#define key_Down 1080
#define key_Left 1075
#define key_Right 1077
#define ENTER 13
#define ESC 27
#define BACKSPACE 127

void getFormedWindow();

void resetMatch(BOARD& a);

void Display(DATA& data);

SHORT display_SCREEN_MAINMENU();

SHORT display_SCREEN_GAME(DATA &gameData,bool newGame = 1, std::string nameGame = "");

void new_GAME_BOARD(DATA& gameDat, BOARD& a);

std::string get_STRING(SHORT x, SHORT y, int len);

SHORT is_WIN(BOARD a, SHORT x, SHORT y);