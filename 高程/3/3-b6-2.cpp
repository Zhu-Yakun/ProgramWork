//2252085 ��19 ������
#include <iostream>
using namespace std;

int main()
{
    double a, b, c, b10, b11, b12;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;

    cout << "������[0-100��)֮�������:" << endl;
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
    
    cout << "��д�����:" << endl;
    switch (a1) {                  //����-����ת��
        case 0:
            break;
        case 1:
            cout << "Ҽʰ";
            break;
        case 2:
            cout << "��ʰ";
            break;
        case 3:
            cout << "��ʰ";
            break;
        case 4:
            cout << "��ʰ";
            break;
        case 5:
            cout << "��ʰ";
            break;
        case 6:
            cout << "½ʰ";
            break;
        case 7:
            cout << "��ʰ";
            break;
        case 8:
            cout << "��ʰ";
            break;
        case 9:
            cout << "��ʰ";
            break;
    }
    switch (a2) {
        case 0:
            if (a1)
                cout << "��";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 2:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 5:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 7:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 9:
            cout << "����";
            break;
    }
    switch (a3) {
        case 0:
            if ((a1 || a2) && (a4 || a5 || a6))
                cout << "��";
            break;
        case 1:
            cout << "ҼǪ";
            break;
        case 2:
            cout << "��Ǫ";
            break;
        case 3:
            cout << "��Ǫ";
            break;
        case 4:
            cout << "��Ǫ";
            break;
        case 5:
            cout << "��Ǫ";
            break;
        case 6:
            cout << "½Ǫ";
            break;
        case 7:
            cout << "��Ǫ";
            break;
        case 8:
            cout << "��Ǫ";
            break;
        case 9:
            cout << "��Ǫ";
            break;
    }
    switch (a4) {
        case 0:
            if (a3 && (a5 || a6))
                cout << "��";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 2:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 5:
            cout << "���";
            break;
        case 6:
            cout << "½��";
            break;
        case 7:
            cout << "���";
            break;
        case 8:
            cout << "�ư�";
            break;
        case 9:
            cout << "����";
            break;
    }
    switch (a5) {
        case 0:
            if ((a3 || a4) && a6)
                cout << "��";
            break;
        case 1:
            cout << "Ҽʰ";
            break;
        case 2:
            cout << "��ʰ";
            break;
        case 3:
            cout << "��ʰ";
            break;
        case 4:
            cout << "��ʰ";
            break;
        case 5:
            cout << "��ʰ";
            break;
        case 6:
            cout << "½ʰ";
            break;
        case 7:
            cout << "��ʰ";
            break;
        case 8:
            cout << "��ʰ";
            break;
        case 9:
            cout << "��ʰ";
            break;
    }
    switch (a6) {
        case 0:
            if (a3 || a4 || a5)
                cout << "��";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 2:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 5:
            cout << "����";
            break;
        case 6:
            cout << "½��";
            break;
        case 7:
            cout << "����";
            break;
        case 8:
            cout << "����";
            break;
        case 9:
            cout << "����";
            break;
    }
    switch (a7) {
        case 0:
            if ((a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
                cout << "��";
            break;
        case 1:
            cout << "ҼǪ";
            break;
        case 2:
            cout << "��Ǫ";
            break;
        case 3:
            cout << "��Ǫ";
            break;
        case 4:
            cout << "��Ǫ";
            break;
        case 5:
            cout << "��Ǫ";
            break;
        case 6:
            cout << "½Ǫ";
            break;
        case 7:
            cout << "��Ǫ";
            break;
        case 8:
            cout << "��Ǫ";
            break;
        case 9:
            cout << "��Ǫ";
            break;
    }
    switch (a8) {
        case 0:
            if ( a7 && (a9 || a10))
                cout << "��";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 2:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 5:
            cout << "���";
            break;
        case 6:
            cout << "½��";
            break;
        case 7:
            cout << "���";
            break;
        case 8:
            cout << "�ư�";
            break;
        case 9:
            cout << "����";
            break;
    }
    switch (a9) {
        case 0:
            if (a8 && a10)
                cout << "��";
            break;
        case 1:
            cout << "Ҽʰ";
            break;
        case 2:
            cout << "��ʰ";
            break;
        case 3:
            cout << "��ʰ";
            break;
        case 4:
            cout << "��ʰ";
            break;
        case 5:
            cout << "��ʰ";
            break;
        case 6:
            cout << "½ʰ";
            break;
        case 7:
            cout << "��ʰ";
            break;
        case 8:
            cout << "��ʰ";
            break;
        case 9:
            cout << "��ʰ";
            break;
    }
    switch (a10) {
        case 0:
            if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
                cout << "Բ";
            if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
                cout << "��Բ";
            break;
        case 1:
            cout << "ҼԲ";
            break;
        case 2:
            cout << "��Բ";
            break;
        case 3:
            cout << "��Բ";
            break;
        case 4:
            cout << "��Բ";
            break;
        case 5:
            cout << "��Բ";
            break;
        case 6:
            cout << "½Բ";
            break;
        case 7:
            cout << "��Բ";
            break;
        case 8:
            cout << "��Բ";
            break;
        case 9:
            cout << "��Բ";
            break;
    }
    switch (a11) {
        case 0:
            if (a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
                cout << "��";
            break;
        case 1:
            cout << "Ҽ��";
            break;
        case 2:
            cout << "����";
            break;
        case 3:
            cout << "����";
            break;
        case 4:
            cout << "����";
            break;
        case 5:
            cout << "���";
            break;
        case 6:
            cout << "½��";
            break;
        case 7:
            cout << "���";
            break;
        case 8:
            cout << "�ƽ�";
            break;
        case 9:
            cout << "����";
            break;
    }
    switch (a12) {
        case 0:
            cout << "��" << endl;
            break;
        case 1:
            cout << "Ҽ��" << endl;
            break;
        case 2:
            cout << "����" << endl;
            break;
        case 3:
            cout << "����" << endl;
            break;
        case 4:
            cout << "����" << endl;
            break;
        case 5:
            cout << "���" << endl;
            break;
        case 6:
            cout << "½��" << endl;
            break;
        case 7:
            cout << "���" << endl;
            break;
        case 8:
            cout << "�Ʒ�" << endl;
            break;
        case 9:
            cout << "����" << endl;
            break;
    }

    return 0;
}