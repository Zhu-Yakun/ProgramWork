/* 信19 2252085 朱亚琨 */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y -= 1;
	}
	int c = y / 100;
	y = y - c * 100;
	int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0)
		w += 7;
	return w % 7;
}

int main()
{
	int y, m, d;
	bool flag = 0, prime = 0;

	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;

		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			prime = 1;
		if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d>31))
			flag = 1;
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30))
			flag = 1;
		else if (m == 2 && ((prime && (d < 1 || d > 29)) || (!prime && (d < 1 || d > 28))))
			flag = 1;

		if (!cin.good())
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();                   //除去cin的标记，使cin.good()恢复为1
			cin.ignore(65536, '\n');     //清除缓冲区的当前行的内容  
		}                              
		else if (y < 1900 || y > 2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (m < 1 || m > 12)
		{
			cout << "月份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (flag)
		{
			cout << "日不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			flag = 0;
		}
		else
			break;
	}

	int w = zeller(y, m, d);
	switch (w)
	{
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}

	return 0;
}
