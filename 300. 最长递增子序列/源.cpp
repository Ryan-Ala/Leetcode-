class Solution {
public:
    int ret, n;
    int dfs(vector<int>& nums, int pos, vector<int>& mem)
    {
        if (mem[pos] != 0)
            return mem[pos];
        int res = 1;
        for (int i = pos + 1; i < n; i++)
        {
            if (nums[i] > nums[pos])   //递归寻找
            {
                res = max(res, dfs(nums, i, mem) + 1);  //更新最大值
            }
        }
        mem[pos] = res;
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> mem(n);  //记忆化数组
        for (int i = 0; i < n; i++)
        {
            ret = max(ret, dfs(nums, i, mem));
        }
        return ret;
    }
};