//2252085 ��19 ������
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c,a10,a11,a12;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
    cout << "������[0-100��)֮�������:" << endl;
    cin >> a;
    c = a + 0.000001;
    b = c / 10;
    a1 = int(b / 1e8) % 10;
    a2 = int(b / 1e7) % 10;
    a3 = int(b / 1e6) %10;
    a4 = int(b / 1e5) % 10;
    a5 = int(b / 1e4) % 10;
    a6 = int(b / 1e3) % 10;
    a7 = int(b / 100) % 10;
    a8 = int(b / 10) % 10;
    a9 = int(b - a1 * 1e8) % 10;
    a10 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9;
    a11 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - int(a10 * 10)*0.1;
    a12 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - int(a10 * 10) * 0.1 - int(a11*100)*0.01;
    
    cout << "ʮ��λ : " << a1 << endl;
    cout << "��λ   : " << a2 << endl;
    cout << "ǧ��λ : " << a3 << endl;
    cout << "����λ : " << a4 << endl;
    cout << "ʮ��λ : " << a5 << endl;
    cout << "��λ   : " << a6 << endl;
    cout << "ǧλ   : " << a7 << endl;
    cout << "��λ   : " << a8 << endl;
    cout << "ʮλ   : " << a9 << endl;
    cout << "Բ     : " << int(a10 * 10) << endl;
    cout << "��     : " << int(a11 * 100) << endl;
    cout << "��     : " << int(a12 * 1000) << endl;

    return 0;
}
