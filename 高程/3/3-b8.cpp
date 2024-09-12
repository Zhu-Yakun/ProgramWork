//2252085 信19 朱亚琨
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int x, i = 1;
	double value = 1, an = 1, n = 1.0, xn = 1.0;
	bool prime = 1;    //输入标记
	
	while (prime)
	{
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x <= 65 && x >= -10)
			prime = 0;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	while (fabs(an) >= 1e-6)
	{
		n *= i;       //  n!
		xn *= x;      //  x^n
		an = xn / n;
		if(fabs(an) >= 1e-6)   //防止多加最后一次（其实也可以最后减掉）
			value += an;
		i++;
	}
	cout << "e^" << x << "=" << setprecision(10) << value << endl;

	return 0;
}