//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

int main()
{
	double r, h;
	printf("%s", "������뾶�͸߶�\n");
	scanf("%lf%lf", &r, &h);
	printf("%s%.2lf\n", "Բ�ܳ�     : ", (2 * pi * r));
	printf("%s%.2lf\n", "Բ���     : ", (pi * r * r));
	printf("%s%.2lf\n", "Բ������ : ", (4 * pi * r * r));
	printf("%s%.2lf\n", "Բ�����   : ", (4 * pi * r * r * r / 3));
	printf("%s%.2lf\n", "Բ�����   : ", (pi * r * r * h));
	
	return 0;
}