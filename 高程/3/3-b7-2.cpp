//2252085 ��19 ������
#include<iostream>
//#include<iomanip>
using namespace std;

int main()
{
	double a;
	int sum = 0;
	int s_a50, s_a20, s_a10, s_a5, s_a1, s_b5, s_b1, s_c5, s_c2, s_c1;
	cout << "����������ֵ��" << endl;
	cin >> a;
	a += 0.0001;

	s_a50 = int(a) / 50;
	a -= s_a50 * 50;

	s_a20 = int(a) / 20;
	a -= s_a20 * 20;

	s_a10 = int(a) / 10;
	a -= s_a10 * 10;

	s_a5 = int(a) / 5;
	a -= s_a5 * 5;

	s_a1 = int(a);
	a -= s_a1;
	
	a *= 10;
	s_b5 = int(a) / 5;
	a -= s_b5 * 5;

	s_b1 = int(a);
	a -= s_b1;

	a *= 10;
	s_c5 = int(a) / 5;
	a -= s_c5 * 5;

	s_c2 = int(a) / 2;
	a -= s_c2 * 2;

	s_c1 = int(a);
	a -= s_c1;

	sum = s_a50 + s_a20 + s_a10 + s_a5 + s_a1 + s_b5 + s_b1 + s_c5 + s_c2 + s_c1;

	cout << "��" << sum << "�����㣬�������£�" << endl;
	if (s_a50)
		cout << "50Ԫ : " << s_a50 << "��" << endl;
	if (s_a20)
		cout << "20Ԫ : " << s_a20 << "��" << endl;
	if (s_a10)
		cout << "10Ԫ : " << s_a10 << "��" << endl;
	if (s_a5)
		cout << "5Ԫ  : " << s_a5 << "��" << endl;
	if (s_a1)
		cout << "1Ԫ  : " << s_a1 << "��" << endl;
	if (s_b5)
		cout << "5��  : " << s_b5 << "��" << endl;
	if (s_b1)
		cout << "1��  : " << s_b1 << "��" << endl;
	if (s_c5)
		cout << "5��  : " << s_c5 << "��" << endl;
	if (s_c2)
		cout << "2��  : " << s_c2 << "��" << endl;
	if (s_c1)
		cout << "1��  : " << s_c1 << "��" << endl;

	return 0;
}