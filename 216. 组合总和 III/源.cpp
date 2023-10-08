class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
    int sum, n, k;
public:
    void dfs(int pos)
    {
        if (sum > n)return;
        if (sum == n && ret.size() == k)
        {
            ans.push_back(ret);
            return;
        }
        for (int i = pos; i <= 9; i++)
        {
            sum += i;
            ret.push_back(i);
            dfs(i + 1);
            ret.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        this->k = k;
        dfs(1);
        return ans;
    }
};