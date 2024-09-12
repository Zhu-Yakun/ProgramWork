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
    while (true) // ע���ѭ���˳�������
    {
        // ������ر���
        int matrix1[MAX] = { 0 }, matrix2[MAX] = { 0 }, result[MAX] = { 0 };
        char choice;
        while (1) {
            system("cls"); // ��������
            menu(); // ���ò˵���ʾ���������в������
            choice = _getche();
            if (choice < '0' || choice > '9') {
                cout << "�����������������";
                wait_for_enter();
                continue;
            }
            else
                break;
        }
        // ��Ҫ������˵�ѡ����choice
        if (choice == '0') // ѡ���˳�
        {
            cout << "\n ȷ���˳���?" << endl;
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                break;
            else
                continue;
        }
        switch (choice)
        {
            // ���������������������Ʋ���ɣ����������������������͵ȣ�����ѡ��ӷ�������в���
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
                cout << "\n ����������������" << endl;
                wait_for_enter();
        }
    }
    return 0;
}