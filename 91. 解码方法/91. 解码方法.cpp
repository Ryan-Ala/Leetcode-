class Solution {
public:
    int numDecodings(string s) {
        int m=s.size();
        vector<int> dp = vector<int>(m+2);
        if(s[0]!='0')
        dp[0]=1;
        else
        return 0;
        if(s[1]!='0')
        {
            dp[1]+=dp[0];
            if((s[1]<='6'&&s[0]=='2')||(s[0]=='1'))
            dp[1]+=1;
        }
        else
        {
            if(s[0]>='1'&&s[0]<='2')
            dp[1]+=1;
        }
        cout<<dp[0]<<dp[1];
        for(int i=2;i<m;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]>='1'&&s[i-1]<='2')
                dp[i]=dp[i-2];
                else
                return 0;
            }
            else
            {
                dp[i]+=dp[i-1];
                if((s[i]<='6'&&s[i-1]=='2')||(s[i-1]=='1'))
                dp[i]+=dp[i-2];
            }
            cout<<dp[i];
        }
        return dp[m-1];

    }
};
