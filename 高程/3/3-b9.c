//2252085 信19 朱亚琨
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    for (int i = 1; i <= 9; i++)    //行控制
    {
        for (int j = 1; j <= i; j++)   //列控制
            printf("%dx%d=%-4d", j, i, i * j);
        printf("\n");   //行尾换行
    }
    printf("\n");

    return 0;
}