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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& size, int begin, int end)
    {
        if (begin > end) return nullptr;
        int i = begin;
        while (i <= end)
            //在中序遍历中寻找与当前前序遍历preorder[size]相同的节点,得到下标i,那么下标i之前的所有节点都为new——node的左子树
        {
            if (preorder[size] == inorder[i])
                break;
            i++;
        }

        TreeNode* new_node = new TreeNode(preorder[size++]);
        new_node->left = dfs(preorder, inorder, size, begin, i - 1);
        new_node->right = dfs(preorder, inorder, size, i + 1, end);
        return new_node;
    }
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return dfs(preorder, inorder, i, 0, preorder.size() - 1);
    }
};