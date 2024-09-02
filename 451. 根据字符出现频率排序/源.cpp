struct lists
{
    char val;
    int count;;
};
int cmp(const void* a, const void* b)
{
    return ((struct lists*)a)->count < ((struct lists*)b)->count;
}
char* frequencySort(char* s) {
    struct lists list[62];
    for (int i = 0; i < 26; i++)
    {
        list[i].val = 'a' + i;
        list[i].count = 0;
    }
    for (int i = 26; i < 36; i++)
    {
        list[i].val = '0' + i - 26;
        list[i].count = 0;
    }
    for (int i = 36; i < 62; i++)
    {
        list[i].val = 'A' + i - 36;
        list[i].count = 0;
    }
    char* p = s;
    while (*s != '\0')
    {
        if (*s >= '0' && *s <= '9')
            list[26 + *s - '0'].count++;
        else if (*s >= 'a' && *s <= 'z')
            list[*s - 'a'].count++;
        else
            list[*s - 'A' + 36].count++;
        s++;
    }
    int k = 0;
    qsort(list, 62, sizeof(struct lists), cmp);
    for (int i = 0; i < 62; i++)
    {
        while (list[i].count--)
        {
            p[k++] = list[i].val;
        }
    }
    return p;
}