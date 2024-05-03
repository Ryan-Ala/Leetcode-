class Solution {
public:
    bool checkPartitioning(string s) {
        int m = s.size();
        vector<vector<bool>> dp = vector(m,vector<bool>(m));

        for(int i=m-1;i>=0;i--)
        {
            for(int j = i;j<m;j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=i+1<j?dp[i+1][j-1]:1;
                }
            }
        }

        for(int i =0;i<m;i++)
        for(int j=i+2;j<m;j++)
        {
            if(dp[0][i]&&dp[i+1][j-1]&&dp[j][m-1])
            return 1;
        }
        return 0;

    }
};