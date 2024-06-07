class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        int m = coins.size();
        vector<vector<int>> dp =vector<vector<int>>(m+1,vector<int>(amount+1));

         for(int j=1;j<=amount;j++)
         dp[0][j]=0x3f3f3f3f;     //前0个硬币组成 总金额为j是不可能的，所以初始化为最大
         //但是组成 0块是可能的

        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i-1])
                dp[i][j]=min(dp[i][j],dp[i][j-coins[i-1]]+1);
            }
        }
        return dp[m][amount]>=0x3f3f3f3f?-1:dp[m][amount];
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int Max = amount + 1;
//         vector<vector<int>> dp(amount + 1,vector<vector<int>> 0x3f3f3f3f);
//         dp[0] = 0;

//         for (int j = 0; j <coins.size(); ++j) {
//             for (int i = 1; i <= amount; ++i) {
//                 if (coins[j] <= i) {
//                     dp[i][j] = min(dp[i][j], dp[i - coins[j]] + 1);
//                 }
//             }
//         }
//         return dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount];
//     }
// };