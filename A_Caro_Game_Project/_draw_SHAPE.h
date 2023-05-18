#pragma once
#include "View_Functions.h"
#include <math.h>
void _draw_shape_x(SHORT _x, SHORT _y);

void _draw_shape_o(SHORT _x, SHORT _y);

void _draw_shape_caro(SHORT _x, SHORT _y, int _color = 1);

void _draw_shape_qr(SHORT _x, SHORT _y);

void _draw_shape_x_o(SHORT _x, SHORT _y, bool _color = 0);

void _draw_shape_x_win(SHORT _x, SHORT _y);

void _draw_shape_o_win(SHORT _x, SHORT _y);

void _draw_shape_bot_face(SHORT _x, SHORT _y);

void _draw_shape_isdraw(SHORT _x, SHORT _y);

void _draw_animation_win(SHORT _x, SHORT _y, void function(SHORT, SHORT));

void _draw_shape_leftarrow(SHORT _x, SHORT _y);

void _draw_shape_rightarrow(SHORT _x, SHORT _y);

void _draw_shape_newboard(SHORT _x, SHORT _y);

void _draw_shape_setting(SHORT _x, SHORT _y);

void _draw_shape_volume(SHORT _x, SHORT _y);

void _draw_shape_volume_dis(SHORT _x, SHORT _y);

void _draw_shape_continue(SHORT _x, SHORT _y);

void _draw_shape_htp(SHORT _x, SHORT _y);

void _draw_shape_console(SHORT _x, SHORT _y);

void _draw_shape_about(SHORT _x, SHORT _y);

void _draw_shape_littleface(SHORT _x, SHORT _y);

void _draw_shape_robot(SHORT _x, SHORT _y);

void _draw_shape_human(SHORT _x, SHORT _y);

void _draw_shape_vs(SHORT _x, SHORT _y);

void _draw_transition();
