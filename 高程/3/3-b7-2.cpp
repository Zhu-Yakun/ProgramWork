//2252085 信19 朱亚琨
#include<iostream>
//#include<iomanip>
using namespace std;

int main()
{
	double a;
	int sum = 0;
	int s_a50, s_a20, s_a10, s_a5, s_a1, s_b5, s_b1, s_c5, s_c2, s_c1;
	cout << "请输入找零值：" << endl;
	cin >> a;
	a += 0.0001;

	s_a50 = int(a) / 50;
	a -= s_a50 * 50;

	s_a20 = int(a) / 20;
	a -= s_a20 * 20;

	s_a10 = int(a) / 10;
	a -= s_a10 * 10;

	s_a5 = int(a) / 5;
	a -= s_a5 * 5;

	s_a1 = int(a);
	a -= s_a1;
	
	a *= 10;
	s_b5 = int(a) / 5;
	a -= s_b5 * 5;

	s_b1 = int(a);
	a -= s_b1;

	a *= 10;
	s_c5 = int(a) / 5;
	a -= s_c5 * 5;

	s_c2 = int(a) / 2;
	a -= s_c2 * 2;

	s_c1 = int(a);
	a -= s_c1;

	sum = s_a50 + s_a20 + s_a10 + s_a5 + s_a1 + s_b5 + s_b1 + s_c5 + s_c2 + s_c1;

	cout << "共" << sum << "张找零，具体如下：" << endl;
	if (s_a50)
		cout << "50元 : " << s_a50 << "张" << endl;
	if (s_a20)
		cout << "20元 : " << s_a20 << "张" << endl;
	if (s_a10)
		cout << "10元 : " << s_a10 << "张" << endl;
	if (s_a5)
		cout << "5元  : " << s_a5 << "张" << endl;
	if (s_a1)
		cout << "1元  : " << s_a1 << "张" << endl;
	if (s_b5)
		cout << "5角  : " << s_b5 << "张" << endl;
	if (s_b1)
		cout << "1角  : " << s_b1 << "张" << endl;
	if (s_c5)
		cout << "5分  : " << s_c5 << "张" << endl;
	if (s_c2)
		cout << "2分  : " << s_c2 << "张" << endl;
	if (s_c1)
		cout << "1分  : " << s_c1 << "张" << endl;

	return 0;
}