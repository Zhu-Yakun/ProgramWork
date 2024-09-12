/* ��19 2252085 ������ */
#include <iostream>
#include<iomanip>
#include<cmath>
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

void calender(int y, int m, int w)
{
	int d, d1 = 31, d2 = 28, d4 = 30;

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)      //�ж����꣬����d2
		d2 = 29;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		d = d1;
	else if (m == 4 || m == 6 || m == 9 || m == 11)     //�����·ݵ�����
		d = d4;
	else
		d = d2;

	cout << y << "��" << m << "��" << endl;
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	int n = int(ceil((d + w) / 7.0));     //����������
	int md = 1;            //ÿһ��
	bool flag = 1;         //��ӡ�������еı��
	for (int i = 1; i <= n; i++)
	{
		int j;
		if (flag)         //�������д�ӡ��λ
		{
			j = w;
			for (int k = w; k > 0; k--)
				cout << "        ";
		}
		else             //�������� j ����
			j = 0;
		for (; (j <= 6) && (md <= d); j++, md++)
		{
			flag = 0;     //�������б��
			cout << setw(4) << md << "    ";
		}
		if (j == 7)       //��β����
		{
			j = 0;        //��ʵ������Բ��ã�д�˷�����һ��˼·��ͬʱ����
			cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	int y, m;
	bool flag = 0, prime = 0;

	while (1)
	{
		cout << "��������[1900-2100]����" << endl;
		cin >> y >> m;

		if (!cin.good())
		{
			cout << "�����������������" << endl;
			cin.clear();                   //��ȥcin�ı�ǣ�ʹcin.good()�ָ�Ϊ1
			cin.ignore(65536, '\n');     //����������ĵ�ǰ�е�����  
		}                              //ԭ������numeric_limits<streamsize>::max()����Ҫ��ͷ�ļ����¿۷� 
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
		else
			break;
	}
	cout << endl;
	int w = zeller(y, m, 1);
	calender(y, m, w);
	cout << endl;

	return 0;
}
