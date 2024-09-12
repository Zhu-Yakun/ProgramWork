#include <iostream>
#include <fstream>
#include "PicReader.h"
#include "compression.h"
using namespace std;

// 构造函数
JpegEncoder::JpegEncoder(unsigned char* data, unsigned int x, unsigned int y) :rgb(data), width(x), height(y) 
{
	InitHuffmanTables();
};
// 析构函数
JpegEncoder::~JpegEncoder()
{
	clean();
}
// 清除数据
void JpegEncoder::clean()
{
	if (rgb) 
		delete[] rgb;
	rgb = 0;
	width = 0;
	height = 0;
}

// 初始化量化表
void JpegEncoder::InitQualityTables(int quality_scale) {
	if (quality_scale <= 0) quality_scale = 1;
	if (quality_scale >= 100) quality_scale = 99;

	for (int i = 0; i < 64; i++)
	{
		int temp = ((int)(L_Table[i] * quality_scale + 50) / 100);
		if (temp <= 0) temp = 1;
		if (temp > 0xFF) temp = 0xFF;
		YQTable[ZigZag[i]] = (unsigned char)temp;

		temp = ((int)(C_Table[i] * quality_scale + 50) / 100);
		if (temp <= 0) 	temp = 1;
		if (temp > 0xFF) temp = 0xFF;
		CbCrQTable[ZigZag[i]] = (unsigned char)temp;
	}
}
// 初始化哈夫曼树
void JpegEncoder::InitHuffmanTables() {
	memset(&Y_DC_Huff_Table, 0, sizeof(Y_DC_Huff_Table));
	ComputeHuffmanTable(Standard_DC_Luminance_NRCodes, Standard_DC_Luminance_Values, Y_DC_Huff_Table);

	memset(&Y_AC_Huff_Table, 0, sizeof(Y_AC_Huff_Table));
	ComputeHuffmanTable(Standard_AC_Luminance_NRCodes, Standard_AC_Luminance_Values, Y_AC_Huff_Table);

	memset(&CbCr_DC_Huff_Table, 0, sizeof(CbCr_DC_Huff_Table));
	ComputeHuffmanTable(Standard_DC_Chrominance_NRCodes, Standard_DC_Chrominance_Values, CbCr_DC_Huff_Table);

	memset(&CbCr_AC_Huff_Table, 0, sizeof(CbCr_AC_Huff_Table));
	ComputeHuffmanTable(Standard_AC_Chrominance_NRCodes, Standard_AC_Chrominance_Values, CbCr_AC_Huff_Table);
}

