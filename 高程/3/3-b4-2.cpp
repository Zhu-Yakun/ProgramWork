//2252085 信19 朱亚琨
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define pi 3.14159

int main()
{
	int a, b, arc;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> arc;
	cout << setiosflags(ios::fixed) << endl;
	cout << "三角形面积为 : " << setprecision(3) << float(a * b * sin(arc / 180.0 * pi) / 2.0) << endl;

	return 0;
}