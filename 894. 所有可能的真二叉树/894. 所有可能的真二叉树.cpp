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
    vector<vector<TreeNode*>> mem_left = vector<vector<TreeNode*>>(20);
    vector<vector<TreeNode*>> mem_right = vector<vector<TreeNode*>>(20);

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)return {};
        if(n==1)return{new TreeNode()};
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2)
        {
            if(mem_left[i].size()==0)
            mem_left[i] = allPossibleFBT(i);
            if(mem_right[n-1-i].size()==0)
            mem_right[n-1-i] = allPossibleFBT(n-1-i);

            for(auto L :mem_left[i])
            for(auto R :mem_right[n-1-i])
            ans.push_back(new TreeNode(0,L,R));

        }
        return ans;
    }
};