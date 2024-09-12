#include <iostream>
#include <fstream>
#include "PicReader.h"
#include "compression.h"
using namespace std;

// ���캯��
JpegEncoder::JpegEncoder(unsigned char* data, unsigned int x, unsigned int y) :rgb(data), width(x), height(y) 
{
	InitHuffmanTables();
};
// ��������
JpegEncoder::~JpegEncoder()
{
	clean();
}
// �������
void JpegEncoder::clean()
{
	if (rgb) 
		delete[] rgb;
	rgb = 0;
	width = 0;
	height = 0;
}

// ��ʼ��������
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
// ��ʼ����������
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

// дjpg�ļ�ͷ
void JpegEncoder::WriteHeader(std::ostream& out) 
{
	// д��Start Of Image (SOI)
	WriteWord(out, 0xFFD8);

	// д��APP0���
	WriteWord(out, 0xFFE0);
	WriteWord(out, 16); // APP0�鳤��
	out.write("JFIF", 5); // JFIF�ַ�������ֹ��
	out.put(1); // Major version��
	out.put(1); // Minor version��
	out.put(0); // �ܶȵ�λ
	WriteWord(out, 1); // X�ܶ�
	WriteWord(out, 1); // Y�ܶ�
	out.put(0); // ����ͼ���
	out.put(0); // ����ͼ�߶�

	// д��Define Quantization Table (DQT) - Y������
	WriteWord(out, 0xFFDB);
	WriteWord(out, 132); // DQT����
	out.put(0); // ������ID
	out.write(reinterpret_cast<const char*>(&YQTable), sizeof(YQTable)); // Y����������

	// д��Define Quantization Table (DQT) - CbCr������
	out.put(1); // CbCr������ID
	out.write(reinterpret_cast<const char*>(&CbCrQTable), sizeof(CbCrQTable)); // CbCr����������

	// д��Start Of Frame (SOF0)
	WriteWord(out, 0xFFC0);
	WriteWord(out, 17); // SOF0�鳤��
	out.put(8); // ����
	WriteWord(out, height); // ͼ��߶�
	WriteWord(out, width); // ͼ����
	out.put(3); // ��ɫ�������

	// ��ɫ�����Ϣ
	out.put(1); // ���ID
	out.put(0x11); // ˮƽ|��ֱ��������
	out.put(0); // ������ID

	out.put(2); // ���ID
	out.put(0x11); // ˮƽ|��ֱ��������
	out.put(1); // ������ID

	out.put(3); // ���ID
	out.put(0x11); // ˮƽ|��ֱ��������
	out.put(1); // ������ID

	// д��Define Huffman Table (DHT)
	WriteWord(out, 0xFFC4);
	WriteWord(out, 0x01A2); // DHT�γ���

	// �������� - DC Luminance
	out.put(0); // ��ID
	out.write(reinterpret_cast<const char*>(&Standard_DC_Luminance_NRCodes), sizeof(Standard_DC_Luminance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_DC_Luminance_Values), sizeof(Standard_DC_Luminance_Values));

	// �������� - AC Luminance
	out.put(0x10); // ��ID
	out.write(reinterpret_cast<const char*>(&Standard_AC_Luminance_NRCodes), sizeof(Standard_AC_Luminance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_AC_Luminance_Values), sizeof(Standard_AC_Luminance_Values));

	// �������� - DC Chrominance
	out.put(0x01); // ��ID
	out.write(reinterpret_cast<const char*>(&Standard_DC_Chrominance_NRCodes), sizeof(Standard_DC_Chrominance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_DC_Chrominance_Values), sizeof(Standard_DC_Chrominance_Values));

	// �������� - AC Chrominance
	out.put(0x11); // ��ID
	out.write(reinterpret_cast<const char*>(&Standard_AC_Chrominance_NRCodes), sizeof(Standard_AC_Chrominance_NRCodes));
	out.write(reinterpret_cast<const char*>(&Standard_AC_Chrominance_Values), sizeof(Standard_AC_Chrominance_Values));

	// д��Start Of Scan (SOS)
	WriteWord(out, 0xFFDA);
	WriteWord(out, 12); // SOS�γ���
	out.put(3); // ��ɫ�������

	// ɨ��ͷ����Ϣ
	out.put(1); // ���ID
	out.put(0); // �ⲿDC��AC�Ĺ����������ID

	out.put(2); // ���ID
	out.put(0x11); // �ⲿDC��AC�Ĺ����������ID

	out.put(3); // ���ID
	out.put(0x11); // �ⲿDC��AC�Ĺ����������ID

	out.put(0); // ���Ե�ɨ��ͷ����Ϣ
	out.put(0x3F); // ���Ե�ɨ��ͷ����Ϣ
	out.put(0); // ���Ե�ɨ��ͷ����Ϣ
}

