#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

// ���������ڵ�ṹ��
struct HuffNode
{
    unsigned char symb = '\0';          // �洢���ַ�
    int order = -1;                      // �������
    int lch = -1, rch = -1;             // ���Һ������
    int cnt = 0;                        // �ַ����ִ���
    int parent = -1;                    // ��������
    char hcode[20] = { 0 };             // ����������
    friend bool operator < (HuffNode x, HuffNode y)
    {
        return x.cnt > y.cnt;
    }
};

// ����������ṹ��
struct HuffCode {
    char* code = NULL;                  // ָ������ָ��
    int len = 0;                        // ���볤��
};

int Count[512] = { 0 };                 // �ַ���������
int* countMap = &Count[256];            // �ַ�����ӳ���
char buffer[1025] = { 0 };              // ������
HuffNode HuffTree[1024] = { 0 };        // ������������
HuffCode HCode[512] = { 0 };            // ��������������
HuffCode* Hcode = &HCode[256];          // ����������ָ��
string str, out;                        // �����ַ���������ַ���

// �жϽڵ��Ƿ�ΪҶ�ӽڵ�
bool is_leaf(HuffNode p)
{
    return (p.lch == -1) && (p.rch == -1);
}

// �������������ڵ�
void createNode(int l, int r, int tot)
{
    HuffTree[tot].order = tot;
    HuffTree[tot].lch = l;
    HuffTree[tot].rch = r;
    HuffTree[tot].cnt = HuffTree[l].cnt + HuffTree[r].cnt;
    HuffTree[l].parent = tot;
    HuffTree[r].parent = tot;
}

// ������������
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

// ���ɹ���������
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

// ѹ���ļ�
void compress(ofstream& outfile, int num_kinds, int file_length)
{
    char temparray[256] = { 0 };
    unsigned char c = 0;
    temparray[0] = 0;
    int pt = 0;
    int i = 0, j = 0, k = 0;
    while (str[k])
    {
        c = str[k++];      //��ȡ��һ���ַ���һ���޷����ַ���
        strcat(temparray, Hcode[c].code);    //�Ѵ��ַ�����ı���׷�Ӹ�temparray���ݴ�
        j = int(strlen(temparray));   //j�����ݴ��ʼ�����ܳ�
        c = 0;      //��������00000000
        while (j >= 8)//ֻҪ��ı���λ������8����ִ�в���д���ļ�
        {
            for (i = 0; i < 8; i++) {
                if (temparray[i] == '1') {
                    c = c << 1;
                    c |= 1;
                }//c�Ķ����������Ʋ���1
                else
                    c = c << 1;//c�Ķ�������������
            }//ʵ�ֶ����ƵĶ�ȡ�ͼ�¼
            out += c;
            strcpy(temparray, temparray + 8);  //temparray��ֵ���¸���
            j = int(strlen(temparray));
        }
    }
    if (j > 0)//��ʣ���ַ���������8��ʱ
    {
        c = 0;
        strcat(temparray, "00000000");
        for (i = 0; i < 8; i++) {
            if (temparray[i] == '1') {
                c = c << 1;
                c |= 1;//λ����
            }
            else
                c = c << 1;//�Բ����λ�����в���
        }
        out += c;
    }

    outfile.seekp(0, ios::beg);

    pt = int(out.length());
    outfile.write((char*)(&file_length), 4);
    outfile.write((char*)(&pt), 4);
    outfile.write((char*)(&num_kinds), 4);//дһ�����ֽڵ����ݣ�Ҫע��pt���ۼ�
    //������д��ѹ���ĸ���������ַ������������ַ�����

    temparray[0] = 0;
    for (i = 0; i < 2 * num_kinds - 1; i++) {
        outfile.write((char*)(&(HuffTree[i]).symb), 1);
        outfile.write((char*)(&(HuffTree[i]).lch), 4);
        outfile.write((char*)(&(HuffTree[i]).rch), 4);
        //����д����ַ����������������
    }
    outfile.write((char*)(&out[0]), out.length());
}
void uccompression(ofstream& outfile, int num_kinds, int file_length, int zipfile_length)
{
    unsigned char c = 0;
    int length = 0, i = 0, j = 7;
    c = str[0]; // ��ʼ�� c Ϊ�ַ����ĵ�һ���ַ�
    int len = int(str.length()); // ��ȡ�ַ����ĳ���
    while (i <= len && length < file_length) {
        int start = 2 * num_kinds - 2; // �� Huffman ���ĸ��ڵ㿪ʼ
        while (i < len && !is_leaf(HuffTree[start])) { // ���� Huffman ��ֱ���ﵽҶ�ڵ�
            if (j == -1) { // ��� c ������λ�����������ˣ����ƶ�����һ���ַ�
                c = str[++i];
                j = 7;
            }
            if ((c & (1UL << j)) == 0) // ��� c �ĵ� j λ
                start = HuffTree[start].lch; // �����λΪ 0�����ƶ������ӽڵ�
            else
                start = HuffTree[start].rch; // �����λΪ 1�����ƶ������ӽڵ�
            j--;
        }
        out += HuffTree[start].symb; // ��Ҷ�ڵ�ķ�����ӵ�����ַ�����
        length++;
    }
    outfile.write((char*)(&out[0]), out.length()); // ������ַ���д������ļ�
}

