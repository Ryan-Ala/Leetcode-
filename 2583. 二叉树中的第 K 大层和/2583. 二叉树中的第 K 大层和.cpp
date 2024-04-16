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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        priority_queue<long long> ans;
        queue<TreeNode*> st;
        st.push(root);
        TreeNode *tmp=nullptr;
        while(!st.empty())
        {
            long long cnt=0;
            int size=st.size();
            while(size--)
            {
                tmp=st.front();
                st.pop();
                cnt+=tmp->val;
                if(tmp->left)
                st.push(tmp->left);
                if(tmp->right)
                st.push(tmp->right);
            }
            ans.push(cnt);
        }
        if(ans.size()<k)
        return -1;
        //cout<<ans.size();
        while(--k)
        ans.pop();
        return ans.top();
    }
};