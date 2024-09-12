/* 信19 2252085 朱亚琨*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	   //本题先估算三个数的大致范围，降低复杂度（范围其实可以更精确，不过没必要）
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;   //三个三位数的各个数
	int total = 0;
	for (int i = 123; i < 600; i++)     //根据百位数估算 600+700+800=2100 > 1953,
	{                         // 500+600+700=1800 < 1953,因此三个数中最小的数一定 < 600,易知一定 > 123
		a1 = i / 100;
		a2 = (i - a1 * 100) / 10;
		a3 = i % 10;
		if ((a1 != a2) && (a1 != a3) && (a2 != a3) && a1 && a2 && a3)
		{
			for (int j = 500; j < 900; j++)   //与第一层循环同理，估算得 j > 500, 同时三个数中 中间的数一定 < 900
			{
				b1 = j / 100;
				b2 = (j - b1 * 100) / 10;
				b3 = j % 10;
				if ((j > i) && (b1 - b2) && (b1 - b3) && (b2 - b3) && (a1 - b1) && (a1 - b2) && (a1 - b3)
					&& (a2 - b1) && (a2 - b2) && (a2 - b3) && (a3 - b1) && (a3 - b2) && (a3 - b3) && b1 && b2 && b3)
				{
					int k = 1953 - i - j;           //此处没有必要再嵌一层循环
					c1 = k / 100;
					c2 = ( k- c1 * 100) / 10;
					c3 = k % 10;
					if ((c1 - c2) && (c1 - c3) && (c2 - c3) && (c1 - a1) && (c1 - a2) && (c1 - a3)
						&& (c2 - a1) && (c2 - a2) && (c2 - a3) && (c3 - a1) && (c3 - a2) && (c3 - a3)
						&& (c1 - b1) && (c1 - b2) && (c1 - b3) && (c2 - b1) && (c2 - b2) && (c2 - b3)
						&& (c3 - b1) && (c3 - b2) && (c3 - b3) && (k > j) && (k <= 987) && c1 && c2 && c3)
					{
						total++;
						cout << "No." << setw(3) << total << " : " << i << "+" << j << "+" << k << "=1953" << endl;
					}
				}
			}
		}
	}
	cout << "total=" << total << endl;

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
