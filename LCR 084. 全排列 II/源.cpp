class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
    bool hash[8];
public:
    void dfs(vector<int>& nums)
    {
        if (ret.size() == nums.size())
        {
            ans.push_back(ret);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash[i] == 1)
                continue;
            if (i == 0 || nums[i] != nums[i - 1] || hash[i - 1] == 1)
            {
                hash[i] = 1;
                ret.push_back(nums[i]);
                dfs(nums);
                ret.pop_back();
                hash[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ans;
    }
};