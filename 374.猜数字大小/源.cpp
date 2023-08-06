#include<iostream>
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int n)
{
    ;
}

//guess����
//  - 1����ѡ�������ֱ���µ�����С pick < num
//    1����ѡ�������ֱ���µ����ִ� pick > num
//    0����ѡ�������ֺ���µ�����һ������ϲ����¶��ˣ�pick == num
//    ������ѡ�������֡�

int guessNumber(int n) {
    int left = 0, right = n - 1, mid = 0;
    while (1)
    {
        mid = left + (right - left) / 2;
        if (guess(mid) == 1)
        {
            left = mid + 1;
        }
        else if (guess(mid) == -1)
        {
            right = mid - 1;
        }
        else
            return mid;
    }
    return 0;
}