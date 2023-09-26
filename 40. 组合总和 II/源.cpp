class Solution {
    vector<vector<int>> ans;
    vector<int> ret;
    int target, sum = 0;
    bool hash[100];
public:
    void dfs(vector<int>& candidates, int pos)
    {
        //��֦�������˾Ͳ��õݹ���
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
        /* set<vector<int>> s(ans.begin(),ans.end());  //��������s������ʼ�����������������������ȥ��
        ans.assign(s.begin(),s.end());          //�������ڵ�Ԫ���ٷ���ans���� */
        return ans;
    }
};