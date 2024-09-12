/* ��19 2252085 ������ */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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