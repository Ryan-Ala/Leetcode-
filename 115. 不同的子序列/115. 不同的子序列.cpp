class Solution {
public:
    int numDistinct(string s, string t) {
        int s_num=s.size(),t_num=t.size();
        s=' '+s;
        t=' '+t;
        vector<vector<double>> dp = vector<vector<double>>(t_num+1,vector<double>(s_num+1));
        for(int i=0;i<=s_num;i++)
        dp[0][i]=1;

        for(int i=1;i<=t_num;i++)
        for(int j=1;j<=s_num;j++)
        
        {
            dp[i][j]+=dp[i][j-1];  //不包含s[j],那么从s[j-1],t[i] 中寻找
            if(t[i]==s[j])dp[i][j]+=dp[i-1][j-1];
        }
        return dp[t_num][s_num];
    }
};