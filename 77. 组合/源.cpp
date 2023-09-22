class Solution {
    int k, n;
    vector<vector<int>> ans;
    vector<int> ret;
public:
    void dfs(int pos)
    {
        if (ret.size() == k)
        {
            ans.push_back(ret);
            return;
        }
        for (int i = pos; i <= n; i++)
        {
            ret.push_back(i);
            dfs(i + 1);
            ret.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        this->n = n;
        dfs(1);
        return ans;
    }
};