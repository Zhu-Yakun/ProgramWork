/* ��19 2252085 ������ */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y -= 1;
	}
	int c = y / 100;
	y = y - c * 100;
	int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0)
		w += 7;
	return w % 7;
}

int main()
{
	int y, m, d;
	bool flag = 0, prime = 0;

	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;

		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			prime = 1;
		if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d>31))
			flag = 1;
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30))
			flag = 1;
		else if (m == 2 && ((prime && (d < 1 || d > 29)) || (!prime && (d < 1 || d > 28))))
			flag = 1;

		if (!cin.good())
		{
			cout << "�����������������" << endl;
			cin.clear();                   //��ȥcin�ı�ǣ�ʹcin.good()�ָ�Ϊ1
			cin.ignore(65536, '\n');     //����������ĵ�ǰ�е�����  
		}                              
		else if (y < 1900 || y > 2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (m < 1 || m > 12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (flag)
		{
			cout << "�ղ���ȷ������������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
			flag = 0;
		}
		else
			break;
	}

	int w = zeller(y, m, d);
	switch (w)
	{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}

	return 0;
}
