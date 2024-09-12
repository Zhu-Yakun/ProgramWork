//2252085 信19 朱亚琨
#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14159

int main()
{
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << endl;
	cout << "圆周长     : " << setprecision(2) << (2 * pi * r) << endl;
	cout << "圆面积     : " << setprecision(2) << (pi * r * r) << endl;
	cout << "圆球表面积 : " << setprecision(2) << (4*pi * r * r) << endl;
	cout << "圆球体积   : " << setprecision(2) << (4 * pi * r * r * r / 3) << endl;
	cout << "圆柱体积   : " << setprecision(2) << (pi * r * r * h) << endl;

	return 0;
}

