#include <iostream>
#include <conio.h>

using namespace std;

void ImageToAscii();

int menu()
{
    cout << "---------------------------------------------------" << endl;
    cout << "              ͼ��תASCIIС����" << endl;
    cout << "             0.�˳�" << endl;
    cout << "             1.ASCIIͼ��鿴��" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << " [��ѡ��:] ";

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