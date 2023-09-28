class Solution {
    vector<string> ans;
    string ret;
public:
    void dfs(string& s, int pos)
    {
        if (ret.size() == s.size())
        {
            ans.push_back(ret);
            return;
        }
        char ch = s[pos];
        //不改变大小写
        ret.push_back(ch);
        dfs(s, pos + 1);
        ret.pop_back();

        if (ch < '0' || ch>'9')
        {
            if (ch >= 'a' && ch <= 'z')
                ch -= 32;
            else
                ch += 32;

            ret.push_back(ch);
            dfs(s, pos + 1);
            ret.pop_back();
        }

    }
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};