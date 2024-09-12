/* 2252085 信19 朱亚琨 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<cstring>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	char status1[5] = { 0 };
	char status2[5] = { 0 };
	friend class stu_list;
public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */
	int a_no[MAX_STU_NUM] = { 0 };

public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	void merge();
	void stu_sort();
	int check(int No, int N, int round);
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */
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
			strcpy(list_merge[n].status2, "补选");
		}
		if(flag)
			n++;
	}
	for (int i = 0; i < N; i++) {
		if(strcmp(list_merge[i].status1, "Y") == 0 && list_merge[i].status2[0] == 0)
			strcpy(list_merge[i].status2, "退课");
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
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "序号 学号     姓名                            第一轮 第二轮" << endl;
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */
	list.merge();
	list.stu_sort();

	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

