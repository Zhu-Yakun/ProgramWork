/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <cmath>
using namespace std;

extern void fun1();
extern void fun2();
extern void fun3();
extern void fun4();

double a, b, c;

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
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
		fun2();
	else if (b * b - 4 * a * c > 0)
		fun3();
	else if (b * b - 4 * a * c < 0)
		fun4();

	return 0;
}