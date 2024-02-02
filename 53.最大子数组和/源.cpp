class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0, max = INT_MIN;
        for (auto e : nums)
        {
            count = fmax(e, count + e);
            if (max < count)
                max = count;
        }
        return max;
    }
};