class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int m =nums.size();
        vector<long long> dp(nums.begin(),nums.end());
        long long sum = 0;
        for(int i=m-1;i>0;i--)
        {
            if(dp[i]>=dp[i-1])
            dp[i-1]+=dp[i];
            sum=max(sum,dp[i-1]);
        }
        return sum;
    }
};