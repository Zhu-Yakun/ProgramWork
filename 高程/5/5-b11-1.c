/* 2252085 朱亚琨 信19 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
    double a, b, c, b10, b11, b12;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
    int cnt = 0;

    printf("请输入[0-100亿)之间的数字:\n");
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
    b10 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9;
    b11 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - (int)(b10 * 10) * 0.1;
    b12 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - (int)(b10 * 10) * 0.1 - (int)(b11 * 100) * 0.01;
    a10 = (int)(b10 * 10);
    a11 = (int)(b11 * 100);
    a12 = (int)(b12 * 1000);

    printf("大写结果是:\n");
    if (a1)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a1], chnstr[2 * a1 + 1], "拾");
        cnt += 4;
    }
    if (a2)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a2], chnstr[2 * a2 + 1], "亿");
        cnt += 4;
    }
    if (!a2 && a1)
    {
        sprintf(&result[cnt], "%s", "亿");
        cnt += 2;
    }
    if (a3)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a3], chnstr[2 * a3 + 1], "仟");
        cnt += 4;
    }
    if (!a3 && (a1 || a2) && (a4 || a5 || a6))
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a4)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a4], chnstr[2 * a4 + 1], "佰");
        cnt += 4;
    }
    if (!a4 && a3 && (a5 || a6))
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a5)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a5], chnstr[2 * a5 + 1], "拾");
        cnt += 4;
    }
    if (!a5 && (a3 || a4) && a6)
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a6)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a6], chnstr[2 * a6 + 1], "万");
        cnt += 4;
    }
    if (!a6 && (a3 || a4 || a5))
    {
        sprintf(&result[cnt], "%s", "万");
        cnt += 2;
    }
    if (a7)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a7], chnstr[2 * a7 + 1], "仟");
        cnt += 4;
    }
    if (!a7 && (a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a8)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a8], chnstr[2 * a8 + 1], "佰");
        cnt += 4;
    }
    if (!a8 && a7 && (a9 || a10))
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a9)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a9], chnstr[2 * a9 + 1], "拾");
        cnt += 4;
    }
    if (!a9 && a8 && a10)
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a10)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a10], chnstr[2 * a10 + 1], "圆");
        cnt += 4;
    }
    if (!a10)
    {
        if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
        {
            sprintf(&result[cnt], "%s", "圆");
            cnt += 2;
        }
        if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
        {
            sprintf(&result[cnt], "%s", "零");
            cnt += 2;
            sprintf(&result[cnt], "%s", "圆");
            cnt += 2;
        }
    }
    if (a11)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a11], chnstr[2 * a11 + 1], "角");
        cnt += 4;
    }
    if (!a11 && a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
    {
        sprintf(&result[cnt], "%s", "零");
        cnt += 2;
    }
    if (a12)
    {
        sprintf(&result[cnt], "%c%c%s", chnstr[2 * a12], chnstr[2 * a12 + 1], "分");
        cnt += 5;
    }
    if (!a12)
    {
        sprintf(&result[cnt], "%s", "整");
        cnt += 3;
    }

    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}