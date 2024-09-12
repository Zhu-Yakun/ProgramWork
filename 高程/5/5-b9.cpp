/* 2252085 ������ ��19 */
#include <iostream>
using namespace std;

int main()
{
    int num_array[9][9] = { 0 };
    int num[9] = { 0 };
    cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
    int r = 0, c = -1;
    while (r < 9 && c < 9)
    {
        cin >> num_array[r][++c];
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "�����������" << r + 1 << "��" << c + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
            c--;
            continue;
        }
        if (num_array[r][c] < 1 || num_array[r][c] > 9)
        {
            cout << "�����������" << r + 1 << "��" << c+1 << "��(���о���1��ʼ����)��ֵ" << endl;
            num_array[r][c] = 0;
            c--;
        }
        else
            if (c == 8)
            {
                c = -1;
                r++;
            }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            if(num_array[i][j] - 1 >= 0)
                num[num_array[i][j]- 1]++;
        for (int j = 0; j < 9; j++)
            if (num[j] != 1)
            {
                cout << "���������Ľ�" << endl;
                return 0;
            }
        for (int j = 0; j < 9; j++)
            num[j] = 0;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            if(num_array[j][i] - 1 >= 0)
                num[num_array[j][i] - 1]++;
        for (int j = 0; j < 9; j++)
            if (num[j] != 1)
            {
                cout << "���������Ľ�" << endl;
                return 0;
            }
        for (int j = 0; j < 9; j++)
            num[j] = 0;
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int m = 0; m < 3; m++)
                for (int n = 0; n < 3; n++)
                {
                    num[num_array[i * 3 + m][j * 3 + n]-1]++;
                    //cout << num_array[i * 3 + m][j * 3 + n] - 1 << endl;
                }
            for(int m = 0; m < 9; m++)
                if (num[j] != 1)
                {
                    cout << "���������Ľ�" << endl;
                    return 0;
                }
            for (int j = 0; j < 9; j++)
                num[j] = 0;
        }
    }
    cout << "�������Ľ�" << endl;  

    return 0;
}
