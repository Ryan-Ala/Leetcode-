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
    void dfs(TreeNode* root,vector<int>& ret)
    {
        if(!root)return;

        dfs(root->left,ret);
        ret.push_back(root->val);
        dfs(root->right,ret);
    }

    vector<int> func(vector<int>&ret,int val)
    {
        int left=0,right=ret.size()-1, mid;
        while(left<right)  //二分查找的是数组中，比val小的第一个数
        {
            mid=left+((right-left+1)>>1);
            if(ret[mid]>val)
            right=mid-1;
            else
            left=mid;
        }
        if(ret[left]==val)
        return {val,val};

        if(ret[left]>val)   //数组左侧第一个
        return {-1,ret[left]};
        else if(left==ret.size()-1)  //数组右侧第一个
        return {ret[left],-1};
        return {ret[left],ret[left+1]};
        
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> ret;
        dfs(root,ret);
        vector<vector<int>> ans;
        for(auto &e:queries)
        {
            ans.push_back(func(ret,e));
        }
        return ans;

    }
};


/*
class Solution {
public:
    vector<int> dfs(TreeNode* root,int &val,int& min,int& max)
    {
        if(!root)
        {
            return {min,max};
        }
        if(val<root->val)
        {
            return dfs(root->left,val,min,root->val);
        }
        else if(val>root->val)
        {
            return dfs(root->right,val,root->val,max);
        }
        
        return {val,val};
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        int a=-1,b=-1;
        for(auto &e:queries)
        {
            ans.push_back(dfs(root,e,a,b));
        }
        return ans;
    }
}; 
 */