/* 2252085 ������ ��19 */
#include <iostream>
#include <cmath>
using namespace std;

void fun1()
{
	cout << "����һԪ���η���" << endl;
}
void fun2(double a, double b, double c)
{
	cout << "���������ʵ����" << endl;
	if (fabs(-b / 2 / a) < 1e-6)
		cout << "x1=x2=" << 0 << endl;
	else
		cout << "x1=x2=" << -b / 2 / a << endl;
}
void fun3(double a, double b, double c)
{
	cout << "����������ʵ����" << endl;
	cout << "x1=" << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << endl;
	cout << "x2=" << (-b - sqrt(b * b - 4 * a * c)) / 2 / a << endl;
}
void fun4(double a, double b, double c)
{
	cout << "�����������" << endl;
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