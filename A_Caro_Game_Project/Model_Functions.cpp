#include "Model_Functions.h"

void setVal_POINT(_POINT& point, int _x, int _y, char _c) {
	point.x = _x;
	point.y = _y;
	point.c = _c;
}

void setVal_POINT(_POINT& point, char _c) {
	point.c = _c;
}

void init_BOARD(BOARD& matrix) {
	matrix.points = new _POINT * [BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) matrix.points[i] = new _POINT[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			setVal_POINT(matrix.points[i][j], j, i, 'N');
		}
	}
}