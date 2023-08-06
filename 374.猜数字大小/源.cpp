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

//guess函数
//  - 1：我选出的数字比你猜的数字小 pick < num
//    1：我选出的数字比你猜的数字大 pick > num
//    0：我选出的数字和你猜的数字一样。恭喜！你猜对了！pick == num
//    返回我选出的数字。

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