// д��һ��WORD������ (�����ֽڣ���λ��ǰ)
void JpegEncoder::WriteWord(std::ostream& out, unsigned short word) {
	out.put(static_cast<char>(word >> 8));
	out.put(static_cast<char>(word & 0xFF));
}

// ��ȡRGB
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
//RGBתΪYCbCr
void JpegEncoder::RGB_YCbCr(unsigned char(&R)[64], unsigned char(&G)[64], unsigned char(&B)[64], char(&y)[64], char(&cb)[64], char(&cr)[64])
{
	for (int i = 0; i < 64; i++) {
		y[i] = char(0.299 * R[i] + 0.587 * G[i] + 0.114 * B[i]);
		cb[i] = char(-0.1687 * R[i] - 0.3313 * G[i] + 0.5 * B[i] + 128);
		cr[i] = char(0.5 * R[i] - 0.4187 * G[i] - 0.0813 * B[i] + 128);
	}
}
//��ɢ���ұ任
void JpegEncoder::DCT(char(&temp)[64], double(&data)[64]) {
	double factor; // ��������factor���ڴ洢�淶����������
	// ��Ӧ��DCT֮ǰ���ȶ�8x8�����ؿ���С����С�����
	// ��ȥ128��Ϊ�˽��޷����ַ����ݵ�ȡֵ��Χ��0...255���任���з��ŵķ�Χ��-128...127��
	// ��������Ϊ������DCT�任�е�ֱ��������DC��������ʹ��DCT���DCϵ���ܱ��ƽ��ֵ������ƫ��
	for (int i = 0; i < 64; i++)
		temp[i] -= 128;
	// ����8x8�����ݿ飬�ֱ��ÿ��Ƶ��(u,v)�ɷֽ���DCT����
	for (int u = 0; u < 8; u++)
		for (int v = 0; v < 8; v++) {
			// ����DCT��ʽ�е�u��v������ǰ�����������
			if (u == 0) {
				if (v == 0)
					factor = 1.0 / 8; // ��u��v��Ϊ0ʱ��������1/8
				else
					factor = sqrt(2.0) / 8; // ��uΪ0��v��Ϊ0ʱ��������sqrt(2)/8
			}
			else {
				if (v == 0)
					factor = sqrt(2.0) / 8; // ��vΪ0��u��Ϊ0ʱҲ��sqrt(2)/8
				else
					factor = 2.0 / 8; // ��u��v����Ϊ0ʱ��������1/4����ȼ۵�2/8
			}
			double sum = 0; // Ϊÿ��Ƶ��(u,v)��ʼ���ۼӽ��

			// ���DCT��˫�غ�
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {
					// ����DCT��ʽ����cosine��
					double p1 = cos(((2 * (double)i + 1) * u * PI) / 16.0);
					double p2 = cos(((2 * (double)j + 1) * v * PI) / 16.0);
					// �ۼӱ任���������temp�Ŀռ���ֵ��cosine��
					sum += temp[i * 8 + j] * p1 * p2;
				}
			// Ӧ���������ӣ����������DCT����洢��data������
			data[u * 8 + v] = factor * sum;
		}
}

// ���ݹ�����������������
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
// ����������
void JpegEncoder::HuffmanEncode(char* data, int& lastDC, BitString* HuffmanTableDC, BitString* HuffmanTableAC, BitString* outStr, int& StrCounts)
{
	int count = 0, i = 1;
	// AC�����еġ�End of Block������������ı��
	BitString EOB = HuffmanTableAC[0x00];
	// 16���������AC������ʾ
	BitString SIXTEEN_ZEROS = HuffmanTableAC[0xF0];
	// ����DC�����Ĳ�ֵ
	int delta = int(data[0] - lastDC);
	// ������һ��DC����ֵ
	lastDC = data[0];

	// ���DC����û�б仯����ʹ��DC���е�0ֵ���������DC�����Ĳ�ֵ
	if (!delta)
		outStr[count++] = HuffmanTableDC[0];
	else {
		BitString bitcode = GetBitCode(delta);
		outStr[count++] = HuffmanTableDC[bitcode.len]; // DC�������ȱ��
		outStr[count++] = bitcode; // DC����ʵ�ʲ�ֵ�ı���
	}

	// �������64��DC�����Ƿ�Ϊ�㣬�����һ��DC������ʼ������
	int end = 63;
	while ((end > 0) && (data[end] == 0))
		end--;

	// ֱ���ҵ����һ������DC���������м��AC�������б���
	while (i <= end) {
		// ����ǰ�����
		int start = i;
		while ((data[i] == 0) && (i <= end))
			i++;
		// ���������������
		int zeronum = i - start;
		// �������16���㣬�������Ĺ���������
		if (zeronum >= 16) {
			for (int j = 1; j <= zeronum / 16; j++)
				outStr[count++] = SIXTEEN_ZEROS;
			zeronum = zeronum % 16;
		}
		// �������AC���������ݳ��Ⱥ�ʵ��ֵ
		BitString bitcode = GetBitCode(data[i]);
		outStr[count++] = HuffmanTableAC[(zeronum << 4) | bitcode.len]; // AC�������Ⱥ����������
		outStr[count++] = bitcode; // AC����ʵ�ʵı���
		i++;
	}

	// ������һ��AC����������64��λ�ã����EOB
	if (end != 63)
		outStr[count++] = EOB;

	// ���±��������ַ����ļ���
	StrCounts = count;
}

