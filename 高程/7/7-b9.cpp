/* 2252085 ��19 ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<cstring>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	char status1[5] = { 0 };
	char status2[5] = { 0 };
	friend class stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */
	int a_no[MAX_STU_NUM] = { 0 };

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void merge();
	void stu_sort();
	int check(int No, int N, int round);
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::merge()
{
	int n = 0;
	for (int i = 0; i < list_num_1; i++) {
		if (check(list_round_1[i].no, 0, 1) == -1) {
			list_merge[n].stu_no = list_round_1[i].no;
			a_no[n] = list_round_1[i].no;
			strcpy(list_merge[n].stu_name, list_round_1[i].name);
			strcpy(list_merge[n].status1, "Y");
			n++;
		}
	}
	int N = n;
	for (int i = 0; i < list_num_2; i++) {
		bool flag = 0;
		if (check(list_round_2[i].no, N, 1) == -1) {
			list_merge[n].stu_no = list_round_2[i].no;
			a_no[n] = list_round_2[i].no;
			strcpy(list_merge[n].stu_name, list_round_2[i].name);
			strcpy(list_merge[n].status2, "Y");
			flag = 1;
		}
		int ret;
		if ((ret = check(list_round_2[i].no, N, 2)) != -1) {
			strcpy(list_merge[ret].status2, "Y");
		}
		else {
			strcpy(list_merge[n].status1, "/");
			strcpy(list_merge[n].status2, "��ѡ");
		}
		if(flag)
			n++;
	}
	for (int i = 0; i < N; i++) {
		if(strcmp(list_merge[i].status1, "Y") == 0 && list_merge[i].status2[0] == 0)
			strcpy(list_merge[i].status2, "�˿�");
	}
	list_merge_num = n;
}
void stu_list::stu_sort()
{
	for (int i = 0; i < list_merge_num; i++) {
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				int _no = list_merge[j].stu_no;
				char _name[MAX_NAME_LEN] = { 0 };
				char _status1[5] = { 0 };
				char _status2[5] = { 0 };
				strcpy(_name, list_merge[j].stu_name);
				strcpy(_status1, list_merge[j].status1);
				strcpy(_status2, list_merge[j].status2);
				list_merge[j].stu_no = list_merge[j + 1].stu_no;
				strcpy(list_merge[j].stu_name, list_merge[j + 1].stu_name);
				strcpy(list_merge[j].status1, list_merge[j + 1].status1);
				strcpy(list_merge[j].status2, list_merge[j + 1].status2);
				list_merge[j + 1].stu_no = _no;
				strcpy(list_merge[j + 1].stu_name, _name);
				strcpy(list_merge[j + 1].status1, _status1);
				strcpy(list_merge[j + 1].status2, _status2);
			}
		}
	}
}
int stu_list::check(int No, int N, int round)
{
	int max = 0;
	if (round == 2)
		max = N;
	else
		max = MAX_STU_NUM;
	for (int i = 0; i < max; i++) {
		if (a_no[i] == 0)
			return -1;
		if (a_no[i] == No)
			return i;
	}
	return -1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	cout << setiosflags(ios::left);
	for (int i = 0; i < list_merge_num; i++) {
		cout << setw(5) << i + 1 << setw(9) << list_merge[i].stu_no << setw(32) 
			<< list_merge[i].stu_name << setw(7) << list_merge[i].status1 << list_merge[i].status2 << endl;
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.merge();
	list.stu_sort();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

