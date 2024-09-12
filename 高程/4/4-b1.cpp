/* 2252085 朱亚琨 信19 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    double a, b, c, b10, b11, b12;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;

    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> a;
    c = a + 0.000001;
    b = c / 10;
    a1 = int(b / 1e8) % 10;
    a2 = int(b / 1e7) % 10;
    a3 = int(b / 1e6) % 10;
    a4 = int(b / 1e5) % 10;
    a5 = int(b / 1e4) % 10;
    a6 = int(b / 1e3) % 10;
    a7 = int(b / 100) % 10;
    a8 = int(b / 10) % 10;
    a9 = int(b - a1 * 1e8) % 10;
    b10 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9;
    b11 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - int(b10 * 10) * 0.1;
    b12 = b - a1 * 1e8 - a2 * 1e7 - a3 * 1e6 - a4 * 1e5 - a5 * 1e4 - a6 * 1e3 - a7 * 100 - a8 * 10 - a9 - int(b10 * 10) * 0.1 - int(b11 * 100) * 0.01;
    a10 = int(b10 * 10);
    a11 = int(b11 * 100);
    a12 = int(b12 * 1000);

    cout << "大写结果是:" << endl;
    if (a1)
    {
        daxie(a1, 0);
        cout << "拾";
    }
    if (a2)
    {
        daxie(a2, 0);
        cout << "亿";
    }
    if(!a2 && a1)
        cout << "亿";
    if (a3)
    {
        daxie(a3, 0);
        cout << "仟";
    }
    if(!a3 && (a1 || a2) && (a4 || a5 || a6))
        daxie(0, 1);
    if (a4)
    {
        daxie(a4, 0);
        cout << "佰";
    }
    if(!a4 && a3 && (a5 || a6))
        daxie(0, 1);
    if (a5)
    {
        daxie(a5, 0);
        cout << "拾";
    }
    if(!a5 && (a3 || a4) && a6)
        daxie(0, 1);
    if (a6)
    {
        daxie(a6, 0);
        cout << "万";
    }
    if(!a6 && (a3 || a4 || a5))
        cout << "万";
    if (a7)
    {
        daxie(a7, 0);
        cout << "仟";
    }
    if (!a7 && (a8 || a9 || a10) && (a1 || a2 || a3 || a4 || a5 || a6))
        daxie(0, 1);
    if (a8)
    {
        daxie(a8, 0);
        cout << "佰";
    }
    if (!a8 && a7 && (a9 || a10))
        daxie(0, 1);
    if (a9)
    {
        daxie(a9, 0);
        cout << "拾";
    }
    if(!a9 && a8 && a10)
        daxie(0, 1);
    if (a10)
    {
        daxie(a10, 0);
        cout << "圆";
    }
    if (!a10)
    {
        if (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9)
            cout << "圆";
        if (!(a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a11 || a12))
        {
            daxie(0, 1);
            cout << "圆";
        }
    }
    if (a11)
    {
        daxie(a11, 0);
        cout << "角";
    }
    if(!a11 && a12 && (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8 || a9 || a10))
        daxie(0, 1);
    if (a12)
    {
        daxie(a12, 0);
        cout << "分" << endl;
    }
    if(!a12)
        cout << "整" << endl;

    return 0;
}