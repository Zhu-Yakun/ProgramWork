/* 信19 2252085 朱亚琨 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "popstar.h"
#include <time.h>
#include <windows.h>
using namespace std;

void draw_frame(int i, int R, int col, bool b)
{
	if (i == 0)
		for (int j = 0; j < 3 * col + 2 + b * (col - 1); j++){
			if(j % 5 == 0)
				Sleep(1);
			if (j == 0)
				cout << "╔";
			else if (j == 3 * col + 1 + b * (col - 1))
				cout << "╗";
			else if (j % 4 == 0 && b)
				cout << "╦";
			else
				cout << "═";
		}
	else if (i == R - 7)
		for (int j = 0; j < 3 * col + 2 + b * (col - 1); j++){
			if (j % 5 == 0)
				Sleep(1);
			if (j == 0)
				cout << "╚";
			else if (j == 3 * col + 1 + b * (col - 1))
				cout << "╝";
			else if (j % 4 == 0 && b)
				cout << "╩";
			else
				cout << "═";
		}
	else if (i % 4 == 0 && b)
		for (int j = 0; j < 3 * col + 2 + b * (col - 1); j++){
			if (j % 5 == 0)
				Sleep(1);
			if (j == 0)
				cout << "╠";
			else if (j == 3 * col + 1 + b * (col - 1))
				cout << "╣";
			else if (j % 4 == 0)
				cout << "╬";
			else
				cout << "═";
		}
	else
		for (int j = 0; j < 3 * col + 2 + b * (col - 1); j++){
			if (j % 5 == 0)
				Sleep(1);
			if (b){
				if (j % 4 == 0)
					cout << "║";
				else
					cout << "  ";
			}
			else{
				if (j == 0 || j == 3 * col + 1 + b * (col - 1))
					cout << "║";
				else
					cout << "  ";
			}
		}
}

void move_block(char map[2 + ROW][4 + COL * 3], int s_r, int s_c, int e_r, int e_c, bool b, bool h)
{
	int s_x = 4 + (6 + 2 * b) * s_c, s_y = (3 + b) * s_r + 3;
	int e_x = 4 + (6 + 2 * b) * e_c, e_y = (3 + b) * e_r + 3;
	int bg = map[e_r + 2][5 + 3 * e_c] - '0';
	if (h) {
		while (s_x > e_x) {
			cct_gotoxy(s_x, s_y);
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "      ";
			cct_gotoxy(s_x, s_y + 1);
			cout << "      ";
			cct_gotoxy(s_x, s_y + 2);
			cout << "      ";
			cct_gotoxy(s_x - 1, s_y);
			cct_setcolor(bg, COLOR_BLACK);
			cout << "╔═╗";
			cct_gotoxy(s_x - 1, s_y + 1);
			cout << "║★║";
			cct_gotoxy(s_x - 1, s_y + 2);
			cout << "╚═╝";
			s_x--;
			if (b && (s_x - 4) % 8 == 0) {
				cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
				cct_gotoxy(s_x + 6, s_y);
				cout << "║";
				cct_gotoxy(s_x + 6, s_y + 1);
				cout << "║";
				cct_gotoxy(s_x + 6, s_y + 2);
				cout << "║";
			}
			cct_setcolor();
			Sleep(10);
		}
	}
	else {
		while (s_y < e_y) {
			cct_gotoxy(s_x, s_y);
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "      ";
			cct_gotoxy(s_x, s_y + 1);
			cout << "      ";
			cct_gotoxy(s_x, s_y + 2);
			cout << "      ";
			cct_gotoxy(s_x, s_y + 1);
			cct_setcolor(bg, COLOR_BLACK);
			cout << "╔═╗";
			cct_gotoxy(s_x, s_y + 2);
			cout << "║★║";
			cct_gotoxy(s_x, s_y + 3);
			cout << "╚═╝";
			s_y++;
			if (b && (s_y - 3) % 4 == 0) {
				cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
				cct_gotoxy(s_x, s_y - 1);
				cout << "═══";
			}
			cct_setcolor();
			Sleep(10);
		}
	}
}

void draw_block(char map[2 + ROW][4 + COL * 3], int r, int c, bool b, int hl)
{
	int x = 4 + (6 + 2 * b) * c, y = (3 + b) * r + 3;
	cct_gotoxy(x, y);             //r 和 c 指的是纯数表中的r行c列
	int bg = map[r + 2][5 + 3 * c] - '0';
	if (bg == 0)
		hl = 3;
	if(hl == 1)
		cct_setcolor(bg, COLOR_HWHITE);
	else if(hl == 2)
		cct_setcolor(bg, COLOR_WHITE);
	else if(hl == 3)
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
	else
		cct_setcolor(bg, COLOR_BLACK);
	cout << "╔═╗";
	cct_gotoxy(x, y + 1);
	cout << "║★║";
	cct_gotoxy(x, y + 2);
	cout << "╚═╝";
	cct_setcolor();
}

void keyboard(char map[2 + ROW][4 + COL * 3], int* r, int* c, int keycode1, int keycode2, int row, int col) 
{
	if (keycode1 == 224)
		switch (keycode2) {
			case KB_ARROW_UP:
				if (*r == 'A')
					*r = row + 'A';
				(*r)--;
				while (map[2 + *r - 'A'][5 + 3 * (*c - '0')] == '0') {
					if (*r == 'A')
						*r = row + 'A';
					(*r)--;
				}
				break;
			case KB_ARROW_DOWN:
				if (*r == row - 1 + 'A')
					*r = 'A' - 1;
				(*r)++;
				while (map[2 + *r - 'A'][5 + 3 * (*c - '0')] == '0') {
					if (*r == row - 1 + 'A')
						*r = 'A' - 1;
					(*r)++;
				}
				break;
			case KB_ARROW_LEFT:
				if (*c == '0')
					*c = col + '0';
				(*c)--;
				while (map[2 + *r - 'A'][5 + 3 * (*c - '0')] == '0') {
					if (*c == '0')
						*c = col + '0';
					(*c)--;
				}
				break;
			case KB_ARROW_RIGHT:
				if (*c == col - 1 + '0')
					*c = '0' - 1;
				(*c)++;
				while (map[2 + *r - 'A'][5 + 3 * (*c - '0')] == '0') {
					if (*c == col - 1 + '0')
						*c = '0' - 1;
					(*c)++;
				}
				break;
		}
}

int in_range(char map[2 + ROW][4 + COL * 3], int X, int Y, int R, int C, bool b, int click, int* p_r, int* p_c)
{
	bool flag = 1;
	int _r = *p_r, _c = *p_c;
	if (Y < 3 || Y > R - 6 || X < 4 || X > C - 2)
		flag = 0;
	*p_r = (Y - 3) / (3 + b);
	*p_c = (X - 4) / (6 + 2 * b);
	if (((b && (Y - 3) % (3 + b) != 3) || !b) 
		&& *p_r < (R + b - 8)/(3 + b))
		*p_r += 'A';
	else{
		flag = 0;
		*p_r = 1;
	}
	if (((b && (X - 4) % (6 + 2 * b) != 6 && (X - 4) % (6 + 2 * b) != 7) || !b) 
		&& *p_c < (C +2 * b - 7)/(6 + 2 * b))
		*p_c += '0';
	else{
		flag = 0;
		*p_c = 1;
	}
	if (flag && map[*p_r - 'A' + 2][5 + 3 * (*p_c - '0')] == '0')
		flag = 0;
	if (flag){
		cct_gotoxy(0, R - 4);
		cout << "[当前鼠标] " << char(*p_r) << "行" << char(*p_c) << "列";
		cout << "                                                                 ";
		draw_block(map, *p_r - 'A', *p_c - '0', b, 1);
		if (click){
			cct_gotoxy(0, R - 4);
			cout << "选中了" << char(*p_r) << "行" << char(*p_c) << "列";
			cout << "                                                                 ";
		}
		return 1;
	}
	else{
		*p_r = _r;
		*p_c = _c;
		draw_block(map, *p_r - 'A', *p_c - '0', b, 0);
		cct_gotoxy(0, R - 4);
		cout << "[当前鼠标] 位置非法                                                      ";
		return 0;
	}
}

int wipe_block(char map[2+ROW][4+COL*3],char sub_map[2+ROW][4+COL * 3],int* r,int* c,int R,int row,int col,bool b,int* kc1,int* kc2,int _X,int _Y, int *score)
{
	cct_gotoxy(0, R - 4);
	cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成                     ";
	for(int i = 2; i < 2 + row; i++)
		for (int j = 4; j < 4 + 3 * col; j++) {
			if (sub_map[i][j] == '*' && (*r != i - 2 + 'A' || *c != (j - 4) / 3 + '0'))
				draw_block(map, i - 2, (j - 4)/3, b, 2);
		}
	int X = 0, Y = 0, ret, maction, click = 0, flag = 0, k_click = 0, C = col * 6 + 7 + 2 * b * (col - 1);
	while (1) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, *kc1, *kc2);
		if (ret == CCT_KEYBOARD_EVENT) {
			if (*kc1 == '\r') {
				click = 1;
				k_click = 1;
			}
			else if (*kc1 == 'Q' || *kc1 == 'q')
				return 2;
			flag = 2;
			break;
		}
		else if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_RIGHT_BUTTON_CLICK)
				return 2;
			int c = (X - 4) / (6 + 2 * b), _c = (_X - 4) / (6 + 2 * b);
			int r = (Y - 3) / (3 + b), _r = (_Y - 3) / (3 + b);
			if ((r != _r || c != _c) || ((b && ((X - 4) % (6 + 2 * b) == 6 || (X - 4) % (6 + 2 * b) == 7)))
				|| c >= (C + 2 * b - 7) / (6 + 2 * b)
				|| ((b && (Y - 3) % (3 + b) == 3) || ((Y - 3) / (3 + b) >= (R + b - 8) / (3 + b)))) {
				flag = 1;
				break;
			}
			if (maction == MOUSE_LEFT_BUTTON_CLICK || maction == MOUSE_LEFT_BUTTON_DOUBLE_CLICK) {
				click = 1;
				break;
			}
		}
	}
	if (flag && click == 0) {
		for (int i = 2; i < 2 + row; i++)
			for (int j = 4; j < 4 + 3 * col; j++) {
				if (sub_map[i][j] == '*') {
					sub_map[i][j] = 0;
					draw_block(map, i - 2, (j - 4) / 3, b, 0);
				}
			}
		keyboard(map, r, c, *kc1, *kc2, row, col);
		in_range(map, X, Y, R, C, b, 0, r, c);
		return 1;
	}
	if (click) {
		for (int i = 2; i < 2 + row; i++)   //消除星星
			for (int j = 4; j < 4 + 3 * col; j++) {
				if (sub_map[i][j] == '*') {
					draw_block(map, i - 2, (j - 4) / 3, b, 3);
				}
			}
		sound_effect(2);
		int cnt = merge(map, sub_map, row, col, 1, b);
		if (!b) {
			cct_gotoxy(0, R - 4);
			cout << "合成完成，回车键/单击左键下落0                                   ";
			while (1) {
				cct_read_keyboard_and_mouse(X, Y, maction, *kc1, *kc2);
				if (*kc1 == '\r' || maction == MOUSE_LEFT_BUTTON_CLICK)
					break;
			}
		}
		land(map, sub_map, row, col, 1, b);
		if (!b) {
			cct_gotoxy(0, R - 4);
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cout << "本次合成结束，按C/单击左键继续新一次的合成                        ";
			cct_setcolor();
			while (1) {
				cct_read_keyboard_and_mouse(X, Y, maction, *kc1, *kc2);
				if (*kc1 == 'C' || *kc1 == 'c' || maction == MOUSE_LEFT_BUTTON_CLICK)
					break;
			}
		}
		int ret3  = cal_score(score, cnt, map, sub_map, row, col, R);
		if (!b)
			return 2;
		if (ret3 == 1)
			return 3;
		if (k_click) {
			for(int i = 2; i < 2 + col; i++)
				if (map[i][5] != '0') {
					*r = 'A' + (i - 2);
					*c = '0';
					draw_block(map, *r - 'A', *c - '0', b, 1);
					return 4;
				}
		}
	}
	return 0;
}

int pgraph(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, bool b, char select, int *score, bool prime)
{
	if(!prime)
		initial_map(map, sub_map, row, col);
	cct_cls();
	int R = row * 3 + 8 + b * (row - 1), C = col * 6 + 7 + 2 * b * (col - 1), m = 0;
	int X = 0, Y = 0, ret, maction, keycode1 = 0, keycode2 = 0, loop = 1, click;
	int r = 'A', c = '0', _r = 'A', _c = '0', ret1 = 0;
	cct_setconsoleborder(C, R, C + 1, R + 1);
	cout << "屏幕当前设置为：" << R << "行" << C << "列" << endl << " ";
	for (int j = 0; j < col; j++){            //横向打印列标
		if (b && j != 0)
			cout << "  ";
		cout << "     " << j;
	}
	cout << endl;
	for (int i = 0; i < R - 6; i++){
		if (i == (3 + b) * m + 2){             //打印行标
			cout << char('A' + m) << ' ';
			m++;
		}
		else
			cout << "  ";
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		draw_frame(i, R, col, b);              //打印本行的边框
		cct_setcolor();
		cout << " " << endl;
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			draw_block(map, i, j, b, 0);       //打印初始的星星色块
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	draw_block(map, _r - 'A', _c - '0', b, 1);    //初始位置定在A行0列，反显
	cct_gotoxy(0, R - 4);
	cout << "箭头键/鼠标移动，回车键/单击左键选择";
	if (select == 'D' || select == 'E')
		cout << "并结束";
	else
		cout << "，Q/单击右键结束";
	while (loop){
		int rt = 1;         //位置是否合法的返回值，初始默认合法
		if (keycode1 == 224 && ret1) {     //如果上次选中后没有进行消除，按了方向键，则在新的位置反显
			if ((_r != r || _c != c) && _r && _c)
				draw_block(map, _r - 'A', _c - '0', b, 0);   //消除旧的位置的反显
			ret = 0;
			_r = r;
			_c = c;
			draw_block(map, r - 'A', c - '0', b, 1);
			cct_gotoxy(0, R - 4);
			cout << "[当前鼠标] " << char(r) << "行" << char(c) << "列";
			cout << "                                                                 ";
		}
		if (ret1 == 4) {
			_r = r;
			_c = c;
		}
		click = 0;
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT){
			if (maction == MOUSE_LEFT_BUTTON_CLICK || maction == MOUSE_LEFT_BUTTON_DOUBLE_CLICK)
				click = 1;
			if (maction == MOUSE_RIGHT_BUTTON_CLICK)
				return 1;
			rt = in_range(map, X, Y, R, C, b, click, &r, &c);   
		}
		else if (ret == CCT_KEYBOARD_EVENT) {
			if (keycode1 == 224)
				keyboard(map, &r, &c, keycode1, keycode2, row, col);
			else if (keycode1 == '\r' && (select == 'D' || select == 'E'))
				return 1;
			else if (keycode1 == '\r')
				click = 1;
			else if (keycode1 == 'Q' || keycode1 == 'q')
				return 1;
			draw_block(map, r - 'A', c - '0', b, 1);
			cct_gotoxy(0, R - 4);
			cout << "[当前鼠标] " << char(r) << "行" << char(c) << "列";
			cout << "                                                                 ";
		} 
		if ((_r != r || _c != c) && _r && _c)
			draw_block(map, _r - 'A', _c - '0', b, 0);   //消除旧的位置的反显
		if (rt || ret == CCT_KEYBOARD_EVENT) {
			_r = r;
			_c = c;
		}
		if (click && rt) {
			sound_effect(1);
			if (select == 'D' || select == 'E')
				return 1;
			else {
				if (sub_find(map, sub_map, row, col, r, c, 0))
					ret1 = wipe_block(map, sub_map, &r, &c, R, row, col, b, &keycode1, &keycode2, X, Y, score);
				else {
					for (int i = 2; i < 2 + row; i++)
						for (int j = 4; j < 4 + col * 3; j += 3)
							if (sub_map[i][j] == '*')
								sub_map[i][j] = 0;
					cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cct_gotoxy(0, R - 4);
					cout << "周围无相同值，";
					cct_setcolor();
					cout << "箭头键/鼠标移动，回车键/单击左键选择，Q/单击右键结束";
					while (1) {
						int x = X, y = Y;
						ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
						if (ret == CCT_MOUSE_EVENT) {
							if (maction == MOUSE_RIGHT_BUTTON_CLICK)
								return 1;
							if (x != X || y != Y)
								break;
						}
						else if (ret == CCT_KEYBOARD_EVENT) {
							if (keycode1 == 'Q' || keycode1 == 'q')
								return 1;
							keyboard(map, &r, &c, keycode1, keycode2, row, col);
							ret1 = 4;
							break;
						}
					}
				}
			}
		}
		if (ret1 == 2)
			return 1;
		if (ret1 == 3)
			pgraph(map, sub_map, row, col, b, select, score, 0);
	}
	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
	return 0;
}
