#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "matrix.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void wait_for_enter()
{
    cout << endl
        << "按回车键继续";
    while (_getch() != '\r')
        ;
    cout << endl
        << endl;
}

void menu()
{
    for (int i = 0; i < 57; i++) cout << "*";
    cout << endl;
    cout << " *      1 矩阵加法      2 矩阵数乘      3 矩阵转置      *" << endl;
    cout << " *      4 矩阵乘法      5 Hadamard乘积  6 矩阵卷积      *" << endl;
    cout << " *      7 卷积应用      8 OTSU 算法     9 segmentation  *" << endl;
    cout << " *      0 退出系统                                      *" << endl;
    for (int i = 0; i < 57; i++) cout << "*";
    cout << endl << "选择菜单项<0~9>:";
}

void input_matrix(int matrix[MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            int a;
            cin >> a;
            if (cin.fail()) {
                cout << "输入有误，请重新输入本行\n";
                j = -1;
                continue;
            }
            else
                matrix[i * col + j] = a;
        }
}

void print_matrix(int matrix[MAX], int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << setw(5) << matrix[i * col + j];
        cout << endl;
    }
}

void matriplus(int matrix1[MAX], int matrix2[MAX], int result[MAX])
{
    int r, c;
    while (1) {
        cout << "\n你选择了 1 矩阵加法\n请输入矩阵1和矩阵2的行数和列数（1到200），用一个空格隔开（如5 5）\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "输入的行数列数不符合要求，请重新输入\n";
        else
            break;
    }
    cout << "请输入矩阵1（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix1, r, c);
    cout << "请输入矩阵2（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix2, r, c);
    for (int i = 0; i < r * c; i++)
        result[i] = matrix1[i] + matrix2[i];
    cout << "\n你输入的矩阵1\n";
    print_matrix(matrix1, r, c);
    cout << "你输入的矩阵2\n";
    print_matrix(matrix2, r, c);
    cout << "\n矩阵1和矩阵2相加后的结果\n";
    print_matrix(result, r, c);
    wait_for_enter();
}

void nummulti(int matrix[MAX], int result[MAX])
{
    int r, c, num;
    while (1) {
        cout << "\n你选择了 2 矩阵数乘\n请输入矩阵的行数和列数（1到200），用一个空格隔开（如5 5）\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "输入的行数列数不符合要求，请重新输入\n";
        else
            break;
    }
    cout << "请输入矩阵（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix, r, c);
    while (1) {
        cout << "请输入要乘的数\n";
        cin >> num;
        if (cin.fail())
            cout << "输入错误，请重新输入\n";
        else
            break;
    }
    for (int i = 0; i < r * c; i++)
        result[i] = matrix[i] * num;
    cout << "\n你输入的矩阵\n";
    print_matrix(matrix, r, c);
    cout << "你输入的数\n" << num << endl;
    cout << "\n矩阵和数相乘后的结果\n";
    print_matrix(result, r, c);
    wait_for_enter();
}

void matritrans(int matrix[MAX], int result[MAX])
{
    int r, c;
    cout << "\n你选择了 3 矩阵转置\n请输入矩阵的行数和列数（1到200），用一个空格隔开（如5 5）\n";
    while (1) {
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "输入的行数列数不符合要求，请重新输入\n";
        else
            break;
    }
    cout << "请输入矩阵（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix, r, c);
    for (int j = 0; j < c; j++)
        for (int i = 0; i < r; i++)
            result[j * r + i] = matrix[i * c + j];
    cout << "\n你输入的矩阵\n";
    print_matrix(matrix, r, c);
    cout << "\n矩阵转置后的结果\n";
    print_matrix(result, c, r);
    wait_for_enter();
}

