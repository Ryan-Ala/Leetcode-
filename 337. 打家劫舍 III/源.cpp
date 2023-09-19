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
typedef vector<int> Type;
class Solution {
public:
    vector<int> dfs(TreeNode* root)
    {
        if (!root)
            return { 0,0 };
        Type left = dfs(root->left);
        Type right = dfs(root->right);

        Type ans(2);
        ans[1] = root->val + left[0] + right[0];
        ans[0] = *max_element(left.begin(), left.end()) + *max_element(right.begin(), right.end());
        return ans;
    }
    int rob(TreeNode* root) {
        Type ans = dfs(root);
        return *max_element(ans.begin(), ans.end());
    }
};