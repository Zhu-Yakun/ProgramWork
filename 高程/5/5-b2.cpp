/* 2252085 ÖìÑÇçû ĞÅ19 */
#include <iostream>
using namespace std;

int main()
{
    int flag = 0;
    int array1[101] = { 0 };
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            int a = array1[j];
            if (j % i == 0)
                array1[j] = int(!a);
        }
    }
    for (int j = 1; j < 101; j++)
    {
        if (array1[j] == 1)
        {
            if (flag++)
                cout << " ";
            cout << j;
        }
    }
    cout << endl;

    return 0;
}