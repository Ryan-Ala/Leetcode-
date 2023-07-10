
#include<iostream>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int min_depth = INT_MAX;
    if (root->left != NULL)
        min_depth = fmin(minDepth(root->left), min_depth);
    if (root->right != NULL)
        min_depth = fmin(minDepth(root->right), min_depth);
    return min_depth + 1;
}