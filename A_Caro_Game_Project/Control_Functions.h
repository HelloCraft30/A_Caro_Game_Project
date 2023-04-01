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

void Display();

SHORT display_SCREEN_MAINMENU();

SHORT display_SCREEN_GAME();
