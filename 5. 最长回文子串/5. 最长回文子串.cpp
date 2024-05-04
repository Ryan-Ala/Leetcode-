class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();

        vector<vector<bool>> dp(length,vector<bool>(length));
        int len_max=0,begin;

        for(int i=length-1;i>=0;i--)
        {
            for(int j=i;j<length;j++)
            {
                if(s[i]==s[j])
                  dp[i][j]=i+1<j?dp[i+1][j-1]:1;
                if(dp[i][j]&&j-i+1>len_max)
                {
                    begin=i;
                    len_max=j-i+1;
                }

            }
        }
        return s.substr(begin,len_max);
    }
};