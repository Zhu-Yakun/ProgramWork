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
        << "���س�������";
    while (_getch() != '\r')
        ;
    cout << endl
        << endl;
}

void menu()
{
    for (int i = 0; i < 57; i++) cout << "*";
    cout << endl;
    cout << " *      1 ����ӷ�      2 ��������      3 ����ת��      *" << endl;
    cout << " *      4 ����˷�      5 Hadamard�˻�  6 ������      *" << endl;
    cout << " *      7 ���Ӧ��      8 OTSU �㷨     9 segmentation  *" << endl;
    cout << " *      0 �˳�ϵͳ                                      *" << endl;
    for (int i = 0; i < 57; i++) cout << "*";
    cout << endl << "ѡ��˵���<0~9>:";
}

void input_matrix(int matrix[MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            int a;
            cin >> a;
            if (cin.fail()) {
                cout << "�����������������뱾��\n";
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
        cout << "\n��ѡ���� 1 ����ӷ�\n���������1�;���2��������������1��200������һ���ո��������5 5��\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "�������������������Ҫ������������\n";
        else
            break;
    }
    cout << "���������1��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix1, r, c);
    cout << "���������2��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix2, r, c);
    for (int i = 0; i < r * c; i++)
        result[i] = matrix1[i] + matrix2[i];
    cout << "\n������ľ���1\n";
    print_matrix(matrix1, r, c);
    cout << "������ľ���2\n";
    print_matrix(matrix2, r, c);
    cout << "\n����1�;���2��Ӻ�Ľ��\n";
    print_matrix(result, r, c);
    wait_for_enter();
}

void nummulti(int matrix[MAX], int result[MAX])
{
    int r, c, num;
    while (1) {
        cout << "\n��ѡ���� 2 ��������\n����������������������1��200������һ���ո��������5 5��\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "�������������������Ҫ������������\n";
        else
            break;
    }
    cout << "���������ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix, r, c);
    while (1) {
        cout << "������Ҫ�˵���\n";
        cin >> num;
        if (cin.fail())
            cout << "�����������������\n";
        else
            break;
    }
    for (int i = 0; i < r * c; i++)
        result[i] = matrix[i] * num;
    cout << "\n������ľ���\n";
    print_matrix(matrix, r, c);
    cout << "���������\n" << num << endl;
    cout << "\n���������˺�Ľ��\n";
    print_matrix(result, r, c);
    wait_for_enter();
}

void matritrans(int matrix[MAX], int result[MAX])
{
    int r, c;
    cout << "\n��ѡ���� 3 ����ת��\n����������������������1��200������һ���ո��������5 5��\n";
    while (1) {
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "�������������������Ҫ������������\n";
        else
            break;
    }
    cout << "���������ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix, r, c);
    for (int j = 0; j < c; j++)
        for (int i = 0; i < r; i++)
            result[j * r + i] = matrix[i * c + j];
    cout << "\n������ľ���\n";
    print_matrix(matrix, r, c);
    cout << "\n����ת�ú�Ľ��\n";
    print_matrix(result, c, r);
    wait_for_enter();
}

void matrimulti(int matrix1[MAX], int matrix2[MAX], int result[MAX])
{
    int r1, c1, r2, c2;
    while (1) {
        cout << "\n��ѡ���� 4 ����˷�\n���������1��������������1��200������һ���ո��������5 5��\n";
        cin >> r1 >> c1;
        if (r1 < 1 || r1 > 200 || c1 < 1 || c1 > 200 || cin.fail())
            cout << "�������������������Ҫ������������\n";
        else {
            cout << "���������2��������������1��200������һ���ո��������5 5��\n";
            cin >> r2 >> c2;
            if (r2 < 1 || r2 > 200 || c2 < 1 || c2 > 200 || cin.fail())
                cout << "�������������������Ҫ������������\n";
            else {
                if (c1 != r2)
                    cout << "������ľ���1�����������2����������ȣ��޷����о���˷�������������\n";
                else
                    break;
            }
        }
    }
    cout << "���������1��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix1, r1, c1);
    cout << "���������2��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix2, r2, c2);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i * c2 + j] += matrix1[i * c1 + k] * matrix2[k * c2 + j];  // r2��c1���
    cout << "\n������ľ���1\n";
    print_matrix(matrix1, r1, c1);
    cout << "������ľ���2\n";
    print_matrix(matrix2, r2, c2);
    cout << "\n����1�;���2��˺�Ľ��\n";
    print_matrix(result, r1, c2);
    wait_for_enter();
}

void hadamulti(int matrix1[MAX], int matrix2[MAX], int result[MAX])
{
    int r, c;
    while (1) {
        cout << "\n��ѡ���� 5 Hadamard�˻�\n���������1�;���2��������������1��200������һ���ո��������5 5��\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "�������������������Ҫ������������\n";
        else
            break;
    }
    cout << "���������1��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix1, r, c);
    cout << "���������2��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    input_matrix(matrix2, r, c);
    for (int i = 0; i < r * c; i++)
        result[i] = matrix1[i] * matrix2[i];
    cout << "\n������ľ���1\n";
    print_matrix(matrix1, r, c);
    cout << "������ľ���2\n";
    print_matrix(matrix2, r, c);
    cout << "\n����1�;���2Hadamard�˻���Ľ��\n";
    print_matrix(result, r, c);
    wait_for_enter();
}

void conv(int matrixA[MAX], int matrixB[MAX], int result[MAX])
{
    int r, c;
    while (1) {
        cout << "\n��ѡ���� 6 ������\n���������A��������������1��200������һ���ո��������5 5��\n";
        cin >> r >> c;
        if (r < 1 || r > 200 || c < 1 || c > 200 || cin.fail())
            cout << "�������������������Ҫ������������\n";
        else
            break;
    }
    cout << "���������A��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n";
    for (int i = 0; i < r + 2; i++)
        for (int j = 0; j < c + 2; j++) {
            if (i == 0 || i == r + 1 || j == 0 || j == c + 1)
                matrixA[i * (c + 2) + j] = 0;
            else {
                int a;
                cin >> a;
                if (cin.fail()) {
                    cout << "�����������������뱾��\n";
                    j = -1;
                    continue;
                }
                else
                    matrixA[i * (c + 2) + j] = a;
            }
        }
    cout << "���������B��ͬһ��ÿ����֮����һ���ո�ָ���ÿһ�е���ռһ�У�\n����B��3�׷���\n";
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
    cout << "\n������ľ���A��������Χ0��\n";
    print_matrix(matrixA, r + 2, c + 2);
    cout << "������ľ���B\n";
    print_matrix(matrixB, 3, 3);
    cout << "\n����A�;���B�����Ľ��\n";
    print_matrix(result, r, c);
    wait_for_enter();
}