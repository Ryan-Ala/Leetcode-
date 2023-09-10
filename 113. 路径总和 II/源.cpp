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
    int in_tar;
public:
    void inorder(TreeNode* root, vector<vector<int>>& ans, vector<int>& ret, int& sum)
    {
        if (!root)
            return;
        ret.push_back(root->val);
        sum += root->val;
        if (sum == in_tar && !root->right && !root->left)
            ans.push_back(ret);
        inorder(root->left, ans, ret, sum);
        inorder(root->right, ans, ret, sum);
        ret.pop_back();
        sum -= root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        in_tar = targetSum;
        vector<vector<int>> ans;
        vector<int> ret;
        inorder(root, ans, ret, sum);
        return ans;
    }
};