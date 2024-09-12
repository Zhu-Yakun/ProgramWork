#pragma once
#define PI 3.1415926     //������
#define MAXSTAR 200	     // ��������
const int Width = 720;  //���ڿ��
const int Height = 720;  //���ڸ߶�
const int CenterX = Width / 2;   //ʱ������X����
const int CenterY = Height / 2;  //ʱ������Y����
const int Radius = min(Width, Height) / 3;  //���̰뾶
const int Length_h = min(Width, Height) / 9;  //���볤��
const int Length_m = min(Width, Height) / 6;
const int Length_s = min(Width, Height) / 4;

// ���ؽṹ��
struct Pixel {
    int r, g, b;
};
// �������ǽṹ��
struct STAR {
    double x;
    int y;
    double step;
    int color;
    bool pre;
    bool now;
};
// ����ʱ�ӽṹ��
struct Clock {
    int centerX;
    int centerY;
    int radius;
};
// ����һ����Ľṹ��
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