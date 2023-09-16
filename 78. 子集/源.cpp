class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int pos)
    {
        ans.push_back(ret);
        for (int i = pos; i < nums.size(); i++)
        {
            ret.push_back(nums[i]);
            dfs(nums, i + 1);
            ret.pop_back();
        }
    }
};