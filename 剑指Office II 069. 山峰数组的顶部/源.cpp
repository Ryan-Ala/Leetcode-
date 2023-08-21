#include<iostream>

int peakIndexInMountainArray(int* arr, int arrSize) {
    int max = arr[0], i = 0;
    for (; i < arrSize; i++)
    {
        if (arr[i + 1] <= arr[i])
            return i;
    }
    return 0;
}

int peakIndexInMountainArray(int* arr, int arrSize) {
    int left = 1, right = arrSize - 2, mid = 0, ans = 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            ans = mid + 1;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}

int peakIndexInMountainArray(int* arr, int arrSize) {
    int left = 0, right = arrSize - 1, mid = 0, ans = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            ans = mid + 1;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}

int main()
{
    int arr[] = { 0,1,0 };
    peakIndexInMountainArray(arr, 4);
}