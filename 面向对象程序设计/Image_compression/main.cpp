#include<iostream>
#include "PicReader.h"
#include "compression.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "请输入3个参数" << endl;
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
		// 如果找到了 . ，并且 . 后还有字符
		if (dotPos != string::npos && dotPos + 1 < outfile.size())  // 把点号后面的内容替换为'jpg'
			outfile.replace(dotPos + 1, outfile.size() - dotPos - 1, "jpg");
		else    // 如果没有找到 . ，则直接在字符串末尾添加'.jpg'
			outfile += ".jpg";

		int quality_scale;
		cout << "请输入文件压缩程度，数字越大，压缩后的文件体积越小" << endl;
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
		cout << "压缩成功！" << endl;
	}
	//else if (strcmp(argv[1], "-decompress") == 0) {
	//	
	//}
	else {
		cout << "指令有错误" << endl;
		return -1;
	}
	return 0;
}