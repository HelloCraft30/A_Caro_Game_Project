#pragma once
#include <Windows.h>
#include <string>
#include "Data_Game.h"

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
#define COLOR_BRIGHTWHITE 15
#define COLOR_BG COLOR_BRIGHTWHITE
#define COLOR_TXT COLOR_BLACK
//LINES
//	SINGLE LINE
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
//	DOUBLE LINE
#define LINE2_LEFT_TOP (char)201
#define LINE2_RIGHT_TOP (char)187
#define LINE2_LEFT_BOT (char)200
#define LINE2_RIGHT_BOT (char)188
#define LINE2_H (char)205
#define LINE2_V (char)186
#define LINE2_V_LEFT (char)204
#define LINE2_V_RIGHT (char)185
#define LINE2_H_TOP (char)203
#define LINE2_H_BOT (char)202
#define LINE2_MIDDLE (char)206
//	BLUR
#define BLUR1 (char)176
#define BLUR2 (char)177
#define BLUR3 (char)178
//POINT / BOARD
#define X_OFFSET 1
#define Y_OFFSET 1
#define POINT_DIST_X 4
#define POINT_DIST_Y 2

//Window console settings functions
void resizeConsole(int width, int height);
void removeScrollBar();
void SetColor(int backgound_color, int text_color);
void GoTo(SHORT posX, SHORT posY);
void DisableSelection();
void Nocursortype();
void changeFont(int x);
void fixConsoleWindow();

//Return default color
void returnColor();
//Draw Border - default text color : black
void draw_BORDER_1line(SHORT posX, SHORT posY, int width, int height, int COLOR = COLOR_TXT);
void draw_BORDER_2line(SHORT posX, SHORT posY, int width, int height, int COLOR = COLOR_TXT);
//Draw retangle of spaces - default bg color : white
void draw_RETANGLE_SPACE(SHORT posX, SHORT posY, int width, int height, int COLOR = COLOR_BG,bool SHADOW = 0);
//Draw Box - default color, bg : white, txt : black
void draw_BOX(SHORT posX, SHORT posY, int width, int height, char type, int COLOR_bg = COLOR_BG, int COLOR_txt = COLOR_TXT);
//Draw grid of board game
void draw_BOARD(SHORT posX, SHORT posY, int sizeBoard, std::string nameBoard);
//Draw point
void draw_POINT(const _POINT& point);
//Draw points
void draw_POINTS(SHORT posX, SHORT posY, const BOARD& matrix);
//Draw text 1 line
void draw_TXT(SHORT posX, SHORT posY, const std::string& str);
//Draw turn display
void show_TURN(SHORT posX, SHORT posY, char turn);
//Draw scores
void show_SCORE_X(SHORT posX, SHORT posY, int score);
void show_SCORE_O(SHORT posX, SHORT posY, int score);
//Draw last move
void show_LASTMOVE(SHORT posX, SHORT posY, const BOARD& board);
void show_GAME_HELP(SHORT posX, SHORT posY);
//MAINMENU SHOWING
void show_SCREEN_MAINMENU(SHORT color, SHORT cmd);
//GAME SHOWING
//some orther function
void show_GET_NAME();
void show_SCREEN_GAME(BOARD& board);
void show_BOARD_CURSOR(SHORT _x, SHORT _y, char type);

void show_SCREEN_SUBMENU(SHORT _x, SHORT _y, SHORT cmd);
void show_SCREEN_CGAME(const BOARD& a);