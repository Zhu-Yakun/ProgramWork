//2252085 信19 朱亚琨
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
	int a, b, arc;
	printf("%s", "请输入三角形的两边及其夹角(角度)\n");
	scanf("%d%d%d", &a, &b, &arc);
	printf("%s%.3f\n", "三角形面积为 : ",(float)( a * b * sin(arc / 180.0 * pi) / 2.0));

	return 0;
}