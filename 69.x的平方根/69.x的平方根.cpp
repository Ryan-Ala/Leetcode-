#include<math.h>

int mySqrt(int x) {
    if (x == 0)
        return 0;
    else
    {
        int num = (int)(exp((double)1 / 2 * log(x)));//exp(��eΪ�׵�ָ����ʽ�������ͷ�ļ�math.h)
        if ((long long)(num + 1) * (num + 1) <= x)
            return num + 1;
        else
            return num;
    }

}