/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <iomanip>
#include<Windows.h>
#include"5-b7.h"
using namespace std;

bool pa;
static int mov;
int order = 1;
int topA = 0, topB = 0, topC = 0;
int A_stack[10];
int B_stack[10];
int C_stack[10];

void sleep(int mov)
{
	switch (mov)
	{
		case 0:
			while (getchar() != '\n')
				;
			break;
		case 1:
			Sleep(500);
			break;
		case 2:
			Sleep(300);
			break;
		case 3:
			Sleep(100);
			break;
		case 4:
			Sleep(50);
			break;
		case 5:
			Sleep(5);
			break;
	}
}
void print_plate(char post, int x, int y)
{
	cct_gotoxy(x, y);
	if (post == 'A')
	{
		for (int i = 0; i < 10; i++)
		{
			if (A_stack[i] != ' ')
				cout << A_stack[i] - '0';
			else
			{
				cout << char(A_stack[i]);
				cct_gotoxy(++x, ++y);
				break;
			}
			cct_gotoxy(x, --y);
		}
	}
	if (post == 'B')
	{
		for (int i = 0; i < 10; i++)
		{
			if (B_stack[i] != ' ')
				cout << B_stack[i] - '0';
			else
			{
				cout << char(B_stack[i]);
				cct_gotoxy(++x, ++y);
				break;
			}
			cct_gotoxy(x, --y);
		}
	}
	if (post == 'C')
	{
		for (int i = 0; i < 10; i++)
		{
			if (C_stack[i] != ' ')
				cout << C_stack[i] - '0';
			else
			{
				cout << char(C_stack[i]);
				cct_gotoxy(++x, ++y);
				break;
			}
			cct_gotoxy(x, --y);
		}
	}
}
void print_array()
{
	cout << " A:";
	for (int i = 0; i < 10; i++)
	{
		if (A_stack[i] != ' ')
			cout << setw(2) <<  A_stack[i] - '0';
		else
			cout << " " << char(A_stack[i]);
	}
	cout << " B:";
	for (int i = 0; i < 10; i++)
	{
		if (B_stack[i] != ' ')
			cout << setw(2) << B_stack[i] - '0';
		else
			cout << " " << char(B_stack[i]);
	}
	cout << " C:";
	for (int i = 0; i < 10; i++)
	{
		if (C_stack[i] != ' ')
			cout << setw(2) << C_stack[i] - '0';
		else
			cout << " " << char(C_stack[i]);
	}
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		sleep(mov);
		cct_gotoxy(10, 20);
		cout << "第" << setw(4) << order++ << " 步(" << n << "#: " << src << "-->" << dst << ")  ";
		switch (src)
		{
			case 'A':
				if (dst == 'B')
				{
					B_stack[topB++] = A_stack[--topA];
					A_stack[topA] = ' ';
					if(pa)
						print_array();
					sleep(mov);
					print_plate('A', 7, 14);
					print_plate('B', 17, 14);
				}
				else
				{
					C_stack[topC++] = A_stack[--topA];
					A_stack[topA] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('A', 7, 14);
					print_plate('C', 27, 14);
				}
				break;
			case 'B':
				if (dst == 'A')
				{
					A_stack[topA++] = B_stack[--topB];
					B_stack[topB] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('B', 17, 14);
					print_plate('A', 7, 14);
				}
				else
				{
					C_stack[topC++] = B_stack[--topB];
					B_stack[topB] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('B', 17, 14);
					print_plate('C', 27, 14);
				}
				break;
			case 'C':
				if (dst == 'B')
				{
					B_stack[topB++] = C_stack[--topC];
					C_stack[topC] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('C', 27, 14);
					print_plate('B', 17, 14);
				}
				else
				{
					A_stack[topA++] = C_stack[--topC];
					C_stack[topC] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('C', 27, 14);
					print_plate('A', 7, 14);
				}
				break;
		}
		return;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		sleep(mov);
		cct_gotoxy(10, 20);
		cout << "第" << setw(4) << order++ << " 步(" << n << "#: " << src << "-->" << dst << ")  ";
		switch (src)
		{
			case 'A':
				if (dst == 'B')
				{
					B_stack[topB++] = A_stack[--topA];
					A_stack[topA] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('A', 7, 14);
					print_plate('B', 17, 14);
				}
				else
				{
					C_stack[topC++] = A_stack[--topA];
					A_stack[topA] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('A', 7, 14);
					print_plate('C', 27, 14);
				}
				break;
			case 'B':
				if (dst == 'A')
				{
					A_stack[topA++] = B_stack[--topB];
					B_stack[topB] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('B', 17, 14);
					print_plate('A', 7, 14);
				}
				else
				{
					C_stack[topC++] = B_stack[--topB];
					B_stack[topB] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('B', 17, 14);
					print_plate('C', 27, 14);
				}
				break;
			case 'C':
				if (dst == 'B')
				{
					B_stack[topB++] = C_stack[--topC];
					C_stack[topC] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('C', 27, 14);
					print_plate('B', 17, 14);
				}
				else
				{
					A_stack[topA++] = C_stack[--topC];
					C_stack[topC] = ' ';
					if (pa)
						print_array();
					sleep(mov);
					print_plate('C', 27, 14);
					print_plate('A', 7, 14);
				}
				break;
		}
		hanoi(n - 1, tmp, src, dst);
	}
}


