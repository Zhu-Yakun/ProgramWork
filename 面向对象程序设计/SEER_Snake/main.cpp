#include<iostream>
#include <conio.h>
#include <ctime>
#include "SEER_Snake.h"
using namespace std;

bool menuFlag = false;

int main()
{
    srand((unsigned int)(time(0)));
    startPage();
    while (1) {
        Mode mode = menu();
        if (mode == Quit) {
            closegraph();
            return 0;
        }
        else if (mode == ResetHighestScore)
            continue;
        else
            SEER_Snake(mode);
    }
}


static bool isInRange(int x, int y, int top, int bottom, int left = 560, int right = 975)
{
    return (x >= left && x <= right && y >= top && y <= bottom);
}

void startPage()
{
    initgraph(menuWidth, menuHeight);
    HWND hwnd = GetHWnd();
    SetWindowText(hwnd, _T("SEER Snake"));
    IMAGE img;
    loadimage(&img, _T("data/start_page.png"));
    putimage(0, 0, &img);
    Sleep(startTime);
}

Mode menu()
{
    if (menuFlag) {
        initgraph(menuWidth, menuHeight);
        HWND hwnd = GetHWnd();
        SetWindowText(hwnd, _T("SEER Snake"));
    }
    menuFlag = true;
    IMAGE img;
    loadimage(&img, _T("data/menu_page.jpg"));
    putimage(0, 0, &img);

    MOUSEMSG mouse{ 0 };
    while (true) {
        if (MouseHit())
            mouse = GetMouseMsg();
        switch (mouse.uMsg) {
            case WM_LBUTTONDOWN:
                if (isInRange(mouse.x, mouse.y, 108, 146)) {
                    loadimage(&img, _T("data/basic_mode_page.jpg"));
                    putimage(0, 0, &img);
                    while (_getch() != ' ')
                        continue;
                    return BasicMode;
                }
                else if (isInRange(mouse.x, mouse.y, 164, 203)) {
                    loadimage(&img, _T("data/advanced_mode_page.jpg"));
                    putimage(0, 0, &img);
                    while (_getch() != ' ')
                        continue;
                    return AdvancedMode;
                }
                else if (isInRange(mouse.x, mouse.y, 218, 259)) {
                    loadimage(&img, _T("data/expert_mode_page.jpg"));
                    putimage(0, 0, &img);
                    while (_getch() != ' ')
                        continue;
                    return ExpertMode;
                }
                else if (isInRange(mouse.x, mouse.y, 274, 315)) {
                    loadimage(&img, _T("data/human_vs_human_mode_page.jpg"));
                    putimage(0, 0, &img);
                    while (_getch() != ' ')
                        continue;
                    return HumanVsHumanMode;
                }
                else if (isInRange(mouse.x, mouse.y, 328, 371)) {
                    loadimage(&img, _T("data/human_vs_AI_mode_page.jpg"));
                    putimage(0, 0, &img);
                    while (_getch() != ' ')
                        continue;
                    return HumanVsAIMode;
                }
                else if (isInRange(mouse.x, mouse.y, 385, 426)) {
                    reset();
                    loadimage(&img, _T("data/reset_page.jpg"));
                    putimage(0, 0, &img);
                    menuFlag = false;
                    while (_getch() != ' ')
                        continue;
                    return ResetHighestScore;
                }
                else if (isInRange(mouse.x, mouse.y, 438, 484, 42, 118))
                    return Quit;
                break;
            default:
                break;
        }
    }
}

void endPage()
{
    IMAGE img;
    loadimage(&img, _T("data/end_page.jpg"));
    int x = (getwidth() - img.getwidth()) / 2, y = (getheight() - img.getheight()) / 2;
    putimage(x, y, &img);
    while (_getch() != ' ')
        continue;
}