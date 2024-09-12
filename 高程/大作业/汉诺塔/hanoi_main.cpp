/* ��19 2252085 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(){	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		char src = 'A', tmp, dst;
		int n, select = menu();
		if (!select)
			return 0;
		if (select == 5) {
			draw_post(select , src);
			cct_gotoxy(0, 20);
			to_be_continued();
			continue;
		}
		input_order(select, &n, &src, &tmp, &dst);
		if (select == 6 || select == 7) {
			draw_post(select , src);
			if (select == 7) {
				if (n % 2 == 0)
					move_plate(select, src, tmp);
				else
					move_plate(select, src, dst);
			}
			to_be_continued();
			continue;
		}
		if (select == 4 || select == 8)
			cct_cls();
		if (select == 4 || select == 8 || select == 3 || select == 9) {
			print_plate(10, select * 4-9*(select==9), n, src, tmp, dst, select);
			print_array(n, src, tmp, dst, select);
		}
		if (select == 8 || select == 9)
			draw_post(select, src);
		if (select != 9)
			hanoi(n, src, tmp, dst, select);
		else
			hanoi_game(n, src, tmp, dst, select);
		if (select == 8 || select == 4) {
			cct_gotoxy(0, 35);
			char ch = getchar();
		}
		to_be_continued();
	}
	return 0;
}
