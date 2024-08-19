void perv(struct TreeNode* root, int* arr, int* i)
{
    if (!root)
        return;
    arr[(*i)++] = root->val;
    perv(root->left, arr, i);
    perv(root->right, arr, i);
}
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int getMinimumDifference(struct TreeNode* root)
{
    int arr[10000], i = 0;
    perv(root, arr, &i);
    qsort(arr, i, sizeof(int), cmp);
    int min = arr[1] - arr[0];
    for (int j = 2; j < i; j++)
    {
        if (arr[j] - arr[j - 1] < min)
            min = arr[j] - arr[j - 1];
    }
    return min;
}