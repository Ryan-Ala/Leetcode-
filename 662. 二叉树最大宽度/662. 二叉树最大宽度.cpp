/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*,unsigned long long>> ret;
        ret.push_back({root,1ll});
        unsigned long long ans=1;

        while (ret.size()) 
        {
            vector<pair<TreeNode*,unsigned long long>> cnt;
            for(auto &[tmp,num]:ret)
            {
                if(tmp->left)
                    cnt.push_back({tmp->left,num*2});
                if(tmp->right)
                    cnt.push_back({tmp->right,num*2+1});
            }
            ans = max(ans,ret[ret.size()-1].second-ret[0].second+1);
            swap(ret,cnt);
        }
        return ans;
    }
};
