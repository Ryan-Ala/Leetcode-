class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;

        function<int(TreeNode*)> dfs=[&](TreeNode *root)->int{
            if(!root)return 0;
            int left=dfs(root->left)+1;
            int right=dfs(root->right)+1;

            ans=max(ans,left+right-1);  // 计算左右节点数，路径需要再对ans--,在返回时减去
            return max(left,right);
        };

        dfs(root);

        return ans-1;
    }
};