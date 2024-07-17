class Solution {
public:
    int minCut(string s) {
        int m = s.size();
        vector<vector<bool>> dp = vector<vector<bool>>(m,vector<bool>(m));
        for(int i = m-1;i>=0;i--)
        {
            for(int j = i;j<m;j++)
            {
                if(s[i]==s[j])
                dp[i][j] = i+1<j?dp[i+1][j-1]:1;
            }
        }

        vector<int> f = vector<int>(m,0x3f3f3f3f);
        f[0]=0;

        for(int i=0;i<m;i++)
        {
            if(dp[0][i])
            {
                f[i]=0;
            }
            else
            {
                for(int j=1;j<=i;j++)
                {
                    if(dp[j][i])
                    f[i]=min(f[i],f[j-1]+1);
                }
            }
        }
        return f[m-1];

    }
};