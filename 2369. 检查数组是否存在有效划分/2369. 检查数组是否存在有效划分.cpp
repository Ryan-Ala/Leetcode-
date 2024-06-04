class Solution {
public:
    bool fun_1(int a,int b)
    {
        return a == b;
    }
    bool fun_2(int a,int b,int c)
    {
        return (a == b && b==c)||(a+1==b&&b+1==c);
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i+1]=dp[i-1]&&fun_1(nums[i],nums[i-1]);
            if(i>1)
            dp[i+1]=dp[i+1]||dp[i-2]&&fun_2(nums[i-2],nums[i-1],nums[i]);
        }
        return dp[n];
    }
};



/* class Solution {
public:
    bool dfs(vector<int>& nums,int x)
    {
        if(x==nums.size())
        return 1;
        if(x<nums.size()-1&&nums[x]==nums[x+1])
        {
            if(x<nums.size()-2&&nums[x+1]==nums[x+2]&&dfs(nums,x+3))
            return 1;
            else
            if(dfs(nums,x+2))
            return 1; 
        }
        else if(x<nums.size()-2&&nums[x]+1==nums[x+1]&&nums[x+1]+1==nums[x+2])
        {
            if(dfs(nums,x+3))
            return 1;
        }
        return 0;
    }
    bool validPartition(vector<int>& nums) {
        return dfs(nums,0);
    }
}; */