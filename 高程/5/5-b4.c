//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int ss[1005] = { 0 };
    int score[101] = { 0 };
    int a, cnt = 0, i = 0;
    printf("������ɼ������1000������������������\n");
    while (1)
    {
        scanf("%d", &a);
        if (a < 0)
            break;
        cnt++;
        if (i < 1000)
            ss[i++] = a;
    }
    if (cnt > 1000)
    {
        cnt = 1000;
        while (getchar() != '\n')
            ;
    }
    if (!cnt)
    {
        printf("����Ч����\n");
        return 0;
    }
    printf("���������Ϊ:\n");
    for (int j = 1; j <= cnt; j++)
    {
        printf("%d ", ss[j - 1]);
        if (j % 10 == 0)
            printf("\n");
    }
    if (cnt % 10 != 0)
        printf("\n");
    for (int j = 0; j < cnt; j++)
        score[ss[j]]++;
    printf("�����������Ķ�Ӧ��ϵΪ:\n");
    for (int j = 100; j >= 0; j--)
        if (score[j])
            printf("%d %d\n", j, score[j]);

    return 0;
}