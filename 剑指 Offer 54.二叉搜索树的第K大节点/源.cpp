#include<iostream>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int Inorder(struct TreeNode* root, int* i, int target)
{
    if (!root)
        return INT_MIN;
    int a = Inorder(root->right, i, target);
    if (++(*i) == target)
        return root->val;
    int b = Inorder(root->left, i, target);
    if (a != INT_MIN)
        return a;
    if (b != INT_MIN)
        return b;
    return INT_MIN;
}


int kthLargest(struct TreeNode* root, int k) {
    int i = 0;
    return Inorder(root, &i, k);
}