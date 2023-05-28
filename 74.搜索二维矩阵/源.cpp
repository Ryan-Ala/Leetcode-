#include<iostream>

//¶ş·Ö²éÕÒ
int find(int* nums, int numsize, int target)
{
    int left = 0, right = numsize - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (target < nums[mid])
        {
            right = mid - 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    for (int i = 0; i < matrixSize; i++)
    {
        if (find(matrix[i], *matrixColSize, target))
            return 1;
    }
    return 0;
}