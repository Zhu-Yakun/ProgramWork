/* 2252085 朱亚琨 信19 */
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
	cout << "                             KFC 2023春季菜单" << endl;
	cout << "=========================================================================" << endl;
	while (p1->num) {
		cout << setiosflags(ios::left);
		cout << " " << setw(2) << p1->num << setw(27) << p1->name << setw(4) << p1->price << "  |  ";
		p1++;
		cout << " " << setw(2) << p1->num << setw(27) << p1->name << setw(4) << p1->price << endl;
		p1++;
	}
	p1 = list;
	cout << endl << "【优惠信息】：" << endl;
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
	cout << endl << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl << "请点单:";
}

int main()
{
	const struct KFC list[] = {
	{'A', "香辣鸡腿堡",			19.5},
	{'B', "劲脆鸡腿堡",			19.5},
	{'C', "新奥尔良烤鸡腿堡",		20.0},
	{'D', "老北京鸡肉卷",			18.5},
	{'E', "黄金SPA鸡排堡(藤椒风味)",	18.0},
	{'F', "经典美式风味嫩牛堡(单层)",	18.0},
	{'G', "吮指原味鸡(1块)",		12.5},
	{'H', "黄金脆皮鸡",			13.5},
	{'I', "新奥尔良烤翅(2块)",		13.5},
	{'J', "劲爆鸡米花",			12.0},
	{'K', "香辣鸡翅(2块)",			12.5},
	{'L', "热辣香骨鸡(3块)",		12.5},
	{'M', "汁汁厚做培根三层和牛堡",	55.0},
	{'N', "薯条(小)",				9.0},
	{'O', "薯条(中)",				12.5},
	{'P', "薯条(大)",				14.5},
	{'Q', "芙蓉蔬荟汤",			9.0},
	{'R', "原味花筒冰激凌",			6.0},
	{'S', "醇香土豆泥",			7.5},
	{'T', "黄金鸡块",				12.5},
	{'U', "葡式蛋挞",				8.0},
	{'V', "百事可乐(小)",			8.5},
	{'W', "百事可乐(中)",			10.0},
	{'X', "百事可乐(大)",			12.0},
	{'Y', "九珍果汁",				13.0},
	{'Z', "雪顶咖啡",				14.5},
	{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
		//{"AOW", "OK三件套(香辣鸡腿堡)",		31}, //如果有需要，放开此项，注释掉下一行的“COW”优惠，观察优惠菜单是否发生了变化
			{"COW", "OK三件套(新奥尔良烤鸡腿堡)",	33.5}, //如果有需要，放开此项，注释掉上一行的“AOW”优惠，观察优惠菜单是否发生了变化
			{"HHHHHKKKSUWWW", "超爆全家桶(脆皮鸡)",	101},
			{"APUY", "人气明星配四件套(8折)",		44},
			{"GG","吮指原味鸡(2块)",			21},
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
				cout << "输入错误，按任意键继续." << endl;
				ch = getchar();
				flag = 0;
				break;
			}
			else 
				merge(list, special, cnt_dish, order, 0);
		}
		if (!flag)
			continue;
		cout << "您的点餐=";
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
		cout << "共计：" << expense << "元" << endl;
		cout << "点单完成，请按任意键继续.";
		char ch = getchar();
	}
	

	return 0;
}