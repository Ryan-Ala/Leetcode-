class Solution {
private:

    vector<string> res{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:

    void fun(int i, string& digits, string ans, vector<string>& ret)
    {
        if (i == digits.size())
        {
            ret.push_back(ans);

            return;
        }
        int num = digits[i] - '2';
        for (int j = 0; j < res[num].size(); j++)
        {
            fun(i + 1, digits, ans + res[num][j], ret);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits == "")
            return ret;

        fun(0, digits, "", ret);
        return ret;
    }
};