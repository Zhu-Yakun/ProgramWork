//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
	int a, b, arc;
	printf("%s", "�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d%d%d", &a, &b, &arc);
	printf("%s%.3f\n", "���������Ϊ : ",(float)( a * b * sin(arc / 180.0 * pi) / 2.0));

	return 0;
}