class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& ret, vector<int>& nums, int pos)
    {
        if (ret.size() > 1)
        {
            ans.push_back(ret);
        }
        int flag = 0;
        for (int i = pos; i < nums.size(); i++)
        {
            if (ret.back() <= nums[i])
            {
                ret.push_back(nums[i]);
                fun(ans, ret, nums, i + 1);
                flag = 1;
                ret.pop_back();
            }
            else
                fun(ans, ret, nums, i + 1);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            vector<int> ret;
            ret.push_back(nums[i]);
            fun(ans, ret, nums, i + 1);

        }

        set<vector<int>>s(ans.begin(), ans.end());
        ans.assign(s.begin(), s.end());

        return  ans;
    }
};