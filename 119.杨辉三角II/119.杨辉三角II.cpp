#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)   //rowIndex ��������ǵ���  *returnSize���������ÿ�е�Ԫ�ظ���
{

    int** ret = (int**)malloc(sizeof(int*) * (rowIndex + 1));   //��̬����һ����ά���飬�����ȷ�������
    for (int i = 0; i <= rowIndex; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * (i + 1));          //��̬�����˶�ά����ÿ���е�Ԫ��
        ret[i][i] = ret[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    *returnSize = rowIndex + 1; 
    return ret[rowIndex];   //���ض�̬�����������
}