/* 2252085 ������ ��19 */
#include <iostream>
#include <cmath>
#include"4-b16.h"
using namespace std;

int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	if (a == 0)
		fun1();
	else if (fabs(b * b - 4 * a * c) < 1e-6)
		fun2(a, b, c);
	else if (b * b - 4 * a * c > 0)
		fun3(a, b, c);
	else if (b * b - 4 * a * c < 0)
		fun4(a, b, c);

	return 0;
}