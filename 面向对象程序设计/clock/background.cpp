#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "clock.h"

extern STAR star[MAXSTAR];

// �ж����ǵ�λ���Ƿ��ڱ��̷�Χ��
bool in_range(double x, int y) {
    int d = int(sqrt(pow(x - CenterX, 2) + pow(y - CenterY, 2)));
    return d < Radius + 4;
}
// ��ʼ������
void InitStar(int i) {
    star[i].x = 0;
    star[i].y = rand() % Height;
    star[i].step = (rand() % 2000) / 1000.0 + 10;
    star[i].color = 255;
    star[i].color = RGB(star[i].color, star[i].color, star[i].color);
    star[i].pre = 0;
    star[i].now = 0;
}
// �ƶ�����
void MoveStar(int i) {
    star[i].pre = !in_range(star[i].x, star[i].y);
    // ������λ��
    star[i].x += star[i].step;
    if (star[i].x > Width) {
        putpixel((int)(star[i].x - star[i].step), star[i].y, 0);
        InitStar(i);
    }
    star[i].now = !in_range(star[i].x, star[i].y);
    // ��������
    if (star[i].now)
        putpixel((int)star[i].x, star[i].y, star[i].color);
    // ����ԭ��������
    if (star[i].pre)
        putpixel((int)(star[i].x - star[i].step), star[i].y, 0);
}

void draw_randStar() {
    setbkmode(TRANSPARENT);
    setcolor(YELLOW);
    LOGFONT f;
    gettextstyle(&f);						// ��ȡ��ǰ��������
    f.lfHeight = 45;						// ��������߶�Ϊ 30
    f.lfWidth = 24;						    // ����������Ϊ 16
    _tcscpy_s(f.lfFaceName, _T("����"));	// ��������Ϊ�����塱
    f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����
    settextstyle(&f);						// ����������ʽ
    int r, x, y;
    if ((r = rand() % 1000) > 500)
        x = rand() % (Width / 4);
    else
        x = rand() % (Width / 4) + Width * 3 / 4;
    if((r = rand() % 1000) > 500)
        y = rand() % (Height / 4);
    else
        y = rand() % (Height / 4) + Height * 3 / 4;
    outtextxy(x, y, L"��");
}


// ��˹Ȩ�ؼ��㺯��
double GaussianWeight(double x, double sigma) {
    return (1.0 / (2 * PI * sigma * sigma)) * exp(-(x * x) / (2 * sigma * sigma));
}
// ��˹ģ���㷨����
void GaussianBlur(std::vector<std::vector<Pixel>>& image, int radius, double sigma) {
    int size = 2 * radius + 1;
    std::vector<double> kernel(size);
    double sum = 0.0;
    // �����˹��Ȩ��
    for (int i = 0; i < size; i++) {
        kernel[i] = GaussianWeight(i - radius, sigma);
        sum += kernel[i];
    }
    // ��һ��
    for (int i = 0; i < size; i++)
        kernel[i] /= sum;
    int width = int(image[0].size());
    int height = int(image.size());
    std::vector<std::vector<Pixel>> tempImage(height, std::vector<Pixel>(width));
    // ˮƽ����ģ��
    for (int y = 0; y < height; y += 3) {
        for (int x = 0; x < width; x += 3) {
            double r = 0.0, g = 0.0, b = 0.0;
            for (int i = -radius; i <= radius; i++) {
                int index = max(0, min(width - 1, x + i));
                r += image[y][index].r * kernel[i + radius];
                g += image[y][index].g * kernel[i + radius];
                b += image[y][index].b * kernel[i + radius];
            }
            tempImage[y][x] = { static_cast<int>(r), static_cast<int>(g), static_cast<int>(b) };
        }
    }
    // ��ֱ����ģ��
    for (int x = 0; x < width; x += 3) {
        for (int y = 0; y < height; y += 3) {
            double r = 0.0, g = 0.0, b = 0.0;
            for (int i = -radius; i <= radius; i++) {
                int index = max(0, min(height - 1, y + i));
                r += tempImage[index][x].r * kernel[i + radius];
                g += tempImage[index][x].g * kernel[i + radius];
                b += tempImage[index][x].b * kernel[i + radius];
            }
            image[y][x] = { static_cast<int>(r), static_cast<int>(g), static_cast<int>(b) };
        }
    }
}
// ������
void Starchain(std::vector<std::vector<Pixel>>& image, Point p1, Point p2, Point pc) {
    int numSegments = 100; // ���߷ֶ���
    for (int i = 0; i <= numSegments; i++) {
        float t = i / float(numSegments);
        int x = int((1 - t) * (1 - t) * p1.x + 2 * (1 - t) * t * pc.x + t * t * p2.x);
        int y = int((1 - t) * (1 - t) * p1.y + 2 * (1 - t) * t * pc.y + t * t * p2.y);
        // �������ص�
        image[y][x] = { 255, 215, 0 };
    }
}