// ���bit����
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
// дbit��
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

// ����
void JpegEncoder::Quantization(double(&ytemp)[64], double(&cbtemp)[64], double(&crtemp)[64])
{
	for (int i = 0; i < 64; i++) {
		ytemp[i] = ytemp[i] / YQTable[i];
		cbtemp[i] = cbtemp[i] / CbCrQTable[i];
		crtemp[i] = crtemp[i] / CbCrQTable[i];
	}
}
// ZigZagɨ��
void JpegEncoder::ZigZag_Scan(char(&y)[64], char(&cb)[64], char(&cr)[64], double(&ytemp)[64], double(&cbtemp)[64], double(&crtemp)[64]) {
	for (int i = 0; i < 64; i++) {
		y[ZigZag[i]] = char(round(ytemp[i]));
		cb[ZigZag[i]] = char(round(cbtemp[i]));
		cr[ZigZag[i]] = char(round(crtemp[i]));
	}
}

//ѹ������
void JpegEncoder::EncodeToJpeg(const char* outfile, int quality_scale) {
	ofstream out;
	// �Զ�����дģʽ���ļ�
	out.open(outfile, ios::out | ios::binary);
	if (!out.is_open()) { // ����ļ���ʧ�ܣ�������󲢷���
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	// ��ʼ���������Ը����ض�������ϵ������ѹ��
	InitQualityTables(quality_scale);

	// д��JPEG�ļ�ͷ������ļ�
	WriteHeader(out);

	// ����DC��������һ��ֵ�����ڲ�ֱ���
	int lastY_DC = 0, lastCb_DC = 0, lastCr_DC = 0;
	int newByte = 0, newbytePos = 7; // �����ֽڱ���ĸ�������

	// ����ͼ���ÿ��8x8���ؿ�
	for (unsigned int y = 0; y < height; y += 8) {
		for (unsigned int x = 0; x < width; x += 8) {

			// �������ݴ洢����������������
			char ydata[64], cbdata[64], crdata[64];
			double ytemp[64], cbtemp[64], crtemp[64];
			unsigned char R[64], G[64], B[64];
			BitString outStr[128];
			int bitCounts;

			// ��ȡһ��8x8���RGB����
			GetRGB(R, G, B, x, y);
			// ת��RGB��YCbCrɫ�ʿռ�
			RGB_YCbCr(R, G, B, ydata, cbdata, crdata);
			// ��ɢ���ұ任��DCT��
			DCT(ydata, ytemp);
			DCT(cbdata, cbtemp);
			DCT(crdata, crtemp);
			// ����DCTϵ��
			Quantization(ytemp, cbtemp, crtemp);
			// ZigZag�����������ϵ����Ϊ�ر�����׼��
			ZigZag_Scan(ydata, cbdata, crdata, ytemp, cbtemp, crtemp);
			// ���Yͨ�����л������ر���
			HuffmanEncode(ydata, lastY_DC, Y_DC_Huff_Table, Y_AC_Huff_Table, outStr, bitCounts);
			// ����������д���ļ�
			WriteBitStr(out, outStr, bitCounts, newByte, newbytePos);
			// ���Cbͨ�����л������ر���
			HuffmanEncode(cbdata, lastCb_DC, CbCr_DC_Huff_Table, CbCr_AC_Huff_Table, outStr, bitCounts);
			// ����������д���ļ�
			WriteBitStr(out, outStr, bitCounts, newByte, newbytePos);
			// ���Crͨ�����л������ر���
			HuffmanEncode(crdata, lastCr_DC, CbCr_DC_Huff_Table, CbCr_AC_Huff_Table, outStr, bitCounts);
			// ����������д���ļ�
			WriteBitStr(out, outStr, bitCounts, newByte, newbytePos);
		}
	}

	// д��JPEGͼ��Ľ�β���
	WriteWord(out, 0xFFD9);
	// �ر��ļ�
	out.close();
}