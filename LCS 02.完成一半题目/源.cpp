#include<iostream>
int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b;
}
int halfQuestions(int* questions, int questionsSize) {
    int nums[1001] = { 0 };  //��0��ʼ������Ҫ����1001����λ������
    for (int i = 0; i < questionsSize; i++)
    {
        nums[questions[i]]++;
    }
    qsort(nums, 1001, sizeof(int), cmp);
    int n = questionsSize / 2, i = 0;
    for (i = 0; i < 1001; i++)
    {
        if (n - nums[i] > 0)
            n -= nums[i];
        else
            break;
    }
    return i + 1;
}