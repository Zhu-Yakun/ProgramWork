#pragma once
#define PI 3.1415926     //常数π
#define MAXSTAR 200	     // 星星总数
const int Width = 720;  //窗口宽度
const int Height = 720;  //窗口高度
const int CenterX = Width / 2;   //时钟中心X坐标
const int CenterY = Height / 2;  //时钟中心Y坐标
const int Radius = min(Width, Height) / 3;  //表盘半径
const int Length_h = min(Width, Height) / 9;  //表针长度
const int Length_m = min(Width, Height) / 6;
const int Length_s = min(Width, Height) / 4;

// 像素结构体
struct Pixel {
    int r, g, b;
};
// 定义星星结构体
struct STAR {
    double x;
    int y;
    double step;
    int color;
    bool pre;
    bool now;
};
// 定义时钟结构体
struct Clock {
    int centerX;
    int centerY;
    int radius;
};
// 任意一个点的结构体
struct Point {
    int x;
    int y;
};

void initClock(Clock& clock, int x, int y, int r);

bool in_range(double x, int y);
void InitStar(int i);
void MoveStar(int i);

void draw_randStar();

double distance_to_line(Point p, Point p1, Point p2);
COLORREF mix_color(COLORREF bg, COLORREF color, double alpha);

void SDF_line(Point p1, Point p2, COLORREF color, double thickness);
void SDF_circle(Point p, COLORREF color, int r);
void draw_scale();
void draw_pointer(Point origin);

double GaussianWeight(double x, double sigma);
void GaussianBlur(std::vector<std::vector<Pixel>>& image, int radius, double sigma);
void Starchain(std::vector<std::vector<Pixel>>& image, Point p1, Point p2, Point pc);