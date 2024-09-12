/* 2252085 朱亚琨 信19 */
#include <iostream>

using namespace std;

int max(int x, int y)
{
	return (x > y ? x : y);
}
int max(int x, int y, int z)
{
	int t = (x > y ? x : y);
	return (t > z ? t : z);
}
int max(int x, int y, int z, int u)
{
	int t = (x > y ? x : y);
	int m = (z > u ? z : u);
	return (t > m ? t : m);
}

int main()
{
	int cnt, x = 1, y = 1, z = 1, u = 1, Max = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> cnt;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (cnt < 2 || cnt > 4) {
			cout << "个数输入错误" << endl;
			return 0;
		}
		else {
			cin >> x >> y;
			if (cnt == 3)
				cin >> z;
			if (cnt == 4)
				cin >> z >> u;
			if (cin.fail() || x <= 0 || y <= 0 || z <= 0 || u <= 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
	}
	if (cnt == 2)
		Max = max(x, y);
	else if(cnt == 3)
		Max = max(x, y, z);
	else if (cnt == 4)
		Max = max(x, y, z, u);
	cout << "max=" << Max << endl;

	return 0;
}