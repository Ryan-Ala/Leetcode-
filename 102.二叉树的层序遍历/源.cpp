#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    struct TreeNode* res[2000];
    int** ret = (int**)malloc(sizeof(int*) * 2000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 2000);
    int left = 0, right = 0, temp = 0;
    res[right++] = root;
    while (right != left)
    {
        temp = right;
        ret[(*returnSize)] = (int*)malloc(sizeof(int) * (right - left));
        (*returnColumnSizes)[(*returnSize)] = right - left;
        for (int i = 0; i < temp - left; i++)
        {
            ret[*returnSize][i] = (res[i + left])->val;
            if (res[i + left]->left)
                res[right++] = res[i + left]->left;
            if (res[i + left]->right)
                res[right++] = res[i + left]->right;
        }
        left = temp;
        (*returnSize)++;
    }
    return ret;
}