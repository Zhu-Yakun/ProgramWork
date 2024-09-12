/* 信19 2252085 朱亚琨 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "popstar.h"
using namespace std;

char menu()
{
	cout << "---------------------------------" << endl;
	cout << "A.命令行找出可消除项并标识" << endl;
	cout << "B.命令行完成一次消除（分步骤显示）" << endl;
	cout << "C.命令行完成一关（分步骤显示）" << endl;
	cout << "D.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl;
	cout << "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl;
	cout << "F.伪图形界面完成一次消除（分步骤）" << endl;
	cout << "G.伪图形界面完整版" << endl;
	cout << "Q.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:] ";
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
			cout << "请输入行数(8-10)：" << endl;
			cin >> row;
			cin.clear();
			cin.ignore(65536, '\n');
			if (row >= 8 && row <= 10)
				break;
		}
		while (1) {
			cout << "请输入列数(8-10)：" << endl;
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
				cout << endl << "当前数组：" << endl;
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
						cout << "剩余" << num << "个不可消除项，本关结束！" << endl;
						cct_setcolor();
						break;
					}
				}
				sur_search(map, sub_map, row, col, &r, &c);
				cout << endl << "查找结果数组：" << endl;
				output(sub_map, sub_map, row, col, 2);
				cout << endl << endl << "当前数组(不同色标识)：" << endl; 
				output(map, sub_map, row, col, 3);
				if (select != 'A'){
					char dlt;
					cout << endl << "请确认是否把" << r << c << "及周围的相同值消除(Y / N / Q)：";
					while (1) {
						dlt = _getche();
						if (dlt != 'Y' && dlt != 'y' && dlt != 'N' && dlt != 'n' && dlt != 'Q' && dlt != 'q')
							continue;
					}
					if (dlt == 'Y' || dlt == 'y'){
						cnt = merge(map, sub_map, row, col, 0, b);
						cout << endl << "相同值归并后的数组(不同色标识)：" << endl;
						output(map, sub_map, row, col, 4);
						score += cnt * cnt * 5;
						cout << endl << "本次得分：" << cnt * cnt * 5 << " 总得分：" << score << endl;
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
					cout << endl << "按回车键进行数组下落操作..." << endl;
					ch = getchar();
					while ((ch = getchar()) != '\n')
						;
					land(map, sub_map, row, col, 0, b);
					cout << "下落后的数组：" << endl;
					output(map, sub_map, row, col, 1);
				}
				if (select != 'C')
					break;
				else{
					cout << endl << "本次消除结束，按回车键继续新一次的消除..." << endl;
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
