//2252085 ��19 ������
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define pi 3.14159

int main()
{
	int a, b, arc;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> arc;
	cout << setiosflags(ios::fixed) << endl;
	cout << "���������Ϊ : " << setprecision(3) << float(a * b * sin(arc / 180.0 * pi) / 2.0) << endl;

	return 0;
}