/* 2252085 ������ ��19 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	srand((unsigned int)(time(0)));
	int len, upr, lwr, num, othr, site;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> len >> upr >> lwr >> num >> othr;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (len < 12 || len > 16) {
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	if (upr < 2 || upr > len) {
		cout << "��д��ĸ����[" << upr << "]����ȷ" << endl;
		return 0;
	}
	if (lwr < 2 || lwr > len) {
		cout << "Сд��ĸ����[" << lwr << "]����ȷ" << endl;
		return 0;
	}
	if (num < 2 || num > len) {
		cout << "���ָ���[" << num << "]����ȷ" << endl;
		return 0;
	}
	if (othr < 2 || othr > len) {
		cout << "�������Ÿ���[" << othr << "]����ȷ" << endl;
		return 0;
	}
	if (upr + lwr + num + othr > len) {
		cout << "�����ַ�����֮��[" << upr << "+" << lwr << "+" << num << "+" << othr << "]���������볤��[12]" << endl;
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