#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char** words, int wordsSize, int* returnSize) {
    int ret[26], min[26];
    memset(ret, 0, sizeof(ret));
    memset(min, 127, sizeof(min));
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; words[i][j] != '\0'; j++)
        {
            ret[words[i][j] - 'a']++;
        }
        for (int k = 0; k < 26; k++)
        {

            min[k] = fmin(min[k], ret[k]);
        }
        memset(ret, 0, sizeof(ret));

    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += min[i];
    }
    char** res = (char**)malloc(sizeof(char*) * sum);
    *returnSize = 0;
    for (int i = 0; i < 26; i++)
    {

        for (int j = 0; j < min[i]; j++)
        {
            res[*returnSize] = (char*)malloc(sizeof(char) * 2);
            res[(*returnSize)][0] = i + 'a';
            res[(*returnSize)][1] = '\0';
            (*returnSize)++;
        }
    }
    return res;
}
