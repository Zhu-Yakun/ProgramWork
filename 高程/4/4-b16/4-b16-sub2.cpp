/* 2252085 ������ ��19 */
#include <iostream>
#include <cmath>
using namespace std;

void fun2(double a, double b, double c)
{
	cout << "���������ʵ����" << endl;
	if (fabs(-b / 2 / a) < 1e-6)
		cout << "x1=x2=" << 0 << endl;
	else
		cout << "x1=x2=" << -b / 2 / a << endl;
}