#include<iostream>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void prev(struct TreeNode* root, int* arr, int* i)
{
    if (!root)
        return;
    arr[(*i)++] = root->val;
    prev(root->left, arr, i);
    prev(root->right, arr, i);
}
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
bool findTarget(struct TreeNode* root, int k) {
    int arr[10000], i = 0;
    prev(root, arr, &i);
    qsort(arr, i, sizeof(int), cmp);
    int j = 0, s = i - 1;
    while (j < s)
    {
        if (arr[j] + arr[s] > k)
            s--;
        else if (arr[j] + arr[s] < k)
            j++;
        else
            return 1;
    }
    return 0;
}