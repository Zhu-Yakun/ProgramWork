#include <iostream>
#include "array.h"

using namespace std;

void Array::checkTypes(bool is_index)
{
    return;
}

int Array::calculateOffset(int indexs[])
{
    int offset = 0, stride = 1;
    for (int i = axisNum - 1; i >= 0; i--) {
        offset += indexs[i] * stride;
        stride *= shape[i];
    }
    return offset;
}

bool Array::is_homogeneous_matrix(Array& a, Array& b)
{
    if (a.axisNum != b.axisNum || a.len != b.len)
        return false;
    else {
        for (int i = 0; i < a.axisNum; i++)
            if (a.shape[i] != b.shape[i])
                return false;
        return true;
    }
}

Array Array::elementwiseOperation(Array& arr, Operation optn)
{
    if (!is_homogeneous_matrix(*this, arr))
        exit(-1);
    Array result;
    for (int i = 0; i < HIGHEST_DIMENSION; i++)
        result.shape[i] = shape[i];
    result.axisNum = axisNum;
    result.nowAxis = nowAxis;
    result.len = len;
    result.check = false;
    delete[] result.data;
    result.data = new(nothrow) int[result.len];
    if (result.data == NULL)
        exit(-1);
    for (int i = 0; i < result.len; i++)
        switch (optn) {
            case Add:
                result.data[i] = data[i] + arr.data[i];
                break;
            case Sub:
                result.data[i] = data[i] - arr.data[i];
                break;
            case Mul:
                result.data[i] = data[i] * arr.data[i];
                break;
            case Div:
                result.data[i] = data[i] / arr.data[i];
                break;
            case Opp:
                result.data[i] = -data[i];
                break;
            default:
                exit(-1);
        }
    return result;
}

Array::Array()
{
    check = true;
}

Array::Array(const Array& other)
{
    data = other.data;
    for (int i = 0; i < HIGHEST_DIMENSION; i++)
        shape[i] = other.shape[i];
    axisNum = other.axisNum;
    nowAxis = other.nowAxis;
    index = other.index;
    len = other.len;
    check = other.check;
}

Array::~Array()
{
    if (check)
        delete[] data;
}

void Array::set(int value)
{
    if (nowAxis == 0)
        this->data[index] = value;
    else
        exit(-1);
}

int* Array::get_content(void)
{
    return data;
}

Array Array::operator[](int n)
{
    if (!isTypeSame(n, int()) || n < 0 || n >= *shape)
        exit(-1);
    Array copy;
    copy.check = false;
    copy.data = data;
    copy.axisNum = axisNum;
    copy.nowAxis = nowAxis - 1;
    for (int i = 0; i < nowAxis; i++)
        copy.shape[i] = shape[i + 1];
    int product = n;
    for (int i = 0; i < copy.nowAxis; i++)
        product *= copy.shape[i];
    int _index = index;
    _index += product;
    copy.index = _index;
    for (int i = 0; i < copy.nowAxis; i++)
        copy.len *= copy.shape[i];
    return copy;
}

Array& Array::operator=(int value)
{
    data[index] = value;
    return *this;
}

Array Array::operator+(Array& arr)
{
    return elementwiseOperation(arr, Add);
}

Array Array::operator-(void)
{
    return elementwiseOperation(*this, Opp);
}

Array Array::operator-(Array& arr)
{
    return elementwiseOperation(arr, Sub);
}

Array Array::operator*(Array& arr)
{
    return elementwiseOperation(arr, Mul);
}

Array Array::operator/(Array& arr)
{
    return elementwiseOperation(arr, Div);
}

Array::operator int(void)
{
    return data[index];
}

ostream& operator<<(ostream& out, const Array& arr)
{
    out << "[" << *arr.data;
    for (int i = 1; i < arr.len; i++)
        out << "," << arr.data[i];
    out << "]";
    return out;
}

istream& operator>>(istream& in, Array& arr)
{
    for (int i = 0; i < arr.len; i++) {
        int n;
        in >> n;
        if (in.fail())
            exit(-1);
        arr.data[i] = n;
    }
    return in;
}

Array elementwiseOperation(Array& arr, int n, Operation optn)
{
    Array result;
    result.check = false;
    result.axisNum = arr.axisNum;
    for (int i = 0; i < HIGHEST_DIMENSION; i++)
        result.shape[i] = arr.shape[i];
    result.len = arr.len;
    delete[] result.data;
    result.data = new(nothrow) int[result.len];
    if (result.data == NULL)
        exit(-1);
    for (int i = 0; i < result.len; i++)
        switch (optn) {
            case MatMulNum:
                result.data[i] = arr.data[i] * n;
                break;
            case NumMulMat:
                result.data[i] = n * arr.data[i];
                break;
            case MatDivNum:
                result.data[i] = arr.data[i] / n;
                break;
            case NumDivMat:
                result.data[i] = n / arr.data[i];
                break;
            default:
                exit(-1);
        }
    return result;
}

Array operator*(Array& arr, int n)
{
    return elementwiseOperation(arr, n, MatMulNum);
}

Array operator*(int n, Array& arr)
{
    return elementwiseOperation(arr, n, NumMulMat);
}

Array operator/(Array& arr, int n)
{
    return elementwiseOperation(arr, n, MatDivNum);
}

Array operator/(int n, Array& arr)
{
    return elementwiseOperation(arr, n, NumDivMat);
}