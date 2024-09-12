#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "clock.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

STAR star[MAXSTAR];

// 初始化时钟结构体
void initClock(Clock& clock, int x, int y, int r) {
    clock.centerX = x;
    clock.centerY = y;
    clock.radius = r;
}

int main()
{
    srand((unsigned)time(NULL));	// 随机种子
    initgraph(Width, Height);

    std::vector<std::vector<Pixel>> image(Height, std::vector<Pixel>(Width, { 0, 0, 0 }));

    IMAGE img;//定义一个(变量)对象
    //相对路径: ./表示当前文件夹下，../表示答盎前文件夹的上一级目录
    loadimage(&img, L"./bg.jpg", getwidth(), getheight(), 0);   

    Clock myClock;
    initClock(myClock, CenterX, CenterY, Radius); // 初始化时钟参数
    // 初始化所有星星
    for (int i = 0; i < MAXSTAR; i++) {
        InitStar(i);
        star[i].x = rand() % 720;
    }
    // 播放bgm  满天星辰不及你
    mciSendString(_T("open bgm.mp3"), NULL, 0, NULL);
    mciSendString(_T("play bgm.mp3"), NULL, 0, NULL);

    BeginBatchDraw();    
    int cnt = 1;
    while (1){
        cnt++;
        if (cnt == 31)
            cnt = 1;
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'b' || ch == 'B') {
                putimage(0, 0, &img);
                FlushBatchDraw();
                Sleep(2000);
            }
            else if (ch == 'q' || ch == 'Q')
                break;
            else
                ;
        }
        cleardevice();
        // 画曲线之前应用高斯模糊
        GaussianBlur(image, 5, 1.0); // 使用半径为5，标准差为1.0的高斯模糊
        Starchain(image, {myClock.centerX - myClock.radius - 100, myClock.centerY},
            { myClock.centerX + myClock.radius + 100, myClock.centerY },
            { myClock.centerX, myClock.centerY + myClock.radius + 300 });
        Starchain(image, { myClock.centerX - myClock.radius - 100, myClock.centerY },
            { myClock.centerX + myClock.radius + 100, myClock.centerY },
            { myClock.centerX, myClock.centerY - myClock.radius - 300 });
        Starchain(image, { myClock.centerX, myClock.centerY - myClock.radius - 100 },
            { myClock.centerX, myClock.centerY + myClock.radius + 100 },
            { myClock.centerX + myClock.radius + 300, myClock.centerY });
        Starchain(image, { myClock.centerX, myClock.centerY - myClock.radius - 100 },
            { myClock.centerX, myClock.centerY + myClock.radius + 100 },
            { myClock.centerX - myClock.radius - 300, myClock.centerY });
        // 将图像绘制到图形窗口
        for (int y = 0; y < Height; y++)
            for (int x = 0; x < Width; x++)
                putpixel(x, y, RGB(image[y][x].r, image[y][x].g, image[y][x].b));
        draw_randStar();
        SDF_circle({ myClock.centerX, myClock.centerY }, RGB(214, 219, 223), myClock.radius);
        SDF_circle({ myClock.centerX, myClock.centerY }, RGB(40, 55, 71), myClock.radius - 5);
        if (cnt >= 5)
            SDF_circle({ myClock.centerX, myClock.centerY }, RGB(93, 173, 226), myClock.radius - 100);
        if(cnt >= 10 && cnt <= 25)
            SDF_circle({ myClock.centerX, myClock.centerY }, RGB(40, 116, 166), myClock.radius - 150);
        if(cnt >= 15 && cnt <= 20)
            SDF_circle({ myClock.centerX, myClock.centerY }, RGB(118, 215, 196), myClock.radius - 200);
        
        draw_pointer({ myClock.centerX, myClock.centerY });
        draw_scale();
        for (int i = 0; i < MAXSTAR; i++)
            MoveStar(i);
        FlushBatchDraw();
    }
    EndBatchDraw();
    closegraph();
    return 0;
}