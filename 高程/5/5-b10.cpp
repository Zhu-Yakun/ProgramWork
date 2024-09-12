/* 2252085 ������ ��19 */
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
    cout << y << "�������:" << endl;
    cout << endl;
    int m_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//ÿ���µ�����
    m_days[1] = 28 + (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
    int week_l;
    int week_m;
    int week_r;
    for (int m = 0; m < 10; m += 3)
    {                            //m�����·�,��ʵ���·�С1
        //��ӡ�����ı�ͷ
        cout << setiosflags(ios::right);
        cout << "           " << setw(2) << m + 1 << "��                            "
            << setw(2) << m + 2 << "��                            " << setw(2) << m + 3 << "��" << endl;
        cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
        week_l = zeller(y, m + 1, 1);//�������·ݵĵ�һ�������ڼ�
        week_m = zeller(y, m + 2, 1);//����м��·ݵĵ�һ�������ڼ�
        week_r = zeller(y, m + 3, 1);//����ұ��·ݵĵ�һ�������ڼ�
        int date_l = 1;
        int date_m = 1;
        int date_r = 1;
        while (date_l <= week_l + m_days[m] || date_m <= week_m + m_days[m + 1] || date_r <= week_r + m_days[m + 2])
        {
            //�ڷ�Χ�ڣ���ӡ
            int tag[23] = { 0 };//�������Ӧ�ô�ӡʲô��������ʾ��ӡ���ڣ�-1��ʾ��ӡ�ո�
            tag[7] = -1;   //����
            tag[15] = -1;
            for (int p = 0; p < 7; ++p, ++date_l, ++date_m, ++date_r)
            {            //pΪtag��ָ��
                //����ָ��p��tag��ֵ
                if (date_l <= week_l + m_days[m])
                {
                    if (date_l < week_l)
                        tag[p] = -1;   //ָ�뻹û�е�����·ݵĵ�һ�죬Ӧ�ô�ӡ�ո�
                    else
                        tag[p] = date_l - week_l;   //��¼Ӧ�ô�ӡ������
                }
                else //�ô�ӡ�����ڱ�����ˣ��������ÿո���
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
                //����ұߵ�������߼���ǰ�ߵ�һ��
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
            //һ��һ�д�ӡ
            for (int i = 0; i < 23; ++i) {
                if (tag[i] == -1 || tag[i] == 0)
                    cout << "    ";   //û������Ҫ��ӡ����ӡ�ĸ��ո�
                else
                {   //�����ڴ�ӡ����ӡ����             
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
    cout << "���������[1900-2100]" << endl;
    cin >> y;
    calender(y);

    return 0;
}