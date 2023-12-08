class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ret[10001] = { 0 };
        for (auto& e : nums)
            ret[e] += e;
        vector<int> f(10001), g(10001);
        for (int i = 1; i < 10001; i++)
        {
            f[i] = ret[i] + g[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        return max(g[10000], f[10000]);

    }
};