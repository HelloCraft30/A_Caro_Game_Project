#include "_draw_SHAPE.h"
#include "View_Functions.h"

using namespace std;

void _draw_X_shape(SHORT _x, SHORT _y) {
	GoTo(_x + 1, _y + 1); cout << (char)223;
	GoTo(_x + 1, _y + 4); cout << (char)223;
	GoTo(_x + 2, _y + 1); cout << (char)220;
	GoTo(_x + 2, _y + 3); cout << (char)220;
	GoTo(_x + 3, _y + 2); cout << (char)223;
	GoTo(_x + 3, _y + 3); cout << (char)223;
	GoTo(_x + 4, _y + 2); cout << (char)220;
	GoTo(_x + 5, _y + 2); cout << (char)223;
	GoTo(_x + 5, _y + 3); cout << (char)223;
	GoTo(_x + 6, _y + 1); cout << (char)220;
	GoTo(_x + 6, _y + 3); cout << (char)220;
	GoTo(_x + 7, _y + 1); cout << (char)223;
	GoTo(_x + 7, _y + 4); cout << (char)223;
}
void _draw_O_shape(SHORT _x, SHORT _y) {
	GoTo(_x + 1, _y + 2); cout << (char)219;
	GoTo(_x + 1, _y + 3); cout << (char)219;
	GoTo(_x + 2, _y + 1); cout << (char)220;
	GoTo(_x + 2, _y + 4); cout << (char)223;
	GoTo(_x + 3, _y + 1); cout << (char)220;
	GoTo(_x + 3, _y + 4); cout << (char)223;
	GoTo(_x + 4, _y + 1); cout << (char)220;
	GoTo(_x + 4, _y + 4); cout << (char)223;
	GoTo(_x + 5, _y + 2); cout << (char)219;
	GoTo(_x + 5, _y + 3); cout << (char)219;
}
void _draw_NAME_CARO(SHORT _x, SHORT _y) {
	GoTo(_x + 43, _y + 26); cout << "- A project made by 11th Group. -";
	GoTo(_x + 1, _y + 2); cout << (char)219; GoTo(_x + 1, _y + 3); cout << (char)219; GoTo(_x + 1, _y + 4); cout << (char)219;
	GoTo(_x + 1, _y + 5); cout << (char)219; GoTo(_x + 1, _y + 6); cout << (char)219; GoTo(_x + 1, _y + 7); cout << (char)219;
	GoTo(_x + 2, _y + 2); cout << (char)219; GoTo(_x + 2, _y + 3); cout << (char)219; GoTo(_x + 2, _y + 4); cout << (char)219;
	GoTo(_x + 2, _y + 5); cout << (char)219; GoTo(_x + 2, _y + 6); cout << (char)219; GoTo(_x + 2, _y + 7); cout << (char)219;
	GoTo(_x + 3, _y + 1); cout << (char)219; GoTo(_x + 3, _y + 2); cout << (char)223; GoTo(_x + 3, _y + 7); cout << (char)220;
	GoTo(_x + 3, _y + 8); cout << (char)219; GoTo(_x + 4, _y + 1); cout << (char)219; GoTo(_x + 4, _y + 8); cout << (char)219;
	GoTo(_x + 5, _y + 1); cout << (char)219; GoTo(_x + 5, _y + 8); cout << (char)219; GoTo(_x + 6, _y + 1); cout << (char)219;
	GoTo(_x + 6, _y + 8); cout << (char)219; GoTo(_x + 7, _y + 1); cout << (char)219; GoTo(_x + 7, _y + 8); cout << (char)219;
	GoTo(_x + 8, _y + 1); cout << (char)219; GoTo(_x + 8, _y + 2); cout << (char)223; GoTo(_x + 8, _y + 7); cout << (char)220;
	GoTo(_x + 8, _y + 8); cout << (char)219; GoTo(_x + 9, _y + 2); cout << (char)219; GoTo(_x + 9, _y + 6); cout << (char)219;
	GoTo(_x + 9, _y + 7); cout << (char)219; GoTo(_x + 10, _y + 2); cout << (char)219; GoTo(_x + 10, _y + 6); cout << (char)219;
	GoTo(_x + 10, _y + 7); cout << (char)219; GoTo(_x + 12, _y + 5); cout << (char)219; GoTo(_x + 12, _y + 6); cout << (char)219;
	GoTo(_x + 12, _y + 7); cout << (char)219; GoTo(_x + 12, _y + 8); cout << (char)219; GoTo(_x + 13, _y + 3); cout << (char)219;
	GoTo(_x + 13, _y + 4); cout << (char)219; GoTo(_x + 13, _y + 5); cout << (char)219; GoTo(_x + 13, _y + 6); cout << (char)219;
	GoTo(_x + 13, _y + 7); cout << (char)219; GoTo(_x + 13, _y + 8); cout << (char)219;
	GoTo(_x + 14, _y + 2); cout << (char)219; GoTo(_x + 14, _y + 3); cout << (char)219;
	GoTo(_x + 14, _y + 4); cout << (char)219;
	GoTo(_x + 14, _y + 6); cout << (char)219;
	GoTo(_x + 14, _y + 7); cout << (char)223;
	GoTo(_x + 15, _y + 1); cout << (char)219;
	GoTo(_x + 15, _y + 2); cout << (char)219;
	GoTo(_x + 15, _y + 3); cout << (char)223;
	GoTo(_x + 15, _y + 6); cout << (char)219;
	GoTo(_x + 16, _y + 1); cout << (char)219;
	GoTo(_x + 16, _y + 6); cout << (char)219;
	GoTo(_x + 17, _y + 1); cout << (char)219;
	GoTo(_x + 17, _y + 6); cout << (char)219;
	GoTo(_x + 18, _y + 1); cout << (char)219;
	GoTo(_x + 18, _y + 2); cout << (char)219;
	GoTo(_x + 18, _y + 3); cout << (char)223;
	GoTo(_x + 18, _y + 6); cout << (char)219;
	GoTo(_x + 19, _y + 2); cout << (char)219;
	GoTo(_x + 19, _y + 3); cout << (char)219;
	GoTo(_x + 19, _y + 4); cout << (char)219;
	GoTo(_x + 19, _y + 6); cout << (char)219;
	GoTo(_x + 19, _y + 7); cout << (char)223;
	GoTo(_x + 20, _y + 3); cout << (char)219;
	GoTo(_x + 20, _y + 4); cout << (char)219;
	GoTo(_x + 20, _y + 5); cout << (char)219;
	GoTo(_x + 20, _y + 6); cout << (char)219;
	GoTo(_x + 20, _y + 7); cout << (char)219;
	GoTo(_x + 20, _y + 8); cout << (char)219;
	GoTo(_x + 21, _y + 5); cout << (char)219;
	GoTo(_x + 21, _y + 6); cout << (char)219;
	GoTo(_x + 21, _y + 7); cout << (char)219;
	GoTo(_x + 21, _y + 8); cout << (char)219;
	GoTo(_x + 23, _y + 1); cout << (char)219;
	GoTo(_x + 23, _y + 2); cout << (char)219;
	GoTo(_x + 23, _y + 3); cout << (char)219;
	GoTo(_x + 23, _y + 4); cout << (char)219;
	GoTo(_x + 23, _y + 5); cout << (char)219;
	GoTo(_x + 23, _y + 6); cout << (char)219;
	GoTo(_x + 23, _y + 7); cout << (char)219;
	GoTo(_x + 23, _y + 8); cout << (char)219;
	GoTo(_x + 24, _y + 1); cout << (char)219;
	GoTo(_x + 24, _y + 2); cout << (char)219;
	GoTo(_x + 24, _y + 3); cout << (char)219;
	GoTo(_x + 24, _y + 4); cout << (char)219;
	GoTo(_x + 24, _y + 5); cout << (char)219;
	GoTo(_x + 24, _y + 6); cout << (char)219;
	GoTo(_x + 24, _y + 7); cout << (char)219;
	GoTo(_x + 24, _y + 8); cout << (char)219;
	GoTo(_x + 25, _y + 1); cout << (char)219;
	GoTo(_x + 25, _y + 5); cout << (char)219;
	GoTo(_x + 26, _y + 1); cout << (char)219;
	GoTo(_x + 26, _y + 5); cout << (char)219;
	GoTo(_x + 27, _y + 1); cout << (char)219;
	GoTo(_x + 27, _y + 5); cout << (char)219;
	GoTo(_x + 28, _y + 1); cout << (char)219;
	GoTo(_x + 28, _y + 2); cout << (char)219;
	GoTo(_x + 28, _y + 4); cout << (char)219;
	GoTo(_x + 28, _y + 5); cout << (char)219;
	GoTo(_x + 28, _y + 6); cout << (char)219;
	GoTo(_x + 29, _y + 2); cout << (char)219;
	GoTo(_x + 29, _y + 3); cout << (char)219;
	GoTo(_x + 29, _y + 4); cout << (char)219;
	GoTo(_x + 29, _y + 5); cout << (char)220;
	GoTo(_x + 29, _y + 6); cout << (char)219;
	GoTo(_x + 29, _y + 7); cout << (char)219;
	GoTo(_x + 29, _y + 8); cout << (char)219;
	GoTo(_x + 30, _y + 3); cout << (char)219;
	GoTo(_x + 30, _y + 7); cout << (char)219;
	GoTo(_x + 30, _y + 8); cout << (char)219;
	GoTo(_x + 32, _y + 2); cout << (char)219;
	GoTo(_x + 32, _y + 3); cout << (char)219;
	GoTo(_x + 32, _y + 4); cout << (char)219;
	GoTo(_x + 32, _y + 5); cout << (char)219;
	GoTo(_x + 32, _y + 6); cout << (char)219;
	GoTo(_x + 32, _y + 7); cout << (char)219;
	GoTo(_x + 33, _y + 1); cout << (char)220;
	GoTo(_x + 33, _y + 2); cout << (char)219;
	GoTo(_x + 33, _y + 3); cout << (char)219;
	GoTo(_x + 33, _y + 4); cout << (char)219;
	GoTo(_x + 33, _y + 5); cout << (char)219;
	GoTo(_x + 33, _y + 6); cout << (char)219;
	GoTo(_x + 33, _y + 7); cout << (char)219;
	GoTo(_x + 33, _y + 8); cout << (char)223;
	GoTo(_x + 34, _y + 1); cout << (char)219;
	GoTo(_x + 34, _y + 2); cout << (char)223;
	GoTo(_x + 34, _y + 7); cout << (char)220;
	GoTo(_x + 34, _y + 8); cout << (char)219;
	GoTo(_x + 35, _y + 1); cout << (char)219;
	GoTo(_x + 35, _y + 8); cout << (char)219;
	GoTo(_x + 36, _y + 1); cout << (char)219;
	GoTo(_x + 36, _y + 8); cout << (char)219;
	GoTo(_x + 37, _y + 1); cout << (char)219;
	GoTo(_x + 37, _y + 8); cout << (char)219;
	GoTo(_x + 38, _y + 1); cout << (char)219;
	GoTo(_x + 38, _y + 8); cout << (char)219;
	GoTo(_x + 39, _y + 1); cout << (char)219;
	GoTo(_x + 39, _y + 2); cout << (char)223;
	GoTo(_x + 39, _y + 7); cout << (char)220;
	GoTo(_x + 39, _y + 8); cout << (char)219;
	GoTo(_x + 40, _y + 1); cout << (char)220;
	GoTo(_x + 40, _y + 2); cout << (char)219;
	GoTo(_x + 40, _y + 3); cout << (char)219;
	GoTo(_x + 40, _y + 4); cout << (char)219;
	GoTo(_x + 40, _y + 5); cout << (char)219;
	GoTo(_x + 40, _y + 6); cout << (char)219;
	GoTo(_x + 40, _y + 7); cout << (char)219;
	GoTo(_x + 40, _y + 8); cout << (char)223;
	GoTo(_x + 41, _y + 2); cout << (char)219;
	GoTo(_x + 41, _y + 3); cout << (char)219;
	GoTo(_x + 41, _y + 4); cout << (char)219;
	GoTo(_x + 41, _y + 5); cout << (char)219;
	GoTo(_x + 41, _y + 6); cout << (char)219;
	GoTo(_x + 41, _y + 7); cout << (char)219;


}
void _draw_MY_BOY(SHORT _x, SHORT _y) {
	GoTo(_x + 6, _y + 3); cout << (char)219;
	GoTo(_x + 6, _y + 4); cout << (char)219;
	GoTo(_x + 6, _y + 5); cout << (char)219;
	GoTo(_x + 6, _y + 6); cout << (char)219;
	GoTo(_x + 6, _y + 7); cout << (char)223;
	GoTo(_x + 6, _y + 11); cout << (char)220;
	GoTo(_x + 6, _y + 12); cout << (char)219;
	GoTo(_x + 6, _y + 13); cout << (char)219;
	GoTo(_x + 7, _y + 2); cout << (char)219;
	GoTo(_x + 7, _y + 5); cout << (char)219;
	GoTo(_x + 7, _y + 7); cout << (char)220;
	GoTo(_x + 7, _y + 8); cout << (char)223;
	GoTo(_x + 7, _y + 11); cout << (char)223;
	GoTo(_x + 7, _y + 13); cout << (char)220;
	GoTo(_x + 8, _y + 1); cout << (char)220;
	GoTo(_x + 8, _y + 4); cout << (char)220;
	GoTo(_x + 8, _y + 8); cout << (char)220;
	GoTo(_x + 8, _y + 9); cout << (char)223;
	GoTo(_x + 8, _y + 10); cout << (char)220;
	GoTo(_x + 8, _y + 13); cout << (char)220;
	GoTo(_x + 9, _y + 1); cout << (char)220;
	GoTo(_x + 9, _y + 4); cout << (char)223;
	GoTo(_x + 9, _y + 9); cout << (char)220;
	GoTo(_x + 9, _y + 10); cout << (char)220;
	GoTo(_x + 9, _y + 13); cout << (char)220;
	GoTo(_x + 10, _y + 1); cout << (char)220;
	GoTo(_x + 10, _y + 3); cout << (char)220;
	GoTo(_x + 10, _y + 9); cout << (char)220;
	GoTo(_x + 10, _y + 10); cout << (char)220;
	GoTo(_x + 10, _y + 13); cout << (char)220;
	GoTo(_x + 11, _y + 1); cout << (char)220;
	GoTo(_x + 11, _y + 3); cout << (char)220;
	GoTo(_x + 11, _y + 7); cout << (char)223;
	GoTo(_x + 11, _y + 9); cout << (char)220;
	GoTo(_x + 11, _y + 10); cout << (char)219;
	GoTo(_x + 11, _y + 13); cout << (char)220;
	GoTo(_x + 12, _y + 1); cout << (char)220;
	GoTo(_x + 12, _y + 4); cout << (char)223;

	GoTo(_x + 12, _y + 7); cout << (char)220;
	GoTo(_x + 12, _y + 9); cout << (char)220;
	GoTo(_x + 12, _y + 11); cout << (char)223;
	GoTo(_x + 12, _y + 13); cout << (char)220;
	GoTo(_x + 13, _y + 1); cout << (char)220;
	GoTo(_x + 13, _y + 4); cout << (char)223;
	GoTo(_x + 13, _y + 8); cout << (char)223;
	GoTo(_x + 13, _y + 9); cout << (char)220;
	GoTo(_x + 13, _y + 11); cout << (char)219;
	GoTo(_x + 13, _y + 13); cout << (char)220;
	GoTo(_x + 14, _y + 1); cout << (char)220;
	GoTo(_x + 14, _y + 4); cout << (char)223;
	GoTo(_x + 14, _y + 5); cout << (char)219;

	GoTo(_x + 14, _y + 8); cout << (char)223;
	GoTo(_x + 14, _y + 9); cout << (char)220;
	GoTo(_x + 14, _y + 11); cout << (char)223;
	GoTo(_x + 14, _y + 12); cout << (char)223;
	GoTo(_x + 14, _y + 13); cout << (char)220;
	GoTo(_x + 15, _y + 1); cout << (char)220;
	GoTo(_x + 15, _y + 3); cout << (char)219;
	GoTo(_x + 15, _y + 8); cout << (char)223;
	GoTo(_x + 15, _y + 9); cout << (char)220;
	GoTo(_x + 15, _y + 10); cout << (char)220;
	GoTo(_x + 15, _y + 12); cout << (char)223;
	GoTo(_x + 15, _y + 13); cout << (char)220;
	GoTo(_x + 16, _y + 1); cout << (char)220;
	GoTo(_x + 16, _y + 4); cout << (char)223;
	GoTo(_x + 16, _y + 8); cout << (char)223;
	GoTo(_x + 16, _y + 9); cout << (char)220;
	GoTo(_x + 16, _y + 10); cout << (char)223;
	GoTo(_x + 16, _y + 12); cout << (char)223;
	GoTo(_x + 16, _y + 13); cout << (char)220;
	GoTo(_x + 17, _y + 1); cout << (char)220;
	GoTo(_x + 17, _y + 4); cout << (char)223;
	GoTo(_x + 17, _y + 8); cout << (char)223;
	GoTo(_x + 17, _y + 9); cout << (char)220;
	GoTo(_x + 17, _y + 10); cout << (char)220;
	GoTo(_x + 17, _y + 11); cout << (char)219;
	GoTo(_x + 17, _y + 13); cout << (char)220;
	GoTo(_x + 18, _y + 1); cout << (char)220;
	GoTo(_x + 18, _y + 3); cout << (char)219;
	GoTo(_x + 18, _y + 5); cout << (char)219;
	GoTo(_x + 18, _y + 7); cout << (char)220;
	GoTo(_x + 18, _y + 9); cout << (char)220;
	GoTo(_x + 18, _y + 10); cout << (char)220;
	GoTo(_x + 18, _y + 13); cout << (char)220;
	GoTo(_x + 19, _y + 1); cout << (char)220;
	GoTo(_x + 19, _y + 4); cout << (char)223;
	GoTo(_x + 19, _y + 7); cout << (char)223;
	GoTo(_x + 19, _y + 9); cout << (char)223;
	GoTo(_x + 19, _y + 10); cout << (char)220;
	GoTo(_x + 19, _y + 13); cout << (char)220;
	GoTo(_x + 20, _y + 2); cout << (char)219;
	GoTo(_x + 20, _y + 4); cout << (char)223;
	GoTo(_x + 20, _y + 8); cout << (char)220;
	GoTo(_x + 20, _y + 10); cout << (char)220;
	GoTo(_x + 20, _y + 13); cout << (char)220;
	GoTo(_x + 21, _y + 3); cout << (char)219;
	GoTo(_x + 21, _y + 4); cout << (char)220;
	GoTo(_x + 21, _y + 5); cout << (char)219;
	GoTo(_x + 21, _y + 6); cout << (char)219;
	GoTo(_x + 21, _y + 7); cout << (char)219;
	GoTo(_x + 21, _y + 8); cout << (char)223;
	GoTo(_x + 21, _y + 11); cout << (char)219;
	GoTo(_x + 21, _y + 12); cout << (char)219;
	GoTo(_x + 21, _y + 13); cout << (char)219;
}
void _draw_TALK_BOX(SHORT _x, SHORT _y) {
	GoTo(_x + 0, _y + 8); cout << (char)223;
	GoTo(_x + 1, _y + 7); cout << (char)220;
	GoTo(_x + 1, _y + 8); cout << (char)223;
	GoTo(_x + 2, _y + 6); cout << (char)220;
	GoTo(_x + 2, _y + 7); cout << (char)223;
	GoTo(_x + 2, _y + 8); cout << (char)223;
	GoTo(_x + 3, _y + 5); cout << (char)219;
	GoTo(_x + 3, _y + 6); cout << (char)223;
	GoTo(_x + 3, _y + 8); cout << (char)223;
	GoTo(_x + 4, _y + 3); cout << (char)219;
	GoTo(_x + 4, _y + 4); cout << (char)219;
	GoTo(_x + 4, _y + 8); cout << (char)223;
	GoTo(_x + 5, _y + 2); cout << (char)220;
	GoTo(_x + 5, _y + 7); cout << (char)220;
	GoTo(_x + 6, _y + 2); cout << (char)223;
	GoTo(_x + 6, _y + 7); cout << (char)220;
	GoTo(_x + 7, _y + 1); cout << (char)220;
	GoTo(_x + 7, _y + 8); cout << (char)223;
	GoTo(_x + 8, _y + 1); cout << (char)220;
	GoTo(_x + 8, _y + 3); cout << (char)219;
	GoTo(_x + 8, _y + 4); cout << (char)219;
	GoTo(_x + 8, _y + 5); cout << (char)219;
	GoTo(_x + 8, _y + 6); cout << (char)223;
	GoTo(_x + 8, _y + 8); cout << (char)223;
	GoTo(_x + 9, _y + 1); cout << (char)220;
	GoTo(_x + 9, _y + 4); cout << (char)220;
	GoTo(_x + 9, _y + 8); cout << (char)223;
	GoTo(_x + 10, _y + 1); cout << (char)220;
	GoTo(_x + 10, _y + 3); cout << (char)219;
	GoTo(_x + 10, _y + 4); cout << (char)219;
	GoTo(_x + 10, _y + 5); cout << (char)219;
	GoTo(_x + 10, _y + 6); cout << (char)223;
	GoTo(_x + 10, _y + 8); cout << (char)223;
	GoTo(_x + 11, _y + 1); cout << (char)220;
	GoTo(_x + 11, _y + 8); cout << (char)223;
	GoTo(_x + 12, _y + 1); cout << (char)220;
	GoTo(_x + 12, _y + 3); cout << (char)219;
	GoTo(_x + 12, _y + 4); cout << (char)219;
	GoTo(_x + 12, _y + 5); cout << (char)219;
	GoTo(_x + 12, _y + 6); cout << (char)223;
	GoTo(_x + 12, _y + 8); cout << (char)223;
	GoTo(_x + 13, _y + 1); cout << (char)220;
	GoTo(_x + 13, _y + 3); cout << (char)223;
	GoTo(_x + 13, _y + 4); cout << (char)220;
	GoTo(_x + 13, _y + 6); cout << (char)223;
	GoTo(_x + 13, _y + 8); cout << (char)223;
	GoTo(_x + 14, _y + 1); cout << (char)220;
	GoTo(_x + 14, _y + 3); cout << (char)223;
	GoTo(_x + 14, _y + 4); cout << (char)220;
	GoTo(_x + 14, _y + 6); cout << (char)223;
	GoTo(_x + 14, _y + 8); cout << (char)223;
	GoTo(_x + 15, _y + 1); cout << (char)220;

	GoTo(_x + 15, _y + 8); cout << (char)223;
	GoTo(_x + 16, _y + 1); cout << (char)220;
	GoTo(_x + 16, _y + 3); cout << (char)219;
	GoTo(_x + 16, _y + 4); cout << (char)219;
	GoTo(_x + 16, _y + 5); cout << (char)219;
	GoTo(_x + 16, _y + 6); cout << (char)223;
	GoTo(_x + 16, _y + 8); cout << (char)223;
	GoTo(_x + 17, _y + 1); cout << (char)220;
	GoTo(_x + 17, _y + 6); cout << (char)223;
	GoTo(_x + 17, _y + 8); cout << (char)223;
	GoTo(_x + 18, _y + 1); cout << (char)220;
	GoTo(_x + 18, _y + 6); cout << (char)223;
	GoTo(_x + 18, _y + 8); cout << (char)223;
	GoTo(_x + 19, _y + 1); cout << (char)220;
	GoTo(_x + 19, _y + 8); cout << (char)223;
	GoTo(_x + 20, _y + 1); cout << (char)220;
	GoTo(_x + 20, _y + 3); cout << (char)219;
	GoTo(_x + 20, _y + 4); cout << (char)219;
	GoTo(_x + 20, _y + 5); cout << (char)219;
	GoTo(_x + 20, _y + 6); cout << (char)223;
	GoTo(_x + 20, _y + 8); cout << (char)223;
	GoTo(_x + 21, _y + 1); cout << (char)220;
	GoTo(_x + 21, _y + 6); cout << (char)223;
	GoTo(_x + 21, _y + 8); cout << (char)223;
	GoTo(_x + 22, _y + 1); cout << (char)220;
	GoTo(_x + 22, _y + 6); cout << (char)223;
	GoTo(_x + 22, _y + 8); cout << (char)223;
	GoTo(_x + 23, _y + 1); cout << (char)220;
	GoTo(_x + 23, _y + 8); cout << (char)223;
	GoTo(_x + 24, _y + 1); cout << (char)220;
	GoTo(_x + 24, _y + 3); cout << (char)220;
	GoTo(_x + 24, _y + 4); cout << (char)219;
	GoTo(_x + 24, _y + 5); cout << (char)219;
	GoTo(_x + 24, _y + 8); cout << (char)223;
	GoTo(_x + 25, _y + 1); cout << (char)220;
	GoTo(_x + 25, _y + 3); cout << (char)223;
	GoTo(_x + 25, _y + 6); cout << (char)223;
	GoTo(_x + 25, _y + 8); cout << (char)223;
	GoTo(_x + 26, _y + 1); cout << (char)220;
	GoTo(_x + 26, _y + 3); cout << (char)223;
	GoTo(_x + 26, _y + 6); cout << (char)223;
	GoTo(_x + 26, _y + 8); cout << (char)223;
	GoTo(_x + 27, _y + 1); cout << (char)220;
	GoTo(_x + 27, _y + 3); cout << (char)220;
	GoTo(_x + 27, _y + 4); cout << (char)219;
	GoTo(_x + 27, _y + 5); cout << (char)219;
	GoTo(_x + 27, _y + 8); cout << (char)223;
	GoTo(_x + 28, _y + 1); cout << (char)220;
	GoTo(_x + 28, _y + 8); cout << (char)223;
	GoTo(_x + 29, _y + 2); cout << (char)223;
	GoTo(_x + 29, _y + 7); cout << (char)220;
	GoTo(_x + 30, _y + 2); cout << (char)220;
	GoTo(_x + 30, _y + 7); cout << (char)223;
	GoTo(_x + 31, _y + 3); cout << (char)219;
	GoTo(_x + 31, _y + 4); cout << (char)219;
	GoTo(_x + 31, _y + 5); cout << (char)219;
	GoTo(_x + 31, _y + 6); cout << (char)219;


}
void _draw_XO_SHAPE(SHORT _x, SHORT _y) {
	GoTo(_x + 2, _y + 1); cout << (char)219;
	GoTo(_x + 2, _y + 5); cout << (char)219;
	GoTo(_x + 3, _y + 1); cout << (char)219;
	GoTo(_x + 3, _y + 2); cout << (char)223;
	GoTo(_x + 3, _y + 4); cout << (char)220;
	GoTo(_x + 3, _y + 5); cout << (char)219;
	GoTo(_x + 4, _y + 1); cout << (char)220;
	GoTo(_x + 4, _y + 2); cout << (char)219;
	GoTo(_x + 4, _y + 4); cout << (char)219;
	GoTo(_x + 4, _y + 5); cout << (char)223;
	GoTo(_x + 5, _y + 2); cout << (char)219;
	GoTo(_x + 5, _y + 3); cout << (char)219;
	GoTo(_x + 5, _y + 4); cout << (char)219;
	GoTo(_x + 6, _y + 2); cout << (char)220;
	GoTo(_x + 6, _y + 3); cout << (char)219;
	GoTo(_x + 6, _y + 4); cout << (char)223;
	GoTo(_x + 7, _y + 2); cout << (char)220;
	GoTo(_x + 7, _y + 3); cout << (char)219;
	GoTo(_x + 7, _y + 4); cout << (char)223;
	GoTo(_x + 8, _y + 2); cout << (char)219;
	GoTo(_x + 8, _y + 3); cout << (char)219;
	GoTo(_x + 8, _y + 4); cout << (char)219;
	GoTo(_x + 9, _y + 1); cout << (char)220;
	GoTo(_x + 9, _y + 2); cout << (char)219;
	GoTo(_x + 9, _y + 4); cout << (char)219;
	GoTo(_x + 9, _y + 5); cout << (char)223;
	GoTo(_x + 10, _y + 1); cout << (char)219;
	GoTo(_x + 10, _y + 2); cout << (char)223;
	GoTo(_x + 10, _y + 4); cout << (char)220;
	GoTo(_x + 10, _y + 5); cout << (char)219;
	GoTo(_x + 11, _y + 1); cout << (char)219;
	GoTo(_x + 11, _y + 5); cout << (char)219;
	GoTo(_x + 14, _y + 2); cout << (char)219;
	GoTo(_x + 14, _y + 3); cout << (char)219;
	GoTo(_x + 14, _y + 4); cout << (char)219;
	GoTo(_x + 15, _y + 1); cout << (char)220;
	GoTo(_x + 15, _y + 2); cout << (char)219;
	GoTo(_x + 15, _y + 3); cout << (char)219;
	GoTo(_x + 15, _y + 4); cout << (char)219;
	GoTo(_x + 15, _y + 5); cout << (char)223;
	GoTo(_x + 16, _y + 1); cout << (char)219;
	GoTo(_x + 16, _y + 2); cout << (char)223;
	GoTo(_x + 16, _y + 4); cout << (char)220;
	GoTo(_x + 16, _y + 5); cout << (char)219;
	GoTo(_x + 17, _y + 1); cout << (char)219;
	GoTo(_x + 17, _y + 5); cout << (char)219;
	GoTo(_x + 18, _y + 1); cout << (char)219;
	GoTo(_x + 18, _y + 5); cout << (char)219;
	GoTo(_x + 19, _y + 1); cout << (char)219;
	GoTo(_x + 19, _y + 5); cout << (char)219;
	GoTo(_x + 20, _y + 1); cout << (char)219;
	GoTo(_x + 20, _y + 5); cout << (char)219;
	GoTo(_x + 21, _y + 1); cout << (char)219;
	GoTo(_x + 21, _y + 2); cout << (char)223;
	GoTo(_x + 21, _y + 4); cout << (char)220;
	GoTo(_x + 21, _y + 5); cout << (char)219;
	GoTo(_x + 22, _y + 1); cout << (char)220;
	GoTo(_x + 22, _y + 2); cout << (char)219;
	GoTo(_x + 22, _y + 3); cout << (char)219;
	GoTo(_x + 22, _y + 4); cout << (char)219;
	GoTo(_x + 22, _y + 5); cout << (char)223;
	GoTo(_x + 23, _y + 2); cout << (char)219;
	GoTo(_x + 23, _y + 3); cout << (char)219;
	GoTo(_x + 23, _y + 4); cout << (char)219;

}