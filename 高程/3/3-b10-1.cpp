/* ��19 2252085 ������*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	   //�����ȹ����������Ĵ��·�Χ�����͸��Ӷȣ���Χ��ʵ���Ը���ȷ������û��Ҫ��
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;   //������λ���ĸ�����
	int total = 0;
	for (int i = 123; i < 600; i++)     //���ݰ�λ������ 600+700+800=2100 > 1953,
	{                         // 500+600+700=1800 < 1953,�������������С����һ�� < 600,��֪һ�� > 123
		a1 = i / 100;
		a2 = (i - a1 * 100) / 10;
		a3 = i % 10;
		if ((a1 != a2) && (a1 != a3) && (a2 != a3) && a1 && a2 && a3)
		{
			for (int j = 500; j < 900; j++)   //���һ��ѭ��ͬ������� j > 500, ͬʱ�������� �м����һ�� < 900
			{
				b1 = j / 100;
				b2 = (j - b1 * 100) / 10;
				b3 = j % 10;
				if ((j > i) && (b1 - b2) && (b1 - b3) && (b2 - b3) && (a1 - b1) && (a1 - b2) && (a1 - b3)
					&& (a2 - b1) && (a2 - b2) && (a2 - b3) && (a3 - b1) && (a3 - b2) && (a3 - b3) && b1 && b2 && b3)
				{
					int k = 1953 - i - j;           //�˴�û�б�Ҫ��Ƕһ��ѭ��
					c1 = k / 100;
					c2 = ( k- c1 * 100) / 10;
					c3 = k % 10;
					if ((c1 - c2) && (c1 - c3) && (c2 - c3) && (c1 - a1) && (c1 - a2) && (c1 - a3)
						&& (c2 - a1) && (c2 - a2) && (c2 - a3) && (c3 - a1) && (c3 - a2) && (c3 - a3)
						&& (c1 - b1) && (c1 - b2) && (c1 - b3) && (c2 - b1) && (c2 - b2) && (c2 - b3)
						&& (c3 - b1) && (c3 - b2) && (c3 - b3) && (k > j) && (k <= 987) && c1 && c2 && c3)
					{
						total++;
						cout << "No." << setw(3) << total << " : " << i << "+" << j << "+" << k << "=1953" << endl;
					}
				}
			}
		}
	}
	cout << "total=" << total << endl;

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}
