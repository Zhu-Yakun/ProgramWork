/* 2252085 ������ ��19 */
#include <iostream>
using namespace std;

int main()
{
    char str[3][128] = { 0 }, ch;
    int i = 0, j = 0;
    int cnt_upr = 0, cnt_lwr = 0, cnt_num = 0, cnt_spc = 0, cnt_other = 0;
    while (i < 3)
    {
        if (j == 0)
            cout << "�������" << i+1 << "��" << endl;
        ch = getchar();
        if (j == 128 && ch != '\n') {
            while (getchar() != '\n')
                ;
            i++;
            j = 0;
            continue;
        }
        if (ch == '\n') {
            i++;
            j = 0;
            continue;
        }
        else if (ch >= 'A' && ch <= 'Z')
            cnt_upr++;
        else if (ch >= 'a' && ch <= 'z')
            cnt_lwr++;
        else if (ch >= '0' && ch <= '9')
            cnt_num++;
        else if (ch == ' ')
            cnt_spc++;
        else
            cnt_other++;
        str[i][j++] = ch;
    }
    cout << "��д : " << cnt_upr << endl;
    cout << "Сд : " << cnt_lwr << endl;
    cout << "���� : " << cnt_num << endl;
    cout << "�ո� : " << cnt_spc << endl;
    cout << "���� : " << cnt_other << endl;

    return 0;
}