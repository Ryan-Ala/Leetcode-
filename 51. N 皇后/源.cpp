class Solution {
    int n, check_1[20], check_2[20], check[20];
    vector<vector<string>> ans;
    vector<string> ret;
public:
    void dfs(int pos)
    {
        if (pos == n)
        {
            ans.push_back(ret);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!check[i] && !check_1[pos - i + n] && !check_2[pos + i])
            {
                check[i] = check_1[pos - i + n] = check_2[pos + i] = 1;
                ret[pos][i] = 'Q';
                dfs(pos + 1);  //ÏÂÒ»²ã
                ret[pos][i] = '.';
                check[i] = check_1[pos - i + n] = check_2[pos + i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string res;
        for (int i = 0; i < n; i++)
            res.push_back('.');
        for (int i = 0; i < n; i++)
            ret.push_back(res);
        dfs(0);
        return ans;
    }
};