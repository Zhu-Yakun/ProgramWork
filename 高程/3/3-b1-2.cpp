//2252085 ��19 ������
#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14159

int main()
{
	double r, h;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << endl;
	cout << "Բ�ܳ�     : " << setprecision(2) << (2 * pi * r) << endl;
	cout << "Բ���     : " << setprecision(2) << (pi * r * r) << endl;
	cout << "Բ������ : " << setprecision(2) << (4*pi * r * r) << endl;
	cout << "Բ�����   : " << setprecision(2) << (4 * pi * r * r * r / 3) << endl;
	cout << "Բ�����   : " << setprecision(2) << (pi * r * r * h) << endl;

	return 0;
}

