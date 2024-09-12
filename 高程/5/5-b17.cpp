/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	srand((unsigned int)(time(0)));
	int len, upr, lwr, num, othr, site;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> upr >> lwr >> num >> othr;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len > 16) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (upr < 2 || upr > len) {
		cout << "大写字母个数[" << upr << "]不正确" << endl;
		return 0;
	}
	if (lwr < 2 || lwr > len) {
		cout << "小写字母个数[" << lwr << "]不正确" << endl;
		return 0;
	}
	if (num < 2 || num > len) {
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if (othr < 2 || othr > len) {
		cout << "其他符号个数[" << othr << "]不正确" << endl;
		return 0;
	}
	if (upr + lwr + num + othr > len) {
		cout << "所有字符类型之和[" << upr << "+" << lwr << "+" << num << "+" << othr << "]大于总密码长度[12]" << endl;
		return 0;
	}
	cout << len << " " << upr << " " << lwr << " " << num << " " << othr << endl;
	while (len - upr - lwr - num - othr > 0) {
		upr += rand() % (len - upr - lwr - num - othr) + 1;
		if(len - upr - lwr - num - othr > 0)
			lwr += rand() % (len - upr - lwr - num - othr) + 1;
		if (len - upr - lwr - num - othr > 0)
			num += rand() % (len - upr - lwr - num - othr) + 1;
		if (len - upr - lwr - num - othr > 0)
			othr += rand() % (len - upr - lwr - num - othr) + 1;
	}
	for (int k = 0; k < 10; k++) {
		char password[17] = { 0 };
		bool occupy[16] = { 0 };
		for (int i = 0; i < upr; i++)
			while (1)
				if (!occupy[(site = rand() % len)]) {
					occupy[site] = 1;
					password[site] = rand() % 26 + 'A';
					break;
				}
		for (int i = 0; i < lwr; i++)
			while (1) 
				if (!occupy[(site = rand() % len)]) {
					occupy[site] = 1;
					password[site] = rand() % 26 + 'a';
					break;
				}
		for (int i = 0; i < num; i++)
			while (1) 
				if (!occupy[(site = rand() % len)]) {
					occupy[site] = 1;
					password[site] = rand() % 10 + '0';
					break;
				}
		for (int i = 0; i < othr; i++)
			while (1) 
				if (!occupy[(site = rand() % len)]) {
					occupy[site] = 1;
					password[site] = other[rand() % 15];
					break;
				}
		cout << password << endl;
	}

	return 0;
}