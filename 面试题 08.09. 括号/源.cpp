class Solution {
    vector<string> ans;
    string ret;
    int n, left = 0, right = 0;
public:
    void dfs()
    {
        if (right == n)
        {
            ans.push_back(ret);
            return;
        }
        if (left < n)
        {
            left++;
            ret.push_back('(');
            dfs();
            ret.pop_back();
            left--;
        }
        if (right < left)
        {
            right++;
            ret.push_back(')');
            dfs();
            ret.pop_back();
            right--;
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs();
        return ans;
    }
};