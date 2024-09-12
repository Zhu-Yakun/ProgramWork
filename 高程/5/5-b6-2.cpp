/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <iomanip>
using namespace std;

int order = 1;
int top[3] = { 0 };
int pst_stack[3][10];

void print_array()
{
	for (int i = 0; i < 3; i++)
	{
		cout << " " << char('A' + i) << ":";
		for (int j = 0; j < 10; j++)
		{
			if (pst_stack[i][j] != ' ')
				cout << setw(2) << pst_stack[i][j] - '0';
			else
				cout << " " << char(pst_stack[i][j]);
		}
	}
	cout << endl;
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		cout << "第" << setw(4) << order++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
		pst_stack[dst - 'A'][top[dst - 'A']++] = pst_stack[src - 'A'][--top[src - 'A']];
		pst_stack[src - 'A'][top[src - 'A']] = ' ';
		print_array();
		return;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		cout << "第" << setw(4) << order++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
		pst_stack[dst - 'A'][top[dst - 'A']++] = pst_stack[src - 'A'][--top[src - 'A']];
		pst_stack[src - 'A'][top[src - 'A']] = ' ';
		print_array();
		hanoi(n - 1, tmp, src, dst);
	}
}


int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 10; j++)
			pst_stack[i][j] = ' ';
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
	for (int i = 0; i < n; i++)
		pst_stack[src - 'A'][i] = '0' + t--;
	top[src - 'A'] = n;
	cout << "初始:               ";
	print_array();
	hanoi(n, src, tmp, dst);

	return 0;
}