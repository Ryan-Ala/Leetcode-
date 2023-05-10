/*给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	for (int i = 1; i <= digitsSize; i++)
	{
		if (digits[digitsSize - i] == 9)
		{
			if (i != digitsSize)
			{
				digits[digitsSize - i] = 0;
				if (digits[digitsSize - i - 1] != 9)
				{
					*returnSize = digitsSize;
					digits[digitsSize - i - 1] += 1;
					return digits;
				}
			}
			else
			{
				*returnSize = digitsSize + 1;
				int* p = (int*)malloc((digitsSize + 1) * sizeof(int));
				p[0] = 1;
				for (int i = 1; i < digitsSize + 1; i++)
				{
					p[i] = 0;
				}
				return p;
			}
		}
		else
		{
			*returnSize = digitsSize;
			digits[digitsSize - i] += 1;
			return digits;
		}
	}
	return 0;
}