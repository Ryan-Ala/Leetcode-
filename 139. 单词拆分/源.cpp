class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Hash;
        for (auto& e : wordDict)
            Hash.insert(e);

        vector<bool> dp(s.size() + 1);  //����������һ������λ
        dp[0] = 1;

        s = ' ' + s;  //��Ŀ���ַ���Ҳ���Ӹ���λ����ȥ��Ӧ�±�Ĺ���

        for (int i = 1; i <= s.size(); i++)  //���ݽ���ÿ��ȥѰ���Ƿ����ַ����ڹ�ϣ����
        {
            for (int j = i; j >= 1; j--)  //Ѱ���Ƿ����ַ����ڹ�ϣ������ǰ����ַ���Ҳ�Ƿ���Ҫ����ִ�
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