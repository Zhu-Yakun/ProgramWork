/* 信19 2252085 朱亚琨 */
#pragma once

#define ROW 10
#define COL 10

//    节拍   一拍 = 400 毫秒

#define beat 400
#define half_beat 200

//    音节   q前缀为低音，1后缀为高音
#define Mqdo 262 
#define Mqre 294
#define Mqmi 330
#define Mqfa 349
#define Mqso 392
#define Mqla 440
#define Mqsi 494
#define Mdo 523
#define Mre 578
#define Mmi 659
#define Mfa 698
#define Mso 784
#define Mla 880
#define Msi 988
#define Mdo1 1046
#define Mre1 1175
#define Mmi1 1318
#define Mfa1 1480
#define Mso1 1568
#define Mla1 1760


void output(char ch[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int b);
void initial_map(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col);

void sur_search(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, char* r, char* c);
bool sub_find(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int r, int c, int read);
int merge(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, bool dr, bool b);
void land(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, bool dr, int b);
void to_old(char sub_map[2 + ROW][4 + COL * 3], int row, int col);
void hor_move(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int c, bool dr, bool b);

void sound_effect(int s);
void to_be_continued(int R);
int cal_score(int* score, int cnt, char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, int R);

int check(char map[2 + ROW][4 + COL * 3], int row, int col, int c);
void draw_frame(int i, int R, int col, bool b);
int pgraph(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int row, int col, bool b, char select, int* score, bool prime);
void draw_block(char map[2 + ROW][4 + COL * 3], int r, int c, bool b, int hl);
int in_range(char map[2 + ROW][4 + COL * 3], int X, int Y, int R, int C, bool b, int click, int* p_r, int* p_col);
void keyboard(char map[2 + ROW][4 + COL * 3], int* r, int* c, int keycode1, int keycode2, int row, int col);
int wipe_block(char map[2 + ROW][4 + COL * 3], char sub_map[2 + ROW][4 + COL * 3], int* r, int* c, int R, int row, int col, bool b, int* kc1, int* kc2, int _X, int _Y,int* score);
void move_block(char map[2 + ROW][4 + COL * 3], int s_r, int s_c, int e_r, int e_c, bool b, bool h);