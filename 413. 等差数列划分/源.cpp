class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        int length = nums.size();

        vector<int> dp(length);
        for (int i = 2; i < length; i++)
        {
            //如果当前位置与前两个成等差数列，那么也与 以前两个为结尾的所有等差数列呈等差数列，+1加的是当前位置与前两个数呈等差数列
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }
        return sum;
    }
};