// 写jpg文件头
void JpegEncoder::WriteHeader(std::ostream& out) 
{
	// 写入Start Of Image (SOI)
	WriteWord(out, 0xFFD8);

	// 写入APP0标记
	WriteWord(out, 0xFFE0);
	WriteWord(out, 16); // APP0块长度
	out.write("JFIF", 5); // JFIF字符串和终止符
	out.put(1); // Major version号
	out.put(1); // Minor version号
	out.put(0); // 密度单位
	WriteWord(out, 1); // X密度
	WriteWord(out, 1); // Y密度
	out.put(0); // 缩略图宽度
	out.put(0); // 缩略图高度

	// 写入Define Quantization Table (DQT) - Y量化表
	WriteWord(out, 0xFFDB);
	WriteWord(out, 132); // DQT长度
	out.put(0); // 量化表ID
	out.write(reinterpret_cast<const char*>(&YQTable), sizeof(YQTable)); // Y量化表数据

	// 写入Define Quantization Table (DQT) - CbCr量化表
	out.put(1); // CbCr量化表ID
	out.write(reinterpret_cast<const char*>(&CbCrQTable), sizeof(CbCrQTable)); // CbCr量化表数据

	// 写入Start Of Frame (SOF0)
	WriteWord(out, 0xFFC0);
	WriteWord(out, 17); // SOF0块长度
	out.put(8); // 精度
	WriteWord(out, height); // 图像高度
	WriteWord(out, width); // 图像宽度
	out.put(3); // 颜色组件数量

	// 颜色组件信息
	out.put(1); // 组件ID
	out.put(0x11); // 水平|垂直采样因子
	out.put(0); // 量化表ID

	out.put(2); // 组件ID
	out.put(0x11); // 水平|垂直采样因子
	out.put(1); // 量化表ID

	out.put(3); // 组件ID
	out.put(0x11); // 水平|垂直采样因子
	out.put(1); // 量化表ID

	// 写入Define Huffman Table (DHT)
	WriteWord(out, 0xFFC4);
	WriteWord(out, 0x01A2); // DHT段长度

	// 哈夫曼表 - DC Luminance
	out.put(0); // 表ID
	out.write(reinterpret_cast<const char*>(&Standard_DC_Luminance_NRCodes), sizeof(Standard_DC_Luminance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_DC_Luminance_Values), sizeof(Standard_DC_Luminance_Values));

	// 哈夫曼表 - AC Luminance
	out.put(0x10); // 表ID
	out.write(reinterpret_cast<const char*>(&Standard_AC_Luminance_NRCodes), sizeof(Standard_AC_Luminance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_AC_Luminance_Values), sizeof(Standard_AC_Luminance_Values));

	// 哈夫曼表 - DC Chrominance
	out.put(0x01); // 表ID
	out.write(reinterpret_cast<const char*>(&Standard_DC_Chrominance_NRCodes), sizeof(Standard_DC_Chrominance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_DC_Chrominance_Values), sizeof(Standard_DC_Chrominance_Values));

	// 哈夫曼表 - AC Chrominance
	out.put(0x11); // 表ID
	out.write(reinterpret_cast<const char*>(&Standard_AC_Chrominance_NRCodes), sizeof(Standard_AC_Chrominance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_AC_Chrominance_Values), sizeof(Standard_AC_Chrominance_Values));

	// 写入Start Of Scan (SOS)
	WriteWord(out, 0xFFDA);
	WriteWord(out, 12); // SOS段长度
	out.put(3); // 颜色组件数量

	// 扫描头部信息
	out.put(1); // 组件ID
	out.put(0); // 外部DC和AC的哈夫曼编码表ID

	out.put(2); // 组件ID
	out.put(0x11); // 外部DC和AC的哈夫曼编码表ID

	out.put(3); // 组件ID
	out.put(0x11); // 外部DC和AC的哈夫曼编码表ID

	out.put(0); // 忽略的扫描头部信息
	out.put(0x3F); // 忽略的扫描头部信息
	out.put(0); // 忽略的扫描头部信息
}

// 写入一个WORD到流中 (两个字节，高位在前)
void JpegEncoder::WriteWord(std::ostream& out, unsigned short word) {
	out.put(static_cast<char>(word >> 8));
	out.put(static_cast<char>(word & 0xFF));
}

// 获取RGB
void JpegEncoder::GetRGB(unsigned char(&R)[64], unsigned char(&G)[64], unsigned char(&B)[64], unsigned int x, unsigned int y) 
{
	int num = 0;
	for (unsigned int i = y; i < y + 8; i++)
		for (unsigned int j = x; j < x + 8; j++) {
			R[num] = rgb[4 * (i * width + j)];
			G[num] = rgb[4 * (i * width + j) + 1];
			B[num] = rgb[4 * (i * width + j) + 2];
			num++;
		}
}
//RGB转为YCbCr
void JpegEncoder::RGB_YCbCr(unsigned char(&R)[64], unsigned char(&G)[64], unsigned char(&B)[64], char(&y)[64], char(&cb)[64], char(&cr)[64])
{
	for (int i = 0; i < 64; i++) {
		y[i] = char(0.299 * R[i] + 0.587 * G[i] + 0.114 * B[i]);
		cb[i] = char(-0.1687 * R[i] - 0.3313 * G[i] + 0.5 * B[i] + 128);
		cr[i] = char(0.5 * R[i] - 0.4187 * G[i] - 0.0813 * B[i] + 128);
	}
}
//离散余弦变换
void JpegEncoder::DCT(char(&temp)[64], double(&data)[64]) {
	double factor; // 声明变量factor用于存储规范化缩放因子
	// 在应用DCT之前，先对8x8的像素块进行“居中”处理
	// 减去128是为了将无符号字符数据的取值范围（0...255）变换到有符号的范围（-128...127）
	// 这样做是为了消除DCT变换中的直流分量（DC分量），使得DCT后的DC系数能表达平均值附近的偏移
	for (int i = 0; i < 64; i++)
		temp[i] -= 128;
	// 遍历8x8的数据块，分别对每个频率(u,v)成分进行DCT计算
	for (int u = 0; u < 8; u++)
		for (int v = 0; v < 8; v++) {
			// 根据DCT公式中的u和v来计算前面的缩放因子
			if (u == 0) {
				if (v == 0)
					factor = 1.0 / 8; // 当u和v都为0时的因子是1/8
				else
					factor = sqrt(2.0) / 8; // 当u为0且v不为0时，因子是sqrt(2)/8
			}
			else {
				if (v == 0)
					factor = sqrt(2.0) / 8; // 当v为0且u不为0时也是sqrt(2)/8
				else
					factor = 2.0 / 8; // 当u和v都不为0时，因子是1/4，或等价的2/8
			}
			double sum = 0; // 为每个频率(u,v)初始化累加结果

			// 求解DCT的双重和
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {
					// 根据DCT公式计算cosine项
					double p1 = cos(((2 * (double)i + 1) * u * PI) / 16.0);
					double p2 = cos(((2 * (double)j + 1) * v * PI) / 16.0);
					// 累加变换结果，包括temp的空间域值和cosine项
					sum += temp[i * 8 + j] * p1 * p2;
				}
			// 应用缩放因子，并将计算的DCT结果存储在data数组中
			data[u * 8 + v] = factor * sum;
		}
}