void matrimulti(int matrix1[MAX], int matrix2[MAX], int result[MAX])
{
    int r1, c1, r2, c2;
    while (1) {
        cout << "\n你选择了 4 矩阵乘法\n请输入矩阵1的行数和列数（1到200），用一个空格隔开（如5 5）\n";
        cin >> r1 >> c1;
        if (r1 < 1 || r1 > 200 || c1 < 1 || c1 > 200 || cin.fail())
            cout << "输入的行数列数不符合要求，请重新输入\n";
        else {
            cout << "请输入矩阵2的行数和列数（1到200），用一个空格隔开（如5 5）\n";
            cin >> r2 >> c2;
            if (r2 < 1 || r2 > 200 || c2 < 1 || c2 > 200 || cin.fail())
                cout << "输入的行数列数不符合要求，请重新输入\n";
            else {
                if (c1 != r2)
                    cout << "你输入的矩阵1的列数与矩阵2的行数不相等，无法进行矩阵乘法，请重新输入\n";
                else
                    break;
            }
        }
    }
    cout << "请输入矩阵1（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix1, r1, c1);
    cout << "请输入矩阵2（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix2, r2, c2);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i * c2 + j] += matrix1[i * c1 + k] * matrix2[k * c2 + j];  // r2与c1相等
    cout << "\n你输入的矩阵1\n";
    print_matrix(matrix1, r1, c1);
    cout << "你输入的矩阵2\n";
    print_matrix(matrix2, r2, c2);
    cout << "\n矩阵1和矩阵2相乘后的结果\n";
    print_matrix(result, r1, c2);
    wait_for_enter();
}

void hadamulti(int matrix1[MAX], int matrix2[MAX], int result[MAX])
{
    int r, c;
    while (1) {
        cout << "\n你选择了 5 Hadamard乘积\n请输入矩阵1和矩阵2的行数和列数（1到200），用一个空格隔开（如5 5）\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "输入的行数列数不符合要求，请重新输入\n";
        else
            break;
    }
    cout << "请输入矩阵1（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix1, r, c);
    cout << "请输入矩阵2（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    input_matrix(matrix2, r, c);
    for (int i = 0; i < r * c; i++)
        result[i] = matrix1[i] * matrix2[i];
    cout << "\n你输入的矩阵1\n";
    print_matrix(matrix1, r, c);
    cout << "你输入的矩阵2\n";
    print_matrix(matrix2, r, c);
    cout << "\n矩阵1和矩阵2Hadamard乘积后的结果\n";
    print_matrix(result, r, c);
    wait_for_enter();
}

void conv(int matrixA[MAX], int matrixB[MAX], int result[MAX])
{
    int r, c;
    while (1) {
        cout << "\n你选择了 6 矩阵卷积\n请输入矩阵A的行数和列数（1到200），用一个空格隔开（如5 5）\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "输入的行数列数不符合要求，请重新输入\n";
        else
            break;
    }
    cout << "请输入矩阵A（同一行每个数之间用一个空格分隔，每一行单独占一行）\n";
    for (int i = 0; i < r + 2; i++)
        for (int j = 0; j < c + 2; j++) {
            if (i == 0 || i == r + 1 || j == 0 || j == c + 1)
                matrixA[i * (c + 2) + j] = 0;
            else {
                int a;
                cin >> a;
                if (cin.fail()) {
                    cout << "输入有误，请重新输入本行\n";
                    j = -1;
                    continue;
                }
                else
                    matrixA[i * (c + 2) + j] = a;
            }
        }
    cout << "请输入矩阵B（同一行每个数之间用一个空格分隔，每一行单独占一行）\n矩阵B是3阶方阵\n";
    input_matrix(matrixB, 3, 3);
    for (int i = 0; i < r + 2 - 3 + 1; i++) {
        for (int j = 0; j < c + 2 - 3 + 1; j++) {
            int sum = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; ++y) {
                    sum += matrixA[(i + x) * (c + 2) + j + y] * matrixB[x * 3 + y];
                }
            }
            result[i * (c + 2 - 3 + 1) + j] = sum;
        }
    }
    cout << "\n你输入的矩阵A（加了外围0）\n";
    print_matrix(matrixA, r + 2, c + 2);
    cout << "你输入的矩阵B\n";
    print_matrix(matrixB, 3, 3);
    cout << "\n矩阵A和矩阵B卷积后的结果\n";
    print_matrix(result, r, c);
    wait_for_enter();
}