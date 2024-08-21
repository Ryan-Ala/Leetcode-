#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
void derete(struct TreeNode* root, int* ret, int* i)
{
    if (!root)
        return;
    derete(root->left, ret, i);
    ret[(*i)++] = root->val;
    derete(root->right, ret, i);
}


bool isValidBST(struct TreeNode* root) {
    int ret[10000], i = 0;
    derete(root, ret, &i);
    for (int k = 0; k < i - 1; k++)
    {
        if (ret[k] >= ret[k + 1])
            return 0;
    }
    return 1;
}


//直接中序比较法
bool derete(struct TreeNode* root, long min, long max)
{
    if (!root)
        return 1;
    if (root->val >= max || root->val <= min)
        return 0;
    return derete(root->left, min, root->val) && derete(root->right, root->val, max);
}
bool isValidBST(struct TreeNode* root) {
    return derete(root, LONG_MIN, LONG_MAX);
}
