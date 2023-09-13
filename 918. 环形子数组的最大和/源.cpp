class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxs = INT_MIN, mins = INT_MAX, length = nums.size(), sum = 0;
        vector<int> f(length + 1, -1000000), g(length + 1, 1000000);

        for (int i = 1; i <= length; i++)
        {
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            maxs = max(f[i], maxs);
            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
            mins = min(mins, g[i]);
            sum += nums[i - 1];
        }
        // 如果sum==mins,说明全部都是负数，那么答案存储在maxs中
        return sum == mins ? maxs : max(maxs, sum - mins);
    }
};