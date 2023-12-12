class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
        {
            if (nums.size() == 0)
                return 0;
            if (nums.size() == 1)
                return nums[0];
        }
        return max(fun(nums, 0, nums.size() - 2), fun(nums, 1, nums.size() - 1));
    }
    int fun(vector<int>& ret, int left, int right)
    {
        int lenght = ret.size();
        vector<int> f(lenght), g(lenght);
        f[left] = ret[left];
        for (int i = left + 1; i <= right; i++)
        {
            f[i] = g[i - 1] + ret[i];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        return max(f[right], g[right]);
    }
};