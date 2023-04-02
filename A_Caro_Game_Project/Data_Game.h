#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>

//WINDOW CONSOLE
#define SCREEN_WIDTH 702
#define SCREEN_HEIGHT 525
//FONT
#define FONT_SIZE 20

#define BOARD_SIZE 12

struct _POINT {
	int x;
	int y;
	char c;
};

typedef struct { _POINT** points; std::string name; int X_wins; int O_wins; char Turn; } BOARD;