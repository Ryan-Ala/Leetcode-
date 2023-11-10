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
    int deap = -1;
    vector<int> ans;
public:
    void dfs(TreeNode* root, int height)
    {
        if (!root)
            return;
        if (height > deap)
        {
            deap++;
            ans.push_back(root->val);
        }
        if (ans[height] < root->val)
            ans[height] = root->val;
        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};