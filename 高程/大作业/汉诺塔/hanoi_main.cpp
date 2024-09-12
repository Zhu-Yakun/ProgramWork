/* 信19 2252085 朱亚琨 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(){	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
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
