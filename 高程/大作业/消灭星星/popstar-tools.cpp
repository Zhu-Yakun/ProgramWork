/* ��19 2252085 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "cmd_console_tools.h"
#include "popstar.h"
using namespace std;

void to_be_continued(int R)
{
	char end[20] = { 0 };
	int x, y;
	bool flag = 0;
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	while (1){
		if (R)
			cct_gotoxy(0, R - 3);
		else
			cout << endl << endl;
		cout << "��С�������������End����...";
		if(flag)
			cout << "               \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		fgets(end, 20, stdin);
		_strupr(end);
		end[strlen(end) - 1] = 0;
		if (strcmp(end, "END") == 0)
			break;
		else{
			cct_getxy(x, y);
			cct_gotoxy(0, y - 2);
			flag = 1;
		}
	}
}

int cal_score(int* score, int cnt, char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int R)
{
	*score += cnt * cnt * 5;
	int ret = 0;
	for (int i = 'A'; i < 'A' + row; i++) {
		for (int j = '0'; j < '0' + col; j++) {
			ret = sub_find(map, sub_map, row, col, i, j, 1);
			if (ret == 1)
				break;
		}
		if (ret == 1)
			break;
	}
	if (!ret) {
		int num = 0, ex_score = 0;
		char ch;
		for (int i = 2; i < 2 + row; i++)
			for (int j = 4; j < 4 + 3 * col; j++)
				if (map[i][j] > '0' && map[i][j] <= '5')
					num++;
		if (num < 10)
			ex_score = (10 - num) * 180;
		if (*score > 1000)
			ex_score += 200;
		*score += ex_score;
		cct_gotoxy(0, 0);
		cout << "�����÷֣�" << ex_score << " �ܵ÷֣�" << *score << "                   ";
		if (!ret) {
			cct_gotoxy(0, R - 4);
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cout << "ʣ��" << num << "�����ǣ��޿���������ؽ�����";
			cct_setcolor();
			cout << "�س�������һ��          ";
		}
		sound_effect(3);
		while ((ch = getchar()) != '\n')
			;
		return 1;
	}
	else {
		cct_gotoxy(0, 0);
		cout << "���ε÷֣�" << cnt * cnt * 5 << " �ܵ÷֣�" << *score << "                   ";
	}
	cnt = 0;
	return 0;
}

void sound_effect(int s)
{
	switch (s) {
		case 1:
			Beep(Mdo1, beat / 4);
			break;
		case 2:
			Beep(Mso1, beat / 4);
			Beep(Mla1, beat / 4);
			Beep(Mso1, beat / 4);
			break;
		case 3:
			Beep(Mdo1, beat / 4);
			Beep(Mre1, beat / 4);
			Beep(Mso1, beat / 4);
			Beep(Mla1, beat / 4);
			break;
	}
}

