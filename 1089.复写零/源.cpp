#include<iostream>
void duplicateZeros(int* arr, int arrSize) {
    int* copy = (int*)malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        copy[i] = arr[i];
    }
    int k = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (copy[i] == 0)
        {
            if (k == arrSize - 1)
            {
                arr[k++] = copy[i];
                break;
            }
            arr[k++] = copy[i];
            if (k == arrSize - 1)
            {
                arr[k++] = copy[i];
                break;
            }
            arr[k++] = copy[i];
        }
        else
        {
            if (k == arrSize - 1)
            {
                arr[k++] = copy[i];
                break;
            }
            arr[k++] = copy[i];
        }
    }
}