class Solution {

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        vector<TreeNode*> ret;
        int left = 0, right = 0, temp = 0;
        ret.push_back(root);
        while (left < ret.size())
        {

            temp = ret.size();
            ans.push_back(ret[temp - 1]->val);
            for (int i = left; i < temp; i++)
            {
                if ((ret[i]->left) != nullptr)
                    ret.push_back(ret[i]->left);
                if ((ret[i]->right) != nullptr)
                    ret.push_back(ret[i]->right);
            }
            left = temp;
        }
        return ans;
    }
};