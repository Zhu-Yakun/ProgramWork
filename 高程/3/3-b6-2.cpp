//2252085 ĞÅ19 ÖìÑÇçû
#include <iostream>
using namespace std;

int main()
{
    double a, b, c, b10, b11, b12;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;

    cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
    cin >> a;
    c = a + 0.000001;
    b = c / 10;
    a1 = int(b / 1e8) % 10;
    a2 = int(b / 1e7) % 10;
    a3 = int(b / 1e6) % 10;
    a4 = int(b / 1e5) % 10;
    a5 = int(b / 1e4) % 10;
    a6 = int(b / 1e3) % 10;
    a7 = int(b / 100) % 10;
    a8 = int(b / 10) % 10;
    a9 = int(b - a1 * 1e8) % 10;
    b10 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9;
    b11 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - int(b10 * 10) * 0.1;
    b12 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - int(b10 * 10) * 0.1 - int(b11 * 100) * 0.01;
    a10 = int(b10 * 10);
    a11 = int(b11 * 100);
    a12 = int(b12 * 1000);
    
    cout << "´óĞ´½á¹ûÊÇ:" << endl;
    switch (a1) {                  //Êı×Ö-ºº×Ö×ª»»
        case 0:
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 9:
            cout << "¾ÁÊ°";
            break;
    }
    switch (a2) {
        case 0:
            if (a1)
                cout << "ÒÚ";
            break;
        case 1:
            cout << "Ò¼ÒÚ";
            break;
        case 2:
            cout << "·¡ÒÚ";
            break;
        case 3:
            cout << "ÈşÒÚ";
            break;
        case 4:
            cout << "ËÁÒÚ";
            break;
        case 5:
            cout << "ÎéÒÚ";
            break;
        case 6:
            cout << "Â½ÒÚ";
            break;
        case 7:
            cout << "ÆâÒÚ";
            break;
        case 8:
            cout << "°ÆÒÚ";
            break;
        case 9:
            cout << "¾ÁÒÚ";
            break;
    }
    switch (a3) {
        case 0:
            if ((a1 || a2) && (a4 || a5 || a6))
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 3:
            cout << "ÈşÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 7:
            cout << "ÆâÇª";
            break;
        case 8:
            cout << "°ÆÇª";
            break;
        case 9:
            cout << "¾ÁÇª";
            break;
    }
    switch (a4) {
        case 0:
            if (a3 && (a5 || a6))
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 3:
            cout << "Èş°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 7:
            cout << "Æâ°Û";
            break;
        case 8:
            cout << "°Æ°Û";
            break;
        case 9:
            cout << "¾Á°Û";
            break;
    }
    switch (a5) {
        case 0:
            if ((a3 || a4) && a6)
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 9:
            cout << "¾ÁÊ°";
            break;
    }
    switch (a6) {
        case 0:
            if (a3 || a4 || a5)
                cout << "Íò";
            break;
        case 1:
            cout << "Ò¼Íò";
            break;
        case 2:
            cout << "·¡Íò";
            break;
        case 3:
            cout << "ÈşÍò";
            break;
        case 4:
            cout << "ËÁÍò";
            break;
        case 5:
            cout << "ÎéÍò";
            break;
        case 6:
            cout << "Â½Íò";
            break;
        case 7:
            cout << "ÆâÍò";
            break;
        case 8:
            cout << "°ÆÍò";
            break;
        case 9:
            cout << "¾ÁÍò";
            break;
    }
    switch (a7) {
        case 0:
            if ((a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 3:
            cout << "ÈşÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 7:
            cout << "ÆâÇª";
            break;
        case 8:
            cout << "°ÆÇª";
            break;
        case 9:
            cout << "¾ÁÇª";
            break;
    }
    switch (a8) {
        case 0:
            if ( a7 && (a9 || a10))
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 3:
            cout << "Èş°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 7:
            cout << "Æâ°Û";
            break;
        case 8:
            cout << "°Æ°Û";
            break;
        case 9:
            cout << "¾Á°Û";
            break;
    }
    switch (a9) {
        case 0:
            if (a8 && a10)
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 9:
            cout << "¾ÁÊ°";
            break;
    }
    switch (a10) {
        case 0:
            if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
                cout << "Ô²";
            if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
                cout << "ÁãÔ²";
            break;
        case 1:
            cout << "Ò¼Ô²";
            break;
        case 2:
            cout << "·¡Ô²";
            break;
        case 3:
            cout << "ÈşÔ²";
            break;
        case 4:
            cout << "ËÁÔ²";
            break;
        case 5:
            cout << "ÎéÔ²";
            break;
        case 6:
            cout << "Â½Ô²";
            break;
        case 7:
            cout << "ÆâÔ²";
            break;
        case 8:
            cout << "°ÆÔ²";
            break;
        case 9:
            cout << "¾ÁÔ²";
            break;
    }
    switch (a11) {
        case 0:
            if (a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
                cout << "Áã";
            break;
        case 1:
            cout << "Ò¼½Ç";
            break;
        case 2:
            cout << "·¡½Ç";
            break;
        case 3:
            cout << "Èş½Ç";
            break;
        case 4:
            cout << "ËÁ½Ç";
            break;
        case 5:
            cout << "Îé½Ç";
            break;
        case 6:
            cout << "Â½½Ç";
            break;
        case 7:
            cout << "Æâ½Ç";
            break;
        case 8:
            cout << "°Æ½Ç";
            break;
        case 9:
            cout << "¾Á½Ç";
            break;
    }
    switch (a12) {
        case 0:
            cout << "Õû" << endl;
            break;
        case 1:
            cout << "Ò¼·Ö" << endl;
            break;
        case 2:
            cout << "·¡·Ö" << endl;
            break;
        case 3:
            cout << "Èş·Ö" << endl;
            break;
        case 4:
            cout << "ËÁ·Ö" << endl;
            break;
        case 5:
            cout << "Îé·Ö" << endl;
            break;
        case 6:
            cout << "Â½·Ö" << endl;
            break;
        case 7:
            cout << "Æâ·Ö" << endl;
            break;
        case 8:
            cout << "°Æ·Ö" << endl;
            break;
        case 9:
            cout << "¾Á·Ö" << endl;
            break;
    }

    return 0;
}