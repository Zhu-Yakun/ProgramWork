//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int is_leap(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;
	else
		return 0;
}
int sum_day(int m, int d, int m_day[])
{
	int sum = 0;
	for (int i = 1; i < m; i++)
		sum += m_day[i];
	return sum + d;
}

int main()
{
	int m_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m, d,sum = 0;
	printf("%s\n", "�������꣬�£���");
	scanf("%d%d%d", &y, &m, &d);
	if (m < 1 || m > 12)
		printf("�������-�·ݲ���ȷ\n");
	if (is_leap(y))
		m_day[2] = 29;
	if(m >= 1 && m <= 12 && (m_day[m] < d || d < 1))
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
	
	printf("%d-%d-%d��%d��ĵ�%d��\n", y, m, d, y, sum_day(m, d, m_day));

	return 0;
}