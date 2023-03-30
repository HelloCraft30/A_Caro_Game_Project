#pragma once
#include "Control_Functions.h"
#include "Model_Functions.h"
#include "View_Functions.h"

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <cstdlib>

//WINDOW CONSOLE
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500
//COLORS
	#define COLOR_BLACK 0
	#define COLOR_BLUE 1
	#define COLOR_GREEN 2
	#define COLOR_AQUA 3
	#define COLOR_RED 4
	#define COLOR_PURPLE 5
	#define COLOR_YELLOW 6
	#define COLOR_WHITE 7
	#define COLOR_GRAY 8

#define COLOR_BG COLOR_WHITE
#define COLOR_TXT COLOR_BLACK
//FONT
#define FONT_SIZE 23
//LINES
	//SINGLE LINE
	#define LINE1_LEFT_TOP (char)218
	#define LINE1_RIGHT_TOP (char)191
	#define LINE1_LEFT_BOT (char)192
	#define LINE1_RIGHT_BOT (char)217
	#define LINE1_H (char)196
	#define LINE1_V (char)179
	#define LINE1_V_LEFT (char)195
	#define LINE1_V_RIGHT (char)180
	#define LINE1_H_TOP (char)194
	#define LINE1_H_VOT (char)193
	#define LINE1_MIDDLE (char)197
	//DOUBLE LINE
	#define LINE2_LEFT_TOP (char)201
	#define LINE2_RIGHT_TOP (char)187
	#define LINE2_LEFT_BOT (char)200
	#define LINE2_RIGHT_BOT (char)188
	#define LINE2_H (char)205
	#define LINE2_V (char)186
	#define LINE2_V_LEFT (char)204
	#define LINE2_V_RIGHT (char)185
	#define LINE2_H_TOP (char)203
	#define LINE2_H_VOT (char)202
	#define LINE2_MIDDLE (char)206
