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
private:
    int sum = 0;
public:
    void fun(TreeNode* root, int max)
    {
        if (!root)
            return;
        if (root->val > max)
            max = root->val;
        if (root->val >= max)
            sum++;
        fun(root->left, max);
        fun(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        int x = INT_MIN;
        fun(root, x);
        return sum;
    }
};