/* 2252085 ������ ��19 */
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	int getx() const
	{
		return x;
	}
	int gety() const
	{
		return y;
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	void set(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
};

class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		if (!check())
			return -1;
		int p1_x = p1.getx();
		int p1_y = p1.gety();
		int p2_x = p2.getx();
		int p2_y = p2.gety();
		int p3_x = p3.getx();
		int p3_y = p3.gety();
		double S = 0.5 * ((p1_x * p2_y + p2_x * p3_y + p3_x * p1_y) - (p1_y * p2_x + p2_y * p3_x + p3_y * p1_x));
		return fabs(S);     //��������õ��Ǹ�˹�����ʽ
	}
	/* ���캯�� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */
	bool check()
	{
		int p1_x = p1.getx();
		int p1_y = p1.gety();
		int p2_x = p2.getx();
		int p2_y = p2.gety();
		int p3_x = p3.getx();
		int p3_y = p3.gety();
		if ((p1_y - p2_y) * (p1_x - p3_x) == (p1_y - p3_y) * (p1_x - p2_x))
			return 0;
		else
			return 1;
	}
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
		}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}

