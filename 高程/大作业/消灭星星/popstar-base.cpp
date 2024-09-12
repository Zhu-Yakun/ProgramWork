/* 信19 2252085 朱亚琨 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "popstar.h"
#include <time.h>
#include <windows.h>
using namespace std;

int check(char map[2 + ROW][4 + COL * 3], int row, int col, int c)
{
	bool flag = 0;    //该列全空返回0，否则返回1
	for (int i = 2; i < 2 + row; i++)
		if (map[i][c] != '0') {
			flag = 1;
			break;
		}
	return flag;
}

void output(char ch[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int b)
{
	for (int i = 0; i < 2 + row; i++){
		for (int j = 0; j < 4 + col * 3; j++){
			if (ch[i][j] == 0)
				ch[i][j] = '0';
			if ((b == 1 || (b == 3 && ch[i][j] != '0') || (b == 4 && sub_map[i][j] == '*')) 
				&& (sub_map[i][j] == '*' || sub_map[i][j] == '#'))
				cct_setcolor(COLOR_GREEN, COLOR_HWHITE);
			if (sub_map[i][j] == '#')
				cout << '0';
			else
				cout << ch[i][j];
			cct_setcolor();
		}
		cout << endl;
	}
}

void to_old(char sub_map[2 + ROW][4 + COL * 3], int row, int col)
{
	for (int i = 2; i < 2 + row; i++)
		for (int j = 4; j < 4 + 3 * col; j++)
			if (sub_map[i][j] == '*')
				sub_map[i][j] = '#';
}

void initial_map(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col)
{
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 2 + row; i++)
		for (int j = 0; j < 4 + col * 3; j++)
			sub_map[i][j] = 0;
	for (int i = 2; i < 2 + row; i++){
		map[i][0] = 'A' - 2 + i;
		map[i][1] = ' ';
		map[i][2] = '|';
		map[i][3] = ' ';
		sub_map[i][0] = 'A' - 2 + i;
		sub_map[i][1] = ' ';
		sub_map[i][2] = '|';
		sub_map[i][3] = ' ';
		for (int j = 4; j < 4 + col * 3; j += 3){
			map[i][j] = ' ';
			map[i][j + 1] = '1' + rand() % 5;
			map[i][j + 2] = ' ';
			sub_map[i][j] = ' ';
			sub_map[i][j + 2] = ' ';
		}
	}
	for (int j = 1; j < 4 + col * 3; j += 3){
		map[0][j] = ' ';
		map[0][j + 2] = ' ';
		sub_map[0][j] = ' ';
		sub_map[0][j + 2] = ' ';
		if (j / 3 - 1 >= 0) {
			map[0][j + 1] = j / 3 - 1 + '0';
			sub_map[0][j + 1] = j / 3 - 1 + '0';
		}
		else{
			map[0][j + 1] = '|';
			sub_map[0][j + 1] = '|';
		}
	}
	for (int j = 0; j < 4 + col * 3; j++){
		map[1][j] = '-';
		sub_map[1][j] = '-';
	}
	map[0][0] = ' ';
	map[1][2] = '+';
	sub_map[0][0] = ' ';
	sub_map[1][2] = '+';
}

bool sub_find(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int r, int c, int read)
{
	int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
	bool flag = 0;
	for (int i = 0; i < 4; ++i){
		int _r = r + delta[i][0];
		int _c = c + delta[i][1];
		if ((_r >= 'A') && (_r < 'A' + row) && (_c >= '0') && (_c < '0' + col)
			&& map[r - 'A' + 2][5 + 3 * (c - '0')] == map[_r - 'A' + 2][5 + 3 * (_c - '0')] 
			&& sub_map[_r - 'A' + 2][5 + 3 * (_c - '0')] != '*' && map[r - 'A' + 2][5 + 3 * (c - '0')] != '0') {
			flag = 1;
			if(read)
				return flag;
			sub_map[_r - 'A' + 2][5 + 3 * (_c - '0')] = '*';
			sub_find(map, sub_map, row, col, _r, _c, 0);
		}
	}
	return flag;
}

void sur_search(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, char* r, char* c)
{
	int x, y;
	bool flag1 = 0, flag2 = 0;
	while (1){
		cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		if (flag2)
			cout << "               \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cin >> *r >> *c;
		if (*r >= 'a' && *r <= 'z')
			*r -= 32;
		if ((*r >= 'A' && *r <= 'A' + row - 1) && (*c >= '0' && *c <= '0' + col - 1))
			break;
		else{
			cout << "输入错误，请重新输入.";
			cct_getxy(x, y);
			cct_gotoxy(0, y - 1);
			flag2 = 1;
		}
	}
	cout << "输入为" << *r << "行" << *c << "列" << endl;
	flag1 = sub_find(map, sub_map, row, col, *r, *c, 0);
	if (flag1)
		sub_map[*r - 'A' + 2][5 + 3 * (*c - '0')] = '*';
	else{
		cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		sur_search(map, sub_map, row, col, r, c);
	}
}

int merge(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, bool dr, bool b)
{
	int cnt = 0;
	for (int i = 2; i < 2 + row; i++)
		for (int j = 4; j < 4 + 3 * col; j++)
			if (sub_map[i][j] == '*' && map[i][j] != '0'){
				map[i][j] = '0';
				sub_map[i][j] = '*';
				cnt++;
			}
	return cnt;
}

void land(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, bool dr, int b)
{
	for (int j = 4; j < 4 + 3 * col; j++){
		for (int i = 1 + row; i >= 2 ; i--){
			if (map[i][j] == '0'){
				int k = i - 1;
				while (k >= 2 && map[k][j] == '0')
					k--;
				if (k == 1)
					break;
				map[i][j] = map[k][j];
				sub_map[i][j] = 0;
				map[k][j] = '0';
				sub_map[k][j] = '*';
				if (dr)
					move_block(map, k - 2, (j - 4) / 3, i - 2, (j - 4) / 3, b, 0);
			}
		}
	}
	for (int j = 4; j < 4 + 3 * col; j++) {
		bool flag = 0;
		for (int i = 2; i < 2 + row; i++)
			if (map[i][j] != '0') {
				flag = 1;
				break;
			}
		if (!flag)
			hor_move(map, sub_map, row, col, j, dr, b);
	}
}

void hor_move(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int c, bool dr, bool b)
{
	for(int j = c; j < 1 + 3 * col; j += 3)
		for (int i = 2; i < 2 + row; i++){
			int delta = 3;
			if (j + delta < 1 + 3 * col && !check(map, row, col, j + delta))
				delta += 3;
			while (j + delta + 3 < 1 + 3 * col && !check(map, row, col, j + delta))
				delta += 3;
			map[i][j] = map[i][j + delta];
			sub_map[i][j] = 0;
			map[i][j + delta] = '0';
			sub_map[i][j + delta] = '*';
			if (dr && map[i][j] != '0')
				move_block(map, i - 2, (j + delta - 4) / 3, i - 2, (j - 4) / 3 , b, 1);
		}
}