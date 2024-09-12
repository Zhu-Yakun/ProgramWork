#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <windows.h> //取系统时间
using namespace std;

// 哈夫曼树节点结构体
struct HuffNode
{
    unsigned char symb = '\0';          // 存储的字符
    int order = -1;                      // 自身序号
    int lch = -1, rch = -1;             // 左右孩子序号
    int cnt = 0;                        // 字符出现次数
    int parent = -1;                    // 父结点序号
    char hcode[20] = { 0 };             // 哈夫曼编码
    friend bool operator < (HuffNode x, HuffNode y)
    {
        return x.cnt > y.cnt;
    }
};

// 哈夫曼编码结构体
struct HuffCode {
    char* code = NULL;                  // 指向编码的指针
    int len = 0;                        // 编码长度
};

int Count[512] = { 0 };                 // 字符计数数组
int* countMap = &Count[256];            // 字符计数映射表
char buffer[1025] = { 0 };              // 缓冲区
HuffNode HuffTree[1024] = { 0 };        // 哈夫曼树数组
HuffCode HCode[512] = { 0 };            // 哈夫曼编码数组
HuffCode* Hcode = &HCode[256];          // 哈夫曼编码指针
string str, out;                        // 输入字符串和输出字符串

// 判断节点是否为叶子节点
bool is_leaf(HuffNode p)
{
    return (p.lch == -1) && (p.rch == -1);
}

// 创建哈夫曼树节点
void createNode(int l, int r, int tot)
{
    HuffTree[tot].order = tot;
    HuffTree[tot].lch = l;
    HuffTree[tot].rch = r;
    HuffTree[tot].cnt = HuffTree[l].cnt + HuffTree[r].cnt;
    HuffTree[l].parent = tot;
    HuffTree[r].parent = tot;
}

// 创建哈夫曼树
void createHuffTree(int num_kinds)
{
    int tot = 0;
    priority_queue<HuffNode> HuffQueue;
    for (int i = -256; i < 256; i++) {
        if (countMap[i] == 0)
            continue;
        HuffTree[tot].order = tot;
        HuffTree[tot].symb = char(i);
        HuffTree[tot].cnt = countMap[i];
        HuffQueue.push(HuffTree[tot]);
        tot++;
    }
    while (!HuffQueue.empty()) {
        if (HuffQueue.size() == 1)
            break;
        int l = HuffQueue.top().order;
        HuffQueue.pop();
        int r = HuffQueue.top().order;
        HuffQueue.pop();
        createNode(l, r, tot);
        HuffQueue.push(HuffTree[tot]);
        tot++;
    }
}

// 生成哈夫曼编码
void CodeHuff(int num_kinds)
{
    for (int i = 0; i < num_kinds; i++) {
        char temp[20] = { 0 };
        for (int c = i, f = HuffTree[c].parent; f != -1; c = f, f = HuffTree[f].parent) {
            if (HuffTree[f].lch == c)
                temp[Hcode[HuffTree[i].symb].len] = '0';
            else
                temp[Hcode[HuffTree[i].symb].len] = '1';
            Hcode[HuffTree[i].symb].len++;
        }
        for (int j = 0; j < Hcode[HuffTree[i].symb].len; j++)
            HuffTree[i].hcode[j] = temp[Hcode[HuffTree[i].symb].len - 1 - j];
        Hcode[HuffTree[i].symb].code = HuffTree[i].hcode;
    }
}

// 压缩文件
void compress(ofstream& outfile, int num_kinds, int file_length)
{
    char temparray[256] = { 0 };
    unsigned char c = 0;
    temparray[0] = 0;
    int pt = 0;
    int i = 0, j = 0, k = 0;
    while (str[k])
    {
        c = str[k++];      //获取下一个字符（一个无符号字符）
        strcat(temparray, Hcode[c].code);    //把此字符种类的编码追加给temparray来暂存
        j = int(strlen(temparray));   //j用来暂存初始编码总长
        c = 0;      //二进制是00000000
        while (j >= 8)//只要存的编码位数大于8，就执行操作写入文件
        {
            for (i = 0; i < 8; i++) {
                if (temparray[i] == '1') {
                    c = c << 1;
                    c |= 1;
                }//c的二进制数左移并加1
                else
                    c = c << 1;//c的二进制数字左移
            }//实现二进制的读取和记录
            out += c;
            strcpy(temparray, temparray + 8);  //temparray的值重新覆盖
            j = int(strlen(temparray));
        }
    }
    if (j > 0)//当剩余字符数量少于8个时
    {
        c = 0;
        strcat(temparray, "00000000");
        for (i = 0; i < 8; i++) {
            if (temparray[i] == '1') {
                c = c << 1;
                c |= 1;//位运算
            }
            else
                c = c << 1;//对不足的位数进行补零
        }
        out += c;
    }

    outfile.seekp(0, ios::beg);

    pt = int(out.length());
    outfile.write((char*)(&file_length), 4);
    outfile.write((char*)(&pt), 4);
    outfile.write((char*)(&num_kinds), 4);//写一个四字节的数据，要注意pt的累加
    //以上是写入压缩的各类参数：字符种类总数，字符总数

    temparray[0] = 0;
    for (i = 0; i < 2 * num_kinds - 1; i++) {
        outfile.write((char*)(&(HuffTree[i]).symb), 1);
        outfile.write((char*)(&(HuffTree[i]).lch), 4);
        outfile.write((char*)(&(HuffTree[i]).rch), 4);
        //以上写入各字符种类哈夫曼编码树
    }
    outfile.write((char*)(&out[0]), out.length());
}
void uccompression(ofstream& outfile, int num_kinds, int file_length, int zipfile_length)
{
    unsigned char c = 0;
    int length = 0, i = 0, j = 7;
    c = str[0]; // 初始化 c 为字符串的第一个字符
    int len = int(str.length()); // 获取字符串的长度
    while (i <= len && length < file_length) {
        int start = 2 * num_kinds - 2; // 从 Huffman 树的根节点开始
        while (i < len && !is_leaf(HuffTree[start])) { // 遍历 Huffman 树直到达到叶节点
            if (j == -1) { // 如果 c 的所有位都被处理完了，就移动到下一个字符
                c = str[++i];
                j = 7;
            }
            if ((c & (1UL << j)) == 0) // 检查 c 的第 j 位
                start = HuffTree[start].lch; // 如果该位为 0，就移动到左子节点
            else
                start = HuffTree[start].rch; // 如果该位为 1，就移动到右子节点
            j--;
        }
        out += HuffTree[start].symb; // 将叶节点的符号添加到输出字符串中
        length++;
    }
    outfile.write((char*)(&out[0]), out.length()); // 将输出字符串写入输出文件
}

