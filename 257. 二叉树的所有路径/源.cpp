class Solution {
    vector<string> ans;

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string ret;
        dfs(root, ret);
        return ans;
    }
    void dfs(TreeNode* root, string ret)
    {
        ret += to_string(root->val);
        if (!root->left && !root->right)
        {
            ans.push_back(ret);
            return;
        }
        ret += "->";
        if (root->left)
            dfs(root->left, ret);
        if (root->right)
            dfs(root->right, ret);
    }
};