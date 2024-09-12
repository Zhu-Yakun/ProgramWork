/* 信19 2252085 朱亚琨 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

int menu();
void sleep(int mov);
void to_be_continued();

void draw_post(int select, char src);
void move_plate(int select, char src, char dst);

int game_order(char* p_src, char* p_dst);
void input_order(int select, int* p_n, char* p_src, char* p_tmp, char* p_dst);

void print_array(int n, char src, char tmp, char dst, int select);
void print_plate(int x, int y, int n, char src, char tmp, char dst, int select);

void hanoi(int n, char src, char tmp, char dst, int select);
void hanoi_game(int n, char src, char tmp, char dst, int select);