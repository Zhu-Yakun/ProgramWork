/* 2252085 朱亚琨 信19 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void input(char id[][8], char name[][9], int score[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
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
	printf("\n全部学生(成绩降序):\n");
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
2255099 王一 48
3232113 王二 78
7889960 王三 70
8778608 王四 59
7879878 王五 80
8786997 王六 89
2362734 王七 98
5776775 王八 78
3247234 王九 78
7664569 王十 68
*/