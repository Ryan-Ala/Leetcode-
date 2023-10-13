class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);  //dp数组记录以当前字符结尾的符合条件的字串
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] += dp[i - 1];   //dp[i]自己为1，即当前的单个字符本身，再加上以当前字符结尾的字串数目
        }
        int Hash[26] = { 0 };
        for (int i = 0; i < n; i++)
        {
            Hash[s[i] - 'a'] = max(Hash[s[i] - 'a'], dp[i]);  //记录最大值，去重，防止1统计重复字串
        }
        int sum = 0;
        for (auto& e : Hash)
            sum += e;
        return sum;
    }
};