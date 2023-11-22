class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int ret = 1, left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ret *= nums[i];

            while (left <= i && ret >= k)
                ret /= nums[left++];

            count += i - left + 1;
        }
        return count;
    }
};

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
    void dfs(TreeNode* root, TreeNode* p, stack<TreeNode*>& sta)
    {
        if (!root)return;
        sta.push(root);
        if (root == p)
            return;
        if (root->val > p->val)
            return dfs(root->left, p, sta);
        else
            return dfs(root->right, p, sta);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sta1, sta2;

        dfs(root, p, sta1);
        dfs(root, q, sta2);

        while (sta1.size() != sta2.size())
        {
            if (sta1.size() > sta2.size())
                sta1.pop();
            else
                sta2.pop();
        }

        while (sta1.top() != sta2.top())
        {
            sta1.pop();
            sta2.pop();
        }
        return sta1.top();
    }
};