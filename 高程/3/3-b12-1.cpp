/* 信19 2252085 朱亚琨 */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

		if (!cin.good())
		{
			cin.clear();                   //除去cin的标记，使cin.good()恢复为1
			cin.ignore(2147483647, '\n');     //清除缓冲区的当前行的内容  
		}                              //原本想用numeric_limits<streamsize>::max()不过要加头文件，怕扣分 
		else if (x >= 0 && x <= 100)
			break;
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}
