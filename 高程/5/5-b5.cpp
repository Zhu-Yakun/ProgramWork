/* 2252085 ������ ��19 */
#include <iostream>
using namespace std;

int main()
{
    int ss[1005] = { 0 };
    int score[101] = { 0 };
    int a, cnt = 0, i = 0, rak = 1;
    cout << "������ɼ������1000������������������" << endl;
    while (1)
    {
        cin >> a;
        if (a < 0)
            break;
        cnt++;
        if (i < 1000)
            ss[i++] = a;
    }
    if (cnt > 1000)
    {
        cnt = 1000;
        cin.clear();
        cin.ignore(65536, '\n');
    }
    if (!cnt)
    {
        cout << "����Ч����" << endl;
        return 0;
    }
    cout << "���������Ϊ:" << endl;
    for (int j = 1; j <= cnt; j++)
    {
        cout << ss[j - 1] << " ";
        if (j % 10 == 0)
            cout << endl;
    }
    if (cnt % 10 != 0)
        cout << endl;
    for (int j = 0; j < cnt; j++)
        score[ss[j]]++;
    cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
    for (int j = 100; j >= 0; j--)
    {
        if (score[j])
        {
            for (int k = 0; k < score[j]; k++)
                cout << j << " " << rak << endl;
            rak += score[j];
        }
    }

    return 0;
}