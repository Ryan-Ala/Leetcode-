class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> Hash(10);
        int ans = -1;
        for (auto e : nums)
        {
            int num = e, max_num = 0;
            while (num > 0)
            {
                max_num = max(num % 10, max_num);
                num /= 10;
            }
            if (Hash[max_num])
                ans = max(ans, Hash[max_num] + e);
            Hash[max_num] = max(Hash[max_num], e);
        }
        return ans;
    }
};