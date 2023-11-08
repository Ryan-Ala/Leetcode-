class Solution {
    long ret = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
    bool dfs(TreeNode* root)
    {
        if (!root)
            return 1;
        bool cur = 0;


        bool left = dfs(root->left);

        if (!left)
            return 0;

        if (root->val <= ret)
            return 0;

        ret = root->val;

        bool right = dfs(root->right);
        if (!right)
            return 0;
        return 1;
    }
};