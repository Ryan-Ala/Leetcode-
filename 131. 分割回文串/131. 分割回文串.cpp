class Solution {
public:
    vector<vector<string>> ans;
    vector<string> ret;
    int m;
    vector<vector<bool>> dp;
    void dfs(int pos,string &s)
    {
        if(pos>m)return;
        if(pos==m)
        {
            ans.push_back(ret);
            return;
        }
        for(int i=pos;i<m;i++)
        {
            if(dp[pos][i])
            {
                ret.push_back(s.substr(pos,i-pos+1));
                dfs(i+1,s);
                ret.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        m=s.size();
        dp= vector<vector<bool>>(m,vector<bool>(m));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=i;j<m;j++)
            {
                if(s[i]==s[j])
                dp[i][j] = i+1<j?dp[i+1][j-1]:1;
            }
        }
        dfs(0,s);
        return ans;
    }
};