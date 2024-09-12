/* 2252085 ������ ��19 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

void menu()
{
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ���ӷ���)\n");
	printf("6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ��ӷ���)\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-6] ");
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
						printf("��Ϸ���������س����˳�.");
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
								printf("��Ϸ���������س����˳�.");
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
						printf("��Ϸ���������س����˳�.");
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
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


	//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
	getchar();

	return 0;
}

/* ˼���⣺1�����ͷ����ASCII����2���ֽڵ���չ�룬��char����1���ֽڵؽ��ж�ȡʱ���ֱ����224��75����75������K��ASCII��
              ֻ��Ҫ��һ��if��䣬�����һ�ζ�ȡ����224����ô���ٶ�ȡһ��
		   2�����ܻ�����ظ�������λ�ã������µ���ĸ���ǵ���ǰ����ĸ              */ 
