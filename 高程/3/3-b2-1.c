//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	printf("%s\n", "������һ��[1..30000]�������:");
	scanf("%d", &a);
	printf("%s%d\n", "��λ : ", a / 10000);
	printf("%s%d\n", "ǧλ : ", (a / 1000) % 10);
	printf("%s%d\n", "��λ : ", (a / 100) % 10);
	printf("%s%d\n", "ʮλ : ", (a / 10) % 10);
	printf("%s%d\n", "��λ : ", a % 10);

	return 0;
}