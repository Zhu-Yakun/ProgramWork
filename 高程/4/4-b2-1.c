/* ��19 2252085 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	int y, m, d, ret;
	int flag = 0, prime = 0;

	while (1)
	{
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d%d%d", &y, &m, &d);

		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			prime = 1;
		if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d>31))
			flag = 1;
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d>30))
			flag = 1;
		else if (m == 2 && ((prime && (d < 1 || d > 29)) || (!prime && (d < 1 || d > 28))))
			flag = 1;

		if (ret != 3)
		{
			printf("�����������������\n");
			while (getchar() != '\n')
				;
		}                
		else if (y < 1900 || y > 2100)
		{
			printf("��ݲ���ȷ������������\n");
			while (getchar() != '\n')
				;
		}
		else if (m < 1 || m > 12)
		{
			printf("�·ݲ���ȷ������������\n");
			while (getchar() != '\n')
				;
		}
		else if (flag)
		{
			printf("�ղ���ȷ������������\n");
			while (getchar() != '\n')
				;
			flag = 0;
		}
		else
			break;
	}

	int w = zeller(y, m, d);
	switch (w)
	{
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
	}

	return 0;
}

