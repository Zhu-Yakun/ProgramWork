/* 2252085 ������ ��19 */
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
		cout << "��" << setw(4) << order++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
		pst_stack[dst - 'A'][top[dst - 'A']++] = pst_stack[src - 'A'][--top[src - 'A']];
		pst_stack[src - 'A'][top[src - 'A']] = ' ';
		print_array();
		return;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		cout << "��" << setw(4) << order++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
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
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;
		cin.clear();
		cin.ignore(65536, '\n');
		if (n >= 1 && n <= 10)
			break;
	}
	while (1)
	{
		cout << "��������ʼ��(A-C)" << endl;
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
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		cin.clear();
		cin.ignore(65536, '\n');
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c'))
		{
			if (dst == 'a' || dst == 'b' || dst == 'c')
				dst -= 32;
			if (src == dst)
				cout << "Ŀ����(" << src << ")��������ʼ��(" << dst << ")��ͬ" << endl;
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
	cout << "��ʼ:               ";
	print_array();
	hanoi(n, src, tmp, dst);

	return 0;
}