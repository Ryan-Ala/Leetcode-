/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root)
    {
        if (root->val == 2)
            return fun(root->left) || fun(root->right);
        else if (root->val == 3)
            return fun(root->left) && fun(root->right);
        if (root->val)
            return 1;
        return 0;
    }
    bool evaluateTree(TreeNode* root) {
        return fun(root);
    }
};