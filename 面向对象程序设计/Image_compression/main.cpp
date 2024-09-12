#include<iostream>
#include "PicReader.h"
#include "compression.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "������3������" << endl;
		return -1;
	}

	if (!strcmp(argv[1], "-read")) {
		PicReader imread;
		BYTE* data = nullptr;
		UINT x, y;
		imread.readPic(argv[2]);
		imread.getData(data, x, y);
		imread.showPic(data, x, y);
		delete[] data;
		data = nullptr;
	}
	else if (!strcmp(argv[1], "-compress")) {
		string outfile = "";
		outfile += argv[2];
		size_t dotPos = outfile.find_last_of('.');
		// ����ҵ��� . ������ . �����ַ�
		if (dotPos != string::npos && dotPos + 1 < outfile.size())  // �ѵ�ź���������滻Ϊ'jpg'
			outfile.replace(dotPos + 1, outfile.size() - dotPos - 1, "jpg");
		else    // ���û���ҵ� . ����ֱ�����ַ���ĩβ���'.jpg'
			outfile += ".jpg";

		int quality_scale;
		cout << "�������ļ�ѹ���̶ȣ�����Խ��ѹ������ļ����ԽС" << endl;
		cin >> quality_scale;
		PicReader imread;
		BYTE* data = nullptr;
		UINT x, y;
		imread.readPic(argv[2]);
		imread.getData(data, x, y);
		JpegEncoder encoder(data, x, y);
		encoder.EncodeToJpeg((const char*)&outfile[0], quality_scale);
		//delete[] data;
		//data = nullptr;
		cout << "ѹ���ɹ���" << endl;
	}
	//else if (strcmp(argv[1], "-decompress") == 0) {
	//	
	//}
	else {
		cout << "ָ���д���" << endl;
		return -1;
	}
	return 0;
}