#include<iostream>
using namespace std;
int main() {
    int year, month;
    while (scanf("%d %d", &year, &month) != EOF)  //��scanf�������᷵��EOF���þ�ʽ����ѭ����������
    {
        if (month != 2)
        {

            switch (month)
            {
            case 4:
            case 6:
            case 9:
            case 11:cout << 30 << endl; break;
            default:cout << 31 << endl; break;
            }

        }
        else
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                cout << 29 << endl;
            else
                cout << 28 << endl;
        }
    }
    return 0;
}
// 64 λ������� printf("%lld")

#include <stdio.h>
int main()
{
    int y = 0;
    int m = 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (scanf("%d%d", &y, &m) != EOF)           //��scanf�������᷵��EOF���þ�ʽ����ѭ����������
    {
        int day = days[m - 1];
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        {
            if (m == 2)
                day += 1;
        }
        printf("%d\n", day);
    }
    return 0;
}