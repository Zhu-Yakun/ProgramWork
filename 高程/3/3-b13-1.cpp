/* 信19 2252085 朱亚琨 */
#include <iostream>
#include<iomanip>
#include<math.h> 
using namespace std;

int main()
{
	int y, m, w, d;
	int d1 = 31, d2 = 28, d4 = 30;   //d1是1月等31天的月份的天数，d4是4月等30天的月份的天数
	                                 //d2的初值是普通年份2月的天数
	while (1) {                         //3-b12-1的内容
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (m >= 1 && m <= 12)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	while (1) {
		cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> w;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (w >= 0 && w <= 6)
		{
			cout << endl;
			break;
		}
		else
			cout << "输入非法，请重新输入" << endl;
	}

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)      //判断闰年，更新d2
		d2 = 29;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)  
		d = d1;
	else if (m == 4 || m == 6 || m == 9 || m == 11)     //更新月份的天数
		d = d4;
	else
		d = d2;

	cout << y << "年" << m << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

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

	return 0;
}
