class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int ret = 1, left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ret *= nums[i];

            while (left <= i && ret >= k)
                ret /= nums[left++];

            count += i - left + 1;
        }
        return count;
    }
};