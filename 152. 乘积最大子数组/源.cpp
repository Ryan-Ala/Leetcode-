class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_dp(nums.size());
        vector<int> min_dp(nums.size());
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        int max_value = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if ((long)max_dp[i - 1] * nums[i] > INT_MAX || (long)max_dp[i - 1] * nums[i] < INT_MIN) {
                continue;
            }
            max_dp[i] = max(nums[i], max(max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]));
            min_dp[i] = min(nums[i], min(min_dp[i - 1] * nums[i], max_dp[i - 1] * nums[i]));
            max_value = max(max(max_dp[i], min_dp[i]), max_value);
        }

        return max_value;
    }
};