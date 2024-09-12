#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SEER_Snake.h"

using namespace std;

void drawGridLines() {
    // 绘制水平网格线
    for (int i = 0; i <= gridRow; ++i) {
        int y = topGridMargin + i * (gridSideLength + gridSpace);
        line(leftGridMargin, y, leftGridMargin + gridCol * (gridSideLength + gridSpace), y + gridSpace - 1);
    }
    // 绘制垂直网格线
    for (int i = 0; i <= gridCol; ++i) {
        int x = leftGridMargin + i * (gridSideLength + gridSpace);
        line(x, topGridMargin, x + gridSpace - 1, topGridMargin + gridRow * (gridSideLength + gridSpace));
    }
}
void displayHighestScore(Mode mode) {
    int highestScore = readHighestScore(mode);
    TCHAR infoText[64];
    _stprintf(infoText, _T("[当前模式历史最高分：%d]"), highestScore);
    settextstyle(&Font);
    settextcolor(WHITE);
    outtextxy(leftGridMargin, topInfoMargin, infoText);
}
void initialize_graphics(Mode mode)
{
    int width = leftGridMargin + rightGridMargin + gridCol * (gridSideLength + gridSpace) + gridSpace;
    int height = topGridMargin + bottomGridMargin + gridRow * (gridSideLength + gridSpace) + gridSpace;
    initgraph(width, height);

    HWND hwnd = GetHWnd();
    SetWindowText(hwnd, _T("SEER Snake"));

    setbkcolor(BLACK);
    setlinecolor(WHITE);
    cleardevice();

    drawGridLines();
    displayHighestScore(mode);
}

void print_status(int row, int col, GridCondition gridCondition, SnakeCategory snakeCategory, Direction direction)
{
    int x = leftGridMargin + col * (gridSideLength + gridSpace) + gridSpace;
    int y = topGridMargin + row * (gridSideLength + gridSpace) + gridSpace;

    IMAGE img;
    LPCTSTR imgPath = nullptr;

    switch (gridCondition) {
        case GridBlank:
            imgPath = _T("data/bg_color.png");
            break;
        case SnakeHead:
            switch (direction) {
                case Up:
                    imgPath = _T("data/SEER_head_up.png"); 
                    break;
                case Down:
                    imgPath = _T("data/SEER_head_down.png"); 
                    break;
                case Left:
                    imgPath = _T("data/SEER_head_left.png"); 
                    break;
                case Right:
                    imgPath = _T("data/SEER_head_right.png"); 
                    break;
                default:
                    exit(-1);
            }
            break;
        case SnakeBody:
            if (snakeCategory == Snake1) {
                imgPath = _T("data/SEER_1_body.png");
            }
            else if (snakeCategory == Snake2) {
                imgPath = _T("data/SEER_2_body.png");
            }
            break;
        case GridWall:
            imgPath = _T("data/grid_wall.png");
            break;
        case energy:
            imgPath = _T("data/energy.png");
            break;
        case pitate:
            imgPath = _T("data/pitate.png");
            break;
        case meteoric:
            imgPath = _T("data/meteoric.png");
            break;
        case S_energy:
            imgPath = _T("data/S_energy.png");
            break;
        case Dene:
            imgPath = _T("data/Dene.png");
            break;
        default:
            exit(-1);
    }

    if (imgPath != nullptr) {
        loadimage(&img, imgPath);
        putimage(x, y, &img);
    }
}