#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

};

int fun(struct TreeNode* root)
{
    if (!root)
        return 0;
    int left = fun(root->left);
    int right = fun(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode* root) {
    return fun(root) != -1;
}