int main()
{
	for (int i = 0; i < 10; i++)
	{
		A_stack[i] = ' ';
		B_stack[i] = ' ';
		C_stack[i] = ' ';
	}

	int n;
	char src, tmp, dst;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		cin.clear();
		cin.ignore(65536, '\n');
		if (n >= 1 && n <= 10)
			break;
	}
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		cin.clear();
		cin.ignore(65536, '\n');
		if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
		{
			if (src == 'a' || src == 'b' || src == 'c')
				src -= 32;
			break;
		}
	}
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		cin.clear();
		cin.ignore(65536, '\n');
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c'))
		{
			if (dst == 'a' || dst == 'b' || dst == 'c')
				dst -= 32;
			if (src == dst)
				cout << "目标柱(" << src << ")不能与起始柱(" << dst << ")相同" << endl;
			else
				break;
		}
	}
	while (1)
	{
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> mov;
		if (mov >= 0 || mov <= 5)
			break;
	}
	while (1)
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> pa;
		if (pa == 1 || pa == 0)
			break;
	}
	char ch = getchar();
	switch (src)
	{
		case 'A':
			tmp = (dst == 'B') ? 'C' : 'B';
			break;
		case 'B':
			tmp = (dst == 'A') ? 'C' : 'A';
			break;
		case 'C':
			tmp = (dst == 'A') ? 'B' : 'A';
			break;
	}
	int t = n;
	switch (src)
	{
		case 'A':
			for (int i = 0; i < n; i++)
				A_stack[i] = '0' + t--;
			topA = n;
			break;
		case 'B':
			for (int i = 0; i < n; i++)
				B_stack[i] = '0' + t--;
			topB = n;
			break;
		case 'C':
			for (int i = 0; i < n; i++)
				C_stack[i] = '0' + t--;
			topC = n;
			break;
	}
	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << mov << "，";
	cout << (pa ? "显示内部数组值" : "不显示内部数组值");
	if (pa)
	{
		cct_gotoxy(10, 20);
		cout << "初始:               ";
		print_array();
		sleep(mov);
	}
	cct_gotoxy(5, 15);
	cout << "=========================" << endl << "       A         B         C";
	if (src == 'A')
		print_plate('A', 7, 14);
	else if (src == 'B')
		print_plate('B', 17, 14);
	else
		print_plate('C', 27, 14);
	hanoi(n, src, tmp, dst);
	cct_gotoxy(10, 30);
	
	system("pause");
	return 0;
}