class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_length=s1.size(),s2_length=s2.size(),s3_length=s3.size();
        if(s1_length==0&&s2_length==0&&s3_length==0)return 1;
        vector<vector<bool>> dp = vector<vector<bool>>(s1_length+1,vector<bool>(s2_length+1));
        if(s1_length+s2_length!=s3_length)return 0;
        s1=' '+s1;
        s2=' '+s2;
        s3=' '+s3;

        for(int i=0;i<=s1_length;i++)
        if(s1[i]==s3[i])
        dp[i][0]=1;
        else
        break;

        for(int i=0;i<=s2_length;i++)
        if(s2[i]==s3[i])
        dp[0][i]=1;
        else
        break;

        for(int i=1;i<=s1_length;i++)
        for(int j=1;j<=s2_length;j++)
        {
            //s1的末尾与s3相等                          //s2的末尾与s3相等
            dp[i][j]= (s1[i]==s3[i+j] && dp[i-1][j])||(s2[j]==s3[i+j] && dp[i][j-1]);
           
        }
        return dp[s1_length][s2_length];
    }
};