// 根据哈夫曼表求解哈夫曼树
void JpegEncoder::ComputeHuffmanTable(const char* NRCODES, const unsigned char* STD_TABLE, BitString* HuffmanTable) 
{
	unsigned char pos = 0;
	unsigned short value = 0;
	for (int k = 1; k <= 16; k++) {
		for (int j = 1; j <= NRCODES[k - 1]; j++){
			HuffmanTable[STD_TABLE[pos]].val = value;
			HuffmanTable[STD_TABLE[pos]].len = k;
			pos++;
			value++;
		}
		value <<= 1;
	}
}
// 哈夫曼编码
void JpegEncoder::HuffmanEncode(char* data, int& lastDC, BitString* HuffmanTableDC, BitString* HuffmanTableAC, BitString* outStr, int& StrCounts)
{
	int count = 0, i = 1;
	// AC分量中的“End of Block”（块结束）的标记
	BitString EOB = HuffmanTableAC[0x00];
	// 16个连续零的AC分量表示
	BitString SIXTEEN_ZEROS = HuffmanTableAC[0xF0];
	// 计算DC分量的差值
	int delta = int(data[0] - lastDC);
	// 更新上一个DC分量值
	lastDC = data[0];

	// 如果DC分量没有变化，则使用DC表中的0值，否则编码DC分量的差值
	if (!delta)
		outStr[count++] = HuffmanTableDC[0];
	else {
		BitString bitcode = GetBitCode(delta);
		outStr[count++] = HuffmanTableDC[bitcode.len]; // DC分量长度标记
		outStr[count++] = bitcode; // DC分量实际差值的编码
	}

	// 检测所有64个DC分量是否为零，从最后一个DC分量开始反向检查
	int end = 63;
	while ((end > 0) && (data[end] == 0))
		end--;

	// 直到找到最后一个非零DC分量，对中间的AC分量进行编码
	while (i <= end) {
		// 跳过前面的零
		int start = i;
		while ((data[i] == 0) && (i <= end))
			i++;
		// 计算跨过的零的数量
		int zeronum = i - start;
		// 如果超过16个零，添加特殊的哈夫曼编码
		if (zeronum >= 16) {
			for (int j = 1; j <= zeronum / 16; j++)
				outStr[count++] = SIXTEEN_ZEROS;
			zeronum = zeronum % 16;
		}
		// 编码非零AC分量的数据长度和实际值
		BitString bitcode = GetBitCode(data[i]);
		outStr[count++] = HuffmanTableAC[(zeronum << 4) | bitcode.len]; // AC分量长度和零数量标记
		outStr[count++] = bitcode; // AC分量实际的编码
		i++;
	}

	// 如果最后一个AC分量不是在64的位置，添加EOB
	if (end != 63)
		outStr[count++] = EOB;

	// 更新编码后输出字符串的计数
	StrCounts = count;
}

