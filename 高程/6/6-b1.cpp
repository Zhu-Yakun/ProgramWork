/* 2252085 ������ ��19 */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str, 256);
	p = str;
	pa = a;
	pnum = a;
	is_num = 0;
	for (; (*p != 0) && (pa - a < 10); p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			if (is_num)
				*pa = *pa * 10 + *p - '0' + '0';
			else
				*pa = *p;
			is_num = 1;
		}
		else
		{
			if (is_num)
				pa++;
			is_num = 0;
		}
	}
	if (*p == 0 && is_num)
		pa++;
	cout << "����" << pa - a << "������" << endl;
	for (; *pnum != 0 && pnum - a < 10; pnum++)
		cout << *pnum - '0' << " ";

	return 0;
}
