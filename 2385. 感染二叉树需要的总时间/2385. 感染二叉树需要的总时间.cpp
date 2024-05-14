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
    TreeNode* start;
    unordered_map<int,TreeNode*> Hash;
    int target;
    void dfs(TreeNode* root,TreeNode* fa)
    {
        if(!root)return;

        Hash[root->val]=fa;

        if(root->val==target)
        start=root;

        dfs(root->left,root);
        dfs(root->right,root);

    }

    int func(TreeNode* root,TreeNode* fa,int depth)
    {
        if(!root)return 0;

        int dep = 0;

        if(root->left!=fa)
        dep=max(dep,func(root->left,root,depth+1));

        if(root->right!=fa)
        dep=max(dep,func(root->right,root,depth+1));

        if(Hash[root->val]!=fa)
        dep=max(dep,func(Hash[root->val],root,depth+1));

        return dep+1;

    }

    int amountOfTime(TreeNode* root, int start) {
        this->target = start;
        dfs(root,nullptr);
        return -1 + func(this->start,nullptr,0);
    }
};