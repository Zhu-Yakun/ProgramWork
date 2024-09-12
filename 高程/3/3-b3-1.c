//2252085 信19 朱亚琨
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c, a10, a11, a12;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
    printf("%s\n", "请输入[0-100亿)之间的数字:");
    scanf("%lf", &a);

    c = a + 0.000001;
    b = c / 10;
    a1 = (int)(b / 1e8) % 10;
    a2 = (int)(b / 1e7) % 10;
    a3 = (int)(b / 1e6) % 10;
    a4 = (int)(b / 1e5) % 10;
    a5 = (int)(b / 1e4) % 10;
    a6 = (int)(b / 1e3) % 10;
    a7 = (int)(b / 100) % 10;
    a8 = (int)(b / 10) % 10;
    a9 = (int)(b - a1 * 1e8) % 10;
    a10 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9;
    a11 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - (int)(a10 * 10) * 0.1;
    a12 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - (int)(a10 * 10) * 0.1 - (int)(a11 * 100) * 0.01;

    printf("%s%d\n", "十亿位 : ", a1);
    printf("%s%d\n", "亿位   : ", a2);
    printf("%s%d\n", "千万位 : ", a3);
    printf("%s%d\n", "百万位 : ", a4);
    printf("%s%d\n", "十万位 : ", a5);
    printf("%s%d\n", "万位   : ", a6);
    printf("%s%d\n", "千位   : ", a7);
    printf("%s%d\n", "百位   : ", a8);
    printf("%s%d\n", "十位   : ", a9);
    printf("%s%d\n", "圆     : ", (int)(a10 * 10));
    printf("%s%d\n", "角     : ", (int)(a11 * 100));
    printf("%s%d\n", "分     : ", (int)(a12 * 1000));

	return 0;
}