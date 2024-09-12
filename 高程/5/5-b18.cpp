/* 2252085 ÖìÑÇçû ÐÅ19 */
#include <iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
    int len, upr, lwr, num, othr, flag = 0;
    char ch;
    while (1) {
        if ((ch = getchar()) != '\n')
            continue;
        cin >> len >> upr >> lwr >> num >> othr;
        if (cin.fail() || (len < 12 || len > 16) || (upr < 2 || upr > len) || (lwr < 2 || lwr > len)
            || (num < 2 || num > len) || (othr < 2 || othr > len) || (upr + lwr + num + othr > len)){
            cout << "´íÎó" << endl;
            return 0;
        }
        ch = getchar();
        for (int i = 0; i < 10; i++) {
            int _len = 0, _upr = 0, _lwr = 0, _num = 0, _othr = 0;
            for (int j = 0; j < len; j++) {
                ch = getchar();
                _len++;
                if (ch >= 'A' && ch <= 'Z')
                    _upr++;
                else if (ch >= 'a' && ch <= 'z')
                    _lwr++;
                else if (ch >= '0' && ch <= '9')
                    _num++;
                else {
                    for (int k = 0; k < 15; k++) 
                        if (other[k] == ch) {
                            flag = 1;
                            break;
                        }
                    if (!flag) {
                        cout << "´íÎó" << endl;
                        return 0;
                    }
                    flag = 0;
                    _othr++;
                }
            }
            if ((_len != len || _upr < upr || _lwr < lwr || _num < num || _othr < othr) && ch != '\n') {
                cout << "´íÎó" << endl;
                return 0;
            }
            ch = getchar();
        }
        break;
    }
    cout << "ÕýÈ·" << endl;

    return 0;
}