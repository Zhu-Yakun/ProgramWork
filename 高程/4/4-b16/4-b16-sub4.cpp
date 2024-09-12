/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <cmath>
using namespace std;

void fun4(double a, double b, double c)
{
	cout << "有两个虚根：" << endl;
	if (fabs(fabs(sqrt(4 * a * c - b * b) / 2 / a) - 1) >= 1e-6)
	{
		if (fabs(-b / 2 / a) >= 1e-6)
		{
			if (fabs(sqrt(4 * a * c - b * b) / 2 / a) >= 1e-6)
			{
				cout << "x1=" << -b / 2 / a << "+" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
				cout << "x2=" << -b / 2 / a << "-" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
			}
			else
			{
				cout << "x1=" << -b / 2 / a << endl;
				cout << "x2=" << -b / 2 / a << endl;
			}
		}
		else
		{
			if (fabs(sqrt(4 * a * c - b * b) / 2 / a) >= 1e-6)
			{
				cout << "x1=" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
				cout << "x2=" << "-" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
			}
			else
				cout << 0 << endl;
		}
	}
	else
	{
		if (fabs(-b / 2 / a) >= 1e-6)
			cout << "x1=" << -b / 2 / a << "+i" << endl << "x2=" << -b / 2 / a << "-i" << endl;
		else
			cout << "x1=" << "i" << endl << "x2=" << "-i" << endl;
	}
}