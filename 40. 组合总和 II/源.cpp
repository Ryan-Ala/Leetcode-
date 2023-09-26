class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
    int target, sum = 0;
    bool hash[100];
public:
    void dfs(vector<int>& candidates, int pos)
    {
        //剪枝，大于了就不用递归了
        if (sum > target)
            return;
        if (sum == target)
        {
            ans.push_back(ret);
            return;
        }
        for (int i = pos; i < candidates.size(); i++)
        {
            if (hash[i] == 1)
                continue;
            if (i == 0 || candidates[i - 1] != candidates[i] || hash[i - 1] == 1)
            {
                hash[i] = 1;
                ret.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates, i + 1);
                sum -= candidates[i];
                ret.pop_back();
                hash[i] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->target = target;
        dfs(candidates, 0);
        /* set<vector<int>> s(ans.begin(),ans.end());  //创建容器s，将初始与结束迭代器丢入容器，并去中
        ans.assign(s.begin(),s.end());          //将容器内的元素再返还ans数组 */
        return ans;
    }
};