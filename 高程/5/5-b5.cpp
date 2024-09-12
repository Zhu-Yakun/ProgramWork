/* 2252085 朱亚琨 信19 */
#include <iostream>
using namespace std;

int main()
{
    int ss[1005] = { 0 };
    int score[101] = { 0 };
    int a, cnt = 0, i = 0, rak = 1;
    cout << "请输入成绩（最多1000个），负数结束输入" << endl;
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
        cout << "无有效输入" << endl;
        return 0;
    }
    cout << "输入的数组为:" << endl;
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
    cout << "分数与名次的对应关系为:" << endl;
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