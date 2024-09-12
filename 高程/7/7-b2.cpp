/* 2252085 ������ ��19 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

struct KFC {
	char num;
	char name[25];
	float price;
};
struct SPECIAL {
	char set[27];
	char name[30];
	float price;
};


void merge(const KFC list[], const SPECIAL special[], int cnt_dish[], char order, int k) {
	const KFC* p1 = list;
	const SPECIAL* p2 = special;
	if (k == 0) {
		if (order != '\n')
			cnt_dish[order - 'A']++;
	}
	else {
		for (int i = 0; i < k - 1; i++)
			p2++;
		int i = 0;
		while (p2->set[i]) {
			cnt_dish[p2->set[i] - 'A']++;
			i++;
		}
	}
}

float cal_price(const KFC list[], const SPECIAL special[], int cnt_dish[])
{
	const KFC* p1 = list;
	const SPECIAL* p2 = special;
	int k = 1;
	float expense = 0;
	while (p2->price) {
		int cnt_dish_set[26] = { 0 }, flag = 1;
		merge(list, special, cnt_dish_set, '\n', k);
		for (int i = 0; i < 26; i++)
			if (cnt_dish[i] < cnt_dish_set[i]) {
				flag = 0;
				break;
			}
		if (flag) {
			for (int i = 0; i < 26; i++)
				cnt_dish[i] -= cnt_dish_set[i];
			expense += p2->price;
		}
		for (int i = 0; i < 26; i++)
			if (cnt_dish[i] < cnt_dish_set[i]) {
				p2++;
				k++;
				memset(cnt_dish_set, 0, sizeof(cnt_dish_set));
				break;
			}
	}
	for (int i = 0; i < 26; i++) {
		p1 = list;
		if (cnt_dish[i] > 0)
			for (int j = 0; j < i; j++)
				p1++;
			expense += p1->price * cnt_dish[i];
		}
	return expense;
}

void menu(const KFC list[], const SPECIAL special[]) {
	const KFC* p1 = list;
	const SPECIAL* p2 = special;
	int cnt_dish[26] = { 0 }, k = 1, prime = 1;
	cout << "=========================================================================" << endl;
	cout << "                             KFC 2023�����˵�" << endl;
	cout << "=========================================================================" << endl;
	while (p1->num) {
		cout << setiosflags(ios::left);
		cout << " " << setw(2) << p1->num << setw(27) << p1->name << setw(4) << p1->price << "  |  ";
		p1++;
		cout << " " << setw(2) << p1->num << setw(27) << p1->name << setw(4) << p1->price << endl;
		p1++;
	}
	p1 = list;
	cout << endl << "���Ż���Ϣ����" << endl;
	while (p2->price) {
		cout << p2->name << "=";
		merge(list, special, cnt_dish, '\n', k);
		for (int i = 0; i < 26; i++) {
			if (cnt_dish[i]) {
				for (int j = 0; j < i; j++)
					p1++;
				if (!prime)
					cout << "+";
				if (cnt_dish[i] != 1) {
					cout << p1->name << "*" << cnt_dish[i];
					prime = 0;
				}
				else {
					cout << p1->name;
					prime = 0;
				}
			}
			p1 = list;
		}
		cout << "=" << p2->price << endl;
		p1 = list;
		p2++;
		k++;
		prime = 1;
		memset(cnt_dish, 0, sizeof(cnt_dish));
	}
	cout << endl << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl << "��㵥:";
}

int main()
{
	const struct KFC list[] = {
	{'A', "�������ȱ�",			19.5},
	{'B', "���༦�ȱ�",			19.5},
	{'C', "�°¶��������ȱ�",		20.0},
	{'D', "�ϱ��������",			18.5},
	{'E', "�ƽ�SPA���ű�(�ٽ���ζ)",	18.0},
	{'F', "������ʽ��ζ��ţ��(����)",	18.0},
	{'G', "˱ָԭζ��(1��)",		12.5},
	{'H', "�ƽ��Ƥ��",			13.5},
	{'I', "�°¶�������(2��)",		13.5},
	{'J', "�������׻�",			12.0},
	{'K', "��������(2��)",			12.5},
	{'L', "������Ǽ�(3��)",		12.5},
	{'M', "֭֭������������ţ��",	55.0},
	{'N', "����(С)",				9.0},
	{'O', "����(��)",				12.5},
	{'P', "����(��)",				14.5},
	{'Q', "ܽ��������",			9.0},
	{'R', "ԭζ��Ͳ������",			6.0},
	{'S', "����������",			7.5},
	{'T', "�ƽ𼦿�",				12.5},
	{'U', "��ʽ��̢",				8.0},
	{'V', "���¿���(С)",			8.5},
	{'W', "���¿���(��)",			10.0},
	{'X', "���¿���(��)",			12.0},
	{'Y', "�����֭",				13.0},
	{'Z', "ѩ������",				14.5},
	{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
		//{"AOW", "OK������(�������ȱ�)",		31}, //�������Ҫ���ſ����ע�͵���һ�еġ�COW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
			{"COW", "OK������(�°¶��������ȱ�)",	33.5}, //�������Ҫ���ſ����ע�͵���һ�еġ�AOW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
			{"HHHHHKKKSUWWW", "����ȫ��Ͱ(��Ƥ��)",	101},
			{"APUY", "�����������ļ���(8��)",		44},
			{"GG","˱ָԭζ��(2��)",			21},
			{NULL, NULL, 0}
	};
	system("mode con cols=130 lines=45");
	while (1) {
		system("cls");
		char order;
		int cnt_dish[26] = { 0 }, prime = 1, i = 0, flag = 1;
		const KFC* p1 = list;
		const SPECIAL* p2 = special;
		menu(list, special);
		while ((order = getchar()) != '\n') {
			char ch;
			if (order < 'A' || order > 'Z') {
				while ((ch = getchar()) != '\n')
					;
				cout << "������󣬰����������." << endl;
				ch = getchar();
				flag = 0;
				break;
			}
			else 
				merge(list, special, cnt_dish, order, 0);
		}
		if (!flag)
			continue;
		cout << "���ĵ��=";
		for (int i = 0; i < 26; i++) {
			p1 = list;
			if (cnt_dish[i]) {
				for (int j = 0; j < i; j++)
					p1++;
				if (!prime)
					cout << "+";
				if (cnt_dish[i] != 1) {
					cout << p1->name << "*" << cnt_dish[i];
					prime = 0;
				}
				else {
					cout << p1->name;
					prime = 0;
				}
			}
		}
		cout << endl;
		float expense = cal_price(list, special, cnt_dish);
		cout << "���ƣ�" << expense << "Ԫ" << endl;
		cout << "�㵥��ɣ��밴���������.";
		char ch = getchar();
	}
	

	return 0;
}