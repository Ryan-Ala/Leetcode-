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
            //�����������Ѱ���뵱ǰǰ�����preorder[size]��ͬ�Ľڵ�,�õ��±�i,��ô�±�i֮ǰ�����нڵ㶼Ϊnew����node��������
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