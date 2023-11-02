class Solution {
    int target, sum = 0;
public:
    void dfs(vector<int>& nums, int pos, int res)
    {
        //确保遍历到了最后一个数字
        if (pos == nums.size() && res == target)
        {
            sum++;
            return;
        }
        if (pos < nums.size())
        {
            dfs(nums, pos + 1, res + nums[pos]);
            dfs(nums, pos + 1, res - nums[pos]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        dfs(nums, 0, 0);
        return sum;
    }
};