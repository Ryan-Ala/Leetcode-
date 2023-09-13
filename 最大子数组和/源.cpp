class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_num = INT_MIN;
        vector<int> dp(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            max_num = max(dp[i], max_num);
        }
        return max_num;
    }
};