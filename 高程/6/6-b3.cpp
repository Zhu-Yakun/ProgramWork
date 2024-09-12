/* 2252085 朱亚琨 信19 */
#include <iostream>
using namespace std;

unsigned int bin_to_dec(char *p_bin)
{
	char* p = p_bin;
	unsigned int _dec = 0, i = 1;
	while (*p++ != 0)
		;
	p--;
	while (--p >= p_bin)
	{
		_dec += (*p - '0') * i;
		i *= 2;
	}
	return _dec;
}

int main()
{
	char bin[33] = { 0 }, *p_bin;
	p_bin = bin;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> bin;
	unsigned int _dec = bin_to_dec(p_bin);
	cout << _dec << endl;

	return 0;
}
