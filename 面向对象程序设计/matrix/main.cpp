#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "matrix.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    while (true) // 注意该循环退出的条件
    {
        // 定义相关变量
        int matrix1[MAX] = { 0 }, matrix2[MAX] = { 0 }, result[MAX] = { 0 };
        char choice;
        while (1) {
            system("cls"); // 清屏函数
            menu(); // 调用菜单显示函数，自行补充完成
            choice = _getche();
            if (choice < '0' || choice > '9') {
                cout << "输入错误，请重新输入";
                wait_for_enter();
                continue;
            }
            else
                break;
        }
        // 按要求输入菜单选择项choice
        if (choice == '0') // 选择退出
        {
            cout << "\n 确定退出吗?" << endl;
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                break;
            else
                continue;
        }
        switch (choice)
        {
            // 下述矩阵操作函数自行设计并完成（包括函数参数及返回类型等），若选择加分项，请自行补充
            case '1':
                matriplus(matrix1, matrix2, result);
                break;
            case '2':
                nummulti(matrix1, result);
                break;
            case '3':
                matritrans(matrix1, result);
                break;
            case '4':
                matrimulti(matrix1, matrix2, result);
                break;
            case '5':
                hadamulti(matrix1, matrix2, result);
                break;
            case '6':
                conv(matrix1, matrix2, result);
                break;
            case '7':
                demo();
                break;
            case '8':
                Otsu();
                break;
            case '9':
                extend();
                break;
            default:
                cout << "\n 输入错误，请从新输入" << endl;
                wait_for_enter();
        }
    }
    return 0;
}