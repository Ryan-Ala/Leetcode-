#include<iostream>

int serch(int nums[], int numsize, int target)
{
	int right = numsize - 1, left = 0;
	int mid = left + (right - left) / 2;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
			return nums[mid];
	}
	return -1;        //Î´ÕÒµ½·µ»Ø-1;
}

int main()
{
	int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << serch(nums, 10, 6);
}