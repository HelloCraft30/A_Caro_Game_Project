#include "_computer_play.h"

int AttackArr[10] = { 0, 3, 24, 192, 1536, 12288, 98304, 531441, 4782969, 500000000 };
int DefendArr[10] = { 0, 2, 18, 140, 800, 8000, 70569, 350000, 30000000, 300000000 };

bool ischan(int x, int y) {
	return ((x < 0) || (x > BOARD_SIZE - 1) || (y < 0) || (y > BOARD_SIZE - 1));
}

int AttackPoint(const BOARD& board, int x, int y) {

	int tX[8] = { 1,0,1,1,-1,0,-1,-1 };
	int tY[8] = { 0,1,1,-1,0,-1,-1,1 };
	int Ally[4]{}, Enemy[4]{}, Block[4]{};
	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < 6; i++) {

			if (ischan(x + i * tX[k], y + i * tY[k])) {
				Block[k % 4]++;
				break;
			}

			if (board.points[x + i * tX[k]][y + i * tY[k]].c == 'N') break;

			if (board.points[x + i * tX[k]][y + i * tY[k]].c == 'O') {
				Ally[k % 4]++;
			}

			if (board.points[x + i * tX[k]][y + i * tY[k]].c == 'X') {
				Enemy[k % 4]++;
				break;
			}
		}
	}

	int SumPoint = 0;
	for (int i = 0; i < 4; i++) {
		int Point = AttackArr[Ally[i]];

		//Mình có 4 con, ưu tiên đánh
		if (Ally[i] == 4) Point = AttackArr[9];

		//Bị chặn thì giảm điểm
		if (Enemy[i] == 1 || Block[i] == 1) Point /= 2;

		//Bị chặn hai đầu thì không đánh
		if (
			Enemy[i] == 1 &&
			Ally[i] < 4 &&
			Block[i] == 1
			) Point = 0;
		if (Enemy[i] == 2) Point = 0;
		SumPoint += Point;
	}

	return SumPoint;
}

int DefendPoint(const BOARD& board, int x, int y) {
	int tX[8] = { 1,0,1,1,-1,0,-1,-1 };
	int tY[8] = { 0,1,1,-1,0,-1,-1,1 };
	int Ally[4]{}, Enemy[4]{}, Block[4]{};

	for (int k = 0; k < 8; k++) {
		for (int i = 1; i < 6; i++) {
			if (ischan(x + i * tX[k], y + i * tY[k])) {
				Block[k % 4]++;
				break;
			}

			if (board.points[x + i * tX[k]][y + i * tY[k]].c == 'N') break;

			if (board.points[x + i * tX[k]][y + i * tY[k]].c == 'X') {
				Enemy[k % 4]++;
			}

			if (board.points[x + i * tX[k]][y + i * tY[k]].c == 'O') {
				Ally[k % 4]++;
				break;
			}
		}
	}

	int SumPoint = 0;
	for (int i = 0; i < 4; i++) {
		int Point = DefendArr[Enemy[i]];

		//Địch có 4 con, ưu tiên chặn
		if (Enemy[i] == 4) Point = DefendArr[9];

		//Bị chặn thì giảm điểm
		if ((Ally[i] == 1) || (Block[i] == 1)) Point /= 2;

		//Bị chặn hai đầu thì điểm bằng 0
		if (
			Ally[i] == 1 &&
			Enemy[i] < 4 &&
			Block[i] == 1
			) Point = 0;
		if (Ally[i] == 2) Point = 0;
		SumPoint += Point;
	}

	return SumPoint;
}

_POINT computer_Turn(const BOARD& board) {
	
	_POINT result;
	setVal_POINT(result, 0, 0, 'N');
	int thisMakeCPNotStupid = 0;
	int MaxPoint = -DefendArr[9];
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board.points[i][j].c == 'N')
			{
				thisMakeCPNotStupid++;
				//Chọn r ngẫu nhiên, tăng tính ngẫu nhiên
				int r = rand() % 2;
				int Point = AttackPoint(board, i, j) + DefendPoint(board, i, j);

				//Lấy tổng điểm lớn nhất (MaxPoint), đánh vào đó
				if (
					MaxPoint < Point ||
					(
						MaxPoint == Point &&
						r == 0
						)
					) {
					MaxPoint = Point;
					result.x = j;
					result.y = i;
					result.c = 'O';
				}
			}
		}
	}
	if (thisMakeCPNotStupid == BOARD_SIZE * BOARD_SIZE) {
		result.x = 5;
		result.y = 6;
		result.c = 'O';
	}
	return result;
}