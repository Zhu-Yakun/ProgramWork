//2252085 ��19 ������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()                                                        
{
    double a, b, c, b10, b11, b12;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0, a12 = 0;
    
    printf("������[0-100��)֮�������:\n");
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

    printf("��д�����:\n");
    switch (a1) {                  //����-����ת��
        case 0:
            break;
        case 1:
            printf("Ҽʰ");
            break;
        case 2:
            printf("��ʰ"); 
            break;
        case 3:
            printf("��ʰ");
            break;
        case 4:
            printf("��ʰ");
            break;
        case 5:
            printf("��ʰ");
            break;
        case 6:
            printf("½ʰ");
            break;
        case 7:
            printf("��ʰ");
            break;
        case 8:
            printf("��ʰ");
            break;
        case 9:
            printf("��ʰ");
            break;
    }
    switch (a2) {
        case 0:
            if (a1)
                printf("��");
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("����");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("����");
            break;
        case 8:
            printf("����");
            break;
        case 9:
            printf("����");
            break;
    }
    switch (a3) {
        case 0:
            if ((a1 || a2) && (a4 || a5 || a6))
                printf("��");
            break;
        case 1:
            printf("ҼǪ");
            break;
        case 2:
            printf("��Ǫ");
            break;
        case 3:
            printf("��Ǫ");
            break;
        case 4:
            printf("��Ǫ");
            break;
        case 5:
            printf("��Ǫ");
            break;
        case 6:
            printf("½Ǫ");
            break;
        case 7:
            printf("��Ǫ");
            break;
        case 8:
            printf("��Ǫ");
            break;
        case 9:
            printf("��Ǫ");
            break;
    }
    switch (a4) {
        case 0:
            if (a3 && (a5 || a6))
                printf("��");
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�ư�");
            break;
        case 9:
            printf("����");
            break;
    }
    switch (a5) {
        case 0:
            if ((a3 || a4) && a6)
                printf("��");
            break;
        case 1:
            printf("Ҽʰ");
            break;
        case 2:
            printf("��ʰ");
            break;
        case 3:
            printf("��ʰ");
            break;
        case 4:
            printf("��ʰ");
            break;
        case 5:
            printf("��ʰ");
            break;
        case 6:
            printf("½ʰ");
            break;
        case 7:
            printf("��ʰ");
            break;
        case 8:
            printf("��ʰ");
            break;
        case 9:
            printf("��ʰ");
            break;
    }
    switch (a6) {
        case 0:
            if (a3 || a4 || a5)
                printf("��");
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("����");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("����");
            break;
        case 8:
            printf("����");
            break;
        case 9:
            printf("����");
            break;
    }
    switch (a7) {
        case 0:
            if ((a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
                printf("��");
            break;
        case 1:
            printf("ҼǪ");
            break;
        case 2:
            printf("��Ǫ");
            break;
        case 3:
            printf("��Ǫ");
            break;
        case 4:
            printf("��Ǫ");
            break;
        case 5:
            printf("��Ǫ");
            break;
        case 6:
            printf("½Ǫ");
            break;
        case 7:
            printf("��Ǫ");
            break;
        case 8:
            printf("��Ǫ");
            break;
        case 9:
            printf("��Ǫ");
            break;
    }
    switch (a8) {
        case 0:
            if (a7 && (a9 || a10))
                printf("��");
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�ư�");
            break;
        case 9:
            printf("����");
            break;
    }
    switch (a9) {
        case 0:
            if (a8 && a10)
                printf("��");
            break;
        case 1:
            printf("Ҽʰ");
            break;
        case 2:
            printf("��ʰ");
            break;
        case 3:
            printf("��ʰ");
            break;
        case 4:
            printf("��ʰ");
            break;
        case 5:
            printf("��ʰ");
            break;
        case 6:
            printf("½ʰ");
            break;
        case 7:
            printf("��ʰ");
            break;
        case 8:
            printf("��ʰ");
            break;
        case 9:
            printf("��ʰ");
            break;
    }
    switch (a10) {
        case 0:
            if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
                printf("Բ");
            if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
                printf("��Բ");
            break;
        case 1:
            printf("ҼԲ");
            break;
        case 2:
            printf("��Բ");
            break;
        case 3:
            printf("��Բ");
            break;
        case 4:
            printf("��Բ");
            break;
        case 5:
            printf("��Բ");
            break;
        case 6:
            printf("½Բ");
            break;
        case 7:
            printf("��Բ");
            break;
        case 8:
            printf("��Բ");
            break;
        case 9:
            printf("��Բ");
            break;
    }
    switch (a11) {
        case 0:
            if (a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
                printf("��");
            break;
        case 1:
            printf("Ҽ��");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("����");
            break;
        case 4:
            printf("����");
            break;
        case 5:
            printf("���");
            break;
        case 6:
            printf("½��");
            break;
        case 7:
            printf("���");
            break;
        case 8:
            printf("�ƽ�");
            break;
        case 9:
            printf("����");
            break;
    }
    switch (a12) {
        case 0:
            printf("��\n");
            break;
        case 1:
            printf("Ҽ��\n");
            break;
        case 2:
            printf("����\n");
            break;
        case 3:
            printf("����\n");
            break;
        case 4:
            printf("����\n");
            break;
        case 5:
            printf("���\n");
            break;
        case 6:
            printf("½��\n");
            break;
        case 7:
            printf("���\n");
            break;
        case 8:
            printf("�Ʒ�\n");
            break;
        case 9:
            printf("����\n");
            break;
    }

	return 0;
}