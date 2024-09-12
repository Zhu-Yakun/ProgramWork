/* 2252085 朱亚琨 信19 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

void menu()
{
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止，加分项)\n");
	printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，加分项)\n");
	printf("0.退出\n");
	printf("[请选择0-6] ");
}

void my_move(const HANDLE hout, int x, int y, int flag)
{
	switch(flag)
	{
		case 1:
		case 2:
			while(1)
			{
				char ch = _getch();
				switch(ch)
				{
					case 'i':
					case 'I':
						if(y > 1)
							gotoxy(hout, x, --y);
						else if(flag == 2 && y == 1)
						{
							y = 17;
							gotoxy(hout, x, y);
						}
						break;
					case 'k': 
					case 'K':
						if(y < 17)
							gotoxy(hout, x, ++y);
						else if(flag == 2 && y == 17)
						{
							y = 1;
							gotoxy(hout, x, y);
						}
						break;
					case 'j':
					case 'J':
						if(x > 1)
							gotoxy(hout, --x, y);
						else if(flag == 2 && x == 1)
						{
							x = 69;
							gotoxy(hout, x, y);
						}
						break;
					case 'l':
					case 'L':
						if(x < 69)
							gotoxy(hout, ++x, y);
						else if(flag == 2 && x == 69)
						{
							x = 1;
							gotoxy(hout, x, y);
						}
						break;
					case 32:
						showch(hout, x, y, ' ');
						gotoxy(hout, x, y);
						break;
					case 'q':
					case 'Q':
						gotoxy(hout, 0, 23);
						printf("游戏结束，按回车键退出.");
						while(1)
						{
							if(_getch() == 13)
							{
								cls(hout);
								return ;
							}
						}
				}
			}
		case 3:
		case 4:
			while(1)
			{
				int sign1 = _getch();
				char ch;
				if(sign1 == 224)
					ch = _getch();
				if(sign1 == 224 || sign1 == 32 || sign1 == 'q' || sign1 == 'Q')
				{
					if(sign1 == 224)
					{
						switch(ch)
						{
							case 72:
								if(y > 1)
									gotoxy(hout, x, --y);
								else if(flag == 4 && y == 1)
								{
									y = 17;
									gotoxy(hout, x, y);
								}
								break;
							case 80:
								if(y < 17)
									gotoxy(hout, x, ++y);
								else if(flag == 4 && y == 17)
								{
									y = 1;
									gotoxy(hout, x, y);
								}
								break;
							case 75:
								if(x > 1)
									gotoxy(hout, --x, y);
								else if(flag == 4 && x == 1)
								{
									x = 69;
									gotoxy(hout, x, y);
								}
								break;
							case 77:
								if(x < 69)
									gotoxy(hout, ++x, y);
								else if(flag == 4 && x == 69)
								{
									x = 1;
									gotoxy(hout, x, y);
								}
								break;
						}
					}
					else
					{
						switch(sign1)
						{
							case 32:
								showch(hout, x, y, ' ');
								gotoxy(hout, x, y);
								break;
							case 'q':
							case 'Q':
								gotoxy(hout, 0, 23);
								printf("游戏结束，按回车键退出.");
								while(1)
								{
									if(_getch() == 13)
									{
										cls(hout);
										return ;
									}
								}
						}
					}
				}
			}
		case 5:
		case 6:
			while(1)
			{
				int sign1 = _getch();
				char ch;
				if(sign1 == 224)
				{
					ch = _getch();
					continue;
				}
				switch(sign1)
				{
					case 'i':
					case 'I':
						if(y > 1)
							gotoxy(hout, x, --y);
						else if(flag == 6 && y == 1)
						{
							y = 17;
							gotoxy(hout, x, y);
						}
						break;
					case 'k': 
					case 'K':
						if(y < 17)
							gotoxy(hout, x, ++y);
						else if(flag == 6 && y == 17)
						{
							y = 1;
							gotoxy(hout, x, y);
						}
						break;
					case 'j':
					case 'J':
						if(x > 1)
							gotoxy(hout, --x, y);
						else if(flag == 6 && x == 1)
						{
							x = 69;
							gotoxy(hout, x, y);
						}
						break;
					case 'l':
					case 'L':
						if(x < 69)
							gotoxy(hout, ++x, y);
						else if(flag == 6 && x == 69)
						{
							x = 1;
							gotoxy(hout, x, y);
						}
						break;
					case 32:
						showch(hout, x, y, ' ');
						gotoxy(hout, x, y);
						break;
					case 'q':
					case 'Q':
						gotoxy(hout, 0, 23);
						printf("游戏结束，按回车键退出.");
						while(1)
						{
							if(_getch() == 13)
							{
								cls(hout);
								return ;
							}
						}
				}
			}
	}
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	while(1)
	{
		cls(hout);
		menu();
		switch(getche()-48)
		{
			case 1:
				cls(hout);
				init_border(hout);
				gotoxy(hout, 35, 9);
				my_move(hout, 35, 9, 1);
				break;
			case 2:
				cls(hout);
				init_border(hout);
				gotoxy(hout, 35, 9);
				my_move(hout, 35, 9, 2);
				break;
			case 3:
				cls(hout);
				init_border(hout);
				gotoxy(hout, 35, 9);
				my_move(hout, 35, 9, 3);
				break;
			case 4:
				cls(hout);
				init_border(hout);
				gotoxy(hout, 35, 9);
				my_move(hout, 35, 9, 4);
				break;
			case 5:
				cls(hout);
				init_border(hout);
				gotoxy(hout, 35, 9);
				my_move(hout, 35, 9, 5);
				break;
			case 6:
				cls(hout);
				init_border(hout);
				gotoxy(hout, 35, 9);
				my_move(hout, 35, 9, 6);
				break;
			case 0:
				return 0;
				break;
		}
	}


	//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
	getchar();

	return 0;
}

/* 思考题：1、左箭头键的ASCII码是2个字节的扩展码，以char类型1个字节地进行读取时，分别代表224、75，而75正好是K的ASCII码
              只需要加一句if语句，如果第一次读取的是224，那么就再读取一次
		   2、可能会出现重复的坐标位置，导致新的字母覆盖掉以前的字母              */ 
