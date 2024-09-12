/* 2252085 朱亚琨 信19 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int order = 1;
int topA = 0, topB = 0, topC = 0;
int A_stack[10];
int B_stack[10];
int C_stack[10];

void print_array()
{
	printf(" A:");
	for (int i = 0; i < 10; i++)
	{
		if (A_stack[i] != ' ')
			printf("%2d", A_stack[i] - '0');
		else
			printf(" %c", A_stack[i]);
	}
	printf(" B:");
	for (int i = 0; i < 10; i++)
	{
		if (B_stack[i] != ' ')
			printf("%2d", B_stack[i] - '0');
		else
			printf(" %c", B_stack[i]);
	}
	printf(" C:");
	for (int i = 0; i < 10; i++)
	{
		if (C_stack[i] != ' ')
			printf("%2d", C_stack[i] - '0');
		else
			printf(" %c", C_stack[i]);
	}
	printf("\n");
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		printf("第%4d 步(%2d): %c-->%c", order++, n, src, dst);
		switch (src)
		{
			case 'A':
				if (dst == 'B')
				{
					B_stack[topB++] = A_stack[--topA];
					A_stack[topA] = ' ';
					print_array();
				}
				else
				{
					C_stack[topC++] = A_stack[--topA];
					A_stack[topA] = ' ';
					print_array();
				}
				break;
			case 'B':
				if (dst == 'A')
				{
					A_stack[topA++] = B_stack[--topB];
					B_stack[topB] = ' ';
					print_array();
				}
				else
				{
					C_stack[topC++] = B_stack[--topB];
					B_stack[topB] = ' ';
					print_array();
				}
				break;
			case 'C':
				if (dst == 'B')
				{
					B_stack[topB++] = C_stack[--topC];
					C_stack[topC] = ' ';
					print_array();
				}
				else
				{
					A_stack[topA++] = C_stack[--topC];
					C_stack[topC] = ' ';
					print_array();
				}
				break;
		}
		return;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		printf("第%4d 步(%2d): %c-->%c", order++, n, src, dst);
		switch (src)
		{
			case 'A':
				if (dst == 'B')
				{
					B_stack[topB++] = A_stack[--topA];
					A_stack[topA] = ' ';
					print_array();
				}
				else
				{
					C_stack[topC++] = A_stack[--topA];
					A_stack[topA] = ' ';
					print_array();
				}
				break;
			case 'B':
				if (dst == 'A')
				{
					A_stack[topA++] = B_stack[--topB];
					B_stack[topB] = ' ';
					print_array();
				}
				else
				{
					C_stack[topC++] = B_stack[--topB];
					B_stack[topB] = ' ';
					print_array();
				}
				break;
			case 'C':
				if (dst == 'B')
				{
					B_stack[topB++] = C_stack[--topC];
					C_stack[topC] = ' ';
					print_array();
				}
				else
				{
					A_stack[topA++] = C_stack[--topC];
					C_stack[topC] = ' ';
					print_array();
				}
				break;
		}
		hanoi(n - 1, tmp, src, dst);
	}
}


int main()
{
	for (int i = 0; i < 10; i++)
	{
		A_stack[i] = ' ';
		B_stack[i] = ' ';
		C_stack[i] = ' ';
	}
	
	int n;
	char src, tmp, dst;
	while (1)
	{
		printf("请输入汉诺塔的层数(1-10)\n");
		scanf("%d", &n);
		while (getchar() != '\n')
			;
		if (n >= 1 && n <= 10)
			break;
	}
	while (1)
	{
		printf("请输入起始柱(A-C)\n");
		scanf("%c", &src);
		while (getchar() != '\n')
			;
		if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
		{
			if (src == 'a' || src == 'b' || src == 'c')
				src -= 32;
			break;
		}
	}
	while (1)
	{
		printf("请输入目标柱(A-C)\n");
		scanf("%c", &dst);
		while (getchar() != '\n')
			;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c'))
		{
			if (dst == 'a' || dst == 'b' || dst == 'c')
				dst -= 32;
			if (src == dst)
				printf("目标柱(%c)不能与起始柱(%c)相同\n", src, dst);
			else
				break;
		}
	}
	switch (src)
	{
		case 'A':
			tmp = (dst == 'B') ? 'C' : 'B';
			break;
		case 'B':
			tmp = (dst == 'A') ? 'C' : 'A';
			break;
		case 'C':
			tmp = (dst == 'A') ? 'B' : 'A';
			break;
	}
	int t = n;
	switch (src)
	{
		case 'A':
			for (int i = 0; i < n; i++)
				A_stack[i] = '0' + t--;
			topA = n;
			break;
		case 'B':
			for (int i = 0; i < n; i++)
				B_stack[i] = '0' + t--;
			topB = n;
			break;
		case 'C':
			for (int i = 0; i < n; i++)
				C_stack[i] = '0' + t--;
			topC = n;
			break;
	}
	printf("初始:               ");
	print_array();
	hanoi(n, src, tmp, dst);

	return 0;
}