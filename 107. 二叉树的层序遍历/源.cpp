void Swap(int** a, int** b)
{
    int** temp = (*a);
    *a = *b;
    *b = *temp;
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode* res[2000];
    int left = 0, right = 0, temp = 0;
    res[right++] = root;
    (*returnSize) = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 2000);
    int** ret = (int**)malloc(sizeof(int*) * 2000);
    while (right != left)
    {

        temp = right;
        ret[(*returnSize)] = (int*)malloc(sizeof(int) * (temp - left));
        (*returnColumnSizes)[(*returnSize)++] = temp - left;
        for (int i = 0; i < temp - left; i++)
        {
            ret[*returnSize - 1][i] = res[i + left]->val;
            if (res[i + left]->left)
                res[right++] = res[i + left]->left;
            if (res[i + left]->right)
                res[right++] = res[i + left]->right;
        }
        left = temp;
    }
    int first = 0, last = (*returnSize) - 1;
    while (first < last)
    {
        temp = (*returnColumnSizes)[first];
        (*returnColumnSizes)[first++] = (*returnColumnSizes)[last];
        (*returnColumnSizes)[last--] = temp;
    }

    first = 0, last = (*returnSize) - 1;
    while (first < last)
    {
        int* temp = ret[first];
        ret[first++] = ret[last];
        ret[last--] = temp;
    }
    return ret;
}