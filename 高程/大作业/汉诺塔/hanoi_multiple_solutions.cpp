/* ��19 2252085 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
#define MIN_Y 2
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
int mov = 4;
int step = 0;
int top[3] = { 0 };
int pst_stack[3][10] = { 0 };

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void to_be_continued()
{
	mov = 4;
	step = 0;
	for (int i = 0; i < 3; i++) {
		top[i] = 0;
		for (int j = 0; j < 10; j++)
			pst_stack[i][j] = 0;
	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor();
	cout << "\n\n\n\n";
	cout << "���س�������...";
	while (getchar() != '\n')
		;
	cct_cls();
	return;
}

int game_order(char* p_src, char* p_dst) 
{
	cct_setcolor();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	char order[20] = { 0 }, ch;
	while (1) {
		cct_gotoxy(0, 33);
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
		cct_gotoxy(59, 33);
		for (int i = 0; i < 20; ) {
			ch = _getche();
			if (ch == '\r' || ch == '\n') {
				cout << endl;
				break;
			}
			if (ch >= 'a' && ch <= 'z')
				ch -= 32;
			order[i++] = ch;
			if (i == 20) {
				i = 0;
				for (int j = 0; j < 20; j++)
					order[j] = 0;
				cct_gotoxy(59, 33);
				cout << "                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			}
		}
		if (order[0] == 'Q' && !order[1] && !order[2])
			return 0;
		else if (order[0] >= 'A' && order[0] <= 'C' && order[1] >= 'A'
			&& order[1] <= 'C' && order[0] != order[1] && !order[2]) {
			*p_src = order[0];
			*p_dst = order[1];
		}
		else {
			cct_gotoxy(59, 33);
			cout << "          \b\b\b\b\b\b\b\b\b\b";
			continue;
		}
		if (pst_stack[*p_dst - 'A'][top[*p_dst - 'A'] - 1] < pst_stack[*p_src - 'A'][top[*p_src - 'A'] - 1] && top[*p_dst - 'A']) {
			cout << "����ѹС�̣��Ƿ��ƶ���";
			Sleep(600);
			cct_gotoxy(0, 34);
			cout << "                      ";
			cct_gotoxy(59, 33);
			cout << "  ";
		}
		else if (!top[*p_src - 'A']) {
			cout << "Դ��Ϊ�գ�";
			Sleep(600);
			cct_gotoxy(0, 34);
			cout << "              ";
			cct_gotoxy(59, 33);
			cout << "  ";
		}
		else {
			cct_gotoxy(59, 33);
			cout << "          \b\b\b\b\b\b\b\b\b\b";
			break;
		}
		for (int i = 0; i < 10; i++)
			order[i] = 0;
	}
	return 1;
}

void input_order(int select, int* p_n, char* p_src, char* p_tmp, char* p_dst) 
{
	while (1){
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> *p_n;
		cin.clear();
		cin.ignore(65536, '\n');
		if (*p_n >= 1 && *p_n <= 10)
			break;
	}
	while (1){
		cout << "��������ʼ��(A-C)" << endl;
		cin >> *p_src;
		cin.clear();
		cin.ignore(65536, '\n');
		if (*p_src == 'A' || *p_src == 'B' || *p_src == 'C' || *p_src == 'a' || *p_src == 'b' || *p_src == 'c'){
			if (*p_src == 'a' || *p_src == 'b' || *p_src == 'c')
				*p_src -= 32;
			break;
		}
	}
	while (1){
		cout << "������Ŀ����(A-C)" << endl;
		cin >> *p_dst;
		cin.clear();
		cin.ignore(65536, '\n');
		if ((*p_dst == 'A' || *p_dst == 'B' || *p_dst == 'C' || *p_dst == 'a' || *p_dst == 'b' || *p_dst == 'c')){
			if (*p_dst == 'a' || *p_dst == 'b' || *p_dst == 'c')
				*p_dst -= 32;
			if (*p_src == *p_dst)
				cout << "Ŀ����(" << *p_src << ")��������ʼ��(" << *p_dst << ")��ͬ" << endl;
			else
				break;
		}
	}
	if (select == 4 || select == 8)
		while (1){
			cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
			cin >> mov;
			if (mov >= 0 || mov <= 5)
				break;
		}
	switch (*p_src) {
		case 'A':
			*p_tmp = (*p_dst == 'B') ? 'C' : 'B';
			break;
		case 'B':
			*p_tmp = (*p_dst == 'A') ? 'C' : 'A';
			break;
		case 'C':
			*p_tmp = (*p_dst == 'A') ? 'B' : 'A';
			break;
	}
	int t = *p_n;
	for (int i = 0; i < *p_n; i++)
		pst_stack[*p_src - 'A'][i] = t--;
	top[*p_src - 'A'] = *p_n;
}

void sleep(int mov)
{
	switch (mov)
	{
		case 0:
			while (getchar() != '\n')
				;
			break;
		case 1:
			Sleep(300);
			break;
		case 2:
			Sleep(200);
			break;
		case 3:
			Sleep(100);
			break;
		case 4:
			Sleep(30);
			break;
		case 5:
			Sleep(5);
			break;
	}
}

void print_plate(int x, int y, int n, char src, char tmp, char dst, int select)
{
	cct_setcolor();
	cct_setcursor(CURSOR_INVISIBLE);
	if (select == 4 || select == 8 || select == 9) {
		if(select != 9)
			sleep(mov);
		if ((select == 4 || select == 8 || select == 9) && step == 0) {
			cct_cls();
			cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
			if(select != 9)
				cout << "����ʱ����Ϊ " << mov << "��";
		}
		cct_gotoxy(x - 5, y + 1);
		cout << "=========================" << endl << "       A         B         C";
		x -= 3;
		cct_gotoxy(x, y);
		for (int i = 0; i < 3; i++) {
			int Y = y;
			for (int j = 0; j < 10; j++) {
				if (pst_stack[i][j] != 0)
					cout << pst_stack[i][j];
				else
					cout << ' ';
				cct_gotoxy(x, --Y);
			}
			x += 10;
			cct_gotoxy(x, y);
		}
	}
}

void print_array(int n, char src, char tmp, char dst, int select)
{
	cct_setcolor();
	if (select == 4 || select == 8 || select == 9) 
		cct_gotoxy(0, select*4-9*(select==9) + 5);
	if (select == 2 && step == 0)
		step++;
	if (step == 0 && select !=1 && select != 2) {
		step++;
		cout << "��ʼ:                ";
	}
	else if(select != 1 )
		cout << "��" << setw(4) << step++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
	else
		cout << setw(2) << n << "# " << src << "-->" << dst << endl;
	if (select == 2)
		cout << endl;
	if (select == 3 || select == 4 || select == 8 || select == 9) {
		for (int i = 0; i < 3; i++) {
			cout << " " << char('A' + i) << ":";
			for (int j = 0; j < 10; j++) {
				if (pst_stack[i][j] != 0)
					cout << setw(2) << pst_stack[i][j];
				else
					cout << "  ";
			}
		}
		cout << endl;
	}
}

void draw_post(int select, char src) 
{
	if(select != 8 && select != 9)
		cct_cls();
	cct_setcursor(CURSOR_VISIBLE_FULL);
	for (int i = 1; i < 1 + 23 * 3 + 9 * 2; i += 32) 
		cct_showch(i, 16, ' ', COLOR_HYELLOW, COLOR_HBLUE, 23);
	for (int i = 12; i < 1 + 23 * 3 + 9 * 2; i += 32)
		for (int j = 15; j > 3; j--) {
			Sleep(25);
			cct_showch(i, j, ' ', COLOR_HYELLOW, COLOR_HBLUE, 1);
			cout << "\b";
		}
	if (select == 6 || select == 7 || select == 8 || select == 9) {
		for (int i = top[src - 'A'], j = 0; i > 0; i--, j++) {
			int x = 1 + 11 + (src - 'A') * 32 - i, y = 15 + i - top[src - 'A'];
			cct_showch(x, y, ' ', (pst_stack[src-'A'][j])%16, (pst_stack[src-'A'][j])%16, 2*i+1);
		}
	}
}

void move_plate(int select, char src, char dst) 
{
	int LENGTH = 2 * pst_stack[((select == 8 || select == 9) ? dst : src) - 'A'][top[((select == 8 || select == 9) ? dst : src) - 'A'] - 1] + 1, x, y;
	int X = 1 + 11 + (src - 'A') * 32 - (LENGTH - 1) / 2, Y = 15 - top[src - 'A'] + 1 - (select == 8 || select == 9);
	int bg_color = (pst_stack[((select == 8 || select == 9) ? dst : src) - 'A'][top[((select == 8 || select == 9) ? dst : src) - 'A'] - 1]) % 16;
	int fg_color = (pst_stack[((select == 8 || select == 9) ? dst : src) - 'A'][top[((select == 8 || select == 9) ? dst : src) - 'A'] - 1]) % 16;
	for (y = Y; y >= MIN_Y; y--) {
		cct_showch(X, y, ' ', bg_color, fg_color, LENGTH);
		cct_setcursor(CURSOR_INVISIBLE);
		mov == 0 ? sleep(4) : sleep(mov);
		if (y > MIN_Y) {
			cct_showch(X, y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
			if(y > MIN_Y + 1)
				cct_showch(X + (LENGTH - 1) / 2, y, ' ', COLOR_HYELLOW, COLOR_HBLUE, 1);
		}
	}
	for (x = X; src < dst ? (x <= X + 32 * (dst - src)) : (x >= X - 32 * (src - dst));  src < dst ? (x++) : (x--)) {
		cct_showch(x, y + 1, ' ', bg_color, fg_color, LENGTH);
		cct_setcursor(CURSOR_INVISIBLE);
		mov == 0 ? sleep(4) : sleep(mov);
		if (src < dst ? (x <= X-1+32*(dst-src)) : (x >= X+1-32*(src-dst)))
			cct_showch(x, y + 1, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
	}
	src < dst ? (x--) : (x++);
	for (y++, Y = 16 - top[dst-'A']+(select == 8 || select == 9); y < Y; y++) {
		cct_showch(x, y, ' ', bg_color, fg_color, LENGTH);
		cct_setcursor(CURSOR_INVISIBLE);
		mov == 0 ? sleep(4) : sleep(mov);
		if (y < Y - 1) {
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
			if (y > MIN_Y + 1)
				cct_showch(x + (LENGTH - 1) / 2, y, ' ', COLOR_HYELLOW, COLOR_HBLUE, 1);
		}
	}
	cct_setcolor();
}  

void hanoi(int n, char src, char tmp, char dst, int select)
{
	if (n != 1)
		hanoi(n - 1, src, dst, tmp, select);
	pst_stack[dst - 'A'][top[dst - 'A']++] = pst_stack[src - 'A'][--top[src - 'A']];
	pst_stack[src - 'A'][top[src - 'A']] = 0;
	print_plate(10, select * 4, n, src, tmp, dst, select);
	print_array(n, src, tmp, dst, select);
	if (select == 8)
		move_plate(select, src, dst);
	if (n != 1)
		hanoi(n - 1, tmp, src, dst, select);
	if (n == 1)
		return;
}

void hanoi_game(int n, char src, char tmp, char dst, int select) 
{
	int ret;
	while (1) {
		ret = game_order(&src, &dst);
		if (!ret) {
			cout << "��Ϸ��ֹ!!!!!";
			break;
		}
		pst_stack[dst - 'A'][top[dst - 'A']++] = pst_stack[src - 'A'][--top[src - 'A']];
		pst_stack[src - 'A'][top[src - 'A']] = 0;
		print_plate(10, select * 3, n, src, tmp, dst, select);
		print_array(n, src, tmp, dst, select);
		move_plate(select, src, dst);
		if (top[dst - 'A'] == n)
			break;
	}
	if (ret) {
		cct_gotoxy(0, 34);
		cout << "��Ϸ����!!!!!";
	}
}