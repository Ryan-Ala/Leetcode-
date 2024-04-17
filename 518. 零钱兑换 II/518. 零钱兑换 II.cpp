// class Solution {
// public:
//     int ans,amount,m;
//     int change(int amount, vector<int>& coins) {
//         int m =coins.size();
//         vector<int> dp = vector<int> (amount+1);
//         dp[0]=1;
//         for(int i=1;i<=m;i++)
//         for(int j=coins[i-1];j<=amount;j++)
//         {
//             dp[j]+=dp[j-coins[i-1]];
//         }
//         return dp[amount];
//     }
// };


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        vector<vector<int>> dp = vector<vector<int>>(m+1,vector<int>(amount+1));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i-1])
                dp[i][j]+=dp[i][j-coins[i-1]];
            }
        }
        return dp[m][amount];

    }
}; 


/* class Solution {
public:
    int ans,amount,m;
    void dfs(vector<int>& coins,int sum,int pos)
    {
        if(sum>amount)
        return;
        if(sum==amount)
        {
            ans++;
            return;
        }
        for(int i=pos;i<m;i++)
        {
            
            dfs(coins,sum+coins[i],i);

        }
    }
    int change(int amount, vector<int>& coins) {
        this->amount = amount;
        m = coins.size();
        dfs(coins,0,0);
        return ans;
    }
}; */