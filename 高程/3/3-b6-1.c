//2252085 ÐÅ19 ÖìÑÇçû
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()                                                        
{
    double a, b, c, b10, b11, b12;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0, a12 = 0;
    
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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

    printf("´óÐ´½á¹ûÊÇ:\n");
    switch (a1) {                  //Êý×Ö-ºº×Ö×ª»»
        case 0:
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 2:
            printf("·¡Ê°"); 
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 9:
            printf("¾ÁÊ°");
            break;
    }
    switch (a2) {
        case 0:
            if (a1)
                printf("ÒÚ");
            break;
        case 1:
            printf("Ò¼ÒÚ");
            break;
        case 2:
            printf("·¡ÒÚ");
            break;
        case 3:
            printf("ÈþÒÚ");
            break;
        case 4:
            printf("ËÁÒÚ");
            break;
        case 5:
            printf("ÎéÒÚ");
            break;
        case 6:
            printf("Â½ÒÚ");
            break;
        case 7:
            printf("ÆâÒÚ");
            break;
        case 8:
            printf("°ÆÒÚ");
            break;
        case 9:
            printf("¾ÁÒÚ");
            break;
    }
    switch (a3) {
        case 0:
            if ((a1 || a2) && (a4 || a5 || a6))
                printf("Áã");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 9:
            printf("¾ÁÇª");
            break;
    }
    switch (a4) {
        case 0:
            if (a3 && (a5 || a6))
                printf("Áã");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 9:
            printf("¾Á°Û");
            break;
    }
    switch (a5) {
        case 0:
            if ((a3 || a4) && a6)
                printf("Áã");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 9:
            printf("¾ÁÊ°");
            break;
    }
    switch (a6) {
        case 0:
            if (a3 || a4 || a5)
                printf("Íò");
            break;
        case 1:
            printf("Ò¼Íò");
            break;
        case 2:
            printf("·¡Íò");
            break;
        case 3:
            printf("ÈþÍò");
            break;
        case 4:
            printf("ËÁÍò");
            break;
        case 5:
            printf("ÎéÍò");
            break;
        case 6:
            printf("Â½Íò");
            break;
        case 7:
            printf("ÆâÍò");
            break;
        case 8:
            printf("°ÆÍò");
            break;
        case 9:
            printf("¾ÁÍò");
            break;
    }
    switch (a7) {
        case 0:
            if ((a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
                printf("Áã");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 9:
            printf("¾ÁÇª");
            break;
    }
    switch (a8) {
        case 0:
            if (a7 && (a9 || a10))
                printf("Áã");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 9:
            printf("¾Á°Û");
            break;
    }
    switch (a9) {
        case 0:
            if (a8 && a10)
                printf("Áã");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 9:
            printf("¾ÁÊ°");
            break;
    }
    switch (a10) {
        case 0:
            if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
                printf("Ô²");
            if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
                printf("ÁãÔ²");
            break;
        case 1:
            printf("Ò¼Ô²");
            break;
        case 2:
            printf("·¡Ô²");
            break;
        case 3:
            printf("ÈþÔ²");
            break;
        case 4:
            printf("ËÁÔ²");
            break;
        case 5:
            printf("ÎéÔ²");
            break;
        case 6:
            printf("Â½Ô²");
            break;
        case 7:
            printf("ÆâÔ²");
            break;
        case 8:
            printf("°ÆÔ²");
            break;
        case 9:
            printf("¾ÁÔ²");
            break;
    }
    switch (a11) {
        case 0:
            if (a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
                printf("Áã");
            break;
        case 1:
            printf("Ò¼½Ç");
            break;
        case 2:
            printf("·¡½Ç");
            break;
        case 3:
            printf("Èþ½Ç");
            break;
        case 4:
            printf("ËÁ½Ç");
            break;
        case 5:
            printf("Îé½Ç");
            break;
        case 6:
            printf("Â½½Ç");
            break;
        case 7:
            printf("Æâ½Ç");
            break;
        case 8:
            printf("°Æ½Ç");
            break;
        case 9:
            printf("¾Á½Ç");
            break;
    }
    switch (a12) {
        case 0:
            printf("Õû\n");
            break;
        case 1:
            printf("Ò¼·Ö\n");
            break;
        case 2:
            printf("·¡·Ö\n");
            break;
        case 3:
            printf("Èþ·Ö\n");
            break;
        case 4:
            printf("ËÁ·Ö\n");
            break;
        case 5:
            printf("Îé·Ö\n");
            break;
        case 6:
            printf("Â½·Ö\n");
            break;
        case 7:
            printf("Æâ·Ö\n");
            break;
        case 8:
            printf("°Æ·Ö\n");
            break;
        case 9:
            printf("¾Á·Ö\n");
            break;
    }

	return 0;
}