struct node
{
    int val;
    const char* sou;
    const char* tar;
};

int cmp(const void* a, const void* b)
{
    return ((struct node*)a)->val > ((struct node*)b)->val;
}

bool str_cmp(char* dir, const char* sour)
{
    while (*sour != '\0' && *dir != '\0')
    {
        if (*dir != *sour)
            return 0;
        dir++;
        sour++;
    }
    if (*sour == '\0')
        return 1;
    return 0;
}

char* findReplaceString(char* s, int* indices, int indicesSize, const char** sources, int sourcesSize, const char** targets, int targetsSize) {
    struct node* ret = (struct node*)malloc(sizeof(struct node) * indicesSize);
    for (int i = 0; i < indicesSize; i++)
    {
        ret[i].val = indices[i];
        ret[i].sou = sources[i];
        ret[i].tar = targets[i];
    }
    qsort(ret, indicesSize, sizeof(struct node), cmp);
    char* ans = (char*)calloc(strlen(s) * 3, sizeof(char));
    const char* pos = NULL;
    int slow = 0, fast = 0, i = 0, num = strlen(s), k = 0;

    while (fast < num && i < indicesSize)
    {

        while (fast != ret[i].val && fast < num)
        {
            ans[slow++] = s[fast++];
        }
        k = strlen(ret[i].sou);
        if (fast < num && str_cmp(&s[fast], ret[i].sou))
        {

            pos = ret[i].tar;
            while (*pos != '\0')
            {
                ans[slow++] = *pos++;
            }
            fast += k;
        }
        else
        {
            while (k--)
            {
                ans[slow++] = s[fast++];
            }
        }
        i++;
    }
    while (fast < num)
    {
        ans[slow++] = s[fast++];
    }

    return ans;
}