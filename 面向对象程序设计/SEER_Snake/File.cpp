#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "SEER_Snake.h"

using namespace std;

template <typename T>
static void readArrayFromFile(const char* filename, T* array, size_t size) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "无法打开文件进行读取: " << filename << endl;
        exit(-1);
    }

    file.read(reinterpret_cast<char*>(array), size * sizeof(T));

    if (!file) {
        cout << "读取文件时发生错误: " << filename << endl;
        file.close();
        exit(-1);
    }

    file.close();
}

template <typename T>
static void saveArrayToFile(const char* filename, const T* array, size_t size) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "无法打开文件进行写入: " << filename << endl;
        exit(-1);
    }

    file.write(reinterpret_cast<const char*>(array), size * sizeof(T));

    if (!file) {
        cout << "写入文件时发生错误: " << filename << endl;
        file.close();
        exit(-1);
    }

    file.close();
}

int readHighestScore(Mode mode)
{
    int highestScore[MODE_NUMBER];
    readArrayFromFile("data/highest_score.dat", highestScore, MODE_NUMBER);
    return highestScore[mode];
}

void updateHighestScore(Mode mode, int score)
{
    int highestScore[MODE_NUMBER];
    readArrayFromFile("data/highest_score.dat", highestScore, MODE_NUMBER);
    highestScore[mode] = score;
    saveArrayToFile("data/highest_score.dat", highestScore, MODE_NUMBER);
}

void reset()
{
    int highestScore[MODE_NUMBER] = { 0 };
    saveArrayToFile("data/highest_score.dat", highestScore, MODE_NUMBER);
}