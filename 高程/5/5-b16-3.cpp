/* 2252085 ������ ��19 */
#include <iostream>
#include<cstring>
using namespace std;

void input(string id[], string name[], int score[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> id[i] >> name[i] >> score[i];
	}
}
void order(string id[], string name[], int score[])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10 - i - 1; j++)
			if (id[j + 1] < id[j])
			{
				string temp1, temp2;
				int temp3 = score[j];
				temp1 = id[j];
				temp2 = name[j];
				id[j] = id[j + 1];
				name[j] = name[j + 1];
				score[j] = score[j + 1];
				id[j + 1] = temp1;
				name[j + 1] = temp2;
				score[j + 1] = temp3;
			}
}
void output(string id[], string name[], int score[])
{
	cout << endl << "ȫ��ѧ��(ѧ������):" << endl;
	for (int i = 0; i < 10; i++)
		cout << name[i] << " " << id[i] << " " << score[i] << endl;
}


int main()
{
	string id[10], name[10];
	int score[10] = { 0 };
	input(id, name, score);
	order(id, name, score);
	output(id, name, score);

	return 0;
}