/* 2252085 朱亚琨 信19 */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
    if (m == 1 || m == 2)
    {
        m += 12;
        y -= 1;
    }
    int c = y / 100;
    y = y - c * 100;
    int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
    while (w < 0)
        w += 7;
    return w % 7;
}

void calender(int y)
{
    cout << y << "年的日历:" << endl;
    cout << endl;
    int m_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//每个月的天数
    m_days[1] = 28 + (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
    int week_l;
    int week_m;
    int week_r;
    for (int m = 0; m < 10; m += 3)
    {                            //m控制月份,比实际月份小1
        //打印日历的表头
        cout << setiosflags(ios::right);
        cout << "           " << setw(2) << m + 1 << "月                            "
            << setw(2) << m + 2 << "月                            " << setw(2) << m + 3 << "月" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
        week_l = zeller(y, m + 1, 1);//求出左边月份的第一天是星期几
        week_m = zeller(y, m + 2, 1);//求出中间月份的第一天是星期几
        week_r = zeller(y, m + 3, 1);//求出右边月份的第一天是星期几
        int date_l = 1;
        int date_m = 1;
        int date_r = 1;
        while (date_l <= week_l + m_days[m] || date_m <= week_m + m_days[m + 1] || date_r <= week_r + m_days[m + 2])
        {
            //在范围内，打印
            int tag[23] = { 0 };//用来标记应该打印什么，整数表示打印日期，-1表示打印空格
            tag[7] = -1;   //界线
            tag[15] = -1;
            for (int p = 0; p < 7; ++p, ++date_l, ++date_m, ++date_r)
            {            //p为tag的指针
                //根据指针p给tag赋值
                if (date_l <= week_l + m_days[m])
                {
                    if (date_l < week_l)
                        tag[p] = -1;   //指针还没有到左边月份的第一天，应该打印空格
                    else
                        tag[p] = date_l - week_l;   //记录应该打印的日期
                }
                else //该打印的日期标记完了，其他的用空格补上
                    tag[p] = -1;
                if (date_m <= week_m + m_days[m + 1])
                {
                    if (date_m < week_m)
                        tag[p + 8] = -1;
                    else
                        tag[p + 8] = date_m - week_m;
                }
                else
                    tag[p + 8] = -1;
                //标记右边的情况，逻辑与前边的一样
                if (date_r <= week_r + m_days[m + 2])
                {
                    if (date_r < week_r)
                        tag[p + 16] = -1;
                    else
                        tag[p + 16] = date_r - week_r;
                }
                else
                    tag[p + 16] = -1;
            }
            //一行一行打印
            for (int i = 0; i < 23; ++i) {
                if (tag[i] == -1 || tag[i] == 0)
                    cout << "    ";   //没有日期要打印，打印四个空格
                else
                {   //有日期打印，打印日期             
                    cout << resetiosflags(ios::right);
                    cout << setiosflags(ios::left);
                    cout << setw(4) << tag[i];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int y;
    cout << "请输入年份[1900-2100]" << endl;
    cin >> y;
    calender(y);

    return 0;
}