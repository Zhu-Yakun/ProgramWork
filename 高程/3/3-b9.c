//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    for (int i = 1; i <= 9; i++)    //�п���
    {
        for (int j = 1; j <= i; j++)   //�п���
            printf("%dx%d=%-4d", j, i, i * j);
        printf("\n");   //��β����
    }
    printf("\n");

    return 0;
}