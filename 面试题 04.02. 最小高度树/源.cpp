#include<iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* BST(int* nums, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = (left + right) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = BST(nums, left, mid - 1);
    root->right = BST(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return BST(nums, 0, numsSize - 1);
}