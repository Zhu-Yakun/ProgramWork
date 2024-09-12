//2252085 信19 朱亚琨
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

int main()
{
	double a;
	int sum = 0;
	int s_a50, s_a20, s_a10, s_a5, s_a1, s_b5, s_b1, s_c5, s_c2, s_c1;
	printf("%s\n", "请输入找零值：");
	scanf("%lf", &a);
	a += 0.0001;

	s_a50 = (int)(a) / 50;
	a -= s_a50 * 50;

	s_a20 = (int)(a) / 20;
	a -= s_a20 * 20;

	s_a10 = (int)(a) / 10;
	a -= s_a10 * 10;

	s_a5 = (int)(a) / 5;
	a -= s_a5 * 5;

	s_a1 = (int)(a);
	a -= s_a1;

	a *= 10;
	s_b5 = (int)(a) / 5;
	a -= s_b5 * 5;

	s_b1 = (int)(a);
	a -= s_b1;

	a *= 10;
	s_c5 = (int)(a) / 5;
	a -= s_c5 * 5;

	s_c2 = (int)(a) / 2;
	a -= s_c2 * 2;

	s_c1 = (int)(a);
	a -= s_c1;

	sum = s_a50 + s_a20 + s_a10 + s_a5 + s_a1 + s_b5 + s_b1 + s_c5 + s_c2 + s_c1;

	printf("共%d张找零，具体如下：\n", sum);
	if (s_a50)
		printf("50元 : %d张\n", s_a50);
	if (s_a20)
		printf("20元 : %d张\n", s_a20);
	if (s_a10)
		printf("10元 : %d张\n", s_a10);
	if (s_a5)
		printf("5元  : %d张\n", s_a5);
	if (s_a1)
		printf("1元  : %d张\n", s_a1);
	if (s_b5)
		printf("5角  : %d张\n", s_b5);
	if (s_b1)
		printf("1角  : %d张\n", s_b1);
	if (s_c5)
		printf("5分  : %d张\n", s_c5);
	if (s_c2)
		printf("2分  : %d张\n", s_c2);
	if (s_c1)
		printf("1分  : %d张\n", s_c1);

	return 0;
}