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
    int ans;
    void dfs(TreeNode* root,int min,int max)
    {
        if(!root)return;
        int val = root->val;
        
        ans=fmax(ans, fmax( abs(val-min) , abs(val-max)));
        int now_min=fmin(min,val),now_max=fmax(max,val);
        dfs(root->left,now_min,now_max);
        dfs(root->right,now_min,now_max);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return ans;
    }
};