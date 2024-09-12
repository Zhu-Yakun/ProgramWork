#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "matrix.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void edit_pic(Mat& image_i, vector<int> matrixB, int opt, int ke)
{
    vector<int> matrixA, result;
    for (int i = 0; i < 256 + 2; i++)
        for (int j = 0; j < 256 + 2; j++) {
            if (i == 0 || i == 256 + 1 || j == 0 || j == 256 + 1)
                matrixA.push_back(0);
            else
                matrixA.push_back(static_cast<int>(image_i.at<uchar>(i - 1, j - 1)));
        }
    for (int p = 0; p < 256 + 2 - 3 + 1; p++) {
        for (int q = 0; q < 256 + 2 - 3 + 1; q++) {
            int sum = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; ++y) {
                    sum += matrixA[(p + x) * (256 + 2) + q + y] * matrixB[x * 3 + y];
                }
            }
            if (ke != 0)
                sum = int(sum * 1.0 / ke);
            if (opt == 1 || opt == 2 || opt == 4)
                sum += 128;
            if (sum > 255)
                sum = 255;
            if (sum < 0)
                sum = 0;
            result.push_back(sum);
        }
    }
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 256; j++)
            image_i.at<uchar>(i, j) = static_cast<uchar>(result[i * 256 + j]);
}

void demo()
{
    /* 对vs+opencv正确配置后方可使用，此处只给出一段读取并显示图像的参考代码，其余功能流程自行设计和查阅文献 */
    Mat image = imread("demolena.jpg", CV_8UC1); // 图像的灰度值存放在格式为Mat的变量image中
    Mat img[6];
    for (int i = 0; i < 6; i++) img[i] = image.clone();
    vector<int> matrixB[6];
    int ke[6] = { 0 };
    matrixB[0] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    matrixB[1] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
    matrixB[2] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    matrixB[3] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
    matrixB[4] = { -1, -1, 0, -1, 0, 1, 0, 1, 1 };
    matrixB[5] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 9; j++)
            ke[i] += matrixB[i][j];
    imshow("Image-original", image);
    moveWindow("Image-original", 100, 200);
    for (int i = 0; i < 6; i++) {
        edit_pic(img[i], matrixB[i], i, ke[i]);
        char str[13] = { 0 };
        sprintf(str, "Image-image%d", i + 1);
        imshow(str, img[i]);
        moveWindow(str, 300 * (i % 3 + 1) + 100, 300 * (i / 3) + 200);
    }
    waitKey(0);
    // 提示：Mat格式可与数组相互转换
    return;
}

int cal_thresh(Mat img)
{
    int thresh = 0, graynum[256] = { 0 }, r = img.rows, c = img.cols;
    for (int i = 0; i < r; ++i) {
        const uchar* ptr = img.ptr<uchar>(i);
        for (int j = 0; j < c; ++j)        //直方图统计
            graynum[ptr[j]]++;
    }
    double P[256] = { 0 }, PK[256] = { 0 }, MK[256] = { 0 };
    double srcpixnum = r * c, sumtmpPK = 0, sumtmpMK = 0;
    for (int i = 0; i < 256; ++i) {
        P[i] = graynum[i] / srcpixnum;   //每个灰度级出现的概率
        PK[i] = sumtmpPK + P[i];         //概率累计和 
        sumtmpPK = PK[i];
        MK[i] = sumtmpMK + i * P[i];       //灰度级的累加均值                                                                                                                                                                                                                                                                                                                                                                                                        
        sumtmpMK = MK[i];
    }
    //计算类间方差
    double Var = 0;
    for (int k = 0; k < 256; ++k) {
        if ((MK[256 - 1] * PK[k] - MK[k]) * (MK[256 - 1] * PK[k] - MK[k]) / (PK[k] * (1 - PK[k])) > Var) {
            Var = (MK[256 - 1] * PK[k] - MK[k]) * (MK[256 - 1] * PK[k] - MK[k]) / (PK[k] * (1 - PK[k]));
            thresh = k;
        }
    }
    return thresh;
}

void Otsu() {
    Mat image = imread("demolena.jpg", CV_8UC1), outimg;
    int thresh = cal_thresh(image);
    int r = image.rows, c = image.cols;
    //阈值处理
    image.copyTo(outimg);
    for (int i = 0; i < r; ++i) {
        uchar* ptr = outimg.ptr<uchar>(i);
        for (int j = 0; j < c; ++j) {
            if (ptr[j] > thresh)
                ptr[j] = 255;
            else
                ptr[j] = 0;
        }
    }
    imshow("Image-original", image);
    moveWindow("Image-original", 100, 200);
    imshow("Image-OTSU", outimg);
    moveWindow("Image-OTSU", 500, 200);
    waitKey(0);
}

void segmentation(Mat img, int x, int y, const char str[])
{
    Mat rice, riceBW, out;
    int thresh = cal_thresh(img);
    //将图像转换成二值图像，用于统计连通域
    cvtColor(img, rice, COLOR_BGR2GRAY);
    threshold(rice, riceBW, thresh, 255, THRESH_BINARY);
    int number = connectedComponents(riceBW, out, 4, CV_16U);
    vector<Vec3b> colors;
    for (int i = 0; i < number; i++) {
        Vec3b vec3 = Vec3b(255, 255, 255);
        colors.push_back(vec3);
    }
    Mat result = Mat::zeros(rice.size(), img.type());
    int w = result.cols, h = result.rows;
    // 遍历连通区域并着色，保持目标区域不变，背景区域设置为黑色
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int label = out.at<ushort>(i, j);
            if (label == 0)
                result.at<Vec3b>(i, j) = Vec3b(0, 0, 0); // 背景设置为黑色
            else
                result.at<Vec3b>(i, j) = colors[label - 1];
        }
    }
    namedWindow(str, WINDOW_NORMAL);
    resizeWindow(str, 256, 256);
    moveWindow(str, x, y);
    imshow(str, result);
}

void Seg(Mat img, int x, int y, char str[])
{
    Mat binary;
    // 应用OTSU算法获得阈值
    int thresh = cal_thresh(img);
    threshold(img, binary, thresh, 255, THRESH_BINARY);

    Mat result = Mat::zeros(img.size(), CV_8UC3);
    // 将二值化图像中的前景区域复制到结果图像中
    img.copyTo(result, binary);
    // 将剩余的背景区域填充为黑色
    result.setTo(cv::Scalar(0, 0, 0), ~binary);

    // 显示结果图像
    _strupr(str);
    namedWindow(str, WINDOW_NORMAL);
    resizeWindow(str, 256, 256);
    moveWindow(str, x, y);
    imshow(str, result);
}

void extend()
{
    Mat img[4];
    char str[4][20] = { "snowball.jpg" , "polyhedrosis.jpg" , "ship.jpg" , "brain.jpg" };
    for (int i = 0; i < 4; i++) {
        img[i] = imread(str[i]);
        segmentation(img[i], 300 * (i + 1), 200, str[i]);
        Seg(img[i], 300 * (i + 1), 500, str[i]);
    }
    waitKey(0);
    destroyAllWindows();
}