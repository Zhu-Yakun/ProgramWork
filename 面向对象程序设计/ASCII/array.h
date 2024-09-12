#pragma once
#include<stdio.h>
#define HIGHEST_DIMENSION 16

using namespace std;

const int consoleWindowsSize = 150;
const char asciiStrength[] = { '@','M','N','H','Q','$','O','C','?','7','1','>','!',':','-','.' };

enum Operation { Add, Sub, Mul, Div, Opp, MatMulNum, NumMulMat, MatDivNum, NumDivMat };

class Array {
private:
    int* data = NULL;
    int shape[HIGHEST_DIMENSION] = { 0 };
    int axisNum = 0;
    int nowAxis = 0;
    int index = 0;
    int len = 1;
    bool check = true;

    void checkTypes(bool is_index);
    int calculateOffset(int indexs[]);
    bool is_homogeneous_matrix(Array& a, Array& b);
    Array elementwiseOperation(Array& arr, Operation optn);

    template <typename T1, typename T2>
    bool isTypeSame(T1, T2)
    {
        return false;
    }

    template <typename T>
    bool isTypeSame(T, T)
    {
        return true;
    }

    template <typename T>
    void checkType(bool is_index, const T& arg)
    {
        if (!isTypeSame(arg, int()) || (is_index ? false : arg < 1))
            exit(-1);
    }

    template <typename T, typename... Args>
    void checkTypes(bool is_index, const T& arg, const Args&... args)
    {
        checkType(is_index, arg);
        checkTypes(is_index, args...);
    }

public:
    Array();
    Array(const Array& other);
    ~Array();
    void set(int value);
    int* get_content(void);
    Array operator[](int n);
    Array& operator=(int value);
    Array operator+(Array& arr);
    Array operator-(void);
    Array operator-(Array& arr);
    Array operator*(Array& arr);
    Array operator/(Array& arr);
    operator int(void);

    friend ostream& operator<<(ostream& out, const Array& arr);
    friend istream& operator>>(istream& in, Array& arr);
    friend Array elementwiseOperation(Array& arr, int n, Operation optn);
    friend Array operator*(Array& arr, int n);
    friend Array operator*(int n, Array& arr);
    friend Array operator/(Array& arr, int n);
    friend Array operator/(int n, Array& arr);

    template <typename... Args>
    Array(Args... args)
    {
        checkTypes(false, args...);
        axisNum = sizeof...(args);
        nowAxis = axisNum;
        int list[] = { args... };
        for (int i = 0; i < axisNum; i++)
            shape[i] = list[i];
        for (int i = 0; i < axisNum; i++)
            len *= shape[i];
        data = new(nothrow) int[len] {0};
        if (data == NULL)
            exit(-1);
    }

    template <typename... Args>
    Array& at(Args... args)
    {
        if (axisNum != sizeof...(args))
            exit(-1);
        checkTypes(true, args...);
        int* indexs = new(nothrow) int[axisNum] {args...};
        if (indexs == NULL)
            exit(-1);
        for (int i = 0; i < axisNum; i++)
            if (indexs[i] >= shape[i] || indexs[i] < 0)
                exit(-1);
        index = calculateOffset(indexs);
        delete[] indexs;
        return *this;
    }

    template <typename... Args>
    void reshape(Args... args)
    {
        checkTypes(false, args...);
        axisNum = sizeof...(args);
        nowAxis = axisNum;
        int list[] = { args... };
        for (int i = 0; i < HIGHEST_DIMENSION; i++)
            shape[i] = ((i < axisNum) ? list[i] : 0);
        int newLen = 1;
        for (int i = 0; i < axisNum; i++)
            newLen *= shape[i];
        if (newLen != len)
            exit(-1);
    }
};