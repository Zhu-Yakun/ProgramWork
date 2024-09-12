/* 2252085 朱亚琨 信19 */
#include <iostream>
#define INF 1000000000
using namespace std;

int min(int x, int y, int z = INF, int u = INF)
{
	int t = (x < y ? x : y);
	int m = (z < u ? z : u);
	return (t < m ? t : m);
}

int main()
{
	int cnt, x = 1, y = 1, z = 1, u = 1, Min = 0;
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
		Min = min(x, y);
	else if (cnt == 3)
		Min = min(x, y, z);
	else if (cnt == 4)
		Min = min(x, y, z, u);
	cout << "min=" << Min << endl;

	return 0;
}