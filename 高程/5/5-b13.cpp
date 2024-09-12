/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main() {

    srand((unsigned int)(time(0)));
    int const ROWS = 10;
    int const COLS = 26;
    int const MINES = 50;
    bool board[ROWS][COLS] = {};  // 初始化所有位置都没有地雷
    int counts[ROWS][COLS] = {};  // 初始化计数器数组所有位置都为 0

    int cnt = 0;
    while (cnt < MINES) 
    {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (!board[row][col]) 
        {
            board[row][col] = 1;
            ++cnt;
        }
    }

    int delta[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} }; 
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            if (board[row][col])
                continue;
            int count = 0;
            for (int i = 0; i < 8; ++i) 
            {
                int r = row + delta[i][0];
                int c = col + delta[i][1];
                if ((r >= 0) && (r < ROWS) && (c >= 0) && (c < COLS) && board[r][c]) 
                    ++count;
            }
            counts[row][col] = count;
        }
    }

    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            if (board[row][col]) 
                cout << '*';
            else
                cout << counts[row][col];
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
