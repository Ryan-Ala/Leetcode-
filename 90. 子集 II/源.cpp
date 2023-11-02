class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
    bool Hash[10];
public:
    void dfs(vector<int>& nums, int pos)
    {
        ans.push_back(ret);
        for (int i = pos; i < nums.size(); i++)
        {
            if (Hash[i] == 1)
                continue;
            if (i == 0 || nums[i] != nums[i - 1] || Hash[i - 1] == 1)
            {
                Hash[i] = 1;
                ret.push_back(nums[i]);
                dfs(nums, i + 1);
                ret.pop_back();
                Hash[i] = 0;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};