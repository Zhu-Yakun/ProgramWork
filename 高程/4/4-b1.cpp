/* 2252085 ������ ��19 */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
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
    if (a1)
    {
        daxie(a1, 0);
        cout << "ʰ";
    }
    if (a2)
    {
        daxie(a2, 0);
        cout << "��";
    }
    if(!a2 && a1)
        cout << "��";
    if (a3)
    {
        daxie(a3, 0);
        cout << "Ǫ";
    }
    if(!a3 && (a1 || a2) && (a4 || a5 || a6))
        daxie(0, 1);
    if (a4)
    {
        daxie(a4, 0);
        cout << "��";
    }
    if(!a4 && a3 && (a5 || a6))
        daxie(0, 1);
    if (a5)
    {
        daxie(a5, 0);
        cout << "ʰ";
    }
    if(!a5 && (a3 || a4) && a6)
        daxie(0, 1);
    if (a6)
    {
        daxie(a6, 0);
        cout << "��";
    }
    if(!a6 && (a3 || a4 || a5))
        cout << "��";
    if (a7)
    {
        daxie(a7, 0);
        cout << "Ǫ";
    }
    if (!a7 && (a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
        daxie(0, 1);
    if (a8)
    {
        daxie(a8, 0);
        cout << "��";
    }
    if (!a8 && a7 && (a9 || a10))
        daxie(0, 1);
    if (a9)
    {
        daxie(a9, 0);
        cout << "ʰ";
    }
    if(!a9 && a8 && a10)
        daxie(0, 1);
    if (a10)
    {
        daxie(a10, 0);
        cout << "Բ";
    }
    if (!a10)
    {
        if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
            cout << "Բ";
        if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
        {
            daxie(0, 1);
            cout << "Բ";
        }
    }
    if (a11)
    {
        daxie(a11, 0);
        cout << "��";
    }
    if(!a11 && a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
        daxie(0, 1);
    if (a12)
    {
        daxie(a12, 0);
        cout << "��" << endl;
    }
    if(!a12)
        cout << "��" << endl;

    return 0;
}