// 获得bit编码
JpegEncoder::BitString JpegEncoder::GetBitCode(int value)
{
	BitString bitcode;
	int len = 0, v = (value > 0) ? value : -value;
	for (len = 0; v; v >>= 1)
		len++;
	bitcode.val = value > 0 ? value : ((1 << len) + value - 1);
	bitcode.len = len;
	return bitcode;
};
// 写bit串
void JpegEncoder::WriteBitStr(ostream& out, BitString* outStr, int bitcounts, int& newbyte, int& newbytePos)
{
	unsigned short mask[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
	for (int i = 0; i < bitcounts; i++) {
		int value = outStr[i].val;
		int pos = outStr[i].len - 1;
		while (pos >= 0) {
			if ((value & mask[pos]) != 0)
				newbyte |= mask[newbytePos];
			pos--;
			newbytePos--;
			if (newbytePos < 0) {
				out.put((unsigned char)newbyte);
				if (newbyte == 0xFF)
					out.put((unsigned char)0x00);
				newbytePos = 7;
				newbyte = 0;
			}
		}
	}
}

// 量化
void JpegEncoder::Quantization(double(&ytemp)[64], double(&cbtemp)[64], double(&crtemp)[64])
{
	for (int i = 0; i < 64; i++) {
		ytemp[i] = ytemp[i] / YQTable[i];
		cbtemp[i] = cbtemp[i] / CbCrQTable[i];
		crtemp[i] = crtemp[i] / CbCrQTable[i];
	}
}
// ZigZag扫描
void JpegEncoder::ZigZag_Scan(char(&y)[64], char(&cb)[64], char(&cr)[64], double(&ytemp)[64], double(&cbtemp)[64], double(&crtemp)[64]) {
	for (int i = 0; i < 64; i++) {
		y[ZigZag[i]] = char(round(ytemp[i]));
		cb[ZigZag[i]] = char(round(cbtemp[i]));
		cr[ZigZag[i]] = char(round(crtemp[i]));
	}
}

//压缩函数
void JpegEncoder::EncodeToJpeg(const char* outfile, int quality_scale) {
	ofstream out;
	// 以二进制写模式打开文件
	out.open(outfile, ios::out | ios::binary);
	if (!out.is_open()) { // 如果文件打开失败，输出错误并返回
		cout << "文件打开失败" << endl;
		return;
	}

	// 初始化量化表，以根据特定的质量系数进行压缩
	InitQualityTables(quality_scale);

	// 写入JPEG文件头到输出文件
	WriteHeader(out);

	// 定义DC分量的上一个值，用于差分编码
	int lastY_DC = 0, lastCb_DC = 0, lastCr_DC = 0;
	int newByte = 0, newbytePos = 7; // 用于字节编码的辅助变量

	// 遍历图像的每个8x8像素块
	for (unsigned int y = 0; y < height; y += 8) {
		for (unsigned int x = 0; x < width; x += 8) {

			// 定义数据存储数组和其他所需变量
			char ydata[64], cbdata[64], crdata[64];
			double ytemp[64], cbtemp[64], crtemp[64];
			unsigned char R[64], G[64], B[64];
			BitString outStr[128];
			int bitCounts;

			// 提取一个8x8块的RGB数据
			GetRGB(R, G, B, x, y);
			// 转换RGB到YCbCr色彩空间
			RGB_YCbCr(R, G, B, ydata, cbdata, crdata);
			// 离散余弦变换（DCT）
			DCT(ydata, ytemp);
			DCT(cbdata, cbtemp);
			DCT(crdata, crtemp);
			// 量化DCT系数
			Quantization(ytemp, cbtemp, crtemp);
			// ZigZag排列量化后的系数，为熵编码做准备
			ZigZag_Scan(ydata, cbdata, crdata, ytemp, cbtemp, crtemp);
			// 针对Y通道进行霍夫曼熵编码
			HuffmanEncode(ydata, lastY_DC, Y_DC_Huff_Table, Y_AC_Huff_Table, outStr, bitCounts);
			// 将编码数据写入文件
			WriteBitStr(out, outStr, bitCounts, newByte, newbytePos);
			// 针对Cb通道进行霍夫曼熵编码
			HuffmanEncode(cbdata, lastCb_DC, CbCr_DC_Huff_Table, CbCr_AC_Huff_Table, outStr, bitCounts);
			// 将编码数据写入文件
			WriteBitStr(out, outStr, bitCounts, newByte, newbytePos);
			// 针对Cr通道进行霍夫曼熵编码
			HuffmanEncode(crdata, lastCr_DC, CbCr_DC_Huff_Table, CbCr_AC_Huff_Table, outStr, bitCounts);
			// 将编码数据写入文件
			WriteBitStr(out, outStr, bitCounts, newByte, newbytePos);
		}
	}

	// 写入JPEG图像的结尾标记
	WriteWord(out, 0xFFD9);
	// 关闭文件
	out.close();
}