/* 2252085 ������ ��19 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void input(char id[][8], char name[][9], int score[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s%s%d", &id[i], &name[i], &score[i]);
	}
}
void order(char id[][8], char name[][9], int score[])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10 - i - 1; j++)
			if (score[j + 1] > score[j])
			{
				char temp1[8], temp2[9];
				int temp3 = score[j];
				strcpy(temp1, id[j]);
				strcpy(temp2, name[j]);
				strcpy(id[j], id[j + 1]);
				strcpy(name[j], name[j + 1]);
				score[j] = score[j + 1];
				strcpy(id[j + 1], temp1);
				strcpy(name[j + 1], temp2);
				score[j + 1] = temp3;
			}
}
void output(char id[][8], char name[][9], int score[])
{
	printf("\nȫ��ѧ��(�ɼ�����):\n");
	for (int i = 0; i < 10; i++)
		printf("%s %s %d\n", name[i], id[i], score[i]);
}

int main()
{
	char id[10][8] = { 0 };
	char name[10][9] = { 0 };
	int score[10] = { 0 };
	input(id, name, score);
	order(id, name, score);
	output(id, name, score);

	return 0;
}
/*
2255099 ��һ 48
3232113 ���� 78
7889960 ���� 70
8778608 ���� 59
7879878 ���� 80
8786997 ���� 89
2362734 ���� 98
5776775 ���� 78
3247234 ���� 78
7664569 ��ʮ 68
*/