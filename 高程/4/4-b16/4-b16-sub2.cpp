/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <cmath>
using namespace std;

void fun2(double a, double b, double c)
{
	cout << "有两个相等实根：" << endl;
	if (fabs(-b / 2 / a) < 1e-6)
		cout << "x1=x2=" << 0 << endl;
	else
		cout << "x1=x2=" << -b / 2 / a << endl;
}