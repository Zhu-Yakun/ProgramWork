/* 2252085 ������ ��19 */
#include <iostream>
#include <cmath>
using namespace std;

void fun3(double a, double b, double c)
{
	cout << "����������ʵ����" << endl;
	cout << "x1=" << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << endl;
	cout << "x2=" << (-b - sqrt(b * b - 4 * a * c)) / 2 / a << endl;
}