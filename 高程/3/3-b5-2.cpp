//2252085 ��19 ������
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int y, m, d;
	int d1 = 31, d2 = 28, d4 = 30, sum = 0;
	bool prime;
	cout << "�������꣬�£���" << endl;
	cin >> y >> m >> d;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		d2 = 29;
	switch (m) {
		case 1:
			sum = d;
			prime = d <= d1;
			break;
		case 2:
			sum = d + d1;
			prime = d <= d2;
			break;
		case 3:
			sum = d + d1 + d2;
			prime = d <= d1;
			break;
		case 4:
			sum = d + d1 * 2 + d2;
			prime = d <= d4;
			break;
		case 5:
			sum = d + d1 * 2 + d2 + d4;
			prime = d <= d1;
			break;
		case 6:
			sum = d + d1 * 3 + d2 + d4;
			prime = d <= d4;
			break;
		case 7:
			sum = d + d1 * 3 + d2 + d4 * 2;
			prime = d <= d1;
			break;
		case 8:
			sum = d + d1 * 4 + d2 + d4 * 2;
			prime = d <= d1;
			break;
		case 9:
			sum = d + d1 * 5 + d2 + d4 * 2;
			prime = d <= d4;
			break;
		case 10:
			sum = d + d1 * 5 + d2 + d4 * 3;
			prime = d <= d1;
			break;
		case 11:
			sum = d + d1 * 6 + d2 + d4 * 3;
			prime = d <= d4;
			break;
		case 12:
			sum = d + d1 * 6 + d2 + d4 * 4;
			prime = d <= d1;
			break;
		default:
			cout << "�������-�·ݲ���ȷ" << endl;
			return 0;
	}
	if (prime)
		cout << y << '-' << m << '-' << d << "��" << y << "��ĵ�" << sum << "��" << endl;
	else
		cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

	return 0;
}