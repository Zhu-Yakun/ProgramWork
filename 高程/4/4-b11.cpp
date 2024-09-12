/* 2252085 ��19 ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
        ����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
                 2��������ų���
                 3������const�ͱ���

        ������ ��1������ȫ�ֱ���
                 2����print_tower֮������������в������徲̬�ֲ����� 
   ----------------------------------------------------------------------------------- */

void print_ret(char end_ch)  //�����ӡ
{
	if(end_ch > 'A')
	{
		cout << end_ch;
		print_ret(end_ch - 1);
	}
	else if(end_ch == 'A')
		cout << end_ch;
	else
		return ;
	return ;
}
void print_seq(char ch1, char ch2) //˳�����ch1��ch2-1���ַ�
{
	if(ch1 <= ch2)
	{
		if(ch1 == ch2)
		return ;
		cout << ch1;
		print_seq(char(ch1+1), ch2);
	}
	else
		return ;
}
void print_space(int order, int prime)  //��ӡ�ո� 
{
	if(order)
	{
		if(prime > 0)
		{
			cout << " ";
			print_space(1, prime-1);
			return ;
		}	
	}
	else
	{
		if(prime > 0)
		{
			print_space(1, prime-1);
			cout << " ";
			return ;
		}	
	}
	return ;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ��ĸ��
  ���������
  �� �� ֵ��
  ˵    �����βΰ�������
            ��ʾ����һ������order��ָ������/���� 
***************************************************************************/
void print_tower(char end_ch, int order, int prime)
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */

	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
	if(order == 1)
	{
		if(end_ch > 'A')
			print_tower(end_ch - 1, order, prime + 1);
		print_space(1, prime);
		print_seq('A', end_ch);
		print_ret(end_ch);
		cout << endl;
		if(end_ch == 'A')
			return ;
	}
	else
	{
		if(order == 2)
			cout << " ";
		print_space(0, prime);
		print_seq('A', end_ch);
		print_ret(end_ch);
		cout << endl;
		if(end_ch > 'A')
			print_tower(end_ch - 1, order, prime + 1);
		if(end_ch == 'A')
			return ;
	}

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw(2*(end_ch-'A'+1)-1) << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw(2*(end_ch-'A'+1)-1) << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 1, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw(2*(end_ch-'A'+1)-1) << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw(2*(end_ch-'A'+1)-1) << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 0, 0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << setfill('=') << setw(2*(end_ch-'A'+1)-1) << '=' << endl;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << setfill('=') << setw(2*(end_ch-'A'+1)-1) << '=' << endl;/* ����ĸ����������= */
	print_tower(end_ch, 1, 0);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch-1, 2, 0);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
