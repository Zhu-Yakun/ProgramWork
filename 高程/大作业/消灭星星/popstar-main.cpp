/* ��19 2252085 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "popstar.h"
using namespace std;

char menu()
{
	cout << "---------------------------------" << endl;
	cout << "A.�������ҳ����������ʶ" << endl;
	cout << "B.���������һ���������ֲ�����ʾ��" << endl;
	cout << "C.���������һ�أ��ֲ�����ʾ��" << endl;
	cout << "D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�" << endl;
	cout << "E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�" << endl;
	cout << "F.αͼ�ν������һ���������ֲ��裩" << endl;
	cout << "G.αͼ�ν���������" << endl;
	cout << "Q.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:] ";
	char ch;
	while (((ch = _getche()) < 'A' || ch > 'G') && ch != 'Q')
		cout << "\b \b";
	cout << endl << endl;
	return ch;
}

int main() 
{
	while (1){
		cct_cls();
		int row, col, score = 0, cnt = 0, ret = 0;
		char map[2 + ROW][4 + COL * 3] = { 0 }, sub_map[2 + ROW][4 + COL * 3] = { 0 }, ch;
		char select = menu();
		cct_cls();
		while (1) {
			cout << "����������(8-10)��" << endl;
			cin >> row;
			cin.clear();
			cin.ignore(65536, '\n');
			if (row >= 8 && row <= 10)
				break;
		}
		while (1) {
			cout << "����������(8-10)��" << endl;
			cin >> col;
			cin.clear();
			cin.ignore(65536, '\n');
			if (col >= 8 && col <= 10)
				break;
		}
		initial_map(map, sub_map, row, col);
		bool b = (select == 'E' || select == 'G');
		int R = row * 3 + 8 + b * (row - 1);
		if(select == 'D' || select == 'E' || select == 'F' || select == 'G')
			ret = pgraph(map, sub_map, row, col, b, select, &score, 1);
		else
			while (1){
				char r, c;
				cout << endl << "��ǰ���飺" << endl;
				output(map, sub_map, row, col, 1);
				cout << endl;
				if (select == 'C') {
					int retC = 0;
					for (int i = 'A'; i < 'A' + row - 1; i++) {
						for (int j = '0'; j < '0' + col - 1; j++) {
							retC = sub_find(map, sub_map, row, col, i, j, 1);
							if (retC == 1)
								break;
						}
						if (retC == 1)
							break;
					}
					if (!retC) {
						int num = 0;
						for (int i = 2; i < 2 + row; i++)
							for (int j = 4; j < 4 + 3 * col; j++)
								if (map[i][j] > '0' && map[i][j] <= '5')
									num++;
						cct_setcolor(COLOR_GREEN, COLOR_HWHITE);
						cout << "ʣ��" << num << "��������������ؽ�����" << endl;
						cct_setcolor();
						break;
					}
				}
				sur_search(map, sub_map, row, col, &r, &c);
				cout << endl << "���ҽ�����飺" << endl;
				output(sub_map, sub_map, row, col, 2);
				cout << endl << endl << "��ǰ����(��ͬɫ��ʶ)��" << endl; 
				output(map, sub_map, row, col, 3);
				if (select != 'A'){
					char dlt;
					cout << endl << "��ȷ���Ƿ��" << r << c << "����Χ����ֵͬ����(Y / N / Q)��";
					while (1) {
						dlt = _getche();
						if (dlt != 'Y' && dlt != 'y' && dlt != 'N' && dlt != 'n' && dlt != 'Q' && dlt != 'q')
							continue;
					}
					if (dlt == 'Y' || dlt == 'y'){
						cnt = merge(map, sub_map, row, col, 0, b);
						cout << endl << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
						output(map, sub_map, row, col, 4);
						score += cnt * cnt * 5;
						cout << endl << "���ε÷֣�" << cnt * cnt * 5 << " �ܵ÷֣�" << score << endl;
						if(select == 'B')
							break;
					}
					else if (dlt == 'N' || dlt == 'n') {
						for (int i = 0; i < 2 + row; i++)
							for (int j = 0; j < 4 + col * 3; j++)
								if (sub_map[i][j] == '*')
									sub_map[i][j] = 0;
						continue;
					}
					else if (dlt == 'Q' || dlt == 'q')
						to_be_continued(0);
					cout << endl << "���س������������������..." << endl;
					ch = getchar();
					while ((ch = getchar()) != '\n')
						;
					land(map, sub_map, row, col, 0, b);
					cout << "���������飺" << endl;
					output(map, sub_map, row, col, 1);
				}
				if (select != 'C')
					break;
				else{
					cout << endl << "�����������������س���������һ�ε�����..." << endl;
					while ((ch = getchar()) != '\n')
						;
				}
				to_old(sub_map, row, col);
			}
		if(ret)
			to_be_continued(R);
		else
			to_be_continued(0);
		score = 0;
	}
	return 0;
}
