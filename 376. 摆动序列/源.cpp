class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        auto g = f;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    f[i] = max(g[j] + 1, f[i]);
                else if (nums[j] > nums[i])
                    g[i] = max(f[j] + 1, g[i]);
            }
            count = max(count, max(f[i], g[i]));
        }
        return count;
    }
};