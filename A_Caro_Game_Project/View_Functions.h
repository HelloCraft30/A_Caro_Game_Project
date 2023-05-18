#pragma once
#include <Windows.h>
#include <string>
#include "Data_Game.h"
#include "Model_Functions.h"

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
void reset_Color();
//Draw Border - default text color : black
void draw_Border_1line(SHORT posX, SHORT posY, int width, int height, int COLOR = COLOR_TXT);
void draw_Border_2line(SHORT posX, SHORT posY, int width, int height, int COLOR = COLOR_TXT);
//Draw retangle of spaces - default bg color : white
void draw_RetangleSpace(SHORT posX, SHORT posY, int width, int height, int COLOR = COLOR_BG, bool SHADOW = 0);
//Draw Box - default color, bg : white, txt : black
void draw_Box(SHORT posX, SHORT posY, int width, int height, char type, int COLOR_bg = COLOR_BG, int COLOR_txt = COLOR_TXT);
//Draw grid of board game
void draw_Board(SHORT posX, SHORT posY, int sizeBoard, std::string nameBoard);
//Draw point
void draw_Point(const _POINT& point);
//Draw points
void draw_GridPoint(SHORT posX, SHORT posY, const BOARD& matrix);
//Draw text 1 line
void draw_Str(SHORT posX, SHORT posY, const std::string& str);

void draw_Grid_XO();

//Draw turn display
void show_Game_Turn(SHORT posX, SHORT posY, char turn);

void draw_limited_Str(SHORT x, SHORT y, std::string str, int len);
//Draw scores
void show_Game_Score_x(SHORT posX, SHORT posY, int score);
void show_Game_Score_o(SHORT posX, SHORT posY, int score);
//Draw last move
void show_Game_LastMove(SHORT posX, SHORT posY, const BOARD& board);
void show_Game_Helps(SHORT posX, SHORT posY);
//MAINMENU SHOWING
void show_Screen_MainMenu(SHORT color, SHORT cmd, bool continue_check, SHORT _x, SHORT _y);
//GAME SHOWING
//some orther function
void show_Get_Name();
void show_Screen_Game(BOARD& board);
void show_Board_Cursor(SHORT _x, SHORT _y, char type);

void show_Screen_SubMenu(SHORT _x, SHORT _y, SHORT cmd);
void show_Screen_ContinueGame(const BOARD& a, const DATA& data, SHORT index, SHORT _x, SHORT _y);

void show_Screen_Setting(SHORT cmd, DATA& dat);
void show_Setting_Volume(SHORT lenVolume, BOOL HL);
void show_Setting_Mute(BOOL check, BOOL HL);
void show_Speaker(bool check);

void show_Ask_Delete(SHORT x, SHORT y, BOOL check);

void show_Screen_HTP(SHORT _x, SHORT _y);

void show_Screen_About(SHORT _x, SHORT _y);

void show_Ask_Gameplay(SHORT x, SHORT y, BOOL check);

void show_Ask_Difficult(SHORT _x, SHORT _y, int cmd);

void show_Ask_Save(SHORT _x, SHORT _y, BOOL check);

void selectSound1();
void selectSound2();
void selectSound3();