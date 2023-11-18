/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int count = 0;
    set<int> Hash;
public:
    void Inorder(TreeNode* root)
    {
        if (!root) return;
        Inorder(root->left);
        Hash.insert(root->val);
        Inorder(root->right);
    }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        int n = ops.size();
        Inorder(root);
        for (int i = n - 1; i >= 0; i--)
        {
            while (1)
            {
                auto it = Hash.lower_bound(ops[i][1]);
                if (it == Hash.end() || (*it) > ops[i][2])
                    break;
                Hash.erase(it);
                if (ops[i][0] == 1)
                    count++;

            }
        }
        return count;

    }
};