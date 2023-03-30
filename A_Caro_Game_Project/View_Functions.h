#pragma once
#include <Windows.h>
#include <string>
#include "Data_Game.h"

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
void DRAW_BORDER_1line(SHORT posX, SHORT posY, int width, int height, int COLOR = 0);
void DRAW_BORDER_2line(SHORT posX, SHORT posY, int width, int height, int COLOR = 0);
//Draw retangle of spaces - default bg color : white
void DRAW_RETANGLE_SPACE(SHORT posX, SHORT posY, int width, int height, int COLOR = 7);
//Draw Box - default color, bg : white, txt : black
void DRAW_BOX(SHORT posX, SHORT posY, int width, int height, char type, int COLOR_bg = 7, int COLOR_txt = 0);
