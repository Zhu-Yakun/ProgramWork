//2252085 信19 朱亚琨
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pi 3.14159

int main()
{
	double r, h;
	printf("%s", "请输入半径和高度\n");
	scanf("%lf%lf", &r, &h);
	printf("%s%.2lf\n", "圆周长     : ", (2 * pi * r));
	printf("%s%.2lf\n", "圆面积     : ", (pi * r * r));
	printf("%s%.2lf\n", "圆球表面积 : ", (4 * pi * r * r));
	printf("%s%.2lf\n", "圆球体积   : ", (4 * pi * r * r * r / 3));
	printf("%s%.2lf\n", "圆柱体积   : ", (pi * r * r * h));
	
	return 0;
}