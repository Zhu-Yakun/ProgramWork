#include <iostream>
#include <conio.h>

using namespace std;

void ImageToAscii();

int menu()
{
    cout << "---------------------------------------------------" << endl;
    cout << "              图像转ASCII小程序" << endl;
    cout << "             0.退出" << endl;
    cout << "             1.ASCII图像查看器" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << " [请选择:] ";

    while (1) {
        char opt = _getche();
        if (opt >= '0' && opt <= '1') {
            cout << endl;
            return opt;
        }
        else {
            cout << "\b \b";
            continue;
        }
    }
}

int main()
{
    if (menu())
        ImageToAscii();
    else
        return 0;
}