int main()
{
    LARGE_INTEGER tick, begin, end;

    int num_kinds = 0;       // 原文件中字符种数
    int file_length = 0;     // 原文件字符数
    int zipfile_length = 0;  // 压缩文件字符数
    cout << "Zipper 0.001! Author: Miracle" << endl;

    string infile, outfile, cmd;
    cout << "请输入你要（解）压缩的文件名和要输出的文件名（带后缀）\n";
    cin >> infile >> outfile;
    cout << "请输入你要压缩（zip）还是解压缩（unzip）\n";
    cin >> cmd;
    if ((cmd != "zip") && (cmd != "unzip")) {
        cerr << "Unknown parameter!\nCommand list:\nzip\nunzip" << endl;
        return -1;
    }

    QueryPerformanceFrequency(&tick);    // 获取硬件计数器的频率
    QueryPerformanceCounter(&begin);    // 获取硬件计数器的初始计数

    ifstream fin(infile, ios::binary); // 以二进制方式打开输入文件
    if (!fin.is_open()) {
        cerr << "Can not open the input file!" << endl; // 输出错误信息并退出
        return -1;
    }

    ofstream fout(outfile, ios::binary); // 打开输出文件
    if (!fout) {
        cerr << "Can not open the output file!" << endl;
        return -1;
    }

    if (cmd == "zip") {
        while (fin && !fin.eof()) {
            fin.read(buffer, 1024); // 从输入文件中读取 1024 字节
            str.append(buffer, 1024); // 将读取的数据添加到字符串中
            int num_read = (int)(fin.gcount()); // 获取读取的字符数
            for (int i = 0; i < num_read; i++) {
                if (countMap[buffer[i]] == 0)
                    num_kinds++; // 统计文件中不同字符的个数
                countMap[buffer[i]]++; // 统计每个字符出现的次数
                file_length++; // 统计文件中字符的总数
            }
        }
        createHuffTree(num_kinds); // 创建 Huffman 树
        CodeHuff(num_kinds); // 生成 Huffman 编码
        compress(fout, num_kinds, file_length); // 压缩文件
    }
    else {
        fin.read((char*)&file_length, 4); // 从压缩文件中读取文件长度
        fin.read((char*)&zipfile_length, 4); // 从压缩文件中读取压缩文件长度
        fin.read((char*)&num_kinds, 4); // 从压缩文件中读取不同字符的个数
        for (int i = 0; i < 2 * num_kinds - 1; i++) {
            fin.read((char*)&HuffTree[i].symb, 1); // 从压缩文件中读取每个节点的符号
            fin.read((char*)&HuffTree[i].lch, 4); // 从压缩文件中读取每个节点的左子节点索引
            fin.read((char*)&HuffTree[i].rch, 4); // 从压缩文件中读取每个节点的右子节点索引
        }
        int cnt = 0;
        while (fin && !fin.eof()) {
            cnt++;
            fin.read(buffer, 1024); // 从压缩文件中读取 1024 字节
            str.append(buffer, 1024); // 将读取的数据添加到字符串中
        }
        uccompression(fout, num_kinds, file_length, zipfile_length); // 解压缩文件
    }

    fin.close(); // 关闭输入文件
    fout.close(); // 关闭输出文件

    QueryPerformanceCounter(&end);        // 获取硬件计数器的最终计数
    if (cmd == "unzip")
        printf("解");
    printf("压缩时间 : %.3f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

    cout << "Complete!" << endl;
    return 0;
}
