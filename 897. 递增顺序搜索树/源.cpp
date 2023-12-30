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
    void order(TreeNode* root, TreeNode** ret, int& i)
    {
        if (!root)
            return;
        order(root->left, ret, i);
        ret[i++] = root;
        order(root->right, ret, i);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ret[100];
        int count = 0;
        order(root, ret, count);
        for (int i = 0; i < count - 1; i++)
        {
            ret[i]->left = nullptr;
            ret[i]->right = ret[i + 1];
        }
        ret[count - 1]->left = nullptr;
        ret[count - 1]->right = nullptr;
        return ret[0];
    }
};