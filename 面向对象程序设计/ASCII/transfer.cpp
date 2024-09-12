#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "FastPrinter.h"
#include "PicReader.h"
#include "array.h"

using namespace std;

void ImageToAscii()
{
    char path[128] = "classic_picture/";
    cout << "请输入要打开的图像文件: ";
    cin >> &path[16];

    PicReader imread;
    BYTE* data = nullptr;
    UINT _x, _y;
    imread.readPic(path);
    imread.getData(data, _x, _y);
    int x = _x, y = _y;

    Array originalImage(x * y * 4);

    for (int i = 0; i < x * y * 4; i++)
        originalImage.get_content()[i] = data[i];

    delete[] data;
    originalImage.reshape(y, x, 4);

    int reductionFactor, total;
    reductionFactor = (max(x, y) - 1) / consoleWindowsSize + 1;
    cout << endl << "降采样因子: " << reductionFactor << endl;

    x /= reductionFactor;
    y /= reductionFactor;
    total = x * y;

    Array reductionImage(y, x, 4);
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++) {
            int start_x = j * reductionFactor, start_y = i * reductionFactor, end_x = start_x + reductionFactor, end_y = start_y + reductionFactor;
            int sum[4] = { 0 };
            for (int m = start_y; m < end_y; m++)
                for (int n = start_x; n < end_x; n++)
                    for (int k = 0; k < 4; k++)
                        sum[k] += originalImage[m][n][k];
            for (int k = 0; k < 4; k++)
                reductionImage.get_content()[(i * x + j) * 4 + k] = int(sum[k] / double(reductionFactor * reductionFactor) + 0.5);
        }

    BYTE* grayscale = new(nothrow) BYTE[x * y];
    if (grayscale == NULL)
        exit(-1);
    int* p = reductionImage.get_content();
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++) {
            int index = i * x + j;
            grayscale[index] = ((306 * p[index * 4] + 601 * p[index * 4 + 1] + 116 * p[index * 4 + 2]) >> 10);
        }

    char* dataBuffer = new(nothrow) char[total * 2];
    if (dataBuffer == NULL)
        exit(-1);
    BYTE* frontColorBuffer = new(nothrow) BYTE[total * 6];
    if (frontColorBuffer == NULL)
        exit(-1);
    BYTE* backColorBuffer = new(nothrow) BYTE[total * 6];
    if (backColorBuffer == NULL)
        exit(-1);

    for (int i = 0; i < total * 2; i++)
        dataBuffer[i] = asciiStrength[int(grayscale[i / 2] / 16.0 + 0.5)];
    delete[] grayscale;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            int index = (i * x + j) * 2;
            for (int k = 0; k < 2; k++) {
                for (int d = 0; d < 3; d++) {
                    frontColorBuffer[index * 3 + d] = 0;
                    backColorBuffer[index * 3 + d] = 255;
                }
                index++;
            }
        }
    }
    cout << endl << "图像处理成功！" << endl;
    cout << "按回车键显示图像";
    while (_getch() != '\r')
        continue;

    FastPrinter printer(x * 2, y, 6);
    printer.cleanSrceen();
    printer.setData(dataBuffer, frontColorBuffer, backColorBuffer);
    printer.draw(true);

    cout << "按回车退出";
    while (_getch() != '\r')
        continue;

    delete[] dataBuffer;
    delete[] frontColorBuffer;
    delete[] backColorBuffer;
}