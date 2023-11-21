class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> Hash;
        int ans = -1;
        for (auto e : nums)
        {
            int ret = 0, num = e;
            while (e > 0)
            {
                ret += e % 10;
                e /= 10;
            }
            if (Hash.count(ret))
                ans = max(ans, num + Hash[ret]);
            Hash[ret] = max(Hash[ret], num);
        }
        return ans;
    }
};