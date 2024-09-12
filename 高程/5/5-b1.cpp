/* 2252085 朱亚琨 信19 */
#include <iostream>
#define MAX 30
using namespace std;

int main()
{
    int array1[MAX] = { 0 };
    int a, mid, cnt = 0, i = 0;
    cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
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
        cout << "无有效输入" << endl;
        return 0;
    }
    cout << "原数组为：" << endl;
    for (int j = 0; j < cnt; j++)
        cout << array1[j] << " ";
    cout << endl << "请输入要插入的正整数" << endl;
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
    cout << "插入后的数组为：" << endl;
    for (int j = 0; j < cnt + 1; j++)
        cout << array1[j] << " ";
    cout << endl;

    return 0;
}