#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

const int MAX = 202 * 202;

void wait_for_enter();
void menu();

void input_matrix(int matrix[MAX], int row, int col);
void print_matrix(int matrix[MAX], int row, int col);

void matriplus(int matrix1[MAX], int matrix2[MAX], int result[MAX]);
void nummulti(int matrix[MAX], int result[MAX]);
void matritrans(int matrix[MAX], int result[MAX]);
void matrimulti(int matrix1[MAX], int matrix2[MAX], int result[MAX]);
void hadamulti(int matrix1[MAX], int matrix2[MAX], int result[MAX]);
void conv(int matrixA[MAX], int matrixB[MAX], int result[MAX]);

void edit_pic(Mat& image_i, vector<int> matrixB, int opt, int ke);
void demo();

int cal_thresh(Mat img);
void Otsu();
void segmentation(Mat img, int x, int y, const char str[]);
void Seg(Mat img, int x, int y, char str[]);
void extend();