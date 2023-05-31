#include<iostream>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int temp = 0;
    for (int i = 0; i < imageSize; i++)
    {
        for (int j = 0; j < *imageColSize / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][*imageColSize - 1 - j];
            image[i][*imageColSize - 1 - j] = temp;
        }
    }
    for (int i = 0; i < imageSize; i++)
    {
        for (int j = 0; j < *imageColSize; j++)
        {
            if (image[i][j])
                image[i][j] = 0;
            else
                image[i][j] = 1;
        }
    }
    *returnSize = imageSize;
    *(returnColumnSizes) = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++)
    {
        (*returnColumnSizes)[i] = *imageColSize;
    }
    return image;
}


//Ò»´Î±éÀú
int** flipAndInvertImage1(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    for (int i = 0; i < imageSize; i++)
    {
        for (int j = 0; j < (*imageColSize + 1) / 2; j++)
        {
            if (image[i][j] == image[i][*imageColSize - 1 - j])
            {
                image[i][j] ^= 1;
                image[i][*imageColSize - 1 - j] ^= 1;
            }
            if (j == *imageColSize - 1 - j)
            {
                image[i][j] ^= 1;
                break;
            }
        }
    }
    *returnSize = imageSize;
    *(returnColumnSizes) = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++)
    {
        (*returnColumnSizes)[i] = *imageColSize;
    }
    return image;
}