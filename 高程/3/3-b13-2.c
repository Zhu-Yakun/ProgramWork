/* ��19 2252085 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
	int y, m, w, d, ret;
	int d1 = 31, d2 = 28, d4 = 30;        //d1��1�µ�31����·ݵ�������d4��4�µ�30����·ݵ�����
	                                      //d2�ĳ�ֵ����ͨ���2�µ�����
	while (1) {                           //3-b12-2������
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d%d", &y, &m);
		if (ret != 2)
		{
			while (getchar() != '\n')
				;
		}
		else if (m >= 1 && m <= 12)
			break;
		printf("����Ƿ�������������\n");
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", y, m);
		ret = scanf("%d", &w);
		if (ret != 1)
		{
			while (getchar() != '\n')
				;
		}
		else if (w >= 0 && w <= 6)
		{
			printf("\n");
			break;
		}
		printf("����Ƿ�������������\n");
	}
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)      //�ж����꣬����d2
		d2 = 29;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		d = d1;
	else if (m == 4 || m == 6 || m == 9 || m == 11)         //�����·ݵ�����
		d = d4;
	else
		d = d2;

	printf("%d��%d�µ�����Ϊ:\n", y, m);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	int n = (int)(ceil((d + w) / 7.0));    //����������
	int md = 1, flag = 1;             //ÿһ��   //��ӡ�������еı��
	for (int i = 1; i <= n; i++)
	{
		int j;
		if (flag)       //�������д�ӡ��λ
		{
			j = w;
			for (int k = w; k > 0; k--)
				printf("        ");
		}
		else            //�������� j ����
			j = 0;
		for (; (j <= 6) && (md <= d); j++, md++)
		{
			flag = 0;             //�������б��
			printf("%4d    ", md);
		}
		if (j == 7)      //��β����
		{
			j = 0;              //��ʵ������Բ��ã�д�˷�����һ��˼·��ͬʱ����
			printf("\n"); 
		}
	}
	printf("\n");

	return 0;
}

