/* ��19 2252085 ������ */
#include <iostream>
#include<iomanip>
#include<math.h> 
using namespace std;

int main()
{
	int y, m, w, d;
	int d1 = 31, d2 = 28, d4 = 30;   //d1��1�µ�31����·ݵ�������d4��4�µ�30����·ݵ�����
	                                 //d2�ĳ�ֵ����ͨ���2�µ�����
	while (1) {                         //3-b12-1������
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> y >> m;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "����Ƿ�������������" << endl;
		}
		else if (m >= 1 && m <= 12)
			break;
		else
			cout << "����Ƿ�������������" << endl;
	}
	while (1) {
		cout << "������" << y << "��" << m << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> w;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "����Ƿ�������������" << endl;
		}
		else if (w >= 0 && w <= 6)
		{
			cout << endl;
			break;
		}
		else
			cout << "����Ƿ�������������" << endl;
	}

	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)      //�ж����꣬����d2
		d2 = 29;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)  
		d = d1;
	else if (m == 4 || m == 6 || m == 9 || m == 11)     //�����·ݵ�����
		d = d4;
	else
		d = d2;

	cout << y << "��" << m << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;

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

	return 0;
}
