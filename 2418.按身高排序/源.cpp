#include<iostream>
using namespace std;

    /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct list
{
    int height;
    char name[21];
}list;
int cmp(const void* a, const void* b)
{
    return ((struct list*)a)->height < ((struct list*)b)->height;
}
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) 
{
    struct list* con = (struct list*)malloc(sizeof(struct list) * namesSize);
    for (int i = 0; i < namesSize; i++)
    {
        strcpy(con[i].name, names[i]);
        con[i].height = heights[i];
    }
    qsort(con, namesSize, sizeof(struct list), cmp);
    char** ret = (char**)malloc(sizeof(char*) * namesSize);
    for (int i = 0; i < namesSize; i++)
    {
        ret[i] = (char*)malloc(sizeof(char) * (strlen(con[i].name) + 1));
        strcpy(ret[i], con[i].name);
    }
    free(con);
    *returnSize = namesSize;
    return ret;
}