int main()
{
    LARGE_INTEGER tick, begin, end;

    int num_kinds = 0;       // ԭ�ļ����ַ�����
    int file_length = 0;     // ԭ�ļ��ַ���
    int zipfile_length = 0;  // ѹ���ļ��ַ���
    cout << "Zipper 0.001! Author: Miracle" << endl;

    string infile, outfile, cmd;
    cout << "��������Ҫ���⣩ѹ�����ļ�����Ҫ������ļ���������׺��\n";
    cin >> infile >> outfile;
    cout << "��������Ҫѹ����zip�����ǽ�ѹ����unzip��\n";
    cin >> cmd;
    if ((cmd != "zip") && (cmd != "unzip")) {
        cerr << "Unknown parameter!\nCommand list:\nzip\nunzip" << endl;
        return -1;
    }

    QueryPerformanceFrequency(&tick);    // ��ȡӲ����������Ƶ��
    QueryPerformanceCounter(&begin);    // ��ȡӲ���������ĳ�ʼ����

    ifstream fin(infile, ios::binary); // �Զ����Ʒ�ʽ�������ļ�
    if (!fin.is_open()) {
        cerr << "Can not open the input file!" << endl; // ���������Ϣ���˳�
        return -1;
    }

    ofstream fout(outfile, ios::binary); // ������ļ�
    if (!fout) {
        cerr << "Can not open the output file!" << endl;
        return -1;
    }

    if (cmd == "zip") {
        while (fin && !fin.eof()) {
            fin.read(buffer, 1024); // �������ļ��ж�ȡ 1024 �ֽ�
            str.append(buffer, 1024); // ����ȡ��������ӵ��ַ�����
            int num_read = (int)(fin.gcount()); // ��ȡ��ȡ���ַ���
            for (int i = 0; i < num_read; i++) {
                if (countMap[buffer[i]] == 0)
                    num_kinds++; // ͳ���ļ��в�ͬ�ַ��ĸ���
                countMap[buffer[i]]++; // ͳ��ÿ���ַ����ֵĴ���
                file_length++; // ͳ���ļ����ַ�������
            }
        }
        createHuffTree(num_kinds); // ���� Huffman ��
        CodeHuff(num_kinds); // ���� Huffman ����
        compress(fout, num_kinds, file_length); // ѹ���ļ�
    }
    else {
        fin.read((char*)&file_length, 4); // ��ѹ���ļ��ж�ȡ�ļ�����
        fin.read((char*)&zipfile_length, 4); // ��ѹ���ļ��ж�ȡѹ���ļ�����
        fin.read((char*)&num_kinds, 4); // ��ѹ���ļ��ж�ȡ��ͬ�ַ��ĸ���
        for (int i = 0; i < 2 * num_kinds - 1; i++) {
            fin.read((char*)&HuffTree[i].symb, 1); // ��ѹ���ļ��ж�ȡÿ���ڵ�ķ���
            fin.read((char*)&HuffTree[i].lch, 4); // ��ѹ���ļ��ж�ȡÿ���ڵ�����ӽڵ�����
            fin.read((char*)&HuffTree[i].rch, 4); // ��ѹ���ļ��ж�ȡÿ���ڵ�����ӽڵ�����
        }
        int cnt = 0;
        while (fin && !fin.eof()) {
            cnt++;
            fin.read(buffer, 1024); // ��ѹ���ļ��ж�ȡ 1024 �ֽ�
            str.append(buffer, 1024); // ����ȡ��������ӵ��ַ�����
        }
        uccompression(fout, num_kinds, file_length, zipfile_length); // ��ѹ���ļ�
    }

    fin.close(); // �ر������ļ�
    fout.close(); // �ر�����ļ�

    QueryPerformanceCounter(&end);        // ��ȡӲ�������������ռ���
    if (cmd == "unzip")
        printf("��");
    printf("ѹ��ʱ�� : %.3f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

    cout << "Complete!" << endl;
    return 0;
}
