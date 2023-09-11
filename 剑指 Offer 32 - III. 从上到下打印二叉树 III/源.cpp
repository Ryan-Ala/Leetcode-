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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<TreeNode*> ret;
        int left = 0, right = 1, tmp, tag = 1;
        ret.push_back(root);
        while (left != right)
        {
            tmp = left;
            left = right;
            vector<int> res;
            for (int i = tmp; i < left; i++)
            {
                res.push_back(ret[i]->val);
                if (ret[i]->left)
                {
                    right++;
                    ret.push_back(ret[i]->left);
                }
                if (ret[i]->right)
                {
                    ret.push_back(ret[i]->right);
                    right++;
                }
            }
            if (tag % 2 == 0)
                reverse(res.begin(), res.end());
            tag++;
            ans.push_back(res);
        }
        return ans;

    }
};