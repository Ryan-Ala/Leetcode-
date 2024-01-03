class Solution {
public:
    void fun(vector<int>& candidates, vector<vector<int>>& ret, vector<int>& pos, int i, int sum, int& target)
    {
        int w = candidates[i] + sum;
        pos.push_back(candidates[i]);
        if (w > target)
        {
            pos.pop_back();
            return;
        }
        if (w == target)
        {
            ret.push_back(pos);
            pos.pop_back();
            return;
        }
        while (i < candidates.size())
        {
            fun(candidates, ret, pos, i, w, target);
            i++;
        }
        pos.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        for (int i = 0; i < candidates.size(); i++)
        {
            vector<int> pos;
            fun(candidates, ret, pos, i, 0, target);
        }
        return ret;
    }
};