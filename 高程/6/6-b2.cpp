/* 2252085 ������ ��19 */
#include <iostream>
using namespace std;


int main()
{
	char str[82] = { 0 } , *p_head, *p_end;
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
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
