#include<iostream>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int findBottomLeftValue(struct TreeNode* root) {
    if (!root)
    {
        return NULL;
    }
    struct TreeNode* res[10000];
    int left = 0, right = 0, temp = 0, ret = 0;
    res[right++] = root;
    while (right != left)
    {
        temp = right;
        for (int i = 0; i < temp - left; i++)
        {
            if (res[i + left]->left)
                res[right++] = res[i + left]->left;
            if (res[i + left]->right)
                res[right++] = res[i + left]->right;
        }
        if (right == temp)
            break;
        ret = temp;
        left = temp;
    }
    return res[ret]->val;
}


void prev(struct TreeNode* root, int height, int* max_height, int* max_left)
{
    if (!root)
        return;
    height++;
    if (height > *max_height)
    {
        *max_height = height;
        *max_left = root->val;
    }
    prev(root->left, height, max_height, max_left);
    prev(root->right, height, max_height, max_left);
}
int findBottomLeftValue(struct TreeNode* root) {
    int max_height = 0, max_left = 0;
    prev(root, 0, &max_height, &max_left);
    return max_left;
}