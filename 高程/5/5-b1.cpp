/* 2252085 ������ ��19 */
#include <iostream>
#define MAX 30
using namespace std;

int main()
{
    int array1[MAX] = { 0 };
    int a, mid, cnt = 0, i = 0;
    cout << "��������������������������20������0������������" << endl;
    while(1)
    {
        cin >> a;
        if (a <= 0)
            break;
        cnt++;
        if(i < 20)
            array1[i++] = a;
    }
    if (cnt > 20)
    {
        cnt = 20;
        cin.clear();
        cin.ignore(65536, '\n');
    }
    if (!cnt)
    {
        cout << "����Ч����" << endl;
        return 0;
    }
    cout << "ԭ����Ϊ��" << endl;
    for (int j = 0; j < cnt; j++)
        cout << array1[j] << " ";
    cout << endl << "������Ҫ�����������" << endl;
    cin >> mid;
    int flag = cnt;
    for (int j = 0; j < cnt; j++)
    {
        if (mid < array1[j])
        {
            flag = j;
            break;
        }
    }
    if (flag == cnt)
        array1[cnt] = mid;
    else
    {
        for(int j = cnt; j > flag; j--)
            array1[j] = array1[j - 1];
        array1[flag] = mid;
    }
    cout << "����������Ϊ��" << endl;
    for (int j = 0; j < cnt + 1; j++)
        cout << array1[j] << " ";
    cout << endl;

    return 0;
}