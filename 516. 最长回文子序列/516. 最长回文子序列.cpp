class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(m));
        
        for(int i=m-1;i>=0;i--)
        {
            dp[i][i]=1;  //以i为开头,i为结尾的回文子序列，长度一定为1
            for(int j=i+1;j<m;j++)
            {
                if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1]+2;
                else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][m-1];
    }
};