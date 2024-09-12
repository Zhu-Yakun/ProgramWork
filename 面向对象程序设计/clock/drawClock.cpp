#include <graphics.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "clock.h"

// 求点到线段的距离
double distance_to_line(Point p, Point p1, Point p2) {
    double x0 = p.x, y0 = p.y;
    double x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
    double dx = x2 - x1, dy = y2 - y1;
    // 点到线段距离公式化简之后的式子
    return fabs(dy * (x1 - x0) - dx * (y1 - y0)) / sqrt(dx * dx + dy * dy);
}
// Alpha Blending
COLORREF mix_color(COLORREF bg, COLORREF color, double alpha) {
    COLORREF result;
    result = RGB(GetRValue(bg) * (1 - alpha) + GetRValue(color) * alpha, GetGValue(bg) * (1 - alpha) + GetGValue(color) * alpha, GetBValue(bg) * (1 - alpha) + GetBValue(color) * alpha);
    return result;
}
// SDF  Signed Distance Filed
// 画线
void SDF_line(Point p1, Point p2, COLORREF color, double thickness) {
    int minX = int(min(p1.x, p2.x) - thickness);
    int maxX = int(max(p1.x, p2.x) + thickness);
    int minY = int(min(p1.y, p2.y) - thickness);
    int maxY = int(max(p1.y, p2.y) + thickness);

    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            Point p = { x, y };
            double distance = distance_to_line(p, p1, p2);
            if (distance <= thickness) {
                double alpha = 1 - distance / thickness;
                COLORREF bg = getpixel(x, y);
                COLORREF result = mix_color(bg, color, alpha);
                putpixel(x, y, result);
            }
        }
    }
}
// 画表盘
void SDF_circle(Point p, COLORREF color, int r)
{
    for (int i = p.x - r - 10; i < p.x + r + 10; i++) {
        for (int j = p.y - r - 10; j < p.y + r + 10; j++) {
            Point p1 = { i,j };
            double d = sqrt((pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2))) - r;
            double alpha = 1 - d / 4;
            if (d < 0)
                continue;
            if (alpha >= 0 && alpha <= 1) {
                COLORREF bg = getpixel(i, j);
                COLORREF result = mix_color(bg, color, alpha);
                putpixel(i, j, result);
            }
        }
    }
    setfillcolor(color);
    setlinecolor(color);
    fillcircle(p.x, p.y, r);
}
// 画刻度
void draw_scale() {
    setbkmode(TRANSPARENT);
    setcolor(YELLOW);
    LOGFONT f;
    gettextstyle(&f);						// 获取当前字体设置
    f.lfHeight = 30;						// 设置字体高度为 30
    f.lfWidth = 16;						    // 设置字体宽度为 16
    _tcscpy_s(f.lfFaceName, _T("宋体"));	// 设置字体为“宋体”
    f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿
    settextstyle(&f);						// 设置字体样式
    outtextxy(CenterX + Radius - 38, CenterY - 16, L"★");
    outtextxy(CenterX - Radius + 8, CenterY - 16, L"★");
    outtextxy(CenterX - 16, CenterY + Radius - 38, L"★");
    outtextxy(CenterX - 16, CenterY - Radius + 8, L"★");
    setcolor(YELLOW);
    outtextxy(CenterX - 16, CenterY - 17, L"★");
    setcolor(WHITE);
    outtextxy(CenterX + (Radius - 45) / 2, CenterY - Radius + 35, L"★");
    outtextxy(CenterX + (Radius - 45) / 2, CenterY + Radius - 70, L"★");
    outtextxy(CenterX - (Radius + 18) / 2, CenterY - Radius + 35, L"★");
    outtextxy(CenterX - (Radius + 18) / 2, CenterY + Radius - 70, L"★");
    outtextxy(CenterX + Radius - 66, CenterY - Radius + 120, L"★");
    outtextxy(CenterX + Radius - 66, CenterY + Radius - 148, L"★");
    outtextxy(CenterX - Radius + 35, CenterY - Radius + 120, L"★");
    outtextxy(CenterX - Radius + 35, CenterY + Radius - 148, L"★");
}
// 画指针
void draw_pointer(Point origin) {
    SYSTEMTIME ti;
    Point p_h, p_m, p_s;
    GetLocalTime(&ti);
    // 时、分、秒针对应转到角度
    double secondAngle = 0, minuteAngle = 0, hourAngle = 0;
    secondAngle = (ti.wSecond / 60.0) * (2 * PI);
    minuteAngle = (ti.wMinute / 60.0) * (2 * PI);
    hourAngle = ((ti.wHour % 12) / 12.0) * (2 * PI) + (ti.wMinute / 60.0) * (2 * PI / 12.0);
    p_s.x = int(origin.x + Length_s * sin(secondAngle));
    p_s.y = int(origin.y - Length_s * cos(secondAngle));
    p_m.x = int(origin.x + Length_m * sin(minuteAngle));
    p_m.y = int(origin.y - Length_m * cos(minuteAngle));
    p_h.x = int(origin.x + Length_h * sin(hourAngle));
    p_h.y = int(origin.y - Length_h * cos(hourAngle));
    SDF_line(origin, p_s, RGB(142, 68, 173), 2);
    SDF_line(origin, p_m, RGB(247, 220, 111), 4);
    SDF_line(origin, p_h, RGB(186, 74, 0), 5);
}