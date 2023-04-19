#pragma once
#include "Control_Functions.h"
#include "Data_Game.h"
#include "_draw_SHAPE.h"
#include "View_Functions.h"

bool ischan(int x, int y);

int AttackPoint(const BOARD& board, int x, int y);

int DefendPoint(const BOARD& board, int x, int y);

_POINT computer_Turn(const BOARD& board);