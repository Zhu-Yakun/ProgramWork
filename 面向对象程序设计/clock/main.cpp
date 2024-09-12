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

// ��ʼ��ʱ�ӽṹ��
void initClock(Clock& clock, int x, int y, int r) {
    clock.centerX = x;
    clock.centerY = y;
    clock.radius = r;
}

int main()
{
    srand((unsigned)time(NULL));	// �������
    initgraph(Width, Height);

    std::vector<std::vector<Pixel>> image(Height, std::vector<Pixel>(Width, { 0, 0, 0 }));

    IMAGE img;//����һ��(����)����
    //���·��: ./��ʾ��ǰ�ļ����£�../��ʾ��ǰ�ļ��е���һ��Ŀ¼
    loadimage(&img, L"./bg.jpg", getwidth(), getheight(), 0);   

    Clock myClock;
    initClock(myClock, CenterX, CenterY, Radius); // ��ʼ��ʱ�Ӳ���
    // ��ʼ����������
    for (int i = 0; i < MAXSTAR; i++) {
        InitStar(i);
        star[i].x = rand() % 720;
    }
    // ����bgm  �����ǳ�������
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
        // ������֮ǰӦ�ø�˹ģ��
        GaussianBlur(image, 5, 1.0); // ʹ�ð뾶Ϊ5����׼��Ϊ1.0�ĸ�˹ģ��
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
        // ��ͼ����Ƶ�ͼ�δ���
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