/*����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/plus-one
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/



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