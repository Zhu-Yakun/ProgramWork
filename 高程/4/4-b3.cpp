/* 信19 2252085 朱亚琨 */
#include <iostream>
#include<iomanip>
#include<cmath>
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

void calender(int y, int m, int w)
{
	int d, d1 = 31, d2 = 28, d4 = 30;

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)      //判断闰年，更新d2
		d2 = 29;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		d = d1;
	else if (m == 4 || m == 6 || m == 9 || m == 11)     //更新月份的天数
		d = d4;
	else
		d = d2;

	cout << y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	int n = int(ceil((d + w) / 7.0));     //月历的行数
	int md = 1;            //每一天
	bool flag = 1;         //打印月历首行的标记
	for (int i = 1; i <= n; i++)
	{
		int j;
		if (flag)         //月历首行打印空位
		{
			j = w;
			for (int k = w; k > 0; k--)
				cout << "        ";
		}
		else             //非首行让 j 归零
			j = 0;
		for (; (j <= 6) && (md <= d); j++, md++)
		{
			flag = 0;     //消除首行标记
			cout << setw(4) << md << "    ";
		}
		if (j == 7)       //行尾换行
		{
			j = 0;        //其实这里可以不用，写了方便理一下思路，同时防重
			cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	int y, m;
	bool flag = 0, prime = 0;

	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;

		if (!cin.good())
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();                   //除去cin的标记，使cin.good()恢复为1
			cin.ignore(65536, '\n');     //清除缓冲区的当前行的内容  
		}                              //原本想用numeric_limits<streamsize>::max()不过要加头文件，怕扣分 
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
		else
			break;
	}
	cout << endl;
	int w = zeller(y, m, 1);
	calender(y, m, w);
	cout << endl;

	return 0;
}
