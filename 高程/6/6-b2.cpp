/* 2252085 朱亚琨 信19 */
#include <iostream>
using namespace std;


int main()
{
	char str[82] = { 0 } , *p_head, *p_end;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 81, stdin);
	p_head = str;
	p_end = str;
	while (*p_end++ != '\n')
		;
	p_end--;
	p_end--;
	while (p_head < p_end)
	{
		if (*p_head != *p_end)
		{
			cout << "no" << endl;
			return 0;
		}
		p_head++;
		p_end--;
	}
	cout << "yes" << endl;

	return 0;
}
