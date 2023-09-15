class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
    bool hash[7];
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ans;
    }
    void dfs(vector<int>& nums)
    {
        if (ret.size() == nums.size())
        {
            ans.push_back(ret);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!hash[i])
            {
                hash[i] = 1;
                ret.push_back(nums[i]);
                dfs(nums);
                ret.pop_back();
                hash[i] = 0;
            }
        }
    }
};