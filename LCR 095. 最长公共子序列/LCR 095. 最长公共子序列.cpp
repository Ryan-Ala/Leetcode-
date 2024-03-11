class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size(),t2=text2.size();
        vector<vector<int>> dp =vector<vector<int>>(t1+2,vector<int>(t2+2));
        string s1=" "+text1,s2=" "+text2;
        for(int i=1;i<=t1;i++)
        for(int j=1;j<=t2;j++)
        {
            if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[t1][t2];
    }
};