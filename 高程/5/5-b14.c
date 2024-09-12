/* 2252085 朱亚琨 信19 */
/* 2253102  鲁浩宇  2252086  孙靖贻  2251925  薛子睿  2251541  原恒  2250695  奥泉瑞 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROWS 10
#define COLS 26

int main()
{
    int board[ROWS][COLS];
    char ch;
    int mines = 0, r = 0, c = 0;
    while ((ch = getchar()) != EOF)
    {
        if (c == 26)
        {
            r++;
            c = 0;
        }
        if (ch == '*')
        {
            mines++;
            board[r][c++] = ch;
        }
        else if (ch >= '0' && ch <= '8')
            board[r][c++] = ch;
    }

    if (mines != 50)
    {
        printf("错误1\n");
        return 0;
    }
    int delta[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == '*')
                continue;
            int count = 0;
            for (int i = 0; i < 8; i++)
            {
                int r = row + delta[i][0];
                int c = col + delta[i][1];
                if ((r >= 0) && (r < ROWS) && (c >= 0) && (c < COLS) && (board[r][c] == '*'))
                    count++;
            }
            if (board[row][col] != count + '0')
            {
                printf("错误2\n");
                return 0;
            }
        }
    }
    printf("正确\n");

    return 0;
}