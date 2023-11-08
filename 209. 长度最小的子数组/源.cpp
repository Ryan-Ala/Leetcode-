class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, min_length = INT_MAX, sum = 0;
        while (right < nums.size())
        {
            sum += nums[right++];
            while (sum >= target)
            {
                if (min_length > right - left)
                    min_length = right - left;
                sum -= nums[left++];
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};