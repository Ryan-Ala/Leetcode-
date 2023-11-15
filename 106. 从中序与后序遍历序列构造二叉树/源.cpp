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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int& size, int begin, int end)
    {
        if (begin > end) return nullptr;
        int i = end;
        while (i >= 0)
            //在中序遍历中寻找与当前前序遍历preorder[size]相同的节点,得到下标i,那么下标i之前的所有节点都为new——node的左子树
        {
            if (postorder[size] == inorder[i])
                break;
            i--;
        }

        TreeNode* new_node = new TreeNode(postorder[size--]);
        new_node->right = dfs(inorder, postorder, size, i + 1, end);
        new_node->left = dfs(inorder, postorder, size, begin, i - 1);
        return new_node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size() - 1;
        return dfs(inorder, postorder, size, 0, size);
    }
};