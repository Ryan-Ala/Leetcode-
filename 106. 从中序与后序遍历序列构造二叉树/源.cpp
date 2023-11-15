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
            //�����������Ѱ���뵱ǰǰ�����preorder[size]��ͬ�Ľڵ�,�õ��±�i,��ô�±�i֮ǰ�����нڵ㶼Ϊnew����node��������
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