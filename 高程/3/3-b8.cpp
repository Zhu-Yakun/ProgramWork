//2252085 ��19 ������
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int x, i = 1;
	double value = 1, an = 1, n = 1.0, xn = 1.0;
	bool prime = 1;    //������
	
	while (prime)
	{
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if (x <= 65 && x >= -10)
			prime = 0;
		else
			cout << "����Ƿ�������������" << endl;
	}
	while (fabs(an) >= 1e-6)
	{
		n *= i;       //  n!
		xn *= x;      //  x^n
		an = xn / n;
		if(fabs(an) >= 1e-6)   //��ֹ������һ�Σ���ʵҲ������������
			value += an;
		i++;
	}
	cout << "e^" << x << "=" << setprecision(10) << value << endl;

	return 0;
}