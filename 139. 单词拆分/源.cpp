class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Hash;
        for (auto& e : wordDict)
            Hash.insert(e);

        vector<bool> dp(s.size() + 1);  //将数组增加一个辅助位
        dp[0] = 1;

        s = ' ' + s;  //在目标字符串也增加辅助位，免去对应下标的工作

        for (int i = 1; i <= s.size(); i++)  //向后递进，每次去寻找是否有字符串在哈希表中
        {
            for (int j = i; j >= 1; j--)  //寻找是否有字符串在哈希表中且前面的字符串也是符合要求的字串
            {
                if (dp[j - 1] && Hash.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

/* class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Hash;
        for(auto &e:wordDict)
        Hash.insert(e);

        vector<bool> dp(wordDict.size()+1);
        dp[0]=1;

        s=' '+s;

        for(int i=1;i<=wordDict.size();i++)
        {
            int j=i;
            for(;j<=wordDict.size();j++)
            {
                if(dp[i-1]&&Hash.count(s.substr(i,j-i+1)))
                {
                    dp[i]=1;
                    break;
                }
            }
            if(j-1==wordDict.size())
            return 0;
        }
        return dp[wordDict.size()];